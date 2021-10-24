#include <iostream>
#include "documentary.h"
#include "utils.h"

Documentary::Documentary(const char *name, int year, int duration) : Movie(name, year) {
    this->duration = duration;
}

Documentary::~Documentary() {
    free((void *) name);
}

Movie *Documentary::In(FILE *file) {
    return new Documentary(
            readString(file),
            readInt(file),
            readInt(file)
    );
}

Movie *Documentary::InRandom() {
    return new Documentary(
            randString(randInt(5, 10)),
            randInt(1950, 2021),
            randInt(1, 10)
    );
}

void Documentary::Out(FILE *file) {
    fprintf(file, "Documentary: name = %s, year = %d, duration = %d\n", name, year, duration);
}

