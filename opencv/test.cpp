#include "opencv2/opencv.hpp"
#include "opencv2/highgui/highgui.hpp"
#include "opencv2/video/background_segm.hpp"
#include <iostream>
#include <unistd.h>

using namespace std;
using namespace cv;

int main(int argc, char *argv[])
{
    Mat frame, mask;
    BackgroundSubtractorMOG bgSubtractor(4,2,0.5,false);
    cout<<"start"<<endl;
    while(1) {
        frame = imread("1.jpg",CV_LOAD_IMAGE_UNCHANGED);
        bgSubtractor(frame,mask,0.001);
        imwrite("2.jpg",mask);
        sleep(1);
    }
    cout<<"end"<<endl;
    return 0;
}
