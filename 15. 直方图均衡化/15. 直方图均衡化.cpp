#include <iostream>
#include <opencv2/opencv.hpp>

using namespace std;
using namespace cv;

//直方图均衡化: 将灰度直方图中过于集中的灰度拉伸,使其分布均衡;
//equalizeHist: 输入输出图像要求为8位单通道图像,对于多通道图像,需要分通道逐一处理;
int main()
{
    Mat inputImage = imread("../Image/血管.png", IMREAD_GRAYSCALE);
    if (inputImage.empty())
    {
        exit(0);
    }
    imshow("输入图像", inputImage);

    //直方图均衡化
    Mat equalizeImage = Mat::zeros(inputImage.size(), inputImage.type());
    equalizeHist(inputImage, equalizeImage);
    imshow("均衡化图像", equalizeImage);

    waitKey();
}
