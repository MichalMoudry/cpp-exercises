#include "Movie.h"
#include <string>

Movie::Movie(std::string movie_name) : Movie(movie_name, 0) {}

Movie::Movie(std::string movie_name, double rating_val)
    : name(movie_name), rating(rating_val), watched(0) {}

std::string Movie::get_name() const {
    return name;
}

void Movie::was_watched(int count) {
    watched += count;
}