CXX=g++
RM=rm -f
CPPFLAGS=-std=c++11
INCFLAGS=-I. -I../../../install/flatbuffers/include -I../headers
INCFLAGS+=-I../../../install/zeromq-4.2.1/include
LDFLAGS=../../../install/zeromq-4.2.1/lib/libzmq.a -lpthread 
OBJS=perf_fb_zmq_position.o

all: perf_fb_zmq_position.tsk int_clean

perf_fb_zmq_position.tsk: $(OBJS) 
	$(CXX) -o $@ $^ $(LDFLAGS) 

perf_fb_zmq_position.o: perf_fb_zmq_position.cpp
	$(CXX) -c $(CPPFLAGS) $< $(INCFLAGS)

.PHONY: clean int_clean
int_clean: 
	$(RM) *.o

clean: int_clean
	$(RM) *.tsk


