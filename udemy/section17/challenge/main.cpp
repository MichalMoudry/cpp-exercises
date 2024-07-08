#include <iostream>
#include <memory>
#include <vector>

class Test final {
private:
    int data;
public:
    Test() : data{0} {
        std::cout << "\tTest constructor (" << data << ")" << std::endl;
    }
    Test(int new_data) : data{new_data} {
        std::cout << "\tTest constructor (" << data << ")" << std::endl;
    }
    int get_data() const { return data; }
    ~Test() {
        std::cout << "\tTest destructor (" << data << ")" << std::endl;
    }
};

std::unique_ptr<std::vector<std::shared_ptr<Test>>> make() {
    return std::make_unique<std::vector<std::shared_ptr<Test>>>();
}

void fill(std::vector<std::shared_ptr<Test>>& vec, int num) {
    int data;
    for (int i = 1; i <= num; i++) {
        std::cout << "Enter data point [" << i << "]: ";
        std::cin >> data;
        vec.push_back(std::make_shared<Test>(data));
    }
}

void display(const std::vector<std::shared_ptr<Test>>& vec) {
    std::cout << "Vector has the following items: [";
    for (const auto& item : vec) {
        std::cout << item->get_data() << " ";
    }
    std::cout << "]" << std::endl;
}

int main(int argc, char const *argv[]) {
    std::unique_ptr<std::vector<std::shared_ptr<Test>>> vec_ptr {make()};

    std::cout << "How many data points do you want to enter: ";
    int num;
    std::cin >> num;
    fill(*vec_ptr, num);

    display(*vec_ptr);

    return 0;
}
