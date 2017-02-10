#include <opencv2/highgui/highgui.hpp>  
#include <opencv2/imgproc/imgproc.hpp>  
#include <opencv2/core/core.hpp>  

using namespace cv;

int main()
{
        VideoCapture cap(0);   //打开摄像头       
        if (!cap.isOpened())   // isOpened函数用来检测VideoCapture类是否打开成功
        {
                return -1;
        }
        Mat frame;
        Mat edges;

        bool stop = false;
        while (!stop)
        {
                cap >> frame;
                cvtColor(frame, edges, CV_BGR2GRAY);  //转灰度值图像  frame输入 edges输出
               // Canny(edges, edges, 0, 30, 3);    //canny
                imshow("当前视频", edges);
                if (waitKey(30) >= 0)  //每播放一个帧就在此等待30 毫秒
                                             
                        stop = false;
        }
        return 0;
}

