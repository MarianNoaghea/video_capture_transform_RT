#include <opencv2/opencv.hpp>
#include <iostream>

using namespace std;

int main() {
    /** open webcam **/
    cv::VideoCapture cap(0);
    if (!cap.isOpened()) {
        cout << "error: cannot open webcam" << endl;
        return -1;
    }

    while (true) {
        cv::Mat frame;

        /** capture frame from webcam **/
        cap >> frame;
        if (frame.empty()) {
            cout << "error: frame reading failed" << endl;
            break;
        }

        /** show video **/
        cv::imshow("Webcam", frame);

        if (cv::waitKey(1) == 'q')
            break;
    }

    cap.release();
    cv::destroyAllWindows();
    return 0;
}