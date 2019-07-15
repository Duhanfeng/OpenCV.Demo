#include <iostream>
#include <opencv2/opencv.hpp>

using namespace std;
using namespace cv;

int main()
{
    Mat inputImage = imread("../Image/零件.bmp", IMREAD_GRAYSCALE);
    if (inputImage.empty())
    {
        exit(0);
    }
    imshow("输入图像", inputImage);

    //边缘检测
    Mat cannyImage = Mat::zeros(inputImage.size(), inputImage.type());
    Canny(inputImage, cannyImage, 180, 220);

    //霍夫线变换
    //输出的数据为Vec4i,4个数据,分别代表起点的x,y以及终点的x,y
    vector<Vec4i> houghLines;
    HoughLinesP(cannyImage, houghLines, 1, CV_PI / 180, 50, 50, 10);

    //获取彩色的输入图像
    Mat colorInputImage = Mat();
    cvtColor(inputImage, colorInputImage, COLOR_GRAY2BGR);

    //在彩色输入图像中画出霍夫直线
    for (size_t i = 0; i < houghLines.size(); i++)
    {
        Vec4i l = houghLines[i];
        line(colorInputImage, Point(l[0], l[1]), Point(l[2], l[3]), Scalar(0, 0, 255), 3, LINE_AA);
    }
    
    //霍夫圆变换
    vector<Vec3f> houghCircles;
    HoughCircles(inputImage, houghCircles, HOUGH_GRADIENT, 1,
        50, //圆心之间的最小距离
        100,//内部canny边缘检测器上限阈值
        30, //中心检测阈值
        20, 150 // change the last two parameters (min_radius & max_radius) to detect larger circles
    );

    //在彩色输入图像中画出霍夫圆
    for (size_t i = 0; i < houghCircles.size(); i++)
    {
        Vec3i c = houghCircles[i];
        circle(colorInputImage, Point(c[0], c[1]), c[2], Scalar(255, 0, 255), 3, LINE_AA);
        circle(colorInputImage, Point(c[0], c[1]), 2, Scalar(0, 255, 0), 3, LINE_AA);
    }

    imshow("霍夫图像", colorInputImage);

    waitKey();
}
