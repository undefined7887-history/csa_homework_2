#ifndef CA_HOMEWORK_CONTAINER_H
#define CA_HOMEWORK_CONTAINER_H

#include <cstdio>
#include <cstddef>
#include "movie.h"

const int MAX_CONTAINER_LEN = 10000;

class Container {
    int len;
    Movie *content[MAX_CONTAINER_LEN];

public:
    Container();

    ~Container();

    void In(FILE *file);

    void InRandom(int size);

    void Out(FILE *file);

    void ShakeSort();
};

#endif //CA_HOMEWORK_CONTAINER_H
