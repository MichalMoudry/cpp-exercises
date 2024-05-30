#ifndef _MOVIES_H_
#define _MOVIES_H_
#include "Movie.h"
#include <string>
#include <vector>

class Movies {
private:
    std::vector<Movie> movies {};
public:
    bool add_movie(std::string name, double rating, int watched);
    bool was_watched(std::string movie_name);
    void display_movies() const;
};

#endif