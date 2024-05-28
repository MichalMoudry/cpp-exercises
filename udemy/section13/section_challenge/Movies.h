#ifndef _MOVIES_H_
#define _MOVIES_H_
#include "Movie.h"
#include <string>
#include <vector>

class Movies {
private:
    std::vector<Movie> movies {};
public:
    void add_movie(std::string name, double rating, int watched);
    void was_watched(std::string movie_name);
    void display_movies() const;
};

#endif