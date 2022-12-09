//
// Created by Ciocan on 12/9/2022.
//

#ifndef OOP_EROARECAUTARENUME_H
#define OOP_EROARECAUTARENUME_H
#include <iostream>
#include "IOStream.h"

class EroareCautareNume: public std::exception, public IOStream {
public:
    EroareCautareNume()=default;
    const char* what() const noexcept override;
    void print(std::ostream&) const override;
};


#endif //OOP_EROARECAUTARENUME_H
