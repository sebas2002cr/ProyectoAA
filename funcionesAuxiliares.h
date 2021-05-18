#ifndef _funcionesAuxiliares_
#define _funcionesAuxiliares_
#include "pixel.h"
#include <iostream>

using namespace std;

int partition(vector<Pixel>& values, int left, int right) {
    int pivotIndex = left + (right - left) / 2;
    int pivotValue = values.at(pivotIndex).value;
    int i = left, j = right;
    Pixel temp;
    while (i <= j) {
        while (values.at(i).value < pivotValue) {
            i++;
        }
        while (values.at(j).value > pivotValue) {
            j--;
        }
        if (i <= j) {
            temp = values[i];
            values[i] = values[j];
            values[j] = temp;
            i++;
            j--;
        }
    }
    return i;
}


void quicksort(vector<Pixel>& values, int left, int right) {
    if (left < right) {
        int pivotIndex = partition(values, left, right);
        quicksort(values, left, pivotIndex - 1);
        quicksort(values, pivotIndex, right);
    }
}
   

void txtWrite(string nombre, string texto){
    cout<<"Iniciado"<<endl;
    FILE*file=fopen(nombre.c_str(), "w");
    fputs(texto.c_str(), file);
    fclose(file);
    cout<<"terminado"<<endl;
}
#endif