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
    vector<Pixel> coincidencias;
    if (img.isContinuous()) {
        array.assign(img.data, img.data + img.total()*img.channels());
    } else {
        for (int i = 0; i < img.rows; ++i) {
            array.insert(array.end(), img.ptr<int>(i), img.ptr<int>(i)+img.cols*img.channels());
         }
    }
    for(int i=0; i<array.size(); i++){
        arrayPix.push_back(Pixel(array.at(i),i));
    }
    quicksort(arrayPix, 0, arrayPix.size() - 1);
    int temp=-1;
    int n;
    for(int i=0; i<arrayPix.size(); i++){
        if(i!=arrayPix.size()-1){
            for(int j=i+1; j<arrayPix.size(); j++){
                temp=arrayPix[i].value;
                if(arrayPix[i].value!=arrayPix[j].value){
                 break;
                }else{
                    if(arrayPix.size()!=(arrayPix[i].pos)+1 && arrayPix.size()!=(arrayPix[j].pos)+1){
                        if(array[arrayPix[i].pos+1]==array[arrayPix[j].pos+1]){
                            //cout<<"coincidencia encontrada"<<endl;
                            coincidencias.push_back(arrayPix[i]);
                            coincidencias.push_back(arrayPix[j]);
                        }
                    }
                    
                }
            }
            //cout<<"ciclo 1 terminado"<<endl;
        }
    }
    cout<<"algoritmo terminado";
    waitKey(0);
    return 0;
}