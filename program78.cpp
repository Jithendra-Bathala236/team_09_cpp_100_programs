#include <iostream>
#include <cmath>
using namespace std;

const int MAX_N = 10;

void printSolution(int board[MAX_N][MAX_N], int N) {
    int solutionArr[N];
    int solutionCount = 0;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            if (board[i][j] == 1){
                cout << "Q ";
                solutionArr[solutionCount] = j;
                solutionCount++;
            } else {
                cout << "* ";
            }
        }
        cout << endl;
    }
    cout << endl;

    cout << "The array of solutions is: [ ";
    for (int i = 0; i < N; i++) {
        if (i < N-1) {
            cout << solutionArr[i] << ", ";
        } else {
            cout << solutionArr[i] << " ]" << endl;
        }
    }
}

bool isSafe(int board[MAX_N][MAX_N], int row, int col, int N) {
    int i, j;

    for (i = 0; i < col; i++) {
        if (board[row][i])
            return false;
    }

    for (i = row, j = col; i >= 0 && j >= 0; i--, j--) {
        if (board[i][j])
            return false;
    }

    for (i = row, j = col; i < N && j >= 0; i++, j--) {
        if (board[i][j])
            return false;
    }

    return true;
}

bool solveNQueens(int board[MAX_N][MAX_N], int col, int N) {
    if (col >= N)
        return true;

    for (int i = 0; i < N; i++) {
        if (isSafe(board, i, col, N)) {
            board[i][col] = 1;

            if (solveNQueens(board, col + 1, N))
                return true;

            board[i][col] = 0;
        }
    }

    return false;
}

int main() {
    int N;

    cout << "Enter the value of N for N-Queens (N should be in between 1 to " << MAX_N << "): ";
    cin >> N;

    if (N < 1 || N > MAX_N) {
        cout << "Invalid input! Please enter a value between 1 and " << MAX_N << ".\n";
        return 1;
    }

    int board[MAX_N][MAX_N] = {0};

    if (solveNQueens(board, 0, N)) {
        cout << "Solution for N-Queens with N = " << N << ":" << endl << endl;
        printSolution(board, N);
    } else {
        cout << "No solution found for N = " << N << "." << endl;
    }

    return 0;
}
