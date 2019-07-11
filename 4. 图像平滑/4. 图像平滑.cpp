#include <opencv2/opencv.hpp>
#include <iostream>
using namespace std;
using namespace cv;

int main()
{
    //加载图像
    Mat inputImage = imread("D:\\OpenCV\\Image\\PCB\\pcb.png");
    Mat blurImage;
    Mat medianImage;
    Mat gaussImage;
    Mat bilateralImage;
    Mat bilateralImages[10];

    //均值滤波
    blur(inputImage, blurImage, Size(5, 5));

    //中值滤波
    medianBlur(inputImage, medianImage, 5);

    //高斯滤波
    GaussianBlur(inputImage, gaussImage, Size(5,5), 0);

    //双边滤波
    bilateralFilter(inputImage, bilateralImage, 20, 100, 100);

    //双边滤波(彩色图像多次迭代)
    bilateralImages[0] = imread("D:\\OpenCV\\Image\\地球\\Earth_4096x2048.png");

    for (int i = 0; i < 9; i++)
    {
        bilateralFilter(bilateralImages[i], bilateralImages[i+1], 10, 50, 50);
    }

    //显示图像
    imshow("输入窗口", inputImage);
    imshow("均值滤波窗口", blurImage);
    imshow("中值滤波窗口", medianImage);
    imshow("高斯滤波窗口", gaussImage);
    imshow("双边滤波窗口", bilateralImage);
    imshow("双边滤波窗口(2)", bilateralImages[9]);

    waitKey();
}


