PROGS = test
CXX = /home/adoge/wrtnode/staging_dir/toolchain-mipsel_24kec+dsp_gcc-4.8-linaro_uClibc-0.9.33.2/bin/mipsel-openwrt-linux-g++
CFLAGS += -Wall
LFLAGS += -pthread
LDLIBS += -lm -lopencv_core -lopencv_highgui -lopencv_video
#LIBDIR += -L/home/adoge/wrtnode/staging_dir/toolchain-mipsel_24kec+dsp_gcc-4.8-linaro_uClibc-0.9.33.2/lib
OBJS = $(PROGS).o


all: $(PROGS)

$(PROGS): $(OBJS)
	$(CXX) $(LFLAGS) $(LDLIBS) $(CFLAGS) $^ -o $@


%.o: %.cpp
	$(CXX) -c $(LFLAGS) $(LDLIBS) $(CFLAGS) $^ -o $@


clean:
	rm -f *.a *.o core *~ *.so *.lo
