#include "examples.pb.h"
#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <unistd.h>


struct Message{
  std::string m_str;
  int m_int;
  long long m_ll;
  bool m_bool;
  std::vector<int> m_vec_int; 
};

Message generate_test_msg(){
  Message msg;
  msg.m_str = "IBM";
  msg.m_int = 42;
  msg.m_ll = 20171017;
  msg.m_bool = false;
  int arr[] = {2,3,5,8,13};
  msg.m_vec_int = std::vector<int>(arr, arr + sizeof(arr) / sizeof(int)); 
  return msg;
}

std::ostream& operator<<(std::ostream& os, const std::vector<int>& vec){
  os << "[";
  for(std::size_t ii=0; ii < vec.size(); ++ii){
    os << vec[ii] << ", ";
  }
  os << "]";
  return os;
}

std::ostream& operator<<(std::ostream& os, const Message& msg){
  os 
    << "m_str: " << msg.m_str << ", "
    << "m_m_int: " << msg.m_int << ", "
    << "m_m_ll: " << msg.m_ll << ", "
    << std::boolalpha
    << "m_bool: " << msg.m_bool << ", "
    << "m_vec_int: " << msg.m_vec_int;
  return os;
}

int main(){
  pid_t pid = fork(); 
  Message msg = generate_test_msg();
  if (pid == 0){
    //child
    std::ofstream ofs("temp.fifo", std::ofstream::binary);
    examples::PbMsg pbmsg;
    pbmsg.set_pb_str(msg.m_str);
    pbmsg.set_pb_int(msg.m_int);
    pbmsg.set_pb_ll(msg.m_ll);
    pbmsg.set_pb_bool(msg.m_bool);
    for(std::size_t ii=0; ii < msg.m_vec_int.size(); ++ii){
      pbmsg.add_pb_vec_int(msg.m_vec_int[ii]);
    }
    std::cout << "WRITER: serialize msg to ostream" << std::endl;
    pbmsg.SerializeToOstream(&ofs);
  }
  else if (pid > 0){
    //parent
    std::cout << "READER: parsing msg from istream" << std::endl;
    std::ifstream ifs("temp.fifo", std::ifstream::binary);
    examples::PbMsg pbmsg;
    if(!pbmsg.ParseFromIstream(&ifs)){
      std::cerr << "failed to parse pbmsg" << std::endl;
      return -1;
    }
    std::cout << "pb_str: " << pbmsg.pb_str() << ", "
      << "pb_int: " << pbmsg.pb_int() << ", "
      << "pb_ll: " << pbmsg.pb_ll() << ", "
      << "pb_bool: " << pbmsg.pb_bool() << std::endl;
    for(int ii=0; ii < pbmsg.pb_vec_int_size(); ++ii){
      std::cout << "pb_vec_int: "
        << pbmsg.pb_vec_int(ii) << ", ";
    }
    std::cout << std::endl;
  }
  else{
    std::cout << "error: fork() failed\n";
    return -1;
  }
  return 0;
}
