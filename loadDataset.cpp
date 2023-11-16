#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <sstream>

struct MyData {
    int userFollowerCount;
    int userFollowingCount;
    int userBiographyLength;
    int userMediaCount;
    int userHasProfilePic;
    int userIsPrivate;
    int userNameDigitCount;
    int usernameLength;
    int isFake;
    int mediaLikeNumbers;
    int mediaCommentNumbers;
    int mediaCommentsAreDisabled;
    int mediaHashtagNumbers;
    std::string mediaUploadTimes;
    int mediaHasLocationInfo;
    int userHasHighlightReels;
    int userHasExternalUrl;
    int userTagsCount;
    int automatedBehaviour;
    int target;
};

std::vector<MyData> loadCSV(const std::string &filename) {
    std::vector<MyData> data;
    std::ifstream file(filename);
    if (!file.is_open()) {
        std::cerr << "Error: Could not open the CSV file" << std::endl;
        return data;
    }

    std::string line;
    // Read the header line if it contains column names and needs to be skipped
    // getline(file, line);

    while (std::getline(file, line)) {
        MyData record;
        std::stringstream lineStream(line);
        std::string cell;

        // Assuming CSV format: userFollowerCount,userFollowingCount,userBiographyLength,...
        if (std::getline(lineStream, cell, ',')) {
            record.userFollowerCount = std::stoi(cell);
        }
        if (std::getline(lineStream, cell, ',')) {
            record.userFollowingCount = std::stoi(cell);
        }
        if (std::getline(lineStream, cell, ',')) {
            record.userBiographyLength = std::stoi(cell);
        }
        // Repeat this for the remaining columns

        data.push_back(record);
    }

    file.close();
    return data;
}

int main() {
    std::string filename = "merged.csv";
    std::vector<MyData> data = loadCSV(filename);

    // Use the loaded data as needed
    for (const MyData &record : data) {
        // Access the fields in the struct and perform operations
        std::cout << "User Follower Count: " << record.userFollowerCount << ", User Following Count: " << record.userFollowingCount << ", Target: " << record.target << std::endl;
    }

    return 0;
}
