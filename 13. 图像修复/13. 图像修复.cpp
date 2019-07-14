#include <iostream>
#include <opencv2/opencv.hpp>

using namespace std;
using namespace cv;

int main()
{
    Mat inputImage = imread("../Image/LOL/role_login(损坏).png");
    if (inputImage.empty())
    {
        exit(0);
    }
    imshow("输入图像", inputImage);

    //提取损坏区域
    Mat thresholdSrcImage = imread("../Image/LOL/role_login(损坏).png", IMREAD_GRAYSCALE);
    Mat thresholdImage;
    threshold(thresholdSrcImage, thresholdImage, 254, 255, THRESH_BINARY);
    imshow("二值化图像", thresholdImage);

    //执行图像修复
    Mat inpaintImage = Mat::zeros(inputImage.size(), inputImage.type());
    inpaint(inputImage, thresholdImage, inpaintImage, 1, INPAINT_NS);
    imshow("修复图像", inpaintImage);

    waitKey();
}
