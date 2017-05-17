#include <position.pb.h>
#include <google/protobuf/io/zero_copy_stream_impl.h> //OstreamOutputStream
#include <google/protobuf/io/zero_copy_stream.h> //ZeroCopyOutputStream
#include <google/protobuf/io/coded_stream.h> //CodedOutputStream
#include <iostream>
#include <fstream>
#include <stdexcept>
namespace gp = google::protobuf;

bool readDelimitedFrom(gp::io::ZeroCopyInputStream *rawInput,
        gp::MessageLite* message){
    gp::io::CodedInputStream input(rawInput);
    uint32_t size;
    if(!input.ReadVarint32(&size)) return false;
    gp::io::CodedInputStream::Limit limit = input.PushLimit(size);
    if(!message->MergeFromCodedStream(&input)) return false;
    if(!input.ConsumedEntireMessage()) return false;
    input.PopLimit(limit);
    return true;
}

void run(int num_times, bool do_debug){
    std::ifstream ifs("temp.fifo", std::ios::binary);
    gp::io::ZeroCopyInputStream *zcis = new gp::io::IstreamInputStream(&ifs);
    for(int ii=0; ii < num_times; ii++){
        demo::Position pos;
        if(!readDelimitedFrom(zcis, &pos)){
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
    std::cout << "FINISHED READING!!!!" << std::endl;    
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
