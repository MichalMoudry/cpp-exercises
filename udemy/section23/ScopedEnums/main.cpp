#include <iostream>
#include <type_traits>

enum struct GroceryItem { Milk = 350, Bread = 250, Apple = 132, Orange = 100 };

std::ostream& operator<<(std::ostream& os, const GroceryItem& item) {
    auto val {std::underlying_type_t<GroceryItem>(item)};
    switch (item) {
        case GroceryItem::Milk:
            os << "Milk";
            break;
        case GroceryItem::Bread:
            os << "Bread";
            break;
        case GroceryItem::Apple:
            os << "Apple";
            break;
        case GroceryItem::Orange:
            os << "Orange";
            break;
        default:
            os << "Invalid item";
    }
    os << ": " << val;

    return os;
}

bool is_valid_grocery_item(GroceryItem item) {
    switch (item) {
        case GroceryItem::Milk:
        case  GroceryItem::Bread:
        case GroceryItem::Apple:
        case GroceryItem::Orange:
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

void test1() {
    std::cout << "\nTest 1 ====================" << std::endl;
    std::vector<GroceryItem> shopping_list {
        GroceryItem::Apple,
        GroceryItem::Milk,
        GroceryItem::Orange
    };
    int helicopter {100};
    shopping_list.emplace_back(GroceryItem(helicopter));
    shopping_list.emplace_back(GroceryItem(0));

    display_grocery_list(shopping_list);
}

void test2() {

}

int main() {
    test1();
    test2();

    return 0;
}
