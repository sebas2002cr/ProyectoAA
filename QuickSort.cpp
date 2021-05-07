
#include <stdio.h>
#include <opencv2/opencv.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <opencv2/img_hash/img_hash_base.hpp>
#include <opencv2/img_hash/average_hash.hpp>
#include <opencv2/img_hash/phash.hpp>
#include <iostream>

using namespace cv;
using namespace std;

/*
int main(int argc, char** argv)
{
	// Read the image file

	Mat image = imread("D:\SunFlower.jpg", IMREAD_GRAYSCALE);

	// Check for failure
	if (image.empty())
	{
		cout << "Could not open or find the image" << endl;
		cin.get(); //wait for any key press
		return -1;
	}

	String windowName = "SunFlower"; //Name of the window

	namedWindow(windowName); // Create a window

	imshow(windowName, image); // Show our image inside the created window.

	waitKey(0); // Wait for any keystroke in the window

	destroyWindow(windowName); //destroy the created window
	 

	return 0;
}
*/

int partition(vector<int>& values, int left, int right) {
    int pivotIndex = left + (right - left) / 2;
    int pivotValue = values[pivotIndex];
    int i = left, j = right;
    int temp;
    while (i <= j) {
        while (values[i] < pivotValue) {
            i++;
        }
        while (values[j] > pivotValue) {
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


void quicksort(vector<int>& values, int left, int right) {
    if (left < right) {
        int pivotIndex = partition(values, left, right);
        quicksort(values, left, pivotIndex - 1);
        quicksort(values, pivotIndex, right);
    }
}


int main() {
    Mat img = imread("D:\SunFlower.jpg", IMREAD_GRAYSCALE);
    imshow("IMAGE", img);
    cout << "filas :" << img.rows << endl;
    cout << "columnas: " << img.cols << endl;
    vector<int> prueba;
    prueba.push_back(8);
   
    vector<int> array;
    if (img.isContinuous()) {
        array.assign(img.data, img.data + img.total() * img.channels());
    }
    else {
        for (int i = 0; i < img.rows; ++i) {
            array.insert(array.end(), img.ptr<float>(i), img.ptr<float>(i) + img.cols * img.channels());
        }
    }
    cout << "array: " << array.size();
    waitKey(0);

        quicksort(array, 0, array.size() - 1);
        for (vector<int>::iterator it = array.begin(); it != array.end(); it++) {
            cout << "Prueba: "<< *it << endl;
        }

    return 0;
}
