#include <cstdio>
#include <iostream>
#include <vector>
#include <map>
#include <set>

using namespace std;

const int MAXN = 145;
const int N = 13;

int board[MAXN][MAXN];

map<int, int> boxcheck[MAXN];
map<int, int> rowcheck[MAXN];
map<int, int> colcheck[MAXN];

void sudoku() {
	int sz;
	scanf("%d\n", &sz);

	int sz2 = sz * sz;

	cout << "Size: " << sz * sz << endl;
	for (int i = 0; i < sz * sz; ++i) {
		for (int j = 0; j < sz * sz; ++j) {
			scanf("%d", &(board[i][j]));
		}
	}

	for (int i = 0; i < sz2; ++i) {
		boxcheck[i].clear();
		rowcheck[i].clear();
		colcheck[i].clear();
	}

	for (int i = 0; i < sz2; ++i) {
		for (int j = 0; j < sz2; ++j) {
			rowcheck[i][ board[i][j] ]++;
			colcheck[j][ board[i][j] ]++;

			int boxnum = (i / sz) * sz + (j / sz);

			boxcheck[boxnum][ board[i][j] ]++;
		}
	}

	bool legit = true;

	set<int> dups, nops;

	for (int b = 0; b < sz2; ++b) {
		dups.clear();
		nops.clear();
		for (int num = 1; num <= sz2; ++num) {
			if (boxcheck[b][num] != 1) {
				if (boxcheck[b][num] == 0) {
					nops.insert(num);
				} else {
					dups.insert(num);
				}
				legit = false;
			}
		}

		if (nops.size()) {
			printf("Square %d has ", b+1);
			for (set<int>::iterator it = nops.begin(); it != nops.end(); ++it) {
				printf("no %ds and ", *it);
			}
			for (set<int>::iterator it = dups.begin(); it != dups.end(); ++it) {
				printf("%d %ds", boxcheck[b][*it], *it);
				if ((++it)-- == dups.end()) {
					printf("\n");
				} else {

					printf(" and ");
				}
			}
		}


	}

	for (int i = 0; i < sz2; ++i) {
		for (int j = 0; j < sz2; ++j) {
			cout << board[i][j] << " ";
		}
		cout << endl;
	}

	for (int i = 1; i <= sz2; ++i) {
		cout << "Box: 3, number: " << i << " appears " << boxcheck[2][i] << endl;
	}
}

int main() {
	int n;
	scanf("%d\n", &n);
	cout << n << endl;
	for (int i = 1; i <= n; ++i) {
		printf("Puzzle %d\n", i);
		sudoku();
	}
	return 0;
}