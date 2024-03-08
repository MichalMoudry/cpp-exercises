#include <iostream>
#include <vector>

using namespace std;

int main() {
    vector<int> nums {10, 20, 30, 40, 50};
    for (unsigned i {0}; i < nums.size(); i++) {
        if (i % 3 == 0)
        {
            cout << nums[i] << endl;
        }
    }
    
    return 0;
}