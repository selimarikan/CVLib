#include "Morph.h"

using namespace cv;

Morph::Morph()
{
}


Morph::~Morph()
{
}


const Mat Morph::OpeningCircle(const Mat image, const int i, const int j)
{
	Mat outImg = Mat::zeros(image.rows, image.cols, image.type());
	Mat strEl = getStructuringElement(CV_SHAPE_ELLIPSE, Size(i, j));
	erode(image, outImg, strEl);
	dilate(outImg, outImg, strEl);
	return outImg;
}

const Mat Morph::ClosingCircle(const Mat image, const int i, const int j)
{
	Mat outImg = Mat::zeros(image.rows, image.cols, image.type());
	Mat strEl = getStructuringElement(CV_SHAPE_ELLIPSE, Size(i, j));
	dilate(image, outImg, strEl);
	erode(outImg, outImg, strEl);
	return outImg;
}