#include <iostream>
#include <iomanip>
#include <string>
#include <list>
#include <sstream>

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
    std::string artist;
    int rating;
public:
    Song() = default;
    Song(std::string song_name, std::string song_artist, int song_rating)
        : name{song_name}, artist{song_artist}, rating{song_rating} {}
    std::string get_name() const {
        return name;
    }
    std::string get_artist() const {
        return artist;
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
        << std::setw(30) << std::left << song.artist
        << std::setw(2) << std::left << song.rating;
    return os;
}

void display_playlist(
    std::list<Song>& playlist,
    Song& current) {
    for (const auto& song : playlist) {
        std::cout << song << std::endl;
    }
    std::cout << "Current song:\n" << current << std::endl;
}

void display_menu() {
    std::cout << "F - Play first song" << std::endl;
    std::cout << "N - Play next song" << std::endl;
    std::cout << "P - Play previous song" << std::endl;
    std::cout << "A - Add and play a new song at current location" << std::endl;
    std::cout << "L - List the current playlist" << std::endl;
    std::cout << "====================================" << std::endl;
    std::cout << "Enter a selection (Q to quit): ";
}

void add_song(
    std::list<Song>& playlist,
    std::list<Song>::iterator& current_song) {
    std::string song_name {};
    std::cout << "Enter song name: ";
    std::getline(std::cin, song_name);
    if (song_name == "") {
        std::cout << "Empty song name..." << std::endl;
        return;
    }

    std::string artist {};
    std::cout << "Enter song's artist: ";
    std::getline(std::cin, artist);
    if (artist == "") {
        std::cout << "Empty artist name..." << std::endl;
        return;
    }

    std::string entry {};
    int rating {};
    std::cout << "Enter song's rating: ";
    std::getline(std::cin, entry);
    std::istringstream validator {entry};
    if (validator >> rating && rating <= 5 && rating >= 0) {
        playlist.emplace(current_song, song_name, artist, rating);
        current_song--;
        std::cout << "\nAdded a new song:\n" << *current_song << std::endl;
    }
    else {
        std::cout << "\n" << entry << " is not a valid rating" << std::endl;
    }
}

void handle_user_input(
    const std::string& input,
    std::list<Song>& playlist,
    std::list<Song>::iterator& current_song) {
    if (input == "F" || input == "f") {
        current_song = playlist.begin();
        std::cout << "\nSwitched to " << *current_song << std::endl;
    }
    else if (input == "N" || input == "n") {
        if (current_song == --playlist.end()) {
            current_song = playlist.begin();
        }
        else {
            current_song++;
        }
        std::cout << "\nSwitched to " << *current_song << std::endl;
    }
    else if (input == "P" || input == "p") {
        if (current_song == playlist.begin()) {
            current_song--;
        }
        current_song--;
        std::cout << "\nSwitched to " << *current_song << std::endl;
    }
    else if (input == "A" || input == "a") {
        add_song(playlist, current_song);
    }
    else if (input == "L" || input == "l") {
        display_playlist(playlist, *current_song);
    }
    else if (input != "Q" && input != "q") {
        std::cout << "Incorrect input..." << std::endl;
    }
}

int main() {
    std::string input;
    std::list<Song> playlist {
        { "New York", "Frank Sinatra", 4 },
        { "Never Be The Same", "Camilla Cabello", 5 },
        { "Whatever It Takes", "Imagine Dragons", 5 }
    };

    auto current_song {playlist.begin()};

    display_playlist(playlist, *current_song);
    std::cout << std::endl;
    do {
        display_menu();
        std::getline(std::cin, input);
        handle_user_input(input, playlist, current_song);
        std::cout << std::endl;
    } while (input != "q" && input != "Q");
    return 0;
}