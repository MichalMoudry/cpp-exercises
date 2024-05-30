#include "Movie.h"
#include <string>

Movie::Movie(std::string movie_name) : Movie(movie_name, 0) {}

Movie::Movie(std::string movie_name, double rating_val)
    : name(movie_name), rating(rating_val), watched(0) {}

Movie::Movie(std::string movie_name, double rating_val, int watched_val)
    : name(movie_name), rating(rating_val), watched(watched_val) {}

std::string Movie::get_name() const {
    return name;
}

double Movie::get_rating() const {
    return rating;
}

int Movie::get_watched_count() const {
    return watched;
}

void Movie::was_watched(int count) {
    watched += count;
}