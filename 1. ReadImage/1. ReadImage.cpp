#include <opencv2/opencv.hpp>
#include <iostream>
using namespace std;
using namespace cv;

int main()
{
    Mat inputImage = imread("../Image/美女.jpg", IMREAD_GRAYSCALE);
    if (inputImage.empty())
    {
        exit(0);
    }
    imshow("输入图像", inputImage);

    waitKey();
}


