#include <iostream>
#include "Morph.h"
#include "Filter.h"

using namespace cv;

int main()
{
	Mat image = imread("c:\\Desert.jpg", CV_LOAD_IMAGE_COLOR);
	Mat image2 = Mat(image);

	namedWindow("MainWindow", CV_WINDOW_NORMAL);
	
	while (true)
	{
		image = imread("c:\\Desert.jpg", CV_LOAD_IMAGE_COLOR);
		image2 = Mat(image);


		/*image2 = Morph::ClosingCircle(&image, 7, 7);
		image = Filter::AbsDiffImage(&image, &image2);*/

		image = Filter::DerivateImage(&image, "x", 2);

		waitKey(1);
		imshow("MainWindow", image);
	}

	return 0;
}