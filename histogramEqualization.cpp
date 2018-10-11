#include <opencv2/core/core.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <opencv2/imgproc/imgproc.hpp>
#include <iostream>
#include <stdio.h>

using namespace cv;
using namespace std;

int main( int argc, char** argv )
{


    /* 1. source and destination images */
  Mat src, dst;

    /* 2. load a source image. */
  src = imread( argv[1], 1 );
  if( !src.data )
    { cout <<  "Could not open or find the image" << std::endl ;
      return -1;}

    /* 3. convert source image to grey scale */
  cvtColor( src, src, CV_BGR2GRAY );

    /* 4.apply histogram equalization with equalizeHist */
  equalizeHist( src, dst );

    /* 5. display both images */
  namedWindow( "image source", CV_WINDOW_AUTOSIZE );
  namedWindow( "image destination", CV_WINDOW_AUTOSIZE );
  imshow( "image source", src );
  imshow( "image destination", dst );


  waitKey(0);

  return 0;
}