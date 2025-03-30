//
// Created by Jesus A Anaya Orozco on 29/03/25.
//

#ifndef OPENCV_COURSER_IMAGESREPOSITORY_H
#define OPENCV_COURSER_IMAGESREPOSITORY_H
#include <memory>
#include <string>
#include <map>

namespace opencv_examples {

    class ImagesRepository {
    public:
        ImagesRepository();
        static std::string getImagePath(const std::string& imageName);

    private:
        static std::unique_ptr<ImagesRepository> instance;
        std::map<std::string, std::string> images_map = {};
        std::string getImagePathFromMap(const std::string& imageName);
    };

}// namespace opencv_examples

#endif//OPENCV_COURSER_IMAGESREPOSITORY_H
