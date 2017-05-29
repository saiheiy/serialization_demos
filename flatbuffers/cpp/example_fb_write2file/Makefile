CXX=c++
RM=rm -f
CPPFLAGS=-std=c++11
INCFLAGS=-I. -I../../../install/flatbuffers/include -I../headers
LDFLAGS=
OBJS=fb_write_to_file.o

all: fb_write_to_file.tsk int_clean

fb_write_to_file.tsk: $(OBJS) 
	$(CXX) -o $@ $^ $(LDFLAGS) 

fb_write_to_file.o: fb_write_to_file.cpp
	$(CXX) -c $(CPPFLAGS) $< $(INCFLAGS)

.PHONY: clean int_clean
int_clean: 
	$(RM) *.o

clean: int_clean
	$(RM) *.tsk


