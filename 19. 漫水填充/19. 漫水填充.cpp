#include <iostream>
#include <opencv2/opencv.hpp>

using namespace std;
using namespace cv;

int main()
{
    //读入图像
    Mat inputImage = imread("../Image/LOL.png");
    if (inputImage.empty())
    {
        exit(0);
    }
    imshow("输入图像", inputImage);

    int lowDif = 10;
    int upDif = 10;
    floodFill(inputImage, Point(10, 10), Scalar(0, 0, 255), 0, Scalar(lowDif, lowDif, lowDif), Scalar(upDif, upDif, upDif));
    imshow("效果图", inputImage);

    waitKey(0);
    return 0;
}
