#ifndef _pixel_
#define _pixel_

class Pixel{
public:
    int value;
    int pos;

    Pixel(int pValue, int pPos){
        this->value=pValue;
        this->pos=pPos;
    }

    Pixel(){}
};
#endif