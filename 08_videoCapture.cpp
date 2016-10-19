#include "opencv2/highgui/highgui.hpp"
#include <iostream>

using namespace cv;
using namespace std;

int main(int argc, char* argv[])
{
    if(argc != 2)
    {
        cout << "  Usage: " << argv[0] << " FILE_OR_ADDRESS" << endl;
        return 1;
    }

    VideoCapture cap(argv[1]);

    if (!cap.isOpened())
    {
        cout << "Cannot open " << argv[1] << endl;
        return -1;
    }

    //cap.set(CV_CAP_PROP_POS_MSEC, 300); //start the video at 300ms

    double fps = cap.get(CV_CAP_PROP_FPS);

    cout << fps << " frames/second" << endl;

    namedWindow("MyVideo",CV_WINDOW_AUTOSIZE);

    while(1)
    {
        Mat frame;

        bool bSuccess = cap.read(frame); // read a frame

        if (!bSuccess) //if not success, break loop
        {
            cout << "Cannot read the frame from " << argv[1] << endl;
            break;
        }

        imshow("MyVideo", frame); //show the frame in window

        if(waitKey(30) == 27) //wait for 'esc' key press for 30 ms.
        {
            cout << "esc key is pressed by user" << endl;
            break;
        } 
    }

    return 0;
}
