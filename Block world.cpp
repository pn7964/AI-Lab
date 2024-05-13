#include <iostream>
#include <unordered_map>
#include <vector>
#include <string>

using namespace std;

class BlocksWorld {
private:
    unordered_map<string, string> table; // Mapping of blocks to their positions

public:
    void addBlock(string block, string position) {
        table[block] = position;
    }

    void moveBlock(string block, string destination) {
        table[block] = destination;
    }

    void printState() {
        for (const auto& entry : table) {
            cout << entry.first << " is at " << entry.second << endl;
        }
    }
};

int main() {
    BlocksWorld world;

    // Initial state
    world.addBlock("A", "table");
    world.addBlock("B", "table");
    world.addBlock("C", "table");

    // Moving blocks
    world.moveBlock("A", "on B");
    world.moveBlock("C", "on A");

    // Print final state
    world.printState();

    return 0;
}