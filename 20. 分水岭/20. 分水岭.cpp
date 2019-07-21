#include <iostream>
#include <opencv2/opencv.hpp>

using namespace std;
using namespace cv;

int main()
{
    //读入图像
    Mat inputImage = imread("../Image/particle.png");
    if (inputImage.empty())
    {
        exit(0);
    }
    imshow("输入图像", inputImage);

    //分水岭分割
    Mat maskers = Mat::zeros(inputImage.size(), CV_32SC1);
    watershed(inputImage, maskers);
    imshow("分水岭图像", inputImage);

    waitKey(0);
    return 0;
}
