//
// Created by Ciocan on 12/9/2022.
//

#include "EroareJucatori.h"
const char *EroareJucatori::what() const noexcept {
    return "Nu se pot adauga atati jucatori. Numarul maxim este 18";
}

void EroareJucatori::print(std::ostream &os) const {
    os << this->what();
}