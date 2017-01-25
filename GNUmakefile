# GNU make

# all the lines in the recipe be passed to a single invocation of the shell
.ONESHELL:

bins = $(patsubst %.cpp,%,$(wildcard *.cpp))


CXXFLAGS = -g -Werror

LD_FLAGS =  -L$(shell pkg-config opencv\
 --variable=prefix)/share/OpenCV/3rdparty/lib\
 $(shell pkg-config opencv --libs)

I_FLAGS = $(shell pkg-config opencv --cflags)


build: $(bins)


fetch: INSTALL_opencv

INSTALL_opencv:
	wget --no-check-certificate\
 https://raw.githubusercontent.com/lanceman2/small_utils/\
5eb33d2201b979ba2a4079851104e064c59a0cc7/INSTALL_opencv\
 -O $@
	chmod 755 $@

$(bins): %: %.o
	$(CXX) $(CXXFLAGS) -o $@ $^ $(LD_FLAGS)

%.o: %.cpp
	$(CXX) $(CXXFLAGS) $(I_FLAGS) -c -o $@ $<

clean:
	rm -f *.o $(bins)

# a little cleaner
distclean cleaner: clean
	rm -f INSTALL_opencv

