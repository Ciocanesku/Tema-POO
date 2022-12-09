//
// Created by Ciocan on 12/9/2022.
//

#ifndef OOP_EROAREJUCATORI_H
#define OOP_EROAREJUCATORI_H
#include <iostream>
#include "IOStream.h"

class EroareJucatori: public std::exception, public IOStream {
public:
    EroareJucatori()=default;
    const char* what() const noexcept override;
    void print(std::ostream&) const override;
};


#endif //OOP_EROAREJUCATORI_H
