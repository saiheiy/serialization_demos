#include <foobar_generated.h>
#include <iostream>

namespace fbh{

const int veclen = 3;

class Encoder{
public:
    Encoder()
        :builder(500)
    {}
    
    void encode(){
        builder.Clear();
        flatbuffers::Offset<foobar::FooBar> vec[veclen];
        for(int ii=0; ii < veclen; ii++){
            foobar::Foo foo(0xABADCAFEABADCAFE + ii, 10000 + ii, '@' + ii, 1000000 + ii);
            foobar::Bar bar(foo, 123456 + ii, 3.14159f + ii, 10000 + ii);
            auto name = builder.CreateString("Hello World");
            auto foobar = foobar::CreateFooBar(builder, &bar, name, 3.1415432432445543543 + ii, '!' + ii);
            vec[ii] = foobar;
        }
        auto location = builder.CreateString("http://google.com/flatbuffers/");
        auto foobarvec = builder.CreateVector(vec, veclen);
        auto foobarcontainer = foobar::CreateFooBarContainer(builder, foobarvec, true, foobar::Enum_Bananas, location);
        builder.Finish(foobarcontainer);
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

const foobar::FooBarContainer *decode(void* buffer){
    foobar::GetFooBarContainer(buffer);
}

bool verify(void* buffer, int size){
    flatbuffers::Verifier verifier((uint8_t *) buffer, size);
    return foobar::VerifyFooBarContainerBuffer(verifier);
}
} //fbh

std::ostream& operator<<(std::ostream& os, const foobar::FooBarContainer& dpos){
    os << std::boolalpha << dpos.initialized() << ", "
        << dpos.location()->c_str() << ", "
        << dpos.fruit() << ", ";
    for(unsigned int ii=0; ii < dpos.list()->Length(); ii++){
        auto fb = dpos.list()->Get(ii);
        auto bar = fb->sibling();
        auto &foo = bar->parent();
        os << "[" 
            << fb->name()->c_str() << ", "
            << fb->postfix() << ", "
            << fb->rating() << ", "
            << bar->ratio() << ", "
            << bar->size() << ", "
            << bar->time() << ", "
            << foo.count() << ", "
            << foo.id() << ", "
            << foo.length() << ", "
            << foo.prefix() << "], ";
    }
    os << "\n";
}
