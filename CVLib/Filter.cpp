#include "Filter.h"

using namespace cv;

Filter::Filter()
{
}


Filter::~Filter()
{
}

const Mat Filter::AbsDiffImage(const Mat* image1, const Mat* image2, const double mult /* = 1.0 */)
{
	//add size check
	Mat outImg;
	absdiff(*image1, *image2, outImg);
	outImg *= mult;
	return outImg;
}

const Mat Filter::AddImage(const Mat* image1, const Mat* image2, const double mult /* = 0.0 */, const double add /* = 0.0 */)
{
	Mat outImg;
	cv::add(*image1, *image2, outImg);
	return (outImg * mult) + add;
}

const Mat Filter::AddImageWeighted(const Mat* image1, const Mat* image2, const double i1Weight /* = 0.5 */, const double i2Weight /* = 0.5 */, const double add /* = 0.0 */)
{
	Mat outImg;
	addWeighted(*image1, i1Weight, *image2, i2Weight, add, outImg);
	return outImg;
}

const Mat Filter::InvertImage(const Mat* image)
{
	Mat outImg;
	invert(*image, outImg);
	return outImg;
}

inline const Mat Filter::ScaleImage(const Mat* image, const double mult, const double add /* = 0.0 */)
{
	return (*image * mult) + add;
}

const Mat Filter::SubImage(const Mat* image1, const Mat* image2, const double mult /* = 1.0 */, const double add /* = 0.0 */)
{
	Mat outImg;
	cv::subtract(*image1, *image2, outImg);
	return (outImg * mult) + add;
}

const Mat Filter::RGBToGray(const Mat* image)
{
	Mat outImg;
	cvtColor(*image, outImg, CV_RGB2GRAY);
	return outImg;
}

const Mat Filter::DerivateImage(const Mat* image, std::string mode, const int degree)
{
	Mat outImg;

	if (!mode.compare("x"))
	{
		Sobel(*image, outImg, CV_16S, degree, 0);
	}
	else if (!mode.compare("y"))
	{
		Sobel(*image, outImg, CV_16S, 0, degree);
	}
	else if (!mode.compare("gradient"))
	{
		Sobel(*image, outImg, CV_16S, degree, degree);
	}

	return outImg;	
}

// laplacian


