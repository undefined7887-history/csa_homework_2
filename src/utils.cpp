#include "utils.h"

void initRand() {
    srand((unsigned) time(nullptr));
}

int randInt(int min, int max) {
    return rand() % (max - min + 1) + min;
}

char *randString(int len) {
    static const char numericalAlphabet[] =
            "0123456789"
            "ABCDEFGHIJKLMNOPQRSTUVWXYZ"
            "abcdefghijklmnopqrstuvwxyz";

    char *result = new char[len + 1];

    for (int i = 0; i < len; ++i) {
        result[i] = numericalAlphabet[rand() % (sizeof(numericalAlphabet) - 1)];
    }

    // Zero terminated string
    result[len] = 0;

    return result;
}

char *readString(FILE *file) {
    char local[128] = {0};
    fscanf(file, "%s", local);

    char *result = (char *) malloc(strlen(local));
    strcpy(result, local);

    return result;
}

int readInt(FILE *file) {
    int result;
    fscanf(file, "%d", &result);

    return result;
}
