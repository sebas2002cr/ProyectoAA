// ImageProcessing.cpp : This file contains the 'main' function. Program execution begins and ends there.
//
#include <opencv2/core.hpp>
#include <opencv2/imgcodecs.hpp>
#include <opencv2/highgui.hpp>
#include <iostream>
using namespace cv;
int main()
{
    std::string image_path = samples::findFile("starry_night.jpg");
    Mat img = imread(image_path, IMREAD_COLOR);
    if (img.empty())
    {
        std::cout << "Could not read the image: " << image_path << std::endl;
        return 1;
    }
    imshow("Display window", img);
    int k = waitKey(0); // Wait for a keystroke in the window
    if (k == 's')
    {
        imwrite("starry_night.png", img);
    }
    return 0;
}


// -----------------------------------------OPERACIONES CON IMAGENES--------------------------------------------------------------------------------

//
//Load an image from a file:
Mat img = imread(filename);

//
//grayscale
Mat img = imread(filename, IMREAD_GRAYSCALE);


//
//grayscale
Mat img = imread(filename, IMREAD_GRAYSCALE);





//
//  Accessing pixel intensity values
//  3 channel image with BGR color ordering (the default format returned by imread):
//
 Vec3b intensity = img.at<Vec3b>(y, x);
            uchar blue = intensity.val[0];
            uchar green = intensity.val[1];
            uchar red = intensity.val[2];

// access a point in this matrix using the same method Mat::at
 Point2f point = pointsMat.at<Point2f>(i, 0);


//There is a number of convenient operators defined on a matrix. For example, here is how we can make a black image from an existing greyscale image img

            img = Scalar(0);
//Selecting a region of interest:

            Rect r(10, 10, 100, 100);
            Mat smallImg = img(r);
//A conversion from Mat to C API data structures (C++ only):

        Mat img = imread("image.jpg");
        IplImage img1 = cvIplImage(img);
        CvMat m = cvMat(img);
//Note that there is no data copying here.

//Conversion from color to greyscale:

        Mat img = imread("image.jpg"); // loading a 8UC3 image
        Mat grey;
        cvtColor(img, grey, COLOR_BGR2GRAY);
//Change image type from 8UC1 to 32FC1:

        src.convertTo(dst, CV_32F);


//It is very useful to see intermediate results of your algorithm during development process.
//OpenCV provides a convenient way of visualizing images. A 8U image can be shown using:

        Mat img = imread("image.jpg");
        namedWindow("image", WINDOW_AUTOSIZE);
        imshow("image", img);
        waitKey();
//A call to waitKey() starts a message passing cycle that waits for a key stroke in the "image" window. 
//A 32F image needs to be converted to 8U type. For example:

        Mat img = imread("image.jpg");
        Mat grey;
        cvtColor(img, grey, COLOR_BGR2GRAY);
        Mat sobelx;
        Sobel(grey, sobelx, CV_32F, 1, 0);
        double minVal, maxVal;
        minMaxLoc(sobelx, &minVal, &maxVal); //find minimum and maximum intensities
        Mat draw;
        sobelx.convertTo(draw, CV_8U, 255.0/(maxVal - minVal), -minVal * 255.0/(maxVal - minVal));
        namedWindow("image", WINDOW_AUTOSIZE);
        imshow("image", draw);
        waitKey();



//Codigo de: https://docs.opencv.org/3.4/d5/d98/tutorial_mat_operations.html

// -----------------------------------------OPERACIONES CON IMAGENES--------------------------------------------------------------------------------
