#include <opencv2/opencv.hpp>

using namespace cv;

int main()
{
	Mat image = imread("��³����.jpg", 0);
	imwrite("��³����gray.jpg", image);
	imshow("��³����", image);
	waitKey(0);
	return 0;
}