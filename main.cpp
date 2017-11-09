#include <iostream>
#include <opencv2/opencv.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <opencv2/core/core.hpp>
#include <string>
#include <time.h>
#include <stdlib.h>
#include <limits.h>
using namespace cv;
int mult(Mat & img,double * matr,int x, int y)
{
    int  res(0);
    for(int i = -1; i < 2; i++) //y
    {
        for(int j = -1; j < 2; j++) //x
        {
            if(x + j >= 0 && x + j < img.cols && y + i >= 0 && y + i < img.rows)
            {
                res += (int)img.at<uchar>(x + j, y + i)*matr[(i+1)*3 + j + 1];
            }
        }
    }
    return res;

}
int main()
{
    double matrX[9] = {-1, -2, -1, 0, 0, 0, 1, 2, 1};
    double matrY[9] = {-1, 0, 1, -2, 0, 2, -1, 0, 1};
    Mat img;
    img = imread("Lenna.png",IMREAD_GRAYSCALE);
    Mat img2 = img.clone();
    for(int y = 0; y < img.rows; y++)
    {
        for(int x = 0; x < img.cols; x++)
        {
            int Gx = mult(img,matrX,x,y);
            int Gy = mult(img,matrY,x,y);
            int G = sqrt(pow(Gx,2) + pow(Gy,2));
            if(G > 255)
                G = 255;
            else if(G < 0 )
                G = 0;
            img2.at<uchar>(x,y) = G;
        }
    }
    namedWindow("Window");
    imshow("Window",img);
    namedWindow("Sobolev");
    imshow("Sobolev",img2);
    char c = waitKey(0);
}
