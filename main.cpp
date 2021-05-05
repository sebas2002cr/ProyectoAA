#include <stdio.h>
#include <opencv2/opencv.hpp>
#include <opencv2/highgui/highgui.hpp>

using namespace cv;
using namespace std;

int main(){
    Mat img=imread("C:\\Users\\fabic\\Desktop\\ProyectoAA\\img\\tiger.png", IMREAD_GRAYSCALE);
    imshow("IMAGE", img);
    cout<<"filas :"<<img.rows<<endl;
    cout<<"columnas: "<<img.cols<<endl;
    vector<int> prueba;
    prueba.push_back(8);
    /**vector<uchar> array;
    if (img.isContinuous()) {
        array.assign((uchar*)img.datastart, (uchar*)img.dataend);
    } else {
        for (int i = 0; i < img.rows; ++i) {
            array.insert(array.end(), img.ptr<uchar>(i), img.ptr<uchar>(i)+img.cols);
        }
    }**/
    vector<float> array;
    if (img.isContinuous()) {
        array.assign(img.data, img.data + img.total()*img.channels());
    } else {
        for (int i = 0; i < img.rows; ++i) {
            array.insert(array.end(), img.ptr<float>(i), img.ptr<float>(i)+img.cols*img.channels());
         }
    }
    cout<<"array: "<<array.size();
    waitKey(0);
    return 0;
}