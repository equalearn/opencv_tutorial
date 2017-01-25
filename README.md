# Just playing around with an IP camera, OpenCV, and HTML5

Thanks to Marc Merlins for his blog at 
[marc.merlins.org] (http://marc.merlins.org/perso/linuxha/post_2013-11-10_Reviewing-IP-Webcams-for-Linux-and-Zoneminder_Dlink-DCS900_-Ubnt-Aircam_-Foscam-FI8904W-FI8910W_-FFI9820W_-FI9821W_-Wansview-NCB541W_-and-Zavio-F3210.html)

I have a ??? IP cameria.  I see hosafe.com on it, but what's the model and
maker?


### C++ code

I made a GNU makefile, *GNUmakefile*, that builds the C++ programs
by running: *make*.  Any .cpp file will be made into a binary program
that is linked with OpenCV libraries.

The code originated from
[opencv-srf.blogspot.com]
(http://opencv-srf.blogspot.com/2013/06).  There is better descriptions in
those pages.


## Ports

This was developed on Xubuntu 16.04 (GNU/Linux).  The code, that is here,
was originally written for Windoz.  Apparently OpenCV is at least ported
to Windoz and GNU/Linux systems.


### Building

We need to download some more files that this package uses.  You can
do this by running (bash shell from top source directory):
```
make fetch
```
which will download (wget) INSTALL_opencv from github.


#### Dependency OpenCV

Edit *INSTALL_opencv* to your
liking.  Run:


  ```
  ./INSTALL_opencv
  ```
or if your not into editing a file run:
  ```
  ./INSTALL_opencv --help
  ```
and go from there.


#### Building the tutorial

Keep editing and trying until you succeed.  If required, make
PKG_CONFIG_PATH contain your OpenCV installation prefix with
*/lib/pkgconfig* appended, for example:
  ```
  export PKG_CONFIG_PATH=/usr/local/lib/pkgconfig
  ```

then:
  ```
  make
  ```

then run programs, edit programs, and rerun *make*.


### Example Commands


These commands worked for me and my IP camera:


High res

```
./08_videoCapture rtsp://192.168.1.4:554/live/ch0
```

Mid res

```
./08_videoCapture rtsp://192.168.1.4:554/live/ch1
```

Low res

```
./08_videoCapture rtsp://192.168.1.4:554/live/ch2
```

To move the camera:
```
wget -q -O - --user=admin --password=pwd 'http://ipaddr/hy-cgi/ptz.cgi?cmd=preset&number=2&act=goto'

wget -q -O - --user=admin --password=pwd 'http://ipaddr/hy-cgi/ptz.cgi?cmd=ptzctrl&act=left&speed=2'

wget -q -O - --user=admin --password=pwd 'http://ipaddr/hy-cgi/ptz.cgi?cmd=ptzctrl&act=stop&speed=2'
```


PTZ can be controlled with GET
ipaddr/hy-cgi/ptz.cgi?cmd=ptzctrl&act=left|right|up|down|stop|home|hscan|vscan


