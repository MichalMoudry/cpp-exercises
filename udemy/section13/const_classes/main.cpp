#include <iostream>
#include <string>

class Player {
private:
    std::string name;
    int health;
    int xp;
public:
    std::string get_name() const {
        return name;
    }
    void set_name(std::string name_val) {
        name = name_val;
    }
    Player();
    Player(std::string name_val);
    Player(std::string name_val, int health_val, int xp_val);
};

Player::Player() : Player{"None", 0, 0} {
}
Player::Player(std::string name_val) : Player {name_val, 0, 0} {
}
Player::Player(std::string name_val, int health_val, int xp_val)
    : name(name_val), health(health_val), xp(xp_val) {}

void display_player_name(const Player& player) {
    std::cout << player.get_name() << std::endl;
}

int main() {
    const Player player1 {"Player 1", 100, 55};
    Player player2 {"Player 2", 100, 15};

    display_player_name(player1);
    display_player_name(player2);
    return 0;
}