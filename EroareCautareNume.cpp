//
// Created by Ciocan on 12/9/2022.
//

#include "EroareCautareNume.h"
const char *EroareCautareNume::what() const noexcept {
    return "Nu exista persoana cu acest nume";
}

void EroareCautareNume::print(std::ostream &os) const {
    os << this->what();
}