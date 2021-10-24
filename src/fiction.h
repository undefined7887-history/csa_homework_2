#ifndef CA_HOMEWORK_FICTION_H
#define CA_HOMEWORK_FICTION_H

#include <cstdio>
#include <string>
#include "movie.h"

class Fiction : public virtual Movie {
protected:
    const char *director;

public:
    Fiction(const char *name, int year, const char *director);

    ~Fiction() override;

    static Movie *In(FILE *file);

    static Movie *InRandom();

    void Out(FILE *file) override;
};

#endif //CA_HOMEWORK_FICTION_H
