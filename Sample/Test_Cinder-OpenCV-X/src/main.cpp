#include <iostream>
#include "opencv2/opencv.hpp"
#include "opencv2/ximgproc.hpp"

using namespace std;
using namespace cv;
using namespace cv::ximgproc;

int main()
{
    cout<<"Hello, OpenCV X!"<<endl;

    string cur_path = "/Users/manster/Desktop/CinderElla/Test_Cinder-OpenCV-X/img/";
    string model_path = cur_path + "model.yml.gz";


    Ptr<StructuredEdgeDetection> pDollar = createStructuredEdgeDetection(model_path);

    string current_filename = cur_path + "seg.jpg";

    Mat3b src = imread(current_filename);

    Mat3f fsrc;
    src.convertTo(fsrc, CV_32F, 1.0 / 255.0);

    Mat1f edges;
    pDollar->detectEdges(fsrc, edges);


    for(int i = 0; i < edges.rows; ++i)
    {
        for(int j = 0; j < edges.cols; ++j)
        {
            edges[i][j] = (1.0 - edges[i][j]) * 255;
        }
    }

    string output_filename = cur_path + "res.jpg";
    imwrite(output_filename, edges);

    return 0;
}
