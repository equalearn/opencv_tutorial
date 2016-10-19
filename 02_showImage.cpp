// ref:
//  http://opencv-srf.blogspot.com/2013/06/load-display-image.html
#include "opencv2/highgui/highgui.hpp"
#include <iostream>

using namespace cv;
using namespace std;

int main(int argc, const char** argv)
{
    if(argc != 2)
    {
        cout << "  Usage: " << argv[0] << " IMG_FILE" << endl;
        return 1;
    }

    Mat img = imread(argv[1], CV_LOAD_IMAGE_UNCHANGED);

    if(img.empty())
    {
        cout << "Error : Image file \""
            << argv[1] << "\" cannot be loaded..!!"
            << endl;
        return -1;
    }

    namedWindow("MyWindow", CV_WINDOW_AUTOSIZE);
    imshow("MyWindow", img);

    waitKey(0); //wait for a keypress

    destroyWindow("MyWindow");

    return 0;
}
