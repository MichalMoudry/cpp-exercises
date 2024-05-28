#include <iostream>
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

int main() {
    Movies movies;

    Movie die_hard {"Die hard"};
    std::cout << "Movie is: " << die_hard.get_name() << std::endl;

    movies.add_movie(die_hard.get_name(), 9.5, 0);
    movies.display_movies();
    //movies.was_watched(die_hard.get_name());
    return 0;
}