#include <opencv2/core.hpp>
#include <opencv2/imgcodecs.hpp>
/**
core section, as here are defined the basic building blocks of the library
highgui module, as this contains the functions for input and output operations
*/
#include <opencv2/highgui.hpp>
#include <iostream>
using namespace cv;
using namespace std;

/**
OpenCV offers support for the image formats Windows bitmap (bmp), 
portable image formats (pbm, pgm, ppm) and Sun raster (sr, ras). With help of 
plugins (you need to specify to use them if you build yourself the library, 
nevertheless in the packages we ship present by default) you may also load image
formats like JPEG (jpeg, jpg, jpe), JPEG 2000 (jp2 - codenamed in the CMake as Jasper),
TIFF files (tiff, tif) and portable network graphics (png). Furthermore, OpenEXR is 
also a possibility.
*/

int main( int argc, char** argv )
{
    /**
     * Read an image.
     *
     * @param 
     * @return 0;
    */
    String imageName( "test.png" ); // by default
    if( argc > 1)
    {
        imageName = argv[1];
    }
    Mat image;
    image = imread( samples::findFile( imageName ), IMREAD_GRAYSCALE ); // Read the file

    /**
    IMREAD_UNCHANGED (<0) loads the image as is (including the alpha channel if present)
    IMREAD_GRAYSCALE ( 0) loads the image as an intensity one
    IMREAD_COLOR (>0) loads the image in the RGB format
    */

    if( image.empty() )                      // Check for invalid input
    {
        cout <<  "Could not open or find the image" << std::endl ;
        return -1;
    }
    namedWindow( "Display window", WINDOW_AUTOSIZE ); // Create a window for display.
    imshow( "Display window", image );                // Show our image inside it.
    waitKey(0); // Wait for a keystroke in the window
    return 0;
}