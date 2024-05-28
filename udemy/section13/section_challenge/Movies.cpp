#include <iostream>
#include "Movies.h"
#include "Movie.h"

void Movies::add_movie(std::string name, double rating, int watched) {
    movies.push_back(Movie {name, rating, watched});
}

void Movies::display_movies() const {
    std::cout << "Current movies are:" << std::endl;
    for (const auto& movie : movies) {
        std::cout << "\t- " << movie.get_name() << std::endl;
    }
}