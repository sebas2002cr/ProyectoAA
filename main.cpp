#include <stdio.h>
#include <opencv2/opencv.hpp>
#include <opencv2/highgui/highgui.hpp>

using namespace cv;

int main(){
    Mat img=imread("C:\\Users\\fabic\\Desktop\\ProyectoAA\\img\\tiger.png");
    imshow("IMAGE", img);
    waitKey(0);
    return 0;
}