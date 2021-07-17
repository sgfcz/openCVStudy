#include <opencv2/opencv.hpp>
#include <iostream>
#include <vector>

using namespace std;
using namespace cv;

int main()
{
	Mat image = imread("C:\\Users\\Test 1\\Pictures\\model\\shirt.bmp");
	Mat imageGray, imageth, imageblur;
	vector <vector<Point>> contours;
	vector <Vec4i> hieraychy;
	int height, drawflag;
	//转换灰度图
	if (image.type() != CV_8UC1)
		cvtColor(image, imageGray, COLOR_BGR2GRAY);

	//线性模糊
	GaussianBlur(imageGray, imageblur, Size(3, 3), 0);
	//二值化
	//threshold(imageblur, imageth, 200, 255, THRESH_BINARY_INV);
	adaptiveThreshold(imageblur, imageth, 255, ADAPTIVE_THRESH_MEAN_C, THRESH_BINARY_INV, 13,8);

	//寻边
	findContours(imageth, contours, hieraychy, RETR_EXTERNAL, 1);
	height = image.rows - 1;
	//画边
	for (int i = 0; i < contours.size(); i++) {
		drawflag = 0;
		double area = contourArea(contours[i]);
		Rect drawRect = boundingRect(contours[i]);
		if (area > 15000 && drawRect.height < height * 0.8 && 
				drawRect.height > 150 && drawRect.width > 150) {
			for (auto point : contours[i]) {
				if (point.y == height || point.y == 0) {
					drawContours(image, contours, i, Scalar(0, 0, 255), 5, 8, hieraychy);
					drawflag = 1;
					break;
				}
			}
			if (drawflag == 0)
				drawContours(image, contours, i, Scalar(0, 255, 0), 5, 8, hieraychy);
		}
	}
	imshow("title", image);
	waitKey(0);
	return 0;
}