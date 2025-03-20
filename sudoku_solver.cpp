// Write a program to solve a Sudoku puzzle by filling the empty cells.
// A sudoku solution must satisfy all of the following rules:
// Each of the digits 1-9 must occur exactly once in each row.
// Each of the digits 1-9 must occur exactly once in each column.
// Each of the digits 1-9 must occur exactly once in each of the 9 3x3 sub-boxes of the grid.
// The '.' character indicates empty cells.

// Constraints:
// board.length == 9
// board[i].length == 9
// board[i][j] is a digit or '.'.
// It is guaranteed that the input board has only one solution.
#include <iostream>
#include <vector>
#include <stdlib.h>
#include <cmath>
using namespace std;
 
// Cross-platform text color function
void setColor(int textColor) {
#ifdef _WIN32
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(hConsole, textColor);
#else
    const char* colorCode;
    switch(textColor) {
        case 4: colorCode = "\033[1;31m"; break;  // Red
        case 6: colorCode = "\033[1;33m"; break;  // Yellow
        case 2: colorCode = "\033[0;32m"; break;  // green
        default: colorCode = "\033[0m";           // Default color
    }
    cout << colorCode;
#endif
}

// print query
void print(vector<vector<char>>& query) {
     for(int i = 0; i < query.size(); i++) {
    	for(int j = 0; j < query[i].size(); j++) {
    		cout << query[i][j] << " ";
    	}
    	cout << "\n";
    }
    return ;
}

bool isValid(vector<vector<char>>& query, int row, int col, char choice) {
     // row
     for(int i = 0; i < query.size(); i++) {
     	if(query[i][col] == choice) return false;
     }
     // col
     for(int i = 0; i < query[row].size(); i++) {
     	if(query[row][i] == choice) return false;
     }
     // 3*3 block 
     int boxSize = sqrt(query.size());
     int startRow = row - row % boxSize;
     int startCol = col - col % boxSize;
     for(int i = 0; i < boxSize; i++) {
     for(int j = 0; j < boxSize; j++) {
     	if(query[startRow + i][startCol + j] == choice) return false;
     	}
     }
     return true;
}

bool puzzle_solver(vector<vector<char>>& query, int row, int col) {
     // base case
     if(row == query.size()) return true;
     
     if(col == query[row].size()) return puzzle_solver(query, row+1, 0);
     
     if(query[row][col] != '.') {
        return puzzle_solver(query, row, col + 1);
     }
     
     // choices
     for(char i = '1'; i <= '9'; i++) {
     	if(isValid(query, row, col, i)) {
     		query[row][col] = i; // choose
     		if(puzzle_solver(query, row, col+1)) return true;  // move forward 
     	    query[row][col] = '.'; // backtrack;
            }   
     }
     return false;
}

int main() { 
    vector<vector<char>> query = {
    	                          {'5','3','.','.','7','.','.','.','.'},
                                  {'6','.','.','1','9','5','.','.','.'}, 
                                  {'.','9','8','.','.','.','.','6','.'}, 
                                  {'8','.','.','.','6','.','.','.','3'}, 
                                  {'4','.','.','8','.','3','.','.','1'}, 
                                  {'7','.','.','.','2','.','.','.','6'}, 
                                  {'.','6','.','.','.','.','2','8','.'}, 
                                  {'.','.','.','4','1','9','.','.','5'}, 
                                  {'.','.','.','.','8','.','.','7','9'}
    	                         }; 
    setColor(4);
    cout << "Sudoku Puzzle >>>" << endl;
    setColor(6);
    print(query);
    setColor(4);
    cout << "Sudoku solved >>>" << endl;
    setColor(2); 
    
    // function call
    if(puzzle_solver(query, 0, 0)) {
    	print(query);
    } else {
    	setColor(4);
    	cout << "Invalid query" << endl;
    }
    return 0;
}