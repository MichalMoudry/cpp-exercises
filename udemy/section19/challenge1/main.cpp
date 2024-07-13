#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>
#include <memory>

struct StudentResponse {
    int score;
    std::string name;
};

int main(int argc, char const *argv[]) {
    std::ifstream in_file;
    in_file.open("./udemy/section19/challenge1/responses.txt");

    if (!in_file.is_open()) {
        std::cerr << "Error opening file" << std::endl;
        return 1;
    }

    std::string correct_answers {};
    in_file >> correct_answers;

    std::string line;
    std::unique_ptr<StudentResponse> response;
    std::vector<std::unique_ptr<StudentResponse>> responses {};
    double score_sum {};
    int line_index {0};

    while (std::getline(in_file, line)) {
        response = std::make_unique<StudentResponse>();
        if (line_index % 2 == 0) {
            for (int i = 0; i < correct_answers.length(); i++) {
                if (line.at(i) == correct_answers.at(i)) {
                    responses.at(line_index / 2 - 1)->score += 1;
                    score_sum += 1;
                }
            }
        } else {
            response->name = line;
            responses.push_back(std::move(response));
        }

        line_index += 1;
    }

    std::cout
        << std::setw(20) << std::left << "Student"
        << std::setw(5) << std::left << "Score"
        << std::endl;
    std::cout << std::setfill('-') << std::setw(26) << "" << std::endl;
    std::cout << std::setfill(' ');

    for (auto& response : responses) {
        std::cout
            << std::setw(20) << std::left << response->name
            << std::setw(3) << std::right << response->score
            << std::endl;
    }

    std::cout << std::setfill('-') << std::setw(26) << "" << std::endl;
    std::cout << std::setfill(' ');

    size_t student_number {responses.size()};
    std::cout
        << std::setw(20) << std::left << "Average score"
        << std::setw(3) << std::right << (student_number != 0 ? score_sum / student_number : 0)
        << std::endl;

    in_file.close();
    return 0;
}
