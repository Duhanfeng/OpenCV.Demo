#include <iostream>
#include <opencv2/opencv.hpp>

using namespace std;
using namespace cv;

int main()
{
    Mat inputImage = imread("../Image/LOL/role_login.png");
    if (inputImage.empty())
    {
        exit(0);
    }
    imshow("输入图像", inputImage);

    Mat polarImage = Mat::zeros(inputImage.size(), inputImage.type());
    logPolar(inputImage, polarImage, Point2f(inputImage.cols * 0.5f, inputImage.rows * 0.5f), 50, INTER_LINEAR | WARP_INVERSE_MAP);

    imshow("极坐标图像", polarImage);

    waitKey();
}

