#include <iostream>
#include <algorithm>
#include <cmath>
#include <climits>
#include <vector>
using namespace std;

//NOT PASSING ALL TEST CASES.

bool DFS (vector<vector<char> > board, bool ** visited, string str, char endLetter, int rowIndex, int colIndex,  int maxRowIndex, int maxColIndex) {
    if (str[0] == endLetter) {
        return true;
    }
    visited[rowIndex][colIndex] = true;
    
    //1
    if ((rowIndex - 1 >= 0) && (board[rowIndex - 1][colIndex] == str[1]) && (visited[rowIndex - 1][colIndex] == false)) {
        bool ans = DFS(board, visited, str.substr(1), 'A', rowIndex - 1, colIndex, maxRowIndex, maxColIndex);   //rI - 1, cI
        if (ans == true) {
            return ans;
        }
        visited[rowIndex - 1][colIndex] = false;
    }//2
    if ((rowIndex - 1 >= 0) && (colIndex + 1 <= maxColIndex) && (board[rowIndex - 1][colIndex + 1] == str[1]) && (visited[rowIndex - 1][colIndex + 1] == false)) {
        bool ans = DFS(board, visited, str.substr(1), 'A', rowIndex - 1, colIndex + 1, maxRowIndex, maxColIndex);   // rI - 1, cI + 1
        if (ans == true) {
            return ans;
        }
        visited[rowIndex - 1][colIndex + 1] = false;
    }//3
    if ((colIndex + 1 <= maxColIndex) && (board[rowIndex][colIndex + 1] == str[1]) && (visited[rowIndex][colIndex + 1] == false)) {
        bool ans = DFS(board, visited, str.substr(1), 'A', rowIndex, colIndex + 1, maxRowIndex, maxColIndex);   // rI, cI + 1
        if (ans == true) {
            return ans;
        }
        visited[rowIndex][colIndex + 1] = false;
    }//4
    if ((rowIndex + 1 <= maxRowIndex) && (colIndex + 1 <= maxColIndex) && (board[rowIndex + 1][colIndex + 1] == str[1]) && (visited[rowIndex + 1][colIndex + 1] == false)) {
        bool ans = DFS(board, visited, str.substr(1), 'A', rowIndex + 1, colIndex + 1, maxRowIndex, maxColIndex);  // rI + 1, cI + 1
        if (ans == true) {
            return ans;
        }
        visited[rowIndex + 1][colIndex + 1] = false;
    }//5
    if ((rowIndex + 1 <= maxRowIndex) && (board[rowIndex + 1][colIndex] == str[1]) && (visited[rowIndex + 1][colIndex] == false)) {
        bool ans = DFS(board, visited, str.substr(1), 'A', rowIndex + 1, colIndex, maxRowIndex, maxColIndex);  //rI + 1, cI
        if (ans == true) {
            return ans;
        }
        visited[rowIndex + 1][colIndex] = false;
    }//6
    if ((rowIndex + 1 <= maxRowIndex) && (colIndex - 1 >= 0) && (board[rowIndex + 1][colIndex - 1]) && (visited[rowIndex + 1][colIndex - 1] == false)) {
        bool ans = DFS(board, visited, str.substr(1), 'A', rowIndex + 1, colIndex - 1, maxRowIndex, maxColIndex);  //rI + 1, cI - 1
        if (ans == true) {
            return ans;
        }
        visited[rowIndex + 1][colIndex - 1] = false;
    }//7
    if ((colIndex - 1 >= 0) && (board[rowIndex][colIndex - 1] == str[1]) && (visited[rowIndex][colIndex - 1] == false)) {
        bool ans = DFS(board, visited, str.substr(1), 'A', rowIndex, colIndex - 1, maxRowIndex, maxColIndex);  //rI, cI - 1
        if (ans == true) {
            return ans;
        }
        visited[rowIndex][colIndex - 1] = false;
    }//8
    if ((rowIndex - 1 >= 0) && (colIndex - 1 >= 0) && (board[rowIndex - 1][colIndex - 1] == str[1]) && (visited[rowIndex - 1][colIndex - 1] == false)) {
        bool ans = DFS(board, visited, str.substr(1), 'A', rowIndex - 1, colIndex - 1, maxRowIndex, maxColIndex); //rI - 1, cI - 1
        if (ans == true) {
            return ans;
        }
        visited[rowIndex - 1][colIndex - 1] = false;
    }

    return false;
}

bool hasPath (vector<vector<char> > &board, int rows, int cols) {
    bool ** visited = new bool * [rows];
    for (int i = 0; i < rows; i++) {
        visited[i] = new bool[cols];
        fill_n(visited[i], cols, false);
    }
    
    bool ans = false;
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            if (board[i][j] == 'C') {
                ans = DFS(board, visited, "CODINGNINJA", 'A', i, j, rows - 1, cols - 1);
                if (ans == true) {
                    break;
                }
            }
        }
    }

    for (int i = 0; i < rows; i++) {
        delete [] visited[i];
    }
    delete [] visited;

    return ans;
}

int main(){
    int n, m;
    cin >> n >> m;

    vector<vector<char> > board(n, vector<char>(m));

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            cin >> board[i][j];
        }
    }

    cout << (hasPath(board, n, m) ? 1 : 0) << endl;
}


