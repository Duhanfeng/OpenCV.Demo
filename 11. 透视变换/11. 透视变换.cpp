#include <iostream>
#include <opencv2/opencv.hpp>

using namespace std;
using namespace cv;

int main()
{
    Mat inputImage = imread("../Image/LOL/role_login.png");
    if (inputImage.data == nullptr)
    {
        exit(0);
    }
    imshow("输入图像", inputImage);

    //计算透视变换矩阵(通过4点映射的方式)
    Point2f srcTri[]
    {
        Point2f(0, 0),
        Point2f(inputImage.cols - 1, 0),
        Point2f(0, inputImage.rows - 1),
        Point2f(inputImage.cols - 1, inputImage.rows - 1),
    };
    Point2f dstTri[]
    {
        Point2f(50, 50),
        Point2f(inputImage.cols * 0.55f, inputImage.rows * 0.86f),
        Point2f(inputImage.cols * 0.8f, inputImage.rows * 0.15f),
        Point2f(inputImage.cols * 0.8f, inputImage.rows * 0.8f),
    };
    Mat perspectiveMat = getPerspectiveTransform(srcTri, dstTri);

    //密集透视变换(针对于图像的变换)
    Mat warpImage = Mat::zeros(inputImage.size(), inputImage.type());
    warpPerspective(inputImage, warpImage, perspectiveMat, inputImage.size());
    imshow("透视图像", warpImage);

    //稀疏透视变换(针对于点位的变换)
    Mat dstMat = Mat();
    Mat srcMat = Mat::zeros(Size(2, 1), CV_32FC2);
    srcMat.at<Vec2f>(0, 0)[0] = inputImage.cols / 2;
    srcMat.at<Vec2f>(0, 0)[1] = 40;
    srcMat.at<Vec2f>(0, 1)[0] = 0;
    srcMat.at<Vec2f>(0, 1)[1] = 0;
    perspectiveTransform(srcMat, dstMat, perspectiveMat);

    waitKey();
}

