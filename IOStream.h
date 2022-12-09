//
// Created by Ciocan on 12/9/2022.
//

#ifndef OOP_IOSTREAM_H
#define OOP_IOSTREAM_H
#include <iostream>

class IOStream {
protected:
    virtual void print(std::ostream &) const=0;

    friend std::ostream& operator <<(std::ostream &, const IOStream&);
    friend std::ostream& operator <<(std::ostream &, const IOStream*);

    virtual ~IOStream();
};


#endif //OOP_IOSTREAM_H
