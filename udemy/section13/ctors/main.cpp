#include <cstdio>
#include <iostream>
#include <string>

class Player {
private:
    std::string name;
    int health;
    int xp;

public:
    void set_name(std::string val) {
        name = val;
    }

    Player() {
        std::cout << "No arg ctor called" << std::endl;
    }

    Player(std::string name_val) {
        std::cout << "One arg ctor called" << std::endl;
    }

    Player(std::string init_name, int init_health, int init_xp) {
        std::cout << "All arg ctor called" << std::endl;
    }

    ~Player() {
        std::cout << "Destructor called for " << name << std::endl;
    }
};

int main() {
    {
        Player test_player;
        test_player.set_name("Test");
    }
    std::printf("------\n");
    {
        Player test_player;
        test_player.set_name("Test");
        Player test_player_2;
        test_player_2.set_name("Test 2");
        Player test_player_3 {"Test 3", 100, 2};
        test_player_3.set_name("Test 3");
    }
    std::printf("------\n");

    Player* test_player = new Player();
    test_player->set_name("Test poiner");

    Player* test_player_2 = new Player("Test pointer 2", 1'000, 300);
    test_player_2->set_name("Test pointer 2");

    delete test_player;
    delete test_player_2;
    return 0;
}