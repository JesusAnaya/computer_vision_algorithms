//
// Created by Jesus A Anaya Orozco on 29/03/25.
//

#ifndef OPENCV_COURSER_CVALGORITHMSINTERFACE_H
#define OPENCV_COURSER_CVALGORITHMSINTERFACE_H

class CVAlgorithmsInterface {
public:
    CVAlgorithmsInterface() = default;
    virtual ~CVAlgorithmsInterface() = default;

    virtual void run() = 0;
};

#endif//OPENCV_COURSER_CVALGORITHMSINTERFACE_H
