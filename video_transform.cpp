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

    /** force the format at the output to H264 and scale video **/
    cv::VideoWriter out("output.avi", cv::VideoWriter::fourcc('H', '2', '6', '4'), 
                        30, cv::Size(640, 480));

    if (!out.isOpened()) {
        cout << "error: cannot open video writer" << endl;
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

        cv::Mat processed;

        /** copy the original frame to processed **/
        frame.copyTo(processed);

        /** Flip image vertically **/
        cv::flip(processed, processed, 0);

        /** create Mat full of white pixels **/
        cv::Mat full255(frame.size(), frame.type(), cv::Scalar(255, 255, 255));

        /** subtract matrix: processed - full255 **/
        cv::subtract(full255, processed, processed);

        /** show video **/
        cv::imshow("Webcam", processed);

        /** write the processed frame to output file **/
        out.write(processed);

        if (cv::waitKey(1) == 'q')
            break;
    }

    cap.release();
    out.release();
    cv::destroyAllWindows();
    return 0;
}
