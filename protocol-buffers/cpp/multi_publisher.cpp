#include <position.pb.h>
#include <google/protobuf/io/zero_copy_stream_impl.h> //OstreamOutputStream
#include <google/protobuf/io/zero_copy_stream.h> //ZeroCopyOutputStream
#include <google/protobuf/io/coded_stream.h> //CodedOutputStream
#include <iostream>
#include <fstream>
#include <stdexcept>
namespace gp = google::protobuf;

bool writeDelimitedTo(const gp::MessageLite& message, 
        gp::io::ZeroCopyOutputStream* rawOutput){
    gp::io::CodedOutputStream output(rawOutput);
    const int size = message.ByteSize();
    output.WriteVarint32(size);
    message.SerializeWithCachedSizes(&output);
    if(output.HadError())
        return false;
    return true;
}


void run(int num_times, bool do_debug){
    long positionId = 9191919191;
    std::string stock("IBM");
    int accountId = 1234;
    double posQty = 100.0;
    double avgCost = 259.54;
    double mv = 25954.00;
    
    std::ofstream ofs("temp.fifo", std::ios::binary);
    gp::io::ZeroCopyOutputStream *zcos = new gp::io::OstreamOutputStream(&ofs);
    for(int ii=0; ii < num_times; ii++){
        demo::Position pos;
        pos.set_positionid(positionId);
        pos.set_secname(stock);
        pos.set_accountid(accountId);
        pos.set_posqty(posQty);
        pos.set_avgcost(avgCost);
        pos.set_mv(mv);
        if(!writeDelimitedTo(pos, zcos))
            throw std::runtime_error("writeDelimitedTo: error");
    }
    delete zcos;
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
