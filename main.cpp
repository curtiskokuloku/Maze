#include <iostream>
#include <cstdlib>  // for system()
#include <ctime>    // for time()

#include "lib/Maze.hpp"


int main() {
    // Seed the random number generator
    std::srand(static_cast<unsigned int>(std::time(nullptr)));

    int level;
    std::cout << "Enter the maze level (1-3): ";
    std::cin >> level;

    try {
        Maze m = Maze::makeMaze(level);

        std::cout << "Generated Maze:\n";
        m.printMaze();

        std::cout << "\nSolved Maze:\n";
        m.solveMaze();
    } catch (const std::exception& e) {
        std::cerr << "Error: " << e.what() << std::endl;
        return 1;  // Return 1 to indicate an error occurred
    }

    return 0;
}
