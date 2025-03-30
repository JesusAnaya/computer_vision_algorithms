//
// Created by Jesus A Anaya Orozco on 29/03/25.
//

#include "cv_algorithms/PowerLawGammaTransformation.h"
#include "utils/ImagesRepository.h"
#include <opencv2/core.hpp>
#include <opencv2/highgui.hpp>
#include <opencv2/imgproc.hpp>
#include <iostream>

namespace opencv_examples {
    void PowerLawGammaTransformation::run() {
        // Load the image
        std::string image_path = ImagesRepository::getImagePath("image_1");
        cv::Mat img = cv::imread(image_path, cv::IMREAD_GRAYSCALE);
        if (img.empty()) {
            std::cerr << "Could not open or find the image!" << std::endl;
            return;
        }

        // Adding dynamic gamma range adjustment by using OpenCV GUI slider
        int gamma_value = 1;
        cv::namedWindow("Power Law Gamma Transformation", cv::WINDOW_AUTOSIZE);
        cv::createTrackbar("(Gamma/100)", "Power Law Gamma Transformation", &gamma_value, 100);

        while (true) {
            // Apply power law transformation
            cv::Mat gamma_img;
            img.convertTo(gamma_img, CV_32F);
            cv::pow(gamma_img / 255.0, gamma_value / 100.0, gamma_img);
            gamma_img.convertTo(gamma_img, CV_8U, 255);

            // Display the transformed image
            cv::imshow("Power Law Gamma Transformation", gamma_img);

            // Break the loop if 'q' is pressed
            if (cv::waitKey(30) == 'q') {
                break;
            }
        }
        // Destroy all windows
        cv::destroyAllWindows();
    }
}// namespace opencv_examples