#include <iostream>
#include <string>

class Player {
private:
    std::string name;
    int health;
    int xp;
public:
    /*Player() {
        name = "None";
        health = 100;
        xp = 0;
    }*/
    Player(std::string name_val, int health_val, int xp_val) {
        name = name_val;
        health = health_val;
        xp = xp_val;
    }
    void set_name(std::string name_val) {
        name = name_val;
    }
    std::string get_name() {
        return name;
    }
    int get_health() {
        return health;
    }
};

int main() {
    //Player test_player;
    Player test_player {"Test 1", 101, 0};
    test_player.set_name("Test 1");
    std::cout << test_player.get_name() << " | health: " << test_player.get_health() << std::endl;
    return 0;
}