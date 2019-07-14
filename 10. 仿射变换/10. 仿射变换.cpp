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

    //计算仿射变换矩阵(通过3点映射的方式)
    Point2f srcTri[]
    {
        Point2f(0, 0),
        Point2f(inputImage.cols - 1, 0),
        Point2f(0, inputImage.rows - 1),
    };
    Point2f dstTri[]
    {
        Point2f(50, 50),
        Point2f(inputImage.cols * 0.15f, inputImage.rows * 0.56),
        Point2f(inputImage.cols * 0.8f, inputImage.rows * 0.15f),
    };
    Mat warpMat = getAffineTransform(srcTri, dstTri);

    //计算仿射变换矩阵(通过点+旋转角度的方式,为getAffineTransform的子集)
    //angle: 角度值,正数为逆时针旋转,负数为顺时针旋转
    Mat rotationMat = getRotationMatrix2D(Point2f(inputImage.cols / 2, inputImage.rows / 2), -90, 1);

    //密集仿射变换(针对于图像的变换)
    Mat warpImage = Mat::zeros(inputImage.size(), inputImage.type());
    warpAffine(inputImage, warpImage, warpMat, inputImage.size());
    imshow("仿射图像", warpImage);

    //稀疏仿射变换(针对于点位的变换)
    Mat sparseMat = Mat::zeros(Size(2, 1), CV_32FC2);
    sparseMat.at<Vec2f>(0, 0)[0] = inputImage.cols / 2;
    sparseMat.at<Vec2f>(0, 0)[1] = 40;
    sparseMat.at<Vec2f>(0, 1)[0] = 0;
    sparseMat.at<Vec2f>(0, 1)[1] = 0;
    transform(sparseMat, warpImage, rotationMat);

    waitKey();
}
