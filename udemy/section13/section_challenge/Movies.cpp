#include "Movies.h"
#include "Movie.h"
#include <iostream>

bool Movies::add_movie(std::string name, double rating, int watched) {
    if (name == "") {
        return false;
    }
    for (const auto& movie : movies) {
        if (movie.get_name() == name) {
            std::cout << "Error: " << name << " already exists in the library" << std::endl;
            return false;
        }
    }
    movies.push_back(Movie {name, rating, watched});
    return true;
}

bool Movies::was_watched(std::string movie_name) {
    Movie* movie_to_watch {nullptr};
    for (auto& movie : movies) {
        if (movie.get_name() == movie_name) {
            movie_to_watch = &movie;
        }
    }
    if (movie_to_watch == nullptr) {
        std::cout << "Error: " << movie_name << " doesn't exist in the library \n";
        return false;
    }
    movie_to_watch->was_watched();
    return true;
}

void Movies::display_movies() const {
    std::cout << "Current movies are:" << std::endl;
    if (movies.size() == 0) {
        std::cout << "\tThere are no movies in the library\n";
        return;
    }
    for (const auto& movie : movies) {
        std::cout
            << "\t- " << movie.get_name()
            << " | Rating: " << movie.get_rating()
            << " | Watched: " << movie.get_watched_count()
            << std::endl;
    }
}