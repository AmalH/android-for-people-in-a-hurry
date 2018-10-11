#include <opencv2/core/core.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <opencv2/imgproc/imgproc.hpp>
#include <iostream>
#include <stdio.h>

using namespace cv;
using namespace std;

int main( int argc, char** argv )
{


    /* 1. declare source and destination images. */
  Mat src, dst;

    /* 2. load image */
  src = imread( argv[1], 1 );
  if( !src.data )
    { cout <<  "Could not open or find the image" << std::endl ;
      return -1;}

    /* 3. seperate source image to 3 plans (R, G et B) with Split. */
  vector<Mat> bgr_planes;
  split( src, bgr_planes );

    /* 4. configure histograms for each plan*/

  int histSize = 256;
  
  float range[] = { 0, 256 } ;
  const float* histRange = { range };
   
  Mat b_hist, g_hist, r_hist;

  calcHist( &bgr_planes[0], 1, 0, Mat(), b_hist, 1, &histSize, &histRange, true, false );
  calcHist( &bgr_planes[1], 1, 0, Mat(), g_hist, 1, &histSize, &histRange, true, false );
  calcHist( &bgr_planes[2], 1, 0, Mat(), r_hist, 1, &histSize, &histRange, true, false );

  /* 5. create an image to display the histogram */
  int hist_w = 500; int hist_h = 400;
  Mat histImage( hist_h, hist_w, CV_8UC3, Scalar( 0,0,0) );

  /* 6. normalizing histograms */
  normalize(b_hist, b_hist, 0, histImage.rows, NORM_MINMAX, -1, Mat() );
  normalize(g_hist, g_hist, 0, histImage.rows, NORM_MINMAX, -1, Mat() );
  normalize(r_hist, r_hist, 0, histImage.rows, NORM_MINMAX, -1, Mat() );

  /* 7. display histograms */
  int bin_w = cvRound( (double) hist_w/histSize );
  for( int i = 1; i < histSize; i++ )
  {
      line( histImage, Point( bin_w*(i-1), hist_h - cvRound(b_hist.at<float>(i-1)) ) ,
                       Point( bin_w*(i), hist_h - cvRound(b_hist.at<float>(i)) ),
                       Scalar( 255, 0, 0), 2, 8, 0  );
      line( histImage, Point( bin_w*(i-1), hist_h - cvRound(g_hist.at<float>(i-1)) ) ,
                       Point( bin_w*(i), hist_h - cvRound(g_hist.at<float>(i)) ),
                       Scalar( 0, 255, 0), 2, 8, 0  );
      line( histImage, Point( bin_w*(i-1), hist_h - cvRound(r_hist.at<float>(i-1)) ) ,
                       Point( bin_w*(i), hist_h - cvRound(r_hist.at<float>(i)) ),
                       Scalar( 0, 0, 255), 2, 8, 0  );
  }
  
  namedWindow("calculate histogramme", CV_WINDOW_AUTOSIZE );
  imshow("calculate histogramme", histImage );


  waitKey(0);

  return 0;
}