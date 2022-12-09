//
// Created by Ciocan on 12/9/2022.
//

#include "IOStream.h"
#include <iostream>

std::ostream& operator<<(std::ostream &os, const IOStream &obj)
{
    obj.print(os);
    return os;
}
std::ostream& operator<<(std::ostream &os, const IOStream *obj) {
    obj->print(os);
    return os;
}
IOStream::~IOStream() = default;