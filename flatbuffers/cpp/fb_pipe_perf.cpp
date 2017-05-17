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


bool fileExists(const char* file){
    struct stat buf;
    return (stat(file, &buf) == 0);
}

void run(int num_times, bool do_debug){
    std::chrono::duration<double> ser_time(0.0);
    std::chrono::duration<double> transport_time(0.0);
    std::chrono::duration<double> des_time(0.0);
    std::chrono::duration<double> total_time(0.0);

    const char *myfifo = "/tmp/temp.fifo";
    if(!fileExists(myfifo)){
        mkfifo(myfifo, 0666);     
    }

    std::cout << __LINE__ << std::endl;
    std::ifstream ifs(myfifo, std::ifstream::binary);
    std::cout << __LINE__ << std::endl;
    std::ofstream ofs(myfifo, std::ofstream::binary);
    std::cout << __LINE__ << std::endl;
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
        

        //DESERIALIZING
        std::vector<char> buffer(enc.size());
        ifs.read(buffer.data(), enc.size());
        if(do_debug){
            if(!fbh::verify(buffer.data(), buffer.size()))
                throw std::runtime_error("verify failed");
            else{
                std::cout << "msg verified to be ok!!\n";
            }
        }
        
        auto time2 = std::chrono::system_clock::now();
        auto *dpos = fbh::decode(buffer.data());
        auto time3 = std::chrono::system_clock::now(); 
        if(do_debug){
            std::cout << *dpos << "\n";
        }
        ser_time += (time1 - time0);
        transport_time += (time2 - time1);
        des_time += (time3 - time2);
        total_time += (time3 - time0);
    }
    std::cout << "ser/des structre " << num_times << " times. \n"
        << "serialization time: " << ser_time.count() << " seconds.\n"
        << "transport time: " << transport_time.count() << " seconds.\n"
        << "deserialization time: " << des_time.count() << " seconds.\n"
        << "total time: " << total_time.count() << " seconds." << std::endl;
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
