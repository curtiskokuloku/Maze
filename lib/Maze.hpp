
#ifndef MAZE_HPP
#define MAZE_HPP

// Including necessary headers for dependencies
#include "iostream"
#include <cstdlib>
#include <random>

#include "Cell.hpp"
#include "GenericStack.hpp"
#include "GenericQueue.hpp"

/**
 * @brief Represents a maze structure with functionalities to generate, print, and solve the maze.
 *
 * The Maze class provides functionalities to create, print, and solve a maze.
 * It uses the Cell class to represent individual cells within the maze and
 * employs Stack1Gen and Q1Gen templates for stack and queue operations, respectively.
 */
class Maze {
public:
    /**
     * @brief Constructor to initialize a MyMaze object.
     *
     * @param rows Total number of rows for the maze.
     * @param cols Total number of columns for the maze.
     * @param startRow Row index of the maze entrance.
     * @param endRow Row index of the maze exit.
     */
    Maze(int rows, int cols, int startRow, int endRow);

    /**
     * @brief Static method to generate a maze based on the specified level.
     *
     * @param level Difficulty level determining maze dimensions.
     *              Level 1: 5x5, Level 2: 5x20, Level 3: 20x20.
     * @return MyMaze object representing the generated maze.
     */
    static Maze makeMaze(int level);

    /**
     * @brief Method to print the current state of the maze to the console.
     *
     * This method prints the maze structure to the console, representing
     * cells, walls, and paths. The start and end points are also highlighted.
     */
    void printMaze() const;

    /**
     * @brief Method to solve the maze from the starting point to the ending point.
     *
     * This method employs an algorithm to find a path from the starting
     * point to the ending point within the maze. Once the path is found,
     * it can be visualized using printMaze().
     */
    void solveMaze();

    /**
     * Destructor to clean up memory to avoid memory leaks
     */
     ~Maze();

private:
    /**
     * 2D array representing the maze grid.
     */
    Cell** maze;

    /**
     * Number of rows in the maze.
     */
    int rows;

    /**
     * Number of columns in the maze.
     */
    int cols;

    /**
     * Row index for the maze's starting point.
     */
    int startRow;

    /**
     * Row index for the maze's ending point.
     */
    int endRow;
};

#endif //MAZE_HPP
