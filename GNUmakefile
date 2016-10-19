# GNU make


bins = $(patsubst %.cpp,%,$(wildcard *.cpp))


CXXFLAGS = -g -Werror

LD_FLAGS =  -L$(shell pkg-config opencv\
 --variable=prefix)/share/OpenCV/3rdparty/lib\
 $(shell pkg-config opencv --libs)

I_FLAGS = $(shell pkg-config opencv --cflags)


build: $(bins)

fetch: INSTALLING_opencv.bash

# We pick a particular version of this file off the web.
# Test it before you make this a newer version.
INSTALLING_opencv.bash:
	wget\
 https://raw.githubusercontent.com/lanceman2/MirrorWorlds/0c2ce796bb01985fd15f78/INSTALLING_opencv.bash\
 -O $@


install_opencv: INSTALLING_opencv.bash
	./INSTALLING_opencv.bash

$(bins): %: %.o
	$(CXX) $(CXXFLAGS) -o $@ $^ $(LD_FLAGS)

%.o: %.cpp
	$(CXX) $(CXXFLAGS) $(I_FLAGS) -c -o $@ $<

clean:
	rm -f *.o $(bins)
# a little cleaner
distclean cleaner: clean
	rm -f INSTALLING_opencv.bash

