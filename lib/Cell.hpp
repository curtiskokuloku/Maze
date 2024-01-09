
#ifndef CELL_HPP
#define CELL_HPP

/**
 * @brief A representation of a Cell in a Maze.
 *
 * Each cell can have a visited status, a right boundary, and a bottom boundary.
 */
class Cell {
public:
    /**
     * @brief Default Constructor.
     *
     * Initializes the cell with all boundaries set.
     */
    Cell() : visited(false), right(true), bottom(true) {}

    /**
     * @brief Set the visited status of the cell.
     *
     * @param visited The visited status to set.
     */
    void setVisited(bool v) {
        this->visited = v;
    }

    /**
     * @brief Set the right boundary of the cell.
     *
     * @param right The right boundary to set.
     */
    void setRight(bool r) {
        this->right = r;
    }

    /**
     * @brief Set the bottom boundary of the cell.
     *
     * @param bottom The bottom boundary to set.
     */
    void setBottom(bool v) {
        this->bottom = v;
    }

    /**
     * @brief Get the visited status of the cell.
     *
     * @return The visited status of the cell.
     */
    [[nodiscard]] bool getVisited() const {
        return this->visited;
    }

    /**
     * @brief Get the right boundary status of the cell.
     *
     * @return The right boundary status of the cell.
     */
    [[nodiscard]] bool getRight() const {
        return this->right;
    }

    /**
     * @brief Get the bottom boundary status of the cell.
     *
     * @return The bottom boundary status of the cell.
     */
    [[nodiscard]] bool getBottom() const {
        return this->bottom;
    }

private:
    /**
     * Determines whether the cell has been visited (true if visited, false if not visited)
     */
    bool visited;

    /**
     * Determines whether the cell has a right boundary (true if a right boundary, false if an open right)
     */
    bool right;

    /**
     * Determines whether the cell has a bottom boundary (true if a bottom boundary, false if an open bottom)
     */
    bool bottom;

};

#endif //CELL_HPP
