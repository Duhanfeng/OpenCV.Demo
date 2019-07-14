#include <iostream>
#include <opencv2/opencv.hpp>

using namespace std;
using namespace cv;

int main()
{
    Mat grayInputImage = imread("../Image/美女.jpg", IMREAD_GRAYSCALE);
    if (grayInputImage.empty())
    {
        exit(0);
    }
    imshow("输入图像(灰度)", grayInputImage);

    //图像降噪
    Mat grayDenoisingImage = Mat::zeros(grayInputImage.size(), grayInputImage.type());
    fastNlMeansDenoising(grayInputImage, grayDenoisingImage);
    imshow("降噪图像(灰度)", grayDenoisingImage);

    Mat rgbInputImage = imread("../Image/美女.jpg");
    if (rgbInputImage.empty())
    {
        exit(0);
    }
    imshow("输入图像(彩色)", rgbInputImage);

    //图像降噪
    Mat rgbDenoisingImage = Mat::zeros(rgbInputImage.size(), rgbInputImage.type());
    fastNlMeansDenoisingColored(rgbInputImage, rgbDenoisingImage);
    imshow("降噪图像(彩色)", rgbDenoisingImage);

    //双边滤波
    Mat filterImage = Mat::zeros(rgbInputImage.size(), rgbInputImage.type());
    bilateralFilter(rgbDenoisingImage, filterImage, 20, 100, 100);
    imshow("双边滤波(彩色)", filterImage);

    waitKey();
}