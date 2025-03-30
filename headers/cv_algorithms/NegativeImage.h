//
// Created by Jesus A Anaya Orozco on 29/03/25.
//

#ifndef OPENCV_COURSER_NEGATIVEIMAGE_H
#define OPENCV_COURSER_NEGATIVEIMAGE_H
#include "CVAlgorithmsInterface.h"

namespace opencv_examples {

    class NegativeImage : public CVAlgorithmsInterface {
    public:
        NegativeImage() = default;

        void run() override;
    };

}// namespace opencv_examples

#endif//OPENCV_COURSER_NEGATIVEIMAGE_H
