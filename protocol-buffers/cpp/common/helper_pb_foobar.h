#include <foobar.pb.h>
#include <iostream>
#include <vector>
#include <stdexcept>

namespace gp = google::protobuf;
using namespace benchpb;

namespace fbh{

const int veclen = 3;

class Encoder{
public:
    void encode(){
        FooBarContainer foobarcontainer;
        for(int i = 0; i < veclen; i++){
            auto foobar = foobarcontainer.add_list();
            foobar->set_name("Hello, World!");
            foobar->set_rating(3.1415432432445543543 + i);
            foobar->set_postfix('!' + i);
            auto bar = foobar->mutable_sibling();
            bar->set_time(123456 + i);
            bar->set_ratio(3.14159f + i);
            bar->set_size(10000 + i);
            auto foo = bar->mutable_parent();
            foo->set_id(0xABADCAFEABADCAFE + i);
            foo->set_count(10000 + i);
            foo->set_prefix('@' + i);
            foo->set_length(1000000 + i);
        }
        foobarcontainer.set_location("http://google.com/flatbuffers/");
        foobarcontainer.set_initialized(true);
        foobarcontainer.set_fruit(Bananas);
        int size = foobarcontainer.ByteSize();
        bufvec.resize(size);
        if(!foobarcontainer.SerializeToArray(bufvec.data(), size))
            throw std::runtime_error("error serializing");
    }

    char *data(){
        return bufvec.data();
    }

    int size(){
        return bufvec.size();
    }
private:
    std::vector<char> bufvec;
};

const FooBarContainer decode(const char *buffer, int size){
    FooBarContainer foobarcontainer;
    foobarcontainer.ParseFromArray(buffer, size);
    return foobarcontainer;
}

} //fbh

std::ostream& operator<<(std::ostream& os, const FooBarContainer& dpos){
    os << std::boolalpha << dpos.initialized() << ", "
        << dpos.location() << ", "
        << dpos.fruit() << ", ";
    for(int ii=0; ii < dpos.list().size(); ii++){
        auto &fb = dpos.list().Get(ii);
        auto &bar = fb.sibling();
        auto &foo = bar.parent();
        os << "[" 
            << fb.name() << ", "
            << fb.postfix() << ", "
            << fb.rating() << ", "
            << bar.ratio() << ", "
            << bar.size() << ", "
            << bar.time() << ", "
            << foo.count() << ", "
            << foo.id() << ", "
            << foo.length() << ", "
            << foo.prefix() << "], ";
    }
    os << "\n";
    return os;
}
