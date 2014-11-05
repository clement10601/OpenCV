#include <opencv2\opencv.hpp>

using namespace cv;

int main()
{
	Mat frame;
	VideoCapture cap(0);

	cap.open("D:/video.avi");
	if (!cap.isOpened())
		return -1;

	BackgroundSubtractorMOG2 bg(50, 30, 0);  // foreground low th low(10~20)
	Mat fore;
	Mat dd;
	Mat ee;

	int f = 0;

	while (cap.read(frame))
	{

		bg(frame, fore, 0.03);
		imshow("fore", fore);

		erode(fore, ee, Mat());   //«I»k
		dilate(ee, dd, Mat());    //¿±µÈ

		f++;
		for (int i = 0; i < frame.rows; i++)
		{
			for (int j = 0; j < frame.cols; j++)
			{
				if (dd.at<uchar>(i, j) == 0)
					frame.at<Vec3b>(i, j) = 0;

			}
		}

		if (f == 150) imwrite("f150.jpg", frame);
		if (f == 250) imwrite("f250.jpg", frame);

		imshow("Vidoe", frame);
		imshow("dilate", dd);
		waitKey(10);

	}
}