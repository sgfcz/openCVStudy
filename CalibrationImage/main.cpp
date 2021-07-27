#include<iostream>
#include<opencv2\opencv.hpp>

// �����ռ�
using namespace std;
using namespace cv;

void main() {
	int n_cols = 6;   // �ǵ��еĸ���
	int n_rows = 8;   //�ǵ��еĸ���
	int n_pix = 100;  //ÿһ���������

	int col = n_pix * (n_cols + 1);   // ���ɱ궨ͼ����
	int row = n_pix * (n_rows + 1);  //���ɱ궨ͼ����

	Mat map = Mat(row, col, CV_8UC3, Scalar::all(0));  //��ʼ�������е�������Ϊ0
	for (int i = 0; i < row; i++) {						// �����������ص�
		for (int j = 0; j < col; j++) {
			if (int(i / n_pix) % 2 == 0) {             //�����������
				if (int(j / n_pix) % 2 != 0) {
					map.at<Vec3b>(i, j)[0] = 255;
					map.at<Vec3b>(i, j)[1] = 255;
					map.at<Vec3b>(i, j)[2] = 255;
				}
			}
			if (int(i / n_pix) % 2 != 0) {            //�����ż����
				if (int(j / n_pix) % 2 == 0) {
					map.at<Vec3b>(i, j)[0] = 255;
					map.at<Vec3b>(i, j)[1] = 255;
					map.at<Vec3b>(i, j)[2] = 255;
				}
			}
		}
	}

	imwrite("map.jpg", map);   // ����
	imshow("map", map);       // ��ʾ
	waitKey(0);
	return;
}