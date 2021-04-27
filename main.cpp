#include <iostream>
#include "funcionesAuxiliares.h"

using namespace std;


int main() 
{ 
    int arr[] = {12,23,3,43,51,35,19,45}; 
    int n = sizeof(arr)/sizeof(arr[0]); 
    cout<<"Input array"<<endl;
    displayArray(arr,n);
    cout<<endl;
    quickSort(arr, 0, n-1); 
    cout<<"Array sorted with quick sort"<<endl; 
    displayArray(arr,n); 
    return 0; 
}