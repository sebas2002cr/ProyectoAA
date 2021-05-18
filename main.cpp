#include <stdio.h>
#include <opencv2/opencv.hpp>
#include <opencv2/highgui/highgui.hpp>
#include "funcionesAuxiliares.h"
#include "pixel.h"

using namespace cv;
using namespace std;

int main(){
    Mat img=imread("C:\\Users\\fabic\\Desktop\\ProyectoAA\\img\\tiger.png", IMREAD_GRAYSCALE);
    //imshow("IMAGE", img);
    cout<<"filas :"<<img.rows<<endl;
    cout<<"columnas: "<<img.cols<<endl;
    vector<int> array;
    vector<Pixel> arrayPix;
    if (img.isContinuous()) {
        array.assign(img.data, img.data + img.total()*img.channels());
    } else {
        for (int i = 0; i < img.rows; ++i) {
            array.insert(array.end(), img.ptr<int>(i), img.ptr<int>(i)+img.cols*img.channels());
         }
    }
    string hola="";
    for(int i=0; i<array.size(); i++){
        hola+=to_string(array.at(i));
        hola+=" ";
        arrayPix.push_back(Pixel(array.at(i),i));
    }
    txtWrite("antesDe.txt",hola);
    //quicksort(array, 0, array.size() - 1);
    quicksort(arrayPix, 0, arrayPix.size() - 1);
    hola="";
    /**for(int i=0; i<array.size(); i++){
        hola+=to_string(array.at(i));
        hola+=" ";
    }
    txtWrite("despuesDe.txt",hola);**/
    for(int i=0; i<arrayPix.size(); i++){
        cout<<"cod: "<<arrayPix[i].value<<" pos: "<<arrayPix[i].pos<<endl;
    }
    cout<<"algoritmo terminado";
    waitKey(0);
    return 0;
}