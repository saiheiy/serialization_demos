#include <position_generated.h>
#include <fstream>
#include <iostream>
#include <string>
#include <stdexcept>
#include <chrono>
#include <sstream>
#include <vector>

int main(){
    std::ifstream ifs("pos.fbo", std::ios::binary);
    if(!ifs.good())
        throw std::runtime_error("file does not exist");
    ifs.seekg(0, std::ios::end);
    std::streamsize size = ifs.tellg();
    ifs.seekg(0, std::ios::beg);
    std::vector<char> buffer(size);
    ifs.read(buffer.data(), size);
    flatbuffers::Verifier verifier((uint8_t *) buffer.data(), buffer.size());
    bool ok = Ps::VerifyPositionBuffer(verifier);
    if(!ok){
        throw std::runtime_error("verify failed");
    }
    const Ps::Position* pos = Ps::GetPosition(buffer.data());
    const int num_times = 1000000;
    const uint64_t positionId = pos->positionId();
    const char* secName = pos->secName()->c_str();
    const int accountId = pos->accountId();
    const double posQty = pos->posQty();
    const double avgCost = pos->avgCost();
    const double mv = pos->mv();


    std::stringstream ss;
    //FLATBUFFERS ACCESS     
    {
        auto start_time = std::chrono::system_clock::now();

        for(int ii=0; ii < num_times; ii++){
            std::cout << pos->positionId() << ","
                << pos->secName()->c_str() << ","
                << pos->accountId() << ","
                << pos->posQty() << ","
                << pos->avgCost() << ","
                << pos->mv() << "\n";
        }
        std::cout << std::endl;
        auto end_time = std::chrono::system_clock::now();
        std::chrono::duration<double> diff = end_time - start_time;
        ss << "fb access: time: " << diff.count() << "\n";
    }

    //DIRECT ACCESS     
    {
        auto start_time = std::chrono::system_clock::now();

        for(int ii=0; ii < num_times; ii++){
            std::cout << positionId << ","
                << secName<< ","
                << accountId << ","
                << posQty << ","
                << avgCost << ","
                << mv << "\n";
        }
        std::cout << std::endl;
        auto end_time = std::chrono::system_clock::now();
        std::chrono::duration<double> diff = end_time - start_time;
        ss << "direct access: time: " << diff.count() << "\n";
    }

    std::cerr << ss.str() << std::endl;
    return 0;
}
