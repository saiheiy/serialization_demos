#include <position_generated.h>
#include <fstream>
#include <string>

int main(){
    uint64_t positionId = 9191919191;
    std::string stock("IBM");
    int accountId = 1234;
    double posQty = 100.0;
    double avgCost = 259.54;
    double mv = 25954.00;

    flatbuffers::FlatBufferBuilder builder;
    auto secName = builder.CreateString(stock);
    Ps::PositionBuilder position_builder(builder);
    position_builder.add_positionId(positionId);
    position_builder.add_secName(secName);
    position_builder.add_accountId(accountId);
    position_builder.add_posQty(posQty);
    position_builder.add_avgCost(avgCost);
    position_builder.add_mv(mv);
    auto pos = position_builder.Finish();
    builder.Finish(pos);

    std::ofstream ofs("pos.fbo", std::ofstream::binary);
    ofs.write((char *) builder.GetBufferPointer(), builder.GetSize());
    ofs.close();
    return 0;
}
