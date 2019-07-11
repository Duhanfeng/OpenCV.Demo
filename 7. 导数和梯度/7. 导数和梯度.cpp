#include <iostream>
#include <opencv2/opencv.hpp>

using namespace std;
using namespace cv;

int main()
{
    Mat inputImage = imread("D:\\OpenCV\\Image\\PCB\\pcb.png", IMREAD_GRAYSCALE);
    imshow("输入图像", inputImage);

    //计算sobel
    Mat sobelImage = Mat::zeros(inputImage.size(), inputImage.type());
    Sobel(inputImage, sobelImage, CV_8U, 1, 1);
    imshow("sobel图像", sobelImage);

    //计算scharr
    Mat scharrImage = Mat::zeros(inputImage.size(), inputImage.type());
    Scharr(inputImage, scharrImage, CV_8U, 0, 1);
    imshow("scharr图像", scharrImage);

    //拉氏变换
    Mat laplacianImage = Mat::zeros(inputImage.size(), inputImage.type());
    Laplacian(inputImage, laplacianImage, CV_8U);
    imshow("laplacian变换", laplacianImage);

    waitKey();
}