#include <position_generated.h>
#include <zmq.hpp>
#include <iostream>
#include <unistd.h>
#include <string>
#include <cstdlib>

void run(int num_times, bool do_debug){
    zmq::context_t context(1);
    zmq::socket_t socket(context, ZMQ_PULL);
    socket.bind("tcp://127.0.0.1:60610");
    for(int ii=0; ii < num_times; ii++){
        zmq::message_t request;
        socket.recv(&request);
        const Ps::Position* pos = Ps::GetPosition(request.data());
        if(do_debug){
            std::cout << "RECEIVED " << ii << " -- " 
                << "positionId: " << pos->positionId() << ", " 
                << "secName: " << pos->secName()->c_str() << ", " 
                << "accountId: " << pos->accountId() << ", " 
                << "posQty: " << pos->posQty() << ", " 
                << "avgCost: " << pos->avgCost() << ", " 
                << "mv: " << pos->mv() << std::endl; 
        }
    }
    std::cout << "DONE!!!" << std::endl;

}

int main(int argc, char *argv[]){
    if(argc == 1){
        run(5, true);   
    }
    else{
        int num_times = std::atoi(argv[1]); 
        run(num_times, false);
    }

    return 0;
}
