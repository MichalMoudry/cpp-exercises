#include <iostream>
#include <string>

class Player {
private:
    std::string name;
    int health;
    int xp;
public:
    std::string get_name() {
        return name;
    }
    int get_health() {
        return health;
    }
    int get_xp() {
        return xp;
    }

    Player(std::string name_val = "None", int health_val = 0, int xp_val = 0)
        : name{name_val}, health{health_val}, xp{xp_val} {
        std::cout << "Three-args ctor for: " << name << std::endl;
    }

    Player(const Player& src_player);

    ~Player() {
        std::cout << "Destructor called for: " << name << std::endl;
    }
};

Player::Player(const Player& src_player)
    : name{src_player.name}, health{src_player.health}, xp{src_player.xp} {
    std::cout << "Copy ctor - made copy of " << src_player.name << std::endl;
}

void display_player(Player p) {
    std::cout << "Name: " << p.get_name() << std::endl;
    std::cout << "Health: " << p.get_health() << std::endl;
    std::cout << "XP: " << p.get_xp() << std::endl;
    std::cout << "----------------------\n";
}

int main() {
    std::cout << "Running copy_ctor file" << std::endl;
    Player empty;
    display_player(empty);

    Player test1 {"Test 1"};
    display_player(test1);
    Player test2 {"Test 2", 100};
    display_player(test2);
    Player test3 {"Test 3", 100, 55};
    display_player(test3);
    return 0;
}