#ifndef CA_HOMEWORK_DOCUMENTARY_H
#define CA_HOMEWORK_DOCUMENTARY_H

#include <cstdio>
#include <string>
#include "movie.h"

class Documentary : public virtual Movie {
protected:
    int duration;

public:
    Documentary(const char *name, int year, int duration);

    ~Documentary() override;

    static Movie *In(FILE *file);

    static Movie *InRandom();

    void Out(FILE *file) override;
};

#endif //CA_HOMEWORK_DOCUMENTARY_H
