#include<iostream>
#include<vector>

using namespace std;

void printBoard(const vector<char>& board) {
	cout << " " << board[0] << " | " << board[1] << " | " << board[2] << endl;
	cout << "---|---|---" << endl;
	cout << " " << board[3] << " | " << board[4] << " | " << board[5] << endl;
	cout << "---|---|---" << endl;
	cout << " " << board[6] << " | " << board[7] << " | " << board[8] << endl;
}

bool checkWin(const vector<char>& board, char player) {
	const int wins[8][3] = { {0, 1, 2}, { 3, 4, 5 }, { 6, 7, 8 }, // Rows
	{ 0, 3, 6 }, { 1, 4, 7 }, { 2, 5, 8 }, // Columns
	{ 0, 4, 8 }, { 2, 4, 6 }            // Diagonals
	};
	for (auto& win : wins) {
		if (board[win[0]] == player && board[win[1]] == player && board[win[2]] == player) { //access the value at index win[0] in the board array
			return true;
		}
	}

	return false;
}

bool isBoardFull(const vector<char>& board) {
	for (char c : board) {
		if (c != 'X' && c != 'O') {
			return false;
		}
	}
	return true;
}

int main() {
	vector<char> board(9, ' '); // Initialize board with empty spaces
	char currentPlayer = 'X';
	int move;
	while (true) {
		printBoard(board);
		cout << "Player " << currentPlayer << ", enter your move (1-9): ";
		cin >> move;
		move--; // Adjust for 0-based index

		if (move < 0 || move >= 9 || board[move] != ' ') {
			cout << "Invalid move. Try again." << endl;
			continue;
		}

		board[move] = currentPlayer;

		if (checkWin(board, currentPlayer)) {
			printBoard(board);
			cout << "Player " << currentPlayer << " wins!" << endl;
			break;
		}

		if (isBoardFull(board)) {
			printBoard(board);
			cout << "It's a tie!" << endl;
			break;
		}

		currentPlayer = (currentPlayer == 'X') ? 'O' : 'X';
	}

	return 0;
}
