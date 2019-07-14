#include <iostream>
#include <opencv2/opencv.hpp>

using namespace std;
using namespace cv;

int main()
{
    Mat inputImage = imread("../Image/LOL/role_login.png");
    imshow("输入图像", inputImage);

    float scale = 0.5;

    //均匀调整
    Mat resizeImage = Mat();
    resize(inputImage, resizeImage, Size(inputImage.size().width * scale, inputImage.size().height * scale));
    imshow("均匀调整(resize)", resizeImage);

    //图像金字塔
    float downScale = 0.5;
    float upScale = 2;

    Mat pyrDownImage = Mat();
    pyrDown(inputImage, pyrDownImage, Size(inputImage.size().width * downScale, inputImage.size().height * downScale));
    imshow("图像金字塔(pyrDown)", pyrDownImage);

    Mat pyrUpImage = Mat();
    pyrUp(inputImage, pyrUpImage, Size(inputImage.size().width * upScale, inputImage.size().height * upScale));
    imshow("图像金字塔(pyrUp)", pyrUpImage);

    vector<Mat> pyrImageArray;
    buildPyramid(inputImage, pyrImageArray, 5);
    for (auto iter = pyrImageArray.begin(); iter != pyrImageArray.end(); ++iter)
    {
        imshow("图像金字塔(多层次)", *iter);
        waitKey();
    }

    waitKey();
}
