#include <iostream>
#include <string>

template<typename T, int N>
class Array {
    int size {N};
    T values[N];

    friend std::ostream& operator<<(std::ostream& os, const Array<T, N>& arr) {
        os << "[ ";
        for (const auto& item : arr.values) {
            os << item << " ";
        }
        os << "]" << std::endl;
        return os;
    }
public:
    Array() = default;
    Array(T init_val) {
        for (auto& item : values) {
            item = init_val;
        }
    }

    void fill(T val) {
        for (auto& item : values) {
            item = val;
        }
    }

    int get_size() const {
        return size;
    }

    T& operator[](int index) {
        return values[index];
    }
};

int main() {
    Array<int, 5> nums;
    std::cout << "The size of nums is: " << nums.get_size() << std::endl;
    std::cout << nums << std::endl;

    nums.fill(0);
    std::cout << "The size of nums is: " << nums.get_size() << std::endl;
    std::cout << nums << std::endl;

    nums[3] = 2'000;
    std::cout << nums << std::endl;

    Array<int, 100> nums2 {1};
    std::cout << "The size of nums is: " << nums2.get_size() << std::endl;
    std::cout << nums2 << std::endl;

    Array<std::string, 5> texts {"-/"};
    texts[2] = std::string{"🚀"};
    std::cout << texts << std::endl;

    return 0;
}