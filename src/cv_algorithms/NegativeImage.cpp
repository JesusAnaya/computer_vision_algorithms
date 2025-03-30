//
// Created by Jesus A Anaya Orozco on 29/03/25.
//

#include "cv_algorithms/NegativeImage.h"
#include "utils/ImagesRepository.h"
#include <opencv2/core.hpp>
#include <opencv2/highgui.hpp>
#include <iostream>

namespace opencv_examples {
    void NegativeImage::run() {
        // Load the image
        std::string image_path = ImagesRepository::getImagePath("image_1");
        cv::Mat img = cv::imread(image_path, cv::IMREAD_GRAYSCALE);
        if (img.empty()) {
            std::cerr << "Could not open or find the image!" << std::endl;
            return;
        }

        // Create a negative image
        cv::Mat negative_img = 255 - img;

        // Display the original and negative images
        cv::imshow("Original Image", img);
        cv::imshow("Negative Image", negative_img);

        // Wait for a key press indefinitely
        cv::waitKey(0);
    }
}// namespace opencv_examples