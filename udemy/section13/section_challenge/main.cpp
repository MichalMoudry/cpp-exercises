#include <iostream>
#include <ostream>
#include <string>
#include "Movie.h"
#include "Movies.h"

/*
Program to track movie watching.

The program must support the following:
class Movie - models a movie that includes
- movie name
- movie rating
- watched (number of times movie has been watched)

class Movies - models a collection of movie objects

Obviously, Movies needs to know about Movie since it is a collection of Movice
object. However, our main driver should only interact with the Movie class.
For example:
- create a Movies object
- ask the Movies object to add a movie by providing the movie name, rating and watched count
- ask the Movies object to increment the watched count by 1 for a movie given its name
- ask the Movies object to display all of its movies

Additionally,
- if we try to add a movie whose name is already in the movies collection we
should display this error to the user
- if we try to increment the watched count for a movie whose name is not in the movies
collection we should display this error to the user

Here is what your project should look like:
- Movie.h - include file file with the Movie class specifiction
- Movie.cpp - file with the Movie class implementation
- Movies.h - include file file with the Movies class specifiction
- Movies.cpp - file with the Movies class implementation
- main.cpp - the main driver that creates a Movies object and adds and increments movies
*/

void handle_input(const std::string input, Movies& movies) {
    if (input.length() == 0) {
        std::cout << "Please, enter a valid input\n";
        return;
    }
    switch (input[0]) {
        case 'q':
        case 'Q':
            std::cout << "Quitting application...\n";
            return;
        case 'a':
        case 'A':
            {
                std::cout << "Enter movie's name: ";
                std::string new_movie {};
                std::getline(std::cin, new_movie);
                auto res {movies.add_movie(new_movie, 0, 0)};
                if (res) {
                    std::cout << new_movie << " was added!\n";
                }
            }
            break;
        case 'd':
        case 'D':
            movies.display_movies();
            break;
        case 'm':
        case 'M':
            {
                std::cout << "Which movie was watched? ";
                std::string watched_movie {};
                std::getline(std::cin, watched_movie);
                auto res {movies.was_watched(watched_movie)};
                if (res) {
                    std::cout << watched_movie << " was successfuly marked as watched!\n";
                }
            }
            break;
        default:
            std::cout << "Error: " << input[0] <<  " is not a valid choice";
            break;
    }
}

int main() {
    /*Movies movies;

    Movie die_hard {"Die hard"};
    std::cout << "Movie is: " << die_hard.get_name() << std::endl;

    movies.add_movie(die_hard.get_name(), 9.5, 0);
    movies.add_movie("Star wars", 9.4, 1);
    movies.display_movies();

    movies.was_watched(die_hard.get_name());
    movies.display_movies();

    movies.add_movie("Star wars", 9.4, 1);
    movies.was_watched("Indiana Jones and the Temple of Doom");*/

    std::string input;
    Movies movies;

    std::cout << "-- Welcome to movie library! --\n";
    movies.display_movies();
    do {
        std::cout << "\nEnter on of the following:\n";
        std::cout << "A - add a movie to the library\n";
        std::cout << "D - display movies in the library\n";
        std::cout << "M - mark movie as watched\n";
        std::cout << "Q - quit\n";
        std::cout << "Your choice: ";
        std::getline(std::cin, input);
        std::cout << "----------------------------------\n";
        handle_input(input, movies);
        std::cout << "----------------------------------";
    } while (input != "q" && input != "Q");
    std::cout << std::endl;
    return 0;
}