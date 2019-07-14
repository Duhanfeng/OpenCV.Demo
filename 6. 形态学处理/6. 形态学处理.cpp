#include <iostream>
#include <opencv2/opencv.hpp>

using namespace std;
using namespace cv;

int main()
{
    Mat inputImage = imread("../Image/PCB/pcb.png");
    imshow("输入图像", inputImage);

    //膨胀
    Mat dilateImage = Mat::zeros(inputImage.size(), inputImage.type());
    Mat dilateKern = getStructuringElement(MORPH_RECT, Size(5, 5));
    dilate(inputImage, dilateImage, dilateKern);
    imshow("膨胀图像", dilateImage);

    //腐蚀运算
    Mat erodeImage = Mat::zeros(inputImage.size(), inputImage.type());
    Mat erodeKern = getStructuringElement(MORPH_RECT, Size(5, 5));
    erode(inputImage, erodeImage, erodeKern);
    imshow("腐蚀图像", erodeImage);

    //开运算(先腐蚀再膨胀)
    Mat openImage = Mat::zeros(inputImage.size(), inputImage.type());
    Mat openKern = getStructuringElement(MORPH_RECT, Size(5, 5));
    morphologyEx(inputImage, openImage, MORPH_OPEN, openKern);
    imshow("开运算图像", openImage);

    //闭运算(先膨胀再腐蚀)
    Mat closeImage = Mat::zeros(inputImage.size(), inputImage.type());
    Mat closeKern = getStructuringElement(MORPH_RECT, Size(5, 5));
    morphologyEx(inputImage, closeImage, MORPH_CLOSE, closeKern);
    imshow("闭运算图像", closeImage);

    //顶帽运算(源图像-开运算图像)
    Mat TophatImage = Mat::zeros(inputImage.size(), inputImage.type());
    Mat TophatKern = getStructuringElement(MORPH_RECT, Size(5, 5));
    morphologyEx(inputImage, TophatImage, MORPH_TOPHAT, TophatKern);
    imshow("顶帽图像", TophatImage);

    //黑帽运算(闭运算图像-开运算图像)
    Mat blackhatImage = Mat::zeros(inputImage.size(), inputImage.type());
    Mat blackhatKern = getStructuringElement(MORPH_RECT, Size(5, 5));
    morphologyEx(inputImage, blackhatImage, MORPH_BLACKHAT, blackhatKern);
    imshow("黑帽图像", blackhatImage);

    waitKey();
}


