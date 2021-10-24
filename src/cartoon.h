#ifndef CA_HOMEWORK_CARTOON_H
#define CA_HOMEWORK_CARTOON_H

#include <cstdio>
#include <string>
#include "movie.h"

class Cartoon : public virtual Movie {
protected:
    enum Type {
        DRAW, PUPPET, PLASTICINE
    };

    Type type;

public:
    Cartoon(const char *name, int year, Type type);

    ~Cartoon() override;

    static Movie *In(FILE *file);

    static Movie *InRandom();

    void Out(FILE *file) override;
};

#endif //CA_HOMEWORK_CARTOON_H
