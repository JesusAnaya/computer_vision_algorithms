//
// Created by Jesus A Anaya Orozco on 29/03/25.
//

#include "cv_algorithms/LogTransformation.h"
#include "utils/ImagesRepository.h"
#include <iostream>
#include <opencv2/core.hpp>
#include <opencv2/highgui.hpp>

namespace opencv_examples {
    void LogTransformation::run() {
        // Load the image
        std::string image_path = ImagesRepository::getImagePath("image_1");
        cv::Mat img = cv::imread(image_path, cv::IMREAD_GRAYSCALE);
        if (img.empty()) {
            std::cerr << "Could not open or find the image!" << std::endl;
            return;
        }

        // Apply log transformation
        cv::Mat log_img = {};
        img.convertTo(log_img, CV_32F);

        log_img += 1; // To avoid log(0)
        cv::log(log_img, log_img);
        log_img.convertTo(log_img, CV_8U, 255.0 / log(256));

        // Display the original and transformed images
        cv::imshow("Original Image", img);
        cv::imshow("Log Transformed Image", log_img);

        // Wait for a key press indefinitely
        cv::waitKey(0);
    }
}// namespace opencv_examples