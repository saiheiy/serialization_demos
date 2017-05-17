#include <position_fb_helper.h>
#include <iostream>
#include <unistd.h>
#include <string>
#include <cstdlib>
#include <stdexcept>
#include <chrono>
#include <fstream>
#include <vector>
#include <sys/stat.h>
#include <sys/types.h>
#include <sys/wait.h>

const char *myfifo = "/tmp/temp.fifo";
void subscriber(int num_times, int size, bool do_debug){
    std::ifstream ifs(myfifo, std::ios::binary);
    std::cout << "reading from: " << myfifo << std::endl;
    std::chrono::duration<double> ser_time(0.0);
    for(int ii=0; ii < num_times; ii++){
        //DESERIALIZING
        std::vector<char> buffer(size);
        ifs.read(buffer.data(), size);
        if(do_debug){
            if(!fbh::verify(buffer.data(), buffer.size())){
                throw std::runtime_error("verify failed");
            }
            else{
                std::cout << "msg verified to be ok!!\n";
            }
        }
        auto time0 = std::chrono::system_clock::now();
        auto *dpos = fbh::decode(buffer.data());
        auto time1 = std::chrono::system_clock::now(); 
        ser_time += (time1 - time0);
        if(do_debug){
            std::cout << *dpos << "\n";
        }
    }
    std::cout << "deserialization time: " << ser_time.count() << " seconds.\n";
}

void publisher(int num_times, bool do_debug){
    std::ofstream ofs(myfifo, std::ios::binary);
    std::chrono::duration<double> des_time(0.0);
    fbh::Encoder enc;
    for(int ii=0; ii < num_times; ii++){
        //SERIALIZING
        auto time0 = std::chrono::system_clock::now();
        enc.encode();
        if(do_debug){
            std::cout << "finished serializing, size: " << enc.size() << "\n"; 
        }
        auto time1 = std::chrono::system_clock::now();
        ofs.write(enc.data(), enc.size());
        des_time += (time1 - time0);
    }
    std::cout << "serialization time: " << des_time.count() << " seconds.\n";
}

int getSize(){
    fbh::Encoder enc;
    enc.encode();
    return enc.size();
}



bool fileExists(const char* file){
    struct stat buf;
    return (stat(file, &buf) == 0);
}

void run(int num_times, bool do_debug){
    if(!fileExists(myfifo)){
        mkfifo(myfifo, 0666);     
    }

    pid_t childPid = fork();
    if(childPid == 0)
    {
        int size = getSize();
        subscriber(num_times, size, do_debug);
    }
    else if(childPid < 0){
        std::runtime_error("fork failed");
    }
    else{
        //auto time3 = std::chrono::steady_clock::now();
        //std::time_t ttp0 = std::chrono::steady_clock::to_time_t(time0);
        //std::cout << "time0: " << ttp0  <<  std::endl;
        auto t1 = std::chrono::high_resolution_clock::now();
        publisher(num_times, do_debug);
        pid_t r = wait(NULL);
        auto t2 = std::chrono::high_resolution_clock::now();
        auto duration = std::chrono::duration_cast<std::chrono::microseconds>(t2 -t1).count();
        //std::time_t ttp1 = std::chrono::steady_clock::to_time_t(time1);
        //std::cout << "time1: " << ttp1  <<  std::endl;
        if(r == -1){
            std::cout << "child returned early?\n";
        }
        std::cout << "ser/des structre " << num_times << " times. \n"
            << "total time: " << duration / 1000000.0 << " seconds." << std::endl;
    }
}

int main(int argc, char *argv[]){
    if(argc == 1){
        run(5, true);
    }
    else{
        int num_times = atoi(argv[1]);
        run(num_times, false);
    }
    return 0;
}
