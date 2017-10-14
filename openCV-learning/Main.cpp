
#include "stdafx.h"
#include <opencv\cv.h>
#include <opencv\cvaux.h>
#include <opencv\cxcore.h>
#include <opencv\highgui.h>
#include <opencv\ml.h>

#include <iostream>

using std::cout;
using std::endl;

#pragma comment (lib, "opencv_world330d.lib")

const char* TAG = " [OpenCV Learning] ";


void TestCV()
{
	cout << TAG << __LINE__ << "\t" << "TestCV" << endl;
	CvFileStorage* fs = cvOpenFileStorage("xy-cfg.xml", 0, CV_STORAGE_WRITE);
	
	cvWriteInt(fs, "xy-frame-count", 10);
	cvStartWriteStruct(fs, "xy-frame-size", CV_NODE_SEQ);
	cvWriteInt(fs, 0, 320);
	cvWriteInt(fs, 0, 200);
	cvEndWriteStruct(fs);

	cvWriteInt(fs, "xy-frame-count", 10);

	cvReleaseFileStorage(&fs);
}

int main()
{
	cout << TAG << __LINE__ << "\t" << "main" << endl;
	TestCV();
	return 0;
}