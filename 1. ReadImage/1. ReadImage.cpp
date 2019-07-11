#include <opencv2/opencv.hpp>
#include <iostream>
using namespace std;
using namespace cv;

int main()
{
    //加载图像
    Mat image = imread("D:\\OpenCV\\Image\\套环\\图像00228.BMP");

    //显示图像
    imshow("显示窗口", image);

    waitKey();
}


