CXX=g++
RM=rm -f
CPPFLAGS=-std=c++11
INCFLAGS=-I. -I../../../install/flatbuffers/include -I../headers
LDFLAGS=
OBJS=perf_fb_foobar.o

all: perf_fb_foobar.tsk int_clean

perf_fb_foobar.tsk: $(OBJS) 
	$(CXX) -o $@ $^ $(LDFLAGS) 

perf_fb_foobar.o: perf_fb_foobar.cpp
	$(CXX) -c $(CPPFLAGS) $< $(INCFLAGS)

.PHONY: clean int_clean
int_clean: 
	$(RM) *.o

clean: int_clean
	$(RM) *.tsk


