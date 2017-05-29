CXX=g++
RM=rm -f
CPPFLAGS=-std=c++11
INCFLAGS=-I. -I../../../install/flatbuffers/include -I../headers
INCFLAGS+=-I../../../install/zeromq-4.2.1/include
LDFLAGS=../../../install/zeromq-4.2.1/lib/libzmq.a -lpthread 
OBJS=fb_zmq_subscriber.o

all: fb_zmq_subscriber.tsk int_clean

fb_zmq_subscriber.tsk: $(OBJS) 
	$(CXX) -o $@ $^ $(LDFLAGS) 

fb_zmq_subscriber.o: fb_zmq_subscriber.cpp
	$(CXX) -c $(CPPFLAGS) $< $(INCFLAGS)

.PHONY: clean int_clean
int_clean: 
	$(RM) *.o

clean: int_clean
	$(RM) *.tsk


