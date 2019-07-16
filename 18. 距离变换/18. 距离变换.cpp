#include <iostream>
#include <opencv2/opencv.hpp>

using namespace std;
using namespace cv;

int main()
{
    Mat inputImage = imread("../Image/螺丝.png", IMREAD_GRAYSCALE);
    if (inputImage.empty())
    {
        exit(0);
    }
    imshow("输入图像", inputImage);

    //二值化
    Mat thresholdImage;
    threshold(~inputImage, thresholdImage, 100, 255, THRESH_BINARY);

    //距离变换
    Mat distanceImage = Mat::zeros(inputImage.size(), inputImage.type());
    distanceTransform(thresholdImage, distanceImage, DIST_L2, DIST_MASK_PRECISE);

    //归一化矩阵
    normalize(distanceImage, distanceImage, 0, 1, NORM_MINMAX);
    imshow("距离变换图像", distanceImage);

    //找出最大值的位置
    for (size_t i = 0; i < distanceImage.cols; i++)
    {
        for (size_t j = 0; j < distanceImage.rows; j++)
        {
            if ((distanceImage.at<float>(j, i) >= 0.999999999) && (distanceImage.at<float>(j, i) <= 1.000000001))
            {
                circle(distanceImage, Point(i,j), 3, Scalar(0, 0, 255), 1);
            }
        }
    }

    imshow("最大距离点", distanceImage);

    waitKey();
}