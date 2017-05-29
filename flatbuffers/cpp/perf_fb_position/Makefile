CXX=c++
RM=rm -f
CPPFLAGS=-std=c++11
INCFLAGS=-I. -I../../../install/flatbuffers/include -I../headers
LDFLAGS=
OBJS=perf_fb_position.o

all: perf_fb_position.tsk int_clean

perf_fb_position.tsk: $(OBJS) 
	$(CXX) -o $@ $^ $(LDFLAGS) 

perf_fb_position.o: perf_fb_position.cpp
	$(CXX) -c $(CPPFLAGS) $< $(INCFLAGS)

.PHONY: clean int_clean
int_clean: 
	$(RM) *.o

clean: int_clean
	$(RM) *.tsk


