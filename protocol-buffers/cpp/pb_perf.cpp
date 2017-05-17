#include <position.pb.h>
#include <google/protobuf/io/zero_copy_stream_impl.h> //OstreamOutputStream
#include <google/protobuf/io/zero_copy_stream.h> //ZeroCopyOutputStream
#include <google/protobuf/io/coded_stream.h> //CodedOutputStream
#include <iostream>
#include <fstream>
#include <stdexcept>
#include <chrono>
namespace gp = google::protobuf;


void run(int num_times, bool do_debug){
    long positionId = 9191919191;
    std::string stock("IBM");
    int accountId = 1234;
    double posQty = 100.0;
    double avgCost = 259.54;
    double mv = 25954.00;
    

    std::chrono::duration<double> ser_time(0.0);
    std::chrono::duration<double> des_time(0.0);
    
    for(int ii=0; ii < num_times; ii++){
        //SERIALIZING
        auto ser_start = std::chrono::system_clock::now();
        demo::Position pos;
        pos.set_positionid(positionId);
        pos.set_secname(stock);
        pos.set_accountid(accountId);
        pos.set_posqty(posQty);
        pos.set_avgcost(avgCost);
        pos.set_mv(mv);
        int size = pos.ByteSize();
        char buffer[size];
        if(!pos.SerializeToArray(buffer, size))
            throw std::runtime_error("error serializing");
        ser_time += (std::chrono::system_clock::now() - ser_start);
        if(do_debug){
            std::cout << "done serializing, size: " << size << "\n" ;
        }

        //DESERIALIZING
        auto des_start = std::chrono::system_clock::now();
        demo::Position dpos;
        if(!dpos.ParseFromArray(buffer, size))
            throw std::runtime_error("error deserializing");
        des_time += (std::chrono::system_clock::now() - des_start);
        if(do_debug){
            std::cout << "DESERIALZIZED: " 
                << "positionId: " << dpos.positionid() << ", "
                << "secName: " << dpos.secname() << ", "
                << "accountId: " << dpos.accountid() << ", "
                << "posQty: " << dpos.posqty() << ", "
                << "avgCost: " << dpos.avgcost() << ", "
                << "mv: " << dpos.mv() << "\n";
        }
    }
    
    std::cout << "ser/des Position structre " << num_times 
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


