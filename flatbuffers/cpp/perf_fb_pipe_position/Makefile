CXX=g++
RM=rm -f
CPPFLAGS=-std=c++11
INCFLAGS=-I. -I../../../install/flatbuffers/include -I../headers
LDFLAGS=
OBJS=perf_fb_pipe_position.o

all: perf_fb_pipe_position.tsk int_clean

perf_fb_pipe_position.tsk: $(OBJS) 
	$(CXX) -o $@ $^ $(LDFLAGS) 

perf_fb_pipe_position.o: perf_fb_pipe_position.cpp
	$(CXX) -c $(CPPFLAGS) $< $(INCFLAGS)

.PHONY: clean int_clean
int_clean: 
	$(RM) *.o

clean: int_clean
	$(RM) *.tsk


