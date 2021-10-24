#ifndef CA_HOMEWORK_UTILS_H
#define CA_HOMEWORK_UTILS_H

#include <cstring>
#include <cstdio>
#include <cstdlib>
#include <ctime>
#include <cstddef>

char *readString(FILE *file);

int readInt(FILE *file);

void initRand();

int randInt(int min, int max);

char *randString(int len);

#endif //CA_HOMEWORK_UTILS_H
