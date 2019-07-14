#include <iostream>
#include <opencv2/opencv.hpp>

using namespace std;
using namespace cv;

int main()
{
    Mat inputImage = imread("../Image/PCB/pcb.png", IMREAD_GRAYSCALE);
    if (inputImage.empty())
    {
        exit(0);
    }
    imshow("输入图像", inputImage);
    
    //边缘检测
    Mat cannyImage = Mat::zeros(inputImage.size(), inputImage.type());
    Canny(inputImage, cannyImage, 180, 220);
    imshow("边缘图像", cannyImage);

    waitKey();
}
