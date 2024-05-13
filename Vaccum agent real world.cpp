#include <iostream>
#include <string>

class VacuumCleaner {
private:
    std::string location;
public:
    VacuumCleaner(std::string initial_location) : location(initial_location) {}

    void clean() {
        std::cout << "Vacuum cleaner is cleaning at location " << location << std::endl;
        std::cout << "Cleaning complete." << std::endl;
    }

    void move(std::string new_location) {
        std::cout << "Moving vacuum cleaner from " << location << " to " << new_location << std::endl;
        location = new_location;
    }
};

int main() {
    VacuumCleaner vc("Home");

    while (true) {
        vc.clean();
        std::string move_to;
        std::cout << "Enter location to move (A/B) or 'quit' to exit: ";
        std::cin >> move_to;
        if (move_to == "quit") {
            break;
        }
        vc.move(move_to);
    }

    return 0;
}
