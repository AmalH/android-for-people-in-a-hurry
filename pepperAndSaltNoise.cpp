#include <opencv2/core/core.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <iostream>
#include <random>

using namespace std;
using namespace cv;



void Pepper_And_Salt(cv::Mat image, int n){

  std::default_random_engine generator;
  std::uniform_int_distribution<int> randomRow(0,image.rows -1);
  std::uniform_int_distribution<int> randomCol(0,image.cols -1);

  int i,j;
	for (long l= 0; l< n; l++)
	{

    i=randomCol(generator);
    j=randomRow(generator);

    if(image.type()==CV_8UC1) // niveau de gris
      image.at<uchar>(j,i) = 255;
    else if(image.type()==CV_8UC3){ // couleurs
      image.at<Vec3b>(j,i)[0] = 255 ;
      image.at<Vec3b>(j,i)[1] = 255;
      image.at<Vec3b>(j,i)[2] = 255;
    }
   
	}
}


int main(){  

  /* Récupérer et lire le flux de la webcam */
CvCapture *capture = cvCreateCameraCapture(0);
cvSetCaptureProperty(capture, CV_CAP_PROP_FRAME_WIDTH, 640);
cvSetCaptureProperty(capture, CV_CAP_PROP_FRAME_HEIGHT, 480);

IplImage* frame;

for (int i = 0; i < 20; i++)
{
    frame = cvQueryFrame(capture);
}
cvSaveImage("me.jpg", frame);


  /* Appeler la méthode Pepper_And_Salt avec n=1000 */
Mat img = imread("me.jpg", CV_LOAD_IMAGE_UNCHANGED | CV_LOAD_IMAGE_ANYDEPTH);
Pepper_And_Salt(img,1000);

  /* Afficher l'image */
imshow("img", img);

waitKey(0);
return 0;


}