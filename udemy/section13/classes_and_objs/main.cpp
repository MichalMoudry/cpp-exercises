#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Player {
    // attributes
    string name;
    int health {100};
    int xp {0};

    // methods
    void talk(string);
    bool is_dead();
};

class Account {
    string name;
    double balance {0};

    bool deposit(double);
    bool withdraw(double);
};

int main() {
    Player michal;
    Player temp;

    Player players[] {michal, temp};
    vector<Player> player_vec {michal};
    player_vec.push_back(temp);

    Player* test {nullptr};
    test = new Player;
    delete test;

    auto test_account {new Account};
    return 0;
}