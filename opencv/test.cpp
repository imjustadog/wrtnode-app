#include "opencv2/opencv.hpp"
#include "opencv2/highgui/highgui.hpp"
#include "opencv2/video/background_segm.hpp"
#include <iostream>
#include <unistd.h>
#include <semaphore.h>

using namespace std;
using namespace cv;

int main(int argc, char *argv[])
{
    Mat frame, mask;
    BackgroundSubtractorMOG bgSubtractor(4,2,0.5,false);
    cout<<"start"<<endl;
    sem_t *sem_test;
    sem_test = sem_open("getphoto",0);
    while(1) {
        sem_wait(sem_test);
        frame = imread("/tmp/1.jpg",CV_LOAD_IMAGE_UNCHANGED);
        bgSubtractor(frame,mask,0.001);
        imwrite("/tmp/2.jpg",mask);
        cout<<"detect"<<endl;
    }
    sem_close(sem_test);
    sem_unlink("getphoto");
    cout<<"end"<<endl;
    return 0;
}
