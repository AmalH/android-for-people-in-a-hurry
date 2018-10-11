#include <opencv2/core/core.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <opencv2/imgproc/imgproc.hpp>
#include <iostream>

using namespace cv;
using namespace std;

int main( int argc, char** argv )
{
    if( argc != 2)
    {
     cout <<" Usage: display_image ImageToLoadAndDisplay" << endl;
     return -1;
    }

    Mat image;
    image = imread(argv[1], CV_LOAD_IMAGE_COLOR);   

    if(! image.data )                            
    {
        cout <<  "Could not open or find the image" << std::endl ;
        return -1;
    }

    /*  convert image to grey sclae with cvtColor */
    Mat gray;
    cvtColor(image, gray, CV_BGR2GRAY);

    //  display the grey sale image. 
     namedWindow( "gray_image", WINDOW_AUTOSIZE );
     imshow( "gray_image", gray );  

    // save it with imwrite.
    imwrite("gray_image.jpg", gray); 

    /*  display both images */
    imshow( "1", image );  
    imshow( "2", gray );  

    /* convert RVB to HSV */
    cvtColor(image, hsv, CV_BGR2HSV);
    imshow( "1 - hsv now", image );  
    imshow( "2", gray ); 

    pyrUp( image, image, Size( image.cols*2, image.rows*2 ) );
    printf( "** Zoom In: Image x 2 \n" );

    pyrDown( image, image, Size( image.cols/2, image.rows/2) );
    printf( "** Zoom Out: Image / 2 \n" );
    imshow( "1", image );  
    
    waitKey(0);                                          
    return 0;
}
