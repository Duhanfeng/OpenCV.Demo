#include <opencv2/opencv.hpp>
#include <iostream>
using namespace std;
using namespace cv;


static Mat g_srcImage;
static Mat g_dstImage;

int g_nContrastValue; //对比度值
int g_nBrightValue;  //亮度值


//-----------------------------【ContrastAndBright( )函数】------------------------------------
//     描述：改变图像对比度和亮度值的回调函数
//-----------------------------------------------------------------------------------------------
static void ContrastAndBright(int, void*)
{

    ////创建窗口
    //namedWindow("【原始图窗口】", 1);
    //
    ////三个for循环，执行运算 g_dstImage(i,j) =a*g_srcImage(i,j) + b
    //for (int y = 0; y < g_srcImage.rows; y++)
    //{
    //    for (int x = 0; x < g_srcImage.cols; x++)
    //    {
    //        for (int c = 0; c < 3; c++)
    //        {
    //            g_dstImage.at<Vec3b>(y, x)[c] = saturate_cast<uchar>((g_nContrastValue * 0.01) * (g_srcImage.at<Vec3b>(y, x)[c]) + g_nBrightValue);
    //        }
    //    }
    //}

    g_srcImage.convertTo(g_dstImage, -1, 0.05 * g_nContrastValue, g_nBrightValue);

    //显示图像
    imshow("【原始图窗口】", g_srcImage);
    imshow("【效果图窗口】", g_dstImage);
}

int main()
{
    //加载图像
    g_srcImage = imread("../Image/LOL/role_login.png");

    if (g_srcImage.data == NULL)
    {
        exit(0);
    }

    g_dstImage = Mat::zeros(g_srcImage.size(), g_srcImage.type());

    //设定对比度和亮度的初值
    g_nContrastValue = 80;
    g_nBrightValue = 80;

    //创建窗口
    namedWindow("【效果图窗口】", 1);

    //创建轨迹条
    createTrackbar("对比度：", "【效果图窗口】", &g_nContrastValue, 300, ContrastAndBright);
    createTrackbar("亮   度：", "【效果图窗口】", &g_nBrightValue, 200, ContrastAndBright);

    //调用回调函数
    ContrastAndBright(g_nContrastValue, 0);
    ContrastAndBright(g_nBrightValue, 0);

    while (char(waitKey(1)) != ' ') {}
    return 0;
}

