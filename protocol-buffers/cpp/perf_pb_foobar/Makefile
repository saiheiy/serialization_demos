CXX=c++
RM=rm -f
COMMON=../common
CPPFLAGS=-std=c++11
INCFLAGS=-I. -I../../../install/protobuf-3.3.0/include -I../common
LDFLAGS=../../../install/protobuf-3.3.0/lib/libprotobuf.a -lpthread
OBJS=perf_pb_foobar.o foobar.pb.o 

all: perf_pb_foobar.tsk int_clean

perf_pb_foobar.tsk: $(OBJS) 
	$(CXX) -o $@ $^ $(LDFLAGS) 

perf_pb_foobar.o: perf_pb_foobar.cpp
	$(CXX) -c $(CPPFLAGS) $< $(INCFLAGS)

foobar.pb.o: $(COMMON)/foobar.pb.cc 
	$(CXX) -c $(CPPFLAGS) $< $(INCFLAGS)

.PHONY: clean int_clean
int_clean: 
	$(RM) *.o

clean: int_clean
	$(RM) *.tsk


