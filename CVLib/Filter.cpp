#include "Filter.h"

using namespace cv;

Filter::Filter()
{
}


Filter::~Filter()
{
}

const Mat Filter::AbsDiffImage(const Mat image1, const Mat image2, const double mult /* = 1.0f */)
{
	//add size check
	Mat outImg;
	absdiff(image1, image2, outImg);
	outImg *= mult;
	return outImg;
}

const Mat Filter::AddImage(const Mat image1, const Mat image2, const double mult /* = 1.0f */, const double add /* = 0 */)
{
	Mat outImg;
	cv::add(image1, image2, outImg);
	outImg = (outImg * mult) + add;
	return outImg;
}

const Mat Filter::AddImageWeighted(const Mat image1, const Mat image2, const double i1Weight /* = 0.5f */, const double i2Weight /* = 0.5f */, const double add /* = 0 */)
{
	Mat outImg;
	addWeighted(image1, i1Weight, image2, i2Weight, add, outImg);
	return outImg;
}