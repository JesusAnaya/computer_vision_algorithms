//
// Created by Jesus A Anaya Orozco on 29/03/25.
//

#ifndef OPENCV_COURSER_POWERLAWGAMMATRANSFORMATION_H
#define OPENCV_COURSER_POWERLAWGAMMATRANSFORMATION_H
#include "CVAlgorithmsInterface.h"

namespace opencv_examples {

    class PowerLawGammaTransformation : public CVAlgorithmsInterface {
    public:
        PowerLawGammaTransformation() = default;

        void run() override;
    };

}// namespace opencv_examples

#endif//OPENCV_COURSER_POWERLAWGAMMATRANSFORMATION_H
