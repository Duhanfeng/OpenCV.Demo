#include <opencv2/opencv.hpp>
#include <iostream>
#include <stdlib.h>
#include <stdio.h>
using namespace std;
using namespace cv;

int main()
{
    //加载图像
    Mat inputImage = imread("D:\\OpenCV\\Image\\套环\\图像00228.BMP");
    Mat thresholdImage;
    Mat blobImage;

    //二值化
    threshold(inputImage, thresholdImage, 100, 255, THRESH_BINARY);

    //Blob
    SimpleBlobDetector::Params params;

    params.minDistBetweenBlobs = 0.0f;
    params.filterByInertia = false;
    params.filterByConvexity = false;
    params.filterByColor = false;
    params.filterByCircularity = false;
    params.filterByArea = false;

    params.minThreshold = 0;
    params.maxThreshold = 100;

    params.filterByArea = true;
    params.minArea = 1100;
    params.maxArea = 4000;

    Ptr<SimpleBlobDetector> detector = SimpleBlobDetector::create(params);
    vector<KeyPoint> keypoints;
    detector->detect(thresholdImage, keypoints, Mat());
    
    drawKeypoints(thresholdImage, keypoints, blobImage, Scalar(0, 0, 255), DrawMatchesFlags::DEFAULT);

    //显示图像
    imshow("原始图像", inputImage);
    imshow("二值化图像", thresholdImage);
    imshow("blob图像", blobImage);

    waitKey();
}
