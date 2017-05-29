CXX=c++
RM=rm -f
CPPFLAGS=-std=c++11
INCFLAGS=-I. -I../../../install/flatbuffers/include -I../headers
LDFLAGS=
OBJS=perf_fb_access.o

all: perf_fb_access.tsk int_clean

perf_fb_access.tsk: $(OBJS) 
	$(CXX) -o $@ $^ $(LDFLAGS) 

perf_fb_access.o: perf_fb_access.cpp
	$(CXX) -c $(CPPFLAGS) $< $(INCFLAGS)

.PHONY: clean int_clean
int_clean: 
	$(RM) *.o

clean: int_clean
	$(RM) *.tsk


