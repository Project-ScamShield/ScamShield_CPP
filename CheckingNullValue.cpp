#include <iostream>
#include <vector>
#include <string>

// Define a structure to represent a DataFrame
struct DataFrame {
    std::vector<std::string> columns;
    std::vector<std::vector<double>> data;
};

int main() {
    // Create a DataFrame (simplified example)
    DataFrame df;
    df.columns = {"userFollowerCount", "userFollowingCount", "userBiographyLength", "userMediaCount", "userIsPrivate", "usernameDigitCount", "usernameLength"};
    df.data = {
        {1000, 500, 150, 50, 1, 2, 10},
        {2000, 800, 120, 30, 0, 3, 15},
        {500, 200, 80, 10, 1, 1, 8}
    };

    // Check for null values and replace with 0
    for (size_t col = 0; col < df.columns.size(); col++) {
        for (size_t row = 0; row < df.data.size(); row++) {
            if (df.data[row][col] == -1) { // Assuming -1 represents a null value
                df.data[row][col] = 0; // Replace null value with 0
            }
        }
    }

    // Print the updated DataFrame
    for (size_t col = 0; col < df.columns.size(); col++) {
        std::cout << df.columns[col] << "\t";
    }
    std::cout << "\n";

    for (size_t row = 0; row < df.data.size(); row++) {
        for (size_t col = 0; col < df.columns.size(); col++) {
            std::cout << df.data[row][col] << "\t";
        }
        std::cout << "\n";
    }

    return 0;
}
