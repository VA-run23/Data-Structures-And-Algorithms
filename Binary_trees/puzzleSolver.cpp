#include <iostream>
#include <vector>
#include <queue>
#include <unordered_set>
#include <string>
#include <sstream>
#include <algorithm>

using namespace std;

// Helper function to convert the board state to a string
string boardToString(const vector<int>& board) {
    stringstream ss;
    for (int num : board) {
        ss << num << ",";
    }
    return ss.str();
}

// Check if the current state is the goal state
bool isGoalState(const vector<int>& board) {
    for (int i = 0; i < 8; ++i) {
        if (board[i] != i + 1) return false;
    }
    return board[8] == 0;
}

// Perform the BFS search
void solvePuzzle(const vector<int>& initialBoard) {
    const vector<pair<int, int>> moves = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}}; // Up, Down, Left, Right
    const vector<char> moveChars = {'U', 'D', 'L', 'R'}; // Corresponding move characters
    const vector<int> goalBoard = {1, 2, 3, 4, 5, 6, 7, 8, 0}; // Goal state

    queue<pair<vector<int>, string>> q;
    unordered_set<string> visited;
    
    q.push({initialBoard, ""});
    visited.insert(boardToString(initialBoard));

    while (!q.empty()) {
        pair<vector<int>, string> front = q.front();
        vector<int> currentBoard = front.first;
        string path = front.second;
        q.pop();

        if (isGoalState(currentBoard)) {
            cout << "Solution found: " << path << endl;
            return;
        }

        int zeroIndex = find(currentBoard.begin(), currentBoard.end(), 0) - currentBoard.begin();
        int zeroRow = zeroIndex / 3;
        int zeroCol = zeroIndex % 3;

        for (int i = 0; i < moves.size(); ++i) {
            int newRow = zeroRow + moves[i].first;
            int newCol = zeroCol + moves[i].second;

            if (newRow >= 0 && newRow < 3 && newCol >= 0 && newCol < 3) {
                int newZeroIndex = newRow * 3 + newCol;
                vector<int> newBoard = currentBoard;
                swap(newBoard[zeroIndex], newBoard[newZeroIndex]);
                
                string newBoardStr = boardToString(newBoard);
                if (visited.find(newBoardStr) == visited.end()) {
                    visited.insert(newBoardStr);
                    string newPath = path + moveChars[i];
                    q.push({newBoard, newPath});
                }
            }
        }
    }
    cout << "No solution found." << endl;
}

int main() {
    vector<int> initialBoard = {1, 2, 6, 4, 5, 3, 7, 0, 8}; // Example initial state

    solvePuzzle(initialBoard);

    return 0;
}
