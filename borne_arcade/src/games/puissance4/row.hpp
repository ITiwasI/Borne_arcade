#ifndef _row_hpp_
#define _row_hpp_

#include <ArduinoSTL.h>
#include "vector"
using std::vector;

class Row {
    public:
        std::vector<char> elements;

        Row();
        ~Row();

        void DisplayRow();

        char& operator[](int j) {return elements[j]; }
};

#endif 