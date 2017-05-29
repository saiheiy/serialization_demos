#include <helper_pb_foobar.h>
#include <iostream>
#include <string>
#include <stdexcept>
#include <chrono>
#include <vector>

void run(int num_times, bool do_debug){
    std::chrono::duration<double> ser_time(0.0);
    std::chrono::duration<double> des_time(0.0);
    fbh::Encoder enc;

    for(int ii=0; ii < num_times; ii++){
        //SERIALIZING
        auto ser_start = std::chrono::high_resolution_clock::now();
        enc.encode();
        ser_time += std::chrono::high_resolution_clock::now() - ser_start;
        char *buffer = enc.data();
        int buffer_size = enc.size();

        if(do_debug){
            std::cout << "finished serializing, size: " << enc.size() << "\n"; 
        }

        //DESERIALIZING
        auto des_start = std::chrono::high_resolution_clock::now();
        const FooBarContainer dpos = fbh::decode(buffer, buffer_size);
        des_time += std::chrono::high_resolution_clock::now() - des_start; 
        if(do_debug){
            std::cout << dpos << "\n";
        }
    }
    std::cout << "ser/des structre " << num_times 
        << " times. \n"
        << "serialization time: " << ser_time.count() << " seconds.\n"
        << "deserialization time: " << des_time.count() << " seconds." << std::endl;
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
