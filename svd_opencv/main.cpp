#include <iostream>
#include <opencv2/opencv.hpp>

using namespace std;
using namespace cv;

int main() {
    Mat A1(2, 3, CV_32F);
    A1.at<float>(0, 0) = 1;
    A1.at<float>(0, 1) = 2;
    A1.at<float>(0, 2) = 3;
    A1.at<float>(1, 0) = 4;
    A1.at<float>(1, 1) = 5;
    A1.at<float>(1, 2) = 6;
    Mat A2(3, 2, CV_32F);
    A2.at<float>(0, 0) = 1;
    A2.at<float>(0, 1) = 2;
    A2.at<float>(1, 0) = 3;
    A2.at<float>(1, 1) = 4;
    A2.at<float>(2, 0) = 5;
    A2.at<float>(2, 1) = 6;


    // 调用OpenCV SVD函数进行计算
    // OpenCV返回的是特征向量以及转置后的VT，所以将特征向量变成对角阵后直接相乘即可
    // 此外需要注意的是对角阵的大小，与原始矩阵行列较小的那个保持一致，变成方阵
    Mat u1, sv1, vt1;
    SVD::compute(A1, sv1, u1, vt1);
    Mat s1 = Mat::eye(2, 2, CV_32F);
    s1.at<float>(0, 0) = sv1.at<float>(0);
    s1.at<float>(1, 1) = sv1.at<float>(1);
    Mat A1_ = u1 * s1 * vt1;

    Mat u2, sv2, vt2;
    SVD::compute(A2, sv2, u2, vt2);
    Mat s2 = Mat::eye(2, 2, CV_32F);
    s2.at<float>(0, 0) = sv2.at<float>(0);
    s2.at<float>(1, 1) = sv2.at<float>(1);
    Mat A2_ = u2 * s2 * vt2;

    cout << A1_ << endl << endl;
    cout << A2_ << endl << endl;
    return 0;
}