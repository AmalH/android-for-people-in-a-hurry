#include "opencv2/opencv.hpp"

using namespace cv;

int main(int argc, char** argv)
{
    int c;
    IplImage* color_img;
    CvCapture* cv_cap = cvCaptureFromCAM(0);
    cvNamedWindow("Video",0); 
    for(;;) {
        color_img = cvQueryFrame(cv_cap); 
        if(color_img != 0)
            cvShowImage("Video", color_img);
        
        imwrite(".../me.png", frame);

        c = cvWaitKey(10); 
        if(c == 27)
            break; 
    }
    cvReleaseCapture( &cv_cap );
    cvDestroyWindow("Video");    
}
