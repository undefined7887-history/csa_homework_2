#ifndef CA_HOMEWORK_MOVIE_H
#define CA_HOMEWORK_MOVIE_H

#include <cstdio>

class Movie {
protected:
    const char *name;
    int year;

public:
    Movie(const char *name, int year);

    virtual ~Movie();

    /**
     * Reads movie from a file
     * @return
     */
    static Movie *In(FILE *file);

    /**
     * Generated random movie
     * @return
     */
    static Movie *InRandom();

    /**
     * Prints movie to the file
     * @return
     */
    virtual void Out(FILE *file);

    /**
     * Movie function
     * @return
     */
    double Quotient();
};

#endif //CA_HOMEWORK_MOVIE_H
