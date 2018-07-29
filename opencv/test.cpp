#include "opencv2/opencv.hpp"
#include "opencv2/highgui/highgui.hpp"
#include <iostream>

using namespace std;
using namespace cv;

int main(int, char**)
{
    cout<<"start"<<endl;
    Mat img = imread("earth.jpg",CV_LOAD_IMAGE_UNCHANGED);
    if(img.empty()) {
        cout << "fail" <<endl;
        return 0;
    }
    else imwrite("dota.jpg",img);
    cout<<"end"<<endl;
    return 0;
}
