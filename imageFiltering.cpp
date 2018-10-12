#include <opencv2/core/core.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <iostream>

using namespace std;
using namespace cv;


int main(){  

  /* 1. load IplImage */
  IplImage* img = cvLoadImage("me.jpg", CV_LOAD_IMAGE_COLOR);
  cvShowImage("before", img);

  /* 2. use Gaussian filter*/
  IplImage* output = cvCreateImage(cvGetSize(img),IPL_DEPTH_8U,3);    
  cvSmooth(img, output,CV_GAUSSIAN,5,3);

  /* 3. display image */
  cvShowImage("after", output);

waitKey(0);
return 0;


}