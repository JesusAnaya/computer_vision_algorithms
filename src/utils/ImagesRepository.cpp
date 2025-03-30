//
// Created by Jesus A Anaya Orozco on 29/03/25.
//

#include "utils/ImagesRepository.h"
#include <filesystem>
#include <iostream>
#include <map>

namespace opencv_examples {
    /**
     * @brief Constructor for ImagesRepository.
     * This constructor reads the images from the data directory and stores them in a map.
     * The key is the image name and the value is the image path.
     */
    ImagesRepository::ImagesRepository() {
        // Read the images from the data directory using the library filesystem
        std::string dataPath = "./data";
        for (const auto &entry: std::filesystem::directory_iterator(dataPath)) {
            if (entry.is_regular_file()) {
                std::string file_path = entry.path().string();
                // remove the extension from the file name
                std::string file_name = entry.path().filename().string();
                std::string key_name = file_name.substr(0, file_name.find_last_of('.'));
                // Store the image path in the map
                images_map[key_name] = file_path;
            }
        }
    }

    /**
     * @brief Get the image path from the map.
     * This function is used to get the image path from the map.
     * @param imageName The name of the image.
     * @return The path of the image.
     */
     std::string ImagesRepository::getImagePathFromMap(const std::string& imageName) {
        auto it = images_map.find(imageName);
        if (it != images_map.end()) {
            return it->second;
        } else {
            return "";
        }
    }

    /*
     * @brief Static instance of the ImagesRepository class.
     * This is used to create a singleton instance of the class.
     */
    ImagesRepository* ImagesRepository::instance = nullptr;

     /**
     * @brief Get the image path from the map.
     * This function is used to get the image path from the map.
     * @param imageName The name of the image.
     * @return The path of the image.
     */
    std::string ImagesRepository::getImagePath(const std::string& imageName) {
        if (instance == nullptr) {
            instance = new ImagesRepository();
        }
        std::string path = instance->getImagePathFromMap(imageName);
        if (path.empty()) {
            std::cerr << "Image not found: " << imageName << std::endl;
        }
        return path;
    }
} // namespace opencv_examples