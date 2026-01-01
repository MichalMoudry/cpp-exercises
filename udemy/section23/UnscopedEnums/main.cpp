#include <iostream>
#include <type_traits>
#include <vector>
#include <string>

enum Direction { North, South, East, West };

std::string direction_to_str(Direction dir) {
    std::string result;
    switch (dir) {
        case North:
            result = "North";
            break;
        case South:
            result = "South";
            break;
        case East:
            result = "East";
            break;
        case West:
            result = "West";
            break;
        default:
            result = "Unknown direction";
    }

    return result;
}

void test1() {
    std::cout << "Test 1 ====================" << std::endl;
    Direction dir {North};

    std::cout << "Direction: " << dir << std::endl;
    std::cout << direction_to_str(dir) << std::endl;

    dir = Direction(100);
    std::cout << "Direction: " << dir << std::endl;
    std::cout << direction_to_str(dir) << std::endl;

    dir = static_cast<Direction>(100);
    std::cout << "Direction: " << dir << std::endl;
    std::cout << direction_to_str(dir) << std::endl;
}

enum GroceryItem { Milk, Bread, Apple, Orange };

std::ostream& operator<<(std::ostream& os, GroceryItem groceryItem) {
    switch (groceryItem) {
        case Milk:
            os << "Milk";
            break;
        case Bread:
            os << "Bread";
            break;
        case Apple:
            os << "Apple";
            break;
        case Orange:
            os << "Orange";
            break;
        default:
            os << "Unknown grocery item";
    }
    return os;
}

bool is_valid_grocery_item(GroceryItem item) {
    switch (item) {
        case Milk:
        case Bread:
        case Apple:
        case Orange:
            return true;
        default:
            return false;
    }
}

void display_grocery_list(const std::vector<GroceryItem>& groceryList) {
    std::cout << "Grocery list" << "\n====================" << std::endl;
    int invalid_item_count {0};
    int valid_item_count {0};
    for (GroceryItem item : groceryList) {
        std::cout << item << std::endl;
        if (is_valid_grocery_item(item)) {
            valid_item_count += 1;
        }
        else {
            invalid_item_count += 1;
        }
    }

    std::cout << "====================" << std::endl;
    std::cout << "Valid items: " << valid_item_count << std::endl;
    std::cout << "Invalid items: " << invalid_item_count << std::endl;
    std::cout << "Total: " << valid_item_count + invalid_item_count << std::endl;
}

void test2() {
    std::cout << "\nTest 2 ====================" << std::endl;
    std::vector<GroceryItem> shopping_list {Apple, Apple, Milk, Orange};
    int helicopter {100};
    shopping_list.emplace_back(GroceryItem(helicopter));
    shopping_list.emplace_back(GroceryItem(0));

    display_grocery_list(shopping_list);
}

enum State { EngineFailure, InclementWeather, Nominal, Unknown };
enum Sequence { Abort, Hold, Launch };

std::istream& operator>>(std::istream& is, State& state) {
    std::underlying_type_t<Sequence> user_input;
    is >> user_input;
    switch (user_input) {
        case EngineFailure:
        case InclementWeather:
        case Unknown:
        case Nominal:
            state = State(user_input);
            break;
        default:
            std::cout << "User input is not a valid launch state" << std::endl;
            state = Unknown;
    }

    return is;
}

std::ostream& operator<<(std::ostream& os, const Sequence& seq) {
    switch (seq) {
        case Abort:
            os << "Abort";
            break;
        case Hold:
            os << "Hold";
            break;
        case Launch:
            os << "Launch";
            break;
    }

    return os;
}

void test3() {

}

int main() {
    test1();
    test2();

    return 0;
}
