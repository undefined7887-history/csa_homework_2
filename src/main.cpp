#include <cstdio>
#include <cstring>
#include <chrono>
#include <iostream>
#include "utils.h"
#include "container.h"

void errCommandLine() {
    printf("incorrect command line!\n"
           "  Waited:\n"
           "     command -f infile outfile01 outfile02\n"
           "  Or:\n"
           "     command -n number outfile01 outfile02\n");
}

void errSecondParameter() {
    printf("incorrect qualifier value!\n"
           "  Waited:\n"
           "     command -f infile outfile01 outfile02\n"
           "  Or:\n"
           "     command -n number outfile01 outfile02\n");
}

void errNumberParams(int size) {
    printf("incorrect number of items = %d. Set 0 < number <= 10000\n", size);
}

void errFile() {
    printf("incorrect file provided for output");
}

int main(int argc, char *argv[]) {
    auto startTime = std::chrono::high_resolution_clock::now();

    initRand();

    if (argc != 5) {
        errCommandLine();
        return 1;
    }

    printf("Start\n");
    auto container = Container();

    if (!strcmp(argv[1], "-f")) {
        FILE *file = fopen(argv[2], "rw");
        container.In(file);

        fclose(file);
    } else if (!strcmp(argv[1], "-n")) {
        int size = atoi(argv[2]);

        if ((size < 1) || (size > 10000)) {
            errNumberParams(size);
            return 3;
        }

        container.InRandom(size);
    } else {
        errSecondParameter();
        return 2;
    }

    FILE *outFile1 = fopen(argv[3], "w+");
    if (outFile1 == nullptr) {
        errFile();
        return 0;
    }

    FILE *outFile2 = fopen(argv[4], "w+");
    if (outFile2 == nullptr) {
        errFile();
        return 0;
    }

    fprintf(outFile1, "Input container:\n");
    container.Out(outFile1);

    container.ShakeSort();
    fprintf(outFile2, "Sorted container:\n");
    container.Out(outFile2);

    fclose(outFile1);
    fclose(outFile2);

    auto endTime = std::chrono::high_resolution_clock::now();
    printf("Stop\n");
    if (!strcmp(argv[1], "-f")) {
        std::cout << "Work time: "
                  << std::chrono::duration_cast<std::chrono::milliseconds>(endTime - startTime).count()
                  << " ms";
    }

    return 0;
}
