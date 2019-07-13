#include <iostream>
#include <opencv2/opencv.hpp>

using namespace std;
using namespace cv;

int main()
{
    Mat inputImage = imread("D:\\OpenCV\\Image\\LOL\\role_login.png");
    imshow("输入图像", inputImage);


    Mat remadImage = Mat::zeros(inputImage.size(), inputImage.type());
    Mat xMap = Mat::zeros(inputImage.size(), CV_32FC1);
    Mat yMap = Mat::zeros(inputImage.size(), CV_32FC1);

    //缩放
    float scale = 0.5f;
    for (int i = inputImage.cols * (scale / 2); i < inputImage.cols * (1 - (scale / 2)); i++)
    {
        for (int j = inputImage.rows * (scale / 2); j < inputImage.rows * (1 - (scale / 2)); j++)
        {
            xMap.at<float>(j, i) = (int)(2 * (i - inputImage.cols * (scale / 2)) + 0.5f);  //i: x方向,对应col +0.5f是为了四舍五入
            yMap.at<float>(j, i) = (int)(2 * (j - inputImage.rows * (scale / 2)) + 0.5f);  //j: y方向,对应row
        }
    }
    remap(inputImage, remadImage, xMap, yMap, INTER_LINEAR);
    imshow("缩放", remadImage);

    //左右翻转
    for (int i = 0; i < inputImage.cols; i++)
    {
        for (int j = 0; j < inputImage.rows; j++)
        {
            xMap.at<float>(j, i) = inputImage.cols - i; //xMap反向
            yMap.at<float>(j, i) = j;   //yMap不变
        }
    }
    remap(inputImage, remadImage, xMap, yMap, INTER_LINEAR);
    imshow("左右翻转", remadImage);

    //上下翻转
    for (int i = 0; i < inputImage.cols; i++)
    {
        for (int j = 0; j < inputImage.rows; j++)
        {
            xMap.at<float>(j, i) = i;   //xMap反向
            yMap.at<float>(j, i) = inputImage.rows - j; //yMap不变
        }
    }
    remap(inputImage, remadImage, xMap, yMap, INTER_LINEAR);
    imshow("上下翻转", remadImage);

    //对角翻转
    for (int i = 0; i < inputImage.cols; i++)
    {
        for (int j = 0; j < inputImage.rows; j++)
        {
            xMap.at<float>(j, i) = inputImage.cols - i; //xMap反向
            yMap.at<float>(j, i) = inputImage.rows - j; //yMap不变
        }
    }
    remap(inputImage, remadImage, xMap, yMap, INTER_LINEAR);
    imshow("对角翻转", remadImage);

    waitKey();
}
