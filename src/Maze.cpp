
#include "../lib/Maze.hpp"

Maze::Maze(int rows, int cols, int startRow, int endRow)
        : rows(rows), cols(cols), startRow(startRow), endRow(endRow) {
    maze = new Cell*[rows];
    for (int i = 0; i < rows; ++i) {
        maze[i] = new Cell[cols];
        for (int j = 0; j < cols; ++j) {
            maze[i][j] = Cell();
        }
    }
}

Maze Maze::makeMaze(int level) {
    int rows, cols, startRow, endRow;
    std::random_device rd;
    std::mt19937 rand(rd());  // Using the Mersenne Twister random number engine

    switch(level) {
        case 1:
            rows = 5;
            cols = 5;
            break;
        case 2:
            rows = 5;
            cols = 20;
            break;
        case 3:
            rows = 20;
            cols = 20;
            break;
        default:
            throw std::invalid_argument("Invalid maze level provided. Defaulting to 20X20");
            rows = 20;
            cols = 20;
    }

    startRow = rand() % rows;
    endRow = rand() % rows;

    Maze m(rows, cols, startRow, endRow);
    int neighbors[3][2];

    GenericStack<int*> s;
    s.push(new int[2]{startRow, 0});

    while (!s.isEmpty()) {
        int i = 0;
        int* top = s.top();
        int r = top[0];
        int c = top[1];

        // Visit the current cell
        m.maze[r][c].setVisited(true);

        // Check each neighbor

        if (r - 1 >= 0 && !m.maze[r - 1][c].getVisited()) { // up
            neighbors[i][0] = r - 1, neighbors[i++][1] = c;
        }

        if (c - 1 >= 0 && !m.maze[r][c - 1].getVisited()) { // left
            neighbors[i][0] = r, neighbors[i++][1] = c - 1;
        }

        if (r + 1 < rows && !m.maze[r + 1][c].getVisited()) { // down
            neighbors[i][0] = r + 1, neighbors[i++][1] = c;
        }

        if (c + 1 < cols && !m.maze[r][c + 1].getVisited()) { // right
            neighbors[i][0] = r, neighbors[i++][1] = c + 1;
        }

        if (i == 0) {
            s.pop();
            delete[] top;  // Freeing the memory allocated
            continue;
        }

        int next = rand() % i;
        int nr = neighbors[next][0], nc = neighbors[next][1];

        s.push(new int[2]{ nr, nc });

        if (r < nr) { // down
            m.maze[r][nc].setBottom(false);
        }
        else if (r > nr) { // up
            m.maze[nr][nc].setBottom(false);
        }
        else if (c < nc) { // right
            m.maze[nr][c].setRight(false);
        }
        else if (c > nc) { // left
            m.maze[nr][nc].setRight(false);
        }
    }

    // Reset visited attribute back to false
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
            m.maze[i][j].setVisited(false);
        }
    }

    return m;
}

void Maze::printMaze() const {
    int newRows = rows * 2 + 1;
    int newCols = cols * 2 + 1;
    std::string vBorder = "|";
    std::string hBorder = "---";
    std::string vSpace = " ";
    std::string hSpace = "   ";
    std::string star = " * ";

    for (int i = 0; i < newRows; ++i) {
        for (int j = 0; j < newCols; ++j) {
            if ((i == startRow * 2 + 1 && j == 0) || (i == endRow * 2 + 1 && j == newCols - 1)) {
                std::cout << vSpace; // keep start and end open
            } else if (i % 2 == 0) {
                std::cout << (j % 2 == 0 ? vBorder : (i > 0 && !maze[(i - 1) / 2][(j - 1) / 2].getBottom() ? hSpace : hBorder)); // checking conditions as per original logic
            } else {
                std::cout << (j % 2 == 0 ? (j > 0 && !maze[(i - 1) / 2][(j - 1) / 2].getRight() ? vSpace : vBorder) : (maze[i / 2][j / 2].getVisited() ? star : hSpace)); // checking conditions as per original logic
            }
        }
        std::cout << std::endl; // move to the next line after printing each row
    }
}

void Maze::solveMaze() {
    GenericQueue<std::pair<int, int>> q;
    q.add(std::make_pair(startRow, 0));

    while (!q.isEmpty()) {
        auto curr = q.remove();
        int r = curr.first;
        int c = curr.second;

        maze[r][c].setVisited(true);

        if (r == endRow && c == cols - 1) break; // end

        if (r - 1 >= 0 && !maze[r - 1][c].getBottom() && !maze[r - 1][c].getVisited()) {
            q.add(std::make_pair(r - 1, c)); // up
        }

        if (c - 1 >= 0 && !maze[r][c - 1].getRight() && !maze[r][c - 1].getVisited()) {
            q.add(std::make_pair(r, c - 1));  // left
        }

        if (r + 1 < rows && !maze[r][c].getBottom() && !maze[r + 1][c].getVisited()) {
            q.add(std::make_pair(r + 1, c));   // down
        }

        if (c + 1 < cols && !maze[r][c].getRight() && !maze[r][c + 1].getVisited()) {
            q.add(std::make_pair(r, c + 1));    // right
        }
    }

    printMaze();
}

Maze::~Maze() {
    for (int i = 0; i < rows; ++i) {
        delete[] maze[i];
    }
    delete[] maze;
}