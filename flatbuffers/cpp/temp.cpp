#include <fstream>

int main(){

    std::ofstream ofs("/tmp/temp.fifo", std::ios::binary);
    char buffer[10] = "blablabla";
    ofs.write(buffer, 10);
    return 0;
}
