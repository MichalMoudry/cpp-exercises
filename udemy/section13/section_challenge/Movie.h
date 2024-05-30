#ifndef _MOVIE_H_
#define _MOVIE_H_
#include <string>

class Movie {
private:
    std::string name;
    double rating;
    int watched;
public:
    std::string get_name() const;
    double get_rating() const;
    int get_watched_count() const;
    void was_watched(int count = 1);
    Movie(std::string movie_name, double rating_val, int watched);
    Movie(std::string movie_name, double rating_val);
    Movie(std::string movie_name);
};

#endif