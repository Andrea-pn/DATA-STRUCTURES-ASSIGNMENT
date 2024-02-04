#include <iostream>
#include <vector>

int summation(const std::vector<int>& arr) {
    int sum = 0;
    for (int num : arr) {
        sum += num;
    }
    return sum;
}

int maximum(const std::vector<int>& arr) {
    int max_num = arr[0];
    for (int num : arr) {
        if (num > max_num) {
            max_num = num;
        }
    }
    return max_num;
}

int main() {
    // Get the length of the array from the user
    int n;
    std::cout << "Enter the length of the array: ";
    std::cin >> n;

    // Initialize a vector to store the integers
    std::vector<int> integer_array;

    // Allow the user to enter n integers and store them in the vector
    for (int i = 0; i < n; ++i) {
        int num;
        std::cout << "Enter integer #" << i + 1 << ": ";
        std::cin >> num;
        integer_array.push_back(num);
    }

    // Call the summation function
    int sum_result = summation(integer_array);
    std::cout << "Sum of the integers: " << sum_result << std::endl;

    // Call the maximum function
    int max_result = maximum(integer_array);
    std::cout << "Maximum integer in the array: " << max_result << std::endl;

    return 0;
}
