//
// Created by Jesus A Anaya Orozco on 29/03/25.
//

#include "cv_algorithms/BitwiseOperators.h"
#include <opencv2/core.hpp>
#include <opencv2/highgui.hpp>
#include <opencv2/imgproc.hpp>

namespace opencv_examples {
    void BitwiseOperators::run() {
        // Create two black images
        cv::Mat img1 = cv::Mat::zeros(300, 300, CV_8UC3);
        cv::Mat img2 = cv::Mat::zeros(300, 300, CV_8UC3);

        // Draw a white rectangle on the first image
        cv::rectangle(img1, cv::Point(50, 50), cv::Point(250, 250), cv::Scalar(255, 255, 255), -1);

        // Draw a white circle on the second image
        cv::circle(img2, cv::Point(150, 150), 100, cv::Scalar(255, 255, 255), -1);

        // Perform bitwise AND operation
        cv::Mat and_result;
        cv::bitwise_and(img1, img2, and_result);

        // Perform bitwise OR operation
        cv::Mat or_result;
        cv::bitwise_or(img1, img2, or_result);

        // Perform bitwise XOR operation
        cv::Mat xor_result;
        cv::bitwise_xor(img1, img2, xor_result);

        // Perform bitwise NOT operation on the first image
        cv::Mat not_result;
        cv::bitwise_not(img1, not_result);

        // Display results
        cv::imshow("Image 1", img1);
        cv::imshow("Image 2", img2);
        cv::imshow("AND Result", and_result);
        cv::imshow("OR Result", or_result);
        cv::imshow("XOR Result", xor_result);
        cv::imshow("NOT Result", not_result);

        // Wait for a key press indefinitely
        cv::waitKey(0);

    }
}// namespace opencv_examples