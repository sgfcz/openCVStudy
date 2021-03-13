#include <opencv2/opencv.hpp>

using namespace cv;

int main()
{
	Mat image = imread("°¢Â³¿¨¶à.jpg", 0);
	imwrite("°¢Â³¿¨¶àgray.jpg", image);
	imshow("°¢Â³¿¨¶à", image);
	waitKey(0);
	return 0;
}