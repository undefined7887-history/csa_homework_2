#include <algorithm>
#include "container.h"

Container::Container() : content() {
    len = 0;
}

Container::~Container() {
    for (int i = 0; i < len; i++) {
        delete content[i];
    }
}

void Container::In(FILE *file) {
    while (!feof(file)) {
        if ((content[len] = Movie::In(file)) != nullptr) {
            len++;
        }
    }
}

void Container::InRandom(int size) {
    while (len < size) {
        if ((content[len] = Movie::InRandom()) != nullptr) {
            len++;
        }
    }
}

void Container::Out(FILE *file) {
    fprintf(file, "Container contains %d elements.\n", len);

    for (int i = 0; i < len; i++) {
        fprintf(file, "%d: ", i + 1);
        content[i]->Out(file);
    }
}

void Container::ShakeSort() {
    int temp = len - 1;

    int left = 0;
    int right = len - 1;

    do {
        for (int i = left; i < right; i++) {
            if (content[i]->Quotient() > content[i + 1]->Quotient()) {
                std::swap(content[i], content[i + 1]);
                temp = i;
            }
        }

        right = temp;
        for (int i = right; i > left; i--) {
            if (content[i]->Quotient() < content[i - 1]->Quotient()) {
                std::swap(content[i], content[i - 1]);
                temp = i;
            }
        }

        left = temp;
    } while (left < right);
}
