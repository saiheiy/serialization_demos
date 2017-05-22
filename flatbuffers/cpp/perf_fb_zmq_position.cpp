#include <position_fb_helper.h>
#include <zmq.hpp>
#include <unistd.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <iostream>
#include <string>
#include <stdexcept>
#include <chrono>
#include <fstream>
#include <vector>

void subscriber(int num_times, bool do_debug){
    zmq::context_t context(1); //TODO: TRY DIFFERENT NUMBER OF THREADS
    zmq::socket_t socket(context, ZMQ_PULL);
    socket.bind("tcp://127.0.0.1:60610");
    std::chrono::duration<double> ser_time(0.0);
    for(int ii=0; ii < num_times; ii++){
        //DESERIALIZING
        zmq::message_t msg; //TODO: TRY WITH INITIAL SIZE
        socket.recv(&msg); 
        if(do_debug){
            if(!fbh::verify(msg.data(), msg.size())){
                throw std::runtime_error("verify failed");
            }
            else{
                std::cout << "msg verified to be ok!!\n";
            }
        }
        auto time0 = std::chrono::system_clock::now();
        auto *dpos = fbh::decode(msg.data());
        auto time1 = std::chrono::system_clock::now(); 
        ser_time += (time1 - time0);
        if(do_debug){
            std::cout << *dpos << "\n";
        }
    }
    std::cout << "deserialization time: " << ser_time.count() << " seconds.\n";
}

void publisher(int num_times, bool do_debug){
    std::chrono::duration<double> des_time(0.0);
    fbh::Encoder enc;
    zmq::context_t context(1); //TODO: try different num threads
    zmq::socket_t socket(context, ZMQ_PUSH);
    socket.connect("tcp://127.0.0.1:60610");
    for(int ii=0; ii < num_times; ii++){
        //SERIALIZING
        auto time0 = std::chrono::system_clock::now();
        enc.encode();
        if(do_debug){
            std::cout << "finished serializing, size: " << enc.size() << "\n"; 
        }
        auto time1 = std::chrono::system_clock::now();
        zmq::message_t msg(enc.size());
        memcpy(msg.data(), enc.data(), enc.size());
        socket.send(msg);
        des_time += (time1 - time0);
    }
    std::cout << "serialization time: " << des_time.count() << " seconds.\n";
}



void run(int num_times, bool do_debug){
    pid_t childPid = fork();
    if(childPid == 0)
    {
        subscriber(num_times, do_debug);
    }
    else if(childPid < 0){
        std::runtime_error("fork failed");
    }
    else{
        auto t1 = std::chrono::high_resolution_clock::now();
        publisher(num_times, do_debug);
        pid_t r = wait(NULL);
        auto t2 = std::chrono::high_resolution_clock::now();
        auto duration = std::chrono::duration_cast<std::chrono::microseconds>(t2 -t1).count();
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
