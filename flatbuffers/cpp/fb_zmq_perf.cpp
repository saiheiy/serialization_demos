#include <position_fb_helper.h>
#include <zmq.hpp>
#include <iostream>
#include <unistd.h>
#include <string>
#include <cstdlib>
#include <stdexcept>
#include <chrono>

void run(int num_times, bool do_debug){
    std::chrono::duration<double> ser_time(0.0);
    std::chrono::duration<double> transport_time(0.0);
    std::chrono::duration<double> des_time(0.0);
    std::chrono::duration<double> total_time(0.0);

    zmq::context_t context(1);
    zmq::socket_t push_socket(context, ZMQ_PUSH);
    push_socket.bind("tcp://127.0.0.1:60610");
    //push_socket.bind("inproc://test2");

    zmq::context_t context_pull(1);
    zmq::socket_t pull_socket(context_pull, ZMQ_PULL);
    pull_socket.connect("tcp://127.0.0.1:60610");
    //pull_socket.connect("inproc://test2");
    
    fbh::Encoder enc;

    for(int ii=0; ii < num_times; ii++){
        //SERIALIZING
        auto time0 = std::chrono::system_clock::now();
        enc.encode();

        if(do_debug){
            std::cout << "finished serializing, size: " << enc.size() << "\n"; 
        }
        auto time1 = std::chrono::system_clock::now();
        zmq::message_t out_msg(enc.size());
        memcpy(out_msg.data(), enc.data(), enc.size());
        push_socket.send(out_msg);
        

        //DESERIALIZING
        zmq::message_t in_msg;
        pull_socket.recv(&in_msg);
        if(do_debug){
            if(!fbh::verify(in_msg.data(), in_msg.size()))
                throw std::runtime_error("verify failed");
            else{
                std::cout << "msg verified to be ok!!\n";
            }
        }
        
        auto time2 = std::chrono::system_clock::now();
        auto *dpos = fbh::decode(in_msg.data());
        //const Ps::Position *dpos = Ps::GetPosition(in_msg.data());
        auto time3 = std::chrono::system_clock::now(); 
        if(do_debug){
            std::cout << *dpos << "\n";
           //std::cout << dpos->positionId() << ","
           //     << dpos->secName()->c_str() << ","
           //     << dpos->accountId() << ","
           //     << dpos->posQty() << ","
           //     << dpos->avgCost() << ","
           //     << dpos->mv() << "\n";
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
