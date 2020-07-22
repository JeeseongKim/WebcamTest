/*
* File:   main.cpp
* Author: sagar
*
* Created on 10 September, 2012, 7:48 PM
*/

#include <opencv2/highgui/highgui.hpp>
#include <opencv2/imgproc/imgproc.hpp>
#include <iostream>
#include <fstream>

using namespace cv;
using namespace std;

int main()
{
	//static const char *img_dir = "D:\\git\\log\\200121_RGB_1\\Image";
	//static const char *img_dir_save = "D:\\git\\log\\200121_RGB_1\\Image_convertedRGB";
	static const char *img_dir = "D:\\git\\log\\200121_RGB_2\\Image";
	static const char *img_dir_save = "D:\\git\\log\\200121_RGB_2\\Image_convertedRGB";
	static const char *img_format = ".jpg";
	//char fname_L[100];
	//char fname_R[100];
	char fname[100];
	char fname_save[100];

	//for image data
	cv::Mat matImg;
	cv::Mat matImg_converted;

	//cv::Mat matImg_L;
	//cv::Mat matImg_R;

	int end_no = 726; //NEEDS TO BE CHANGED EVERYTIME
	int aa = 0;

	for (int i = 1; i < end_no; i++)
	{
		//sprintf(fname_L, "%s\\%0.6d_1.jpg", img_dir, i);
		//sprintf(fname_R, "%s\\%0.6d_0.jpg", img_dir, i);
		sprintf(fname, "%s\\%0.6d_0.jpg", img_dir, i);

		//read the left and right images
		//matImg_L = cv::imread(fname_L, 0);
		//matImg_R = cv::imread(fname_R, 0);
		matImg = cv::imread(fname, cv::IMREAD_ANYCOLOR | cv::IMREAD_ANYDEPTH); //RGB image
		cv::cvtColor(matImg, matImg_converted, cv::COLOR_BGR2RGB);
		//cv::imshow("left", matImgL_);
		//cv::imshow("right", matImg_R);

		cv::imshow("original", matImg);
		cv::imshow("converted",matImg_converted);
		cv::waitKey(5);

		sprintf(fname_save, "%s\\%0.6d_0.jpg", img_dir_save, i);
		cv::imwrite(fname_save, matImg_converted);

		if (aa == 0)
		{
			aa = 1;
			cv::waitKey(0);
		}


	}

	return 0;
}