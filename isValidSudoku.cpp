#include <iostream>
#include <vector>
#include <unordered_map>
#include <cassert>
using namespace std;
class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
			const int n = 9;
			// validamos las filass para verificar repeticiones
			for (int i = 0; i < n; ++i) {
					unordered_map<char, int> rows;
					for (int j = 0; j < n; ++j) {
							char num = board[i][j];
							if (num != '.') {
									if (rows.find(num) != rows.end()) {
											return false;  // carácter repetido en la misma fila
									} rows[num] = 1;
							}
					}
			}

			// validamos las columnas para verificar repeticiones
			for (int j = 0; j < n; ++j) {
					unordered_map<char, int> cols;
					for (int i = 0; i < n; ++i) {
							char num = board[i][j];
							if (num != '.') {
									if (cols.find(num) != cols.end()) {
											return false;  // carácter repetido en la misma columna
									}
									cols[num] = 1;
							}
					}
			}

			// Recorrer las casillas de 3x3 para verificar repeticiones
			const int casillasSize = 3;
			for (int i = 0; i < n; i += casillasSize) {
					for (int j = 0; j < n; j += casillasSize) {
							unordered_map<char, int> casillas;
							for (int x = i; x < i + casillasSize; ++x) { // + 3 ya que son bloques de 3x3 y hay 9 bloques
									for (int y = j; y < j + casillasSize; ++y) {
											char num = board[x][y];
											if (num != '.') {
													if (casillas.find(num) != casillas.end()) {
															return false;  // caracter repetido en la misma casilla de 3x3
													}
													casillas[num] = 1;
											}
									}
							}
					}
			}

    return true;  // sudoku válidado
  }
};

void test(){
	
	vector<vector<char>> board = {
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
	assert(Solution().isValidSudoku(board) == true);
	
	
	board = {
		{'8','3','.','.','7','.','.','.','.'},
		{'6','.','.','1','9','5','.','.','.'},
		{'.','9','8','.','.','.','.','6','.'},
		{'8','.','.','.','6','.','.','.','3'},
		{'4','.','.','8','.','3','.','.','1'},
		{'7','.','.','.','2','.','.','.','6'},
		{'.','6','.','.','.','.','2','8','.'},
		{'.','.','.','4','1','9','.','.','5'},
		{'.','.','.','.','8','.','.','7','9'}};
	assert(Solution().isValidSudoku(board) == false);
}

int main(){
	test();
	return 0;
}
