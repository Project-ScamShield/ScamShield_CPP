#include <iostream>
#include <vector>
#include <algorithm>
#include <random>

int main() {
    // Create a simplified dataset (features and target values)
    std::vector<std::vector<double>> features = {
        {1000, 500, 150, 50, 1, 2, 10},
        {2000, 800, 120, 30, 0, 3, 15},
        // Add more data...
    };

    std::vector<int> target = {1, 0, 1, 0}; // Example target values

    // Set the random seed for reproducibility
    std::mt19937 rng(42);
    std::shuffle(features.begin(), features.end(), rng);
    std::shuffle(target.begin(), target.end(), rng);

    // Split the dataset into training and test sets (75% training, 25% test)
    size_t split = features.size() * 0.75;
    std::vector<std::vector<double>> X_train(features.begin(), features.begin() + split);
    std::vector<int> y_train(target.begin(), target.begin() + split);
    std::vector<std::vector<double>> X_test(features.begin() + split, features.end());
    std::vector<int> y_test(target.begin() + split, target.end());

    // Print the training and test sets
    std::cout << "Training Set:\n";
    for (size_t i = 0; i < X_train.size(); i++) {
        for (size_t j = 0; j < X_train[i].size(); j++) {
            std::cout << X_train[i][j] << "\t";
        }
        std::cout << "Label: " << y_train[i] << "\n";
    }

    std::cout << "Test Set:\n";
    for (size_t i = 0; i < X_test.size(); i++) {
        for (size_t j = 0; j < X_test[i].size(); j++) {
            std::cout << X_test[i][j] << "\t";
        }
        std::cout << "Label: " << y_test[i] << "\n";
    }

    return 0;
}
