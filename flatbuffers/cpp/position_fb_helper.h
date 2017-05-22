#include <position_generated.h>
#include <iostream>

namespace fbh{

const long positionId = 9191919191;
//std::string stock("IBM");
const char* stock = "IBM";
const int accountId = 1234;
const double posQty = 100.0;
const double avgCost = 259.54;
const double mv = 25954.00;

class Encoder{
public:
    Encoder()
        :builder(100)
    {}
    
    void encode(){
        builder.Clear();
        auto pos_offset = Ps::CreatePositionDirect(
                builder,
                positionId,
                stock,
                accountId,
                posQty,
                avgCost,
                mv);
        builder.Finish(pos_offset);
    }

    char *data(){
        return (char *) builder.GetBufferPointer();
    }

    int size(){
        return builder.GetSize();
    }

private: 
    flatbuffers::FlatBufferBuilder builder;
};

const Ps::Position *decode(void* buffer){
    return Ps::GetPosition(buffer);
}

bool verify(void* buffer, int size){
    flatbuffers::Verifier verifier((uint8_t *) buffer, size);
    return Ps::VerifyPositionBuffer(verifier);
}
} //fbh

std::ostream& operator<<(std::ostream& os, const Ps::Position& dpos){
    os << dpos.positionId() << ","
        << dpos.secName()->c_str() << ","
        << dpos.accountId() << ","
        << dpos.posQty() << ","
        << dpos.avgCost() << ","
        << dpos.mv() << "\n";
    return os;
}
