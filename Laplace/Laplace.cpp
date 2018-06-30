#include "opencv2/imgproc/imgproc.hpp"
#include "opencv2/highgui/highgui.hpp"
#include <stdlib.h>
#include <stdio.h>
using namespace cv;

int main()
{
	Mat src, src_gray, dst;
	int kernel_size = 3;
	int scale = 1;
	int delta = 0;
	int ddepth = CV_16S;
	char* window_name = "Laplace Demo";

	int c;

	// װ��ͼ��
	src = imread("cat.jpg");

	if (!src.data)
	{
		return -1;
	}

	// ʹ�ø�˹�˲���������
	GaussianBlur(src, src, Size(3, 3), 0, 0, BORDER_DEFAULT);

	// ת��Ϊ�Ҷ�ͼ
	cvtColor(src, src_gray, CV_RGB2GRAY);

	// ������ʾ����
	namedWindow(window_name, CV_WINDOW_AUTOSIZE);

	// ʹ��Laplace����
	Mat abs_dst;

	Laplacian(src_gray, dst, ddepth, kernel_size, scale, delta, BORDER_DEFAULT);
	convertScaleAbs(dst, abs_dst);

	// ��ʾ���
	imshow(window_name, abs_dst);

	waitKey(0);

	return 0;
}