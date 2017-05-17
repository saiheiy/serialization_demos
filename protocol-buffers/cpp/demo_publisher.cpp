#include <position.pb.h>
#include <iostream>
#include <fstream>

void run(int num_times, bool do_debug){
    std::ofstream ofs("temp.fifo");
    long positionId = 9191919191;
    std::string stock("IBM");
    int accountId = 1234;
    double posQty = 100.0;
    double avgCost = 259.54;
    double mv = 25954.00;

    std::cout << "start" << std::endl;

    for(int ii=0; ii < num_times; ii++){
        demo::Position pos;
        pos.set_positionid(positionId);
        pos.set_secname(stock);
        pos.set_accountid(accountId);
        pos.set_posqty(posQty);
        pos.set_avgcost(avgCost);
        pos.set_mv(mv);
        //pos.SerializeToOstream(&ofs);
        std::string msg;
        if(!pos.SerializeToString(&msg))
            throw std::runtime_error("cannot serialize");
        ofs << msg;
    }
    std::cout << "FINISH PUBLISHING!!!!" << std::endl;
}

int main(int argc, char *argv[]){
    std::cout << "start0" << std::endl;
    if(argc == 1){
        run(5, true);
    }
    else{
        int num_times = atoi(argv[1]);
        run(num_times, false);
    }
    return 0;
}
