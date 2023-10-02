#include <opencv2/core.hpp>
#include <opencv2/highgui.hpp>
#include <opencv2/objdetect.hpp>
#include <opencv2/imgproc.hpp>
#include <iostream>

static const int minFaceSize = 100;
static const cv::Scalar frColor(255, 0, 0);

void detect(cv::Mat &img, cv::CascadeClassifier &cascade, double scale);

int main() {
    cv::VideoCapture capture;
    cv::Mat frame, image;
    double scale = .75;
    cv::CascadeClassifier cascade; 

    cascade.load("haarcascades/haarcascade_frontalface_alt.xml");
    capture.open(1);
    
    if (capture.isOpened()) {
        while (true) {
            capture >> frame;

            if (frame.empty()) break;

            detect(frame, cascade, scale);

            cv::waitKey(1);
        }
    } else {
        std::cout << "dumbass" << std::endl;
        return 1;
    }
    return 0;
} // main

void detect(cv::Mat &img, cv::CascadeClassifier &cascade, double scale) {
    std::vector<cv::Rect> faces, faces2;
    cv::Mat gray, smallImage;
    double fx = 1 / scale;

    cv::cvtColor(img, gray, cv::COLOR_BGR2GRAY);

    cv::resize(gray, smallImage, cv::Size(), fx, fx, cv::INTER_LINEAR);
    cv::equalizeHist(smallImage, smallImage);

    cascade.detectMultiScale(smallImage, faces, 1.1, 2, 0|cv::CASCADE_SCALE_IMAGE, cv::Size(30, 30));
    cv::Rect faceRectangle;

    for (size_t i = 0; i < faces.size(); i++) {
        faceRectangle = faces[i];

        if (faceRectangle.height < minFaceSize) continue;
        std::cout << faces[i] << std::endl;

        cv::rectangle(img, cv::Point(faceRectangle.x * scale, faceRectangle.y * scale), cv::Point((faceRectangle.x + faceRectangle.width - 1) * scale, (faceRectangle.y + faceRectangle.height - 1) * scale), frColor, 8);

    }

    cv::imshow("Faces", img);
} // detect