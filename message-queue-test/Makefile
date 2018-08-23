PROGS = out1 out2
CXX = g++
CFLAGS += -Wall
LDLIBS += -lrt -pthread
OBJS = $(PROGS).o

all: $(PROGS)

%: %.o
	$(CXX) $(LDLIBS) $(CFLAGS) $^ -o $@


%.o: %.cpp
	$(CXX) -c $(LDLIBS) $(CFLAGS) $^ -o $@

clean:
	rm -f *.o $(PROGS)



