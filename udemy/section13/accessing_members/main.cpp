#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Player {
public:
    // attributes
    string name;
    int health {100};
    int xp {0};

    // methods
    void talk(string text) {
        cout << name << ": " << text << endl;
    }
    bool is_dead();
};

class Account {
public:
    string name;
    double balance {0};

    bool deposit(double val) {
        balance += val;
        return true;
    }
    bool withdraw(double val) {
        balance -= val;
        return true;
    }
};

int main() {
    Player test_player;
    test_player.name = "Michal";
    test_player.health = 100;
    test_player.xp = 12;
    cout << test_player.name << endl << test_player.health << endl;
    test_player.talk("Hello, there!");

    auto point_player {new Player()};
    point_player->name = "Pointer player";
    point_player->talk("hello");
    delete point_player;

    Account test_account;
    test_account.name = "Test account";
    test_account.balance = 5'000;
    test_account.deposit(1'000);
    test_account.withdraw(500);
    cout << test_account.name << " has balance: " << test_account.balance << endl;
    return 0;
}