#include <iostream>
#include "fiction.h"
#include "utils.h"

Fiction::Fiction(const char *name, int year, const char *director) : Movie(name, year) {
    this->director = director;
}

Fiction::~Fiction() {
    free((void *) name);
    free((void *) director);
}

Movie *Fiction::In(FILE *file) {
    return new Fiction(
            readString(file),
            readInt(file),
            readString(file)
    );
}

Movie *Fiction::InRandom() {
    return new Fiction(
            randString(randInt(5, 10)),
            randInt(1950, 2021),
            randString(randInt(10, 20))
    );
}

void Fiction::Out(FILE *file) {
    fprintf(file, "Fiction: name = %s, year = %d, director = %s\n", name, year, director);
}
