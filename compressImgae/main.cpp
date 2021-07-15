#include <opencv2\opencv.hpp>
#include <vector>
#include <string>
#include <regex>

using namespace std;

int main()
{
	vector<string> imagePath;
	string imagefrom = "C:\\Users\\Test 1\\Pictures\\*.bmp";
	string savepath = "C:\\Users\\Test 1\\Pictures\\imagecompress\\";
	regex re("Image.*.bmp");
	cv::glob(imagefrom, imagePath);
	for (auto image : imagePath) {
		smatch imagenames;
		cv::Mat saveImage;
		cv::Mat compressImage = cv::imread(image);
		int width = compressImage.cols / 2;
		int height = compressImage.rows / 2;
		regex_search(image, imagenames, re);
		cv::resize(compressImage, saveImage, cv::Size(width, height));
		cv::imwrite(savepath + imagenames[0].str(), saveImage);
	}
	return 0;
}