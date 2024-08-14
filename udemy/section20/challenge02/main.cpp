#include <iostream>
#include <iomanip>
#include <string>

/*
Using std::list

Create a menu driven application that will simulate a user playing songs from
a playlist of songs.

We will use a list to simulate the user selecting the first song in the playlist
then selecting next and previous to play forward or backwards through the playlist.

We will also allow users to add new song to the playlist and they will be added
prior to the currently playing song.

The menu looks as follows:
F - Play first song
N - Play next song
P - Play previous song
A - Add and play a new Song at current location
L - List the current playlist
====================================
Enter a selection (Q to quit):
*/

class Song final {
private:
    friend std::ostream& operator<<(std::ostream& os, const Song& song);
    std::string name;
    std::string author;
    int rating;
public:
    std::string get_name() const {
        return name;
    }
    std::string get_author() const {
        return author;
    }
    int get_rating() const {
        return rating;
    }

    bool operator<(const Song& rhs) const {
        return this->name < rhs.name;
    }

    bool operator==(const Song& rhs) const {
        return this->name == rhs.name;
    }
};

std::ostream& operator<<(std::ostream& os, const Song& song) {
    os
        << std::setw(20) << std::left << song.name
        << std::setw(20) << std::left << song.author
        << std::setw(20) << std::left << song.rating;
    return os;
}

void display_menu() {
    std::cout << "F - Play first song" << std::endl;
    std::cout << "N - Play next song" << std::endl;
    std::cout << "P - Play previous song" << std::endl;
    std::cout << "A - Add and play a new song at current location" << std::endl;
    std::cout << "L - List the current playlist" << std::endl;
}

int main() {
    std::string input;
    return 0;
}