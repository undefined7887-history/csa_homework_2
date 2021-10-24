#include <iostream>
#include "cartoon.h"
#include "utils.h"

Cartoon::Cartoon(const char *name, int year, Cartoon::Type type) : Movie(name, year), type(type) {}

Cartoon::~Cartoon() {
    free((void *) name);
}

Movie *Cartoon::In(FILE *file) {
    char *name = readString(file);
    int year = readInt(file);

    char *stringType = readString(file);
    Cartoon::Type type;

    if (strcmp(stringType, "draw") == 0) {
        type = Cartoon::DRAW;
    } else if (strcmp(stringType, "puppet") == 0) {
        type = Cartoon::PUPPET;
    } else if (strcmp(stringType, "plasticine") == 0) {
        type = Cartoon::PLASTICINE;
    } else {
        type = Cartoon::DRAW;
    }

    // readString allocates string
    free(stringType);

    return new Cartoon(
            name,
            year,
            type
    );
}

Movie *Cartoon::InRandom() {
    return new Cartoon(
            randString(randInt(5, 10)),
            randInt(1950, 2021),
            static_cast<Cartoon::Type>(randInt(0, 2))
    );
}

void Cartoon::Out(FILE *file) {
    char *stringType;

    switch (type) {
        case Cartoon::DRAW:
            stringType = (char *) "DRAW";
            break;
        case Cartoon::PUPPET:
            stringType = (char *) "PUPPET";
            break;
        case Cartoon::PLASTICINE:
            stringType = (char *) "PLASTICINE";
            break;
    }

    fprintf(file, "Cartoon: name = %s, year = %d, stringType = %s\n", name, year, stringType);
}

