#include <position_generated.h>
#include <iostream>
#include <string>
#include <stdexcept>
#include <chrono>

void run(int num_times, bool do_debug){
    long positionId = 9191919191;
    //std::string stock("IBM");
    const char* stock = "IBM";
    int accountId = 1234;
    double posQty = 100.0;
    double avgCost = 259.54;
    double mv = 25954.00;

    std::chrono::duration<double> ser_time(0.0);
    std::chrono::duration<double> des_time(0.0);
    flatbuffers::FlatBufferBuilder builder;

    for(int ii=0; ii < num_times; ii++){
        //SERIALIZING
        auto ser_start = std::chrono::system_clock::now();
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
        ser_time += std::chrono::system_clock::now() - ser_start;
        char *buffer = (char *) builder.GetBufferPointer();

        if(do_debug){
            std::cout << "finished serializing, size: " << builder.GetSize() << "\n"; 
        }

        //DESERIALIZING
        if(do_debug){
            flatbuffers::Verifier verifier((uint8_t *) buffer, builder.GetSize()); 
            bool ok = Ps::VerifyPositionBuffer(verifier);
            if(!ok)
                throw std::runtime_error("verify failed");
        }
        auto des_start = std::chrono::system_clock::now();
        const Ps::Position *dpos = Ps::GetPosition(buffer);
        des_time += std::chrono::system_clock::now() - des_start; 
        if(do_debug){
            std::cout << dpos->positionId() << ","
                << dpos->secName()->c_str() << ","
                << dpos->accountId() << ","
                << dpos->posQty() << ","
                << dpos->avgCost() << ","
                << dpos->mv() << "\n";
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
