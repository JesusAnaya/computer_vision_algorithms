cmake_minimum_required(VERSION 3.30)
project(OpenCV_Courser)

set(CMAKE_CXX_STANDARD 17)

find_package( OpenCV REQUIRED )
include_directories(${OpenCV_INCLUDE_DIRS})
include_directories(${CMAKE_SOURCE_DIR}/headers)

add_executable(OpenCV_Courser src/main.cpp
        src/cv_algorithms/BitwiseOperators.cpp
        headers/cv_algorithms/BitwiseOperators.h
        src/cv_algorithms/LogTransformation.cpp
        headers/cv_algorithms/LogTransformation.h
        headers/cv_algorithms/CVAlgorithmsInterface.h
        src/utils/ImagesRepository.cpp
        headers/utils/ImagesRepository.h
        src/cv_algorithms/NegativeImage.cpp
        headers/cv_algorithms/NegativeImage.h
        src/cv_algorithms/PowerLawGammaTransformation.cpp
        headers/cv_algorithms/PowerLawGammaTransformation.h
)

target_link_libraries(OpenCV_Courser ${OpenCV_LIBS})
