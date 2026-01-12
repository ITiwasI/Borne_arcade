#include <Arduino.h>
#include "row.hpp"

Row::Row()
{
    elements.resize(7);
    std::fill(elements.begin(), elements.end(), '-');
}

Row::~Row()
{
    
}

void Row::DisplayRow()
{
    for (char c : elements)
    {
        Serial.print(c);
        Serial.print(" ");
    }
    Serial.println(" ");
}

