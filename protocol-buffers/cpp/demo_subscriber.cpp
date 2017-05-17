#include <position.pb.h>
#include <iostream>
#include <fstream>
#include <stdexcept>
#include <string>

void run(int num_times, bool do_debug){
    std::ifstream ifs("temp.fifo");
    for(int ii=0; ii < num_times; ii++){
        demo::Position pos;
        std::string msg;
        std::getline(ifs, msg);
        std::cout << msg << std::endl;
        if(!pos.ParseFromString(msg)){
            throw std::runtime_error("failed to parse msg");
        }
        if(do_debug){
            std::cout << "RECEIVED: " 
                << "positionId: " << pos.positionid() << ", "
                << "secName: " << pos.secname() << ", "
                << "accountId: " << pos.accountid() << ", "
                << "posQty: " << pos.posqty() << ", "
                << "avgCost: " << pos.avgcost() << ", "
                << "mv: " << pos.mv() << "\n";
        }
    }
    std::cout << "FINISH READING!!!" << std::endl;
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
