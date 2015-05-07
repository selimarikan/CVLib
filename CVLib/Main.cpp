#include <iostream>
#include "Morph.h"

using namespace cv;

int main()
{
	Mat image = imread("c:\\Desert.jpg", CV_LOAD_IMAGE_COLOR);

	namedWindow("MainWindow", CV_WINDOW_NORMAL);
	
	while (true)
	{
		image = Morph::ClosingCircle(image, 7, 7);
		imshow("MainWindow", image);
		waitKey(1);
	}

	return 0;
}