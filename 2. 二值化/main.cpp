#include <opencv2/opencv.hpp>
#include <iostream>
using namespace std;
using namespace cv;

int main()
{
    //加载图像
    Mat inputImage = imread("D:\\OpenCV\\Image\\套环\\图像00228.BMP", IMREAD_GRAYSCALE);
    Mat thresholdImage;
    Mat otsuThresholdImage;
    Mat adaptiveThresholdImage;

    //二值化
    threshold(inputImage, thresholdImage, 100, 255, THRESH_BINARY);

    //自动二值化
    threshold(inputImage, otsuThresholdImage, 0, 255, THRESH_BINARY | THRESH_OTSU);

    //自适应二值化
    adaptiveThreshold(inputImage, adaptiveThresholdImage, 255, ADAPTIVE_THRESH_MEAN_C, THRESH_BINARY, 71, 15);

    //显示图像
    imshow("原始图像", inputImage);
    imshow("二值化图像(threshold: THRESH_BINARY)", thresholdImage);
    imshow("自动二值化图像(threshold: THRESH_BINARY | THRESH_OTSU)", otsuThresholdImage);
    imshow("自适应二值化(adaptiveThreshold)", adaptiveThresholdImage);

    waitKey();
}
