#include<iostream>
#include<opencv2\opencv.hpp>

// 命名空间
using namespace std;
using namespace cv;

void main() {
	int n_cols = 6;   // 角点行的个数
	int n_rows = 8;   //角点列的个数
	int n_pix = 100;  //每一个块的像素

	int col = n_pix * (n_cols + 1);   // 生成标定图的列
	int row = n_pix * (n_rows + 1);  //生成标定图的行

	Mat map = Mat(row, col, CV_8UC3, Scalar::all(0));  //初始化将所有的像素设为0
	for (int i = 0; i < row; i++) {						// 遍历所有像素点
		for (int j = 0; j < col; j++) {
			if (int(i / n_pix) % 2 == 0) {             //如果是奇数行
				if (int(j / n_pix) % 2 != 0) {
					map.at<Vec3b>(i, j)[0] = 255;
					map.at<Vec3b>(i, j)[1] = 255;
					map.at<Vec3b>(i, j)[2] = 255;
				}
			}
			if (int(i / n_pix) % 2 != 0) {            //如果是偶数行
				if (int(j / n_pix) % 2 == 0) {
					map.at<Vec3b>(i, j)[0] = 255;
					map.at<Vec3b>(i, j)[1] = 255;
					map.at<Vec3b>(i, j)[2] = 255;
				}
			}
		}
	}

	imwrite("map.jpg", map);   // 保存
	imshow("map", map);       // 显示
	waitKey(0);
	return;
}