#include <iostream>
#include "movie.h"
#include "utils.h"
#include "fiction.h"
#include "cartoon.h"
#include "documentary.h"

Movie::Movie(const char *name, int year) {
    this->name = name;
    this->year = year;
}

Movie *Movie::In(FILE *file) {
    int movieType;
    fscanf(file, "%d", &movieType);

    switch (movieType) {
        case 1:
            return Fiction::In(file);

        case 2:
            return Cartoon::In(file);

        case 3:
            return Documentary::In(file);

        default:
            return nullptr;
    }
}

Movie *Movie::InRandom() {
    int movieType = randInt(1, 3);

    switch (movieType) {
        case 1:
            return Fiction::InRandom();

        case 2:
            return Cartoon::InRandom();

        case 3:
            return Documentary::InRandom();

        default:
            return nullptr;
    }
}

double Movie::Quotient() {
    return static_cast<double>(year) / static_cast<double>(strlen(name));
}

void Movie::Out(FILE *file) {
}

Movie::~Movie() {
}
