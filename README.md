# Sudoku Solver

This project is a **Sudoku Solver** implemented in C++. The program takes a 9x9 Sudoku puzzle as input, solves it using backtracking, and displays the solved puzzle with color-coded output for better visualization.

## Features
✅ Efficient backtracking algorithm for solving Sudoku puzzles.  
✅ Validates Sudoku rules for rows, columns, and 3x3 grids.  
✅ Cross-platform console color support for enhanced output.  
✅ Clear code structure for readability and maintainability.

## Getting Started

### Prerequisites
- C++ Compiler (e.g., g++)
- Compatible terminal (for color-coded output support)

### Installation
1. Clone the repository:
   ```bash
   git clone <repository_url>
   cd sudoku-solver
   ```
2. Compile the code using g++:
   ```bash
   g++ -std=c++11 sudoku_solver.cpp -o sudoku_solver.out
   ```
3. Run the compiled program:
   ```bash
   ./sudoku_solver.out
   ```

## Code Explanation

### Key Functions
- **`print()`**: Displays the Sudoku grid.
- **`isValid()`**: Checks if a number can be placed at a specific position by validating the row, column, and 3x3 grid.
- **`puzzle_solver()`**: The core backtracking algorithm that recursively solves the Sudoku puzzle.
- **`setColor()`**: Cross-platform text color function for improved console output.

### Sample Sudoku Puzzle
```
5 3 . . 7 . . . .
6 . . 1 9 5 . . .
. 9 8 . . . . 6 .
8 . . . 6 . . . 3
4 . . 8 . 3 . . 1
7 . . . 2 . . . 6
. 6 . . . . 2 8 .
. . . 4 1 9 . . 5
. . . . 8 . . 7 9
```

### Expected Output
```
Sudoku Puzzle >>>
5 3 . . 7 . . . .
6 . . 1 9 5 . . .
. 9 8 . . . . 6 .
8 . . . 6 . . . 3
4 . . 8 . 3 . . 1
7 . . . 2 . . . 6
. 6 . . . . 2 8 .
. . . 4 1 9 . . 5
. . . . 8 . . 7 9

Sudoku Solved >>>
5 3 4 6 7 8 9 1 2
6 7 2 1 9 5 3 4 8
1 9 8 3 4 2 5 6 7
8 5 9 7 6 1 4 2 3
4 2 6 8 5 3 7 9 1
7 1 3 9 2 4 8 5 6
9 6 1 5 3 7 2 8 4
2 8 7 4 1 9 6 3 5
3 4 5 2 8 6 1 7 9
```

## Constraints
- `board.length == 9`
- `board[i].length == 9`
- Each cell in the board is either a digit ('1'-'9') or a '.' indicating an empty cell.
- The puzzle is guaranteed to have exactly one solution.

## License
This project is open-source and available for use under the [MIT License](LICENSE).

## Contact
For any inquiries or improvements, feel free to reach out via [GitHub](https://github.com/rudxkush).

