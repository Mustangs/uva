/**
 * UVA 278 - Placing Queens
 */
#include <string>
#include <iostream>
#include <cstdio>
#include <algorithm>
#include <vector>
#include <map>
#include <queue>
#include <stack>
#define si(t) scanf("%d", &t)
#define sd(t) scanf("%f", &t)
#define forr(i, a, b) for(int i=a; i<b;i++)
#define foreach(it, container) \
	for(typeof(container.begin()) it = container.begin(); it != container.end(); it++)
#define MAX 1000

using namespace std;

//const int oo = ~(1 << 31);
//typedef pair<int, int> ii;
//typedef vector<ii> vii;
//vector<vii> adj;

int grid[11][11];
bool pos[11][11];
bool save[11][11];
int m, n;

void saveGrid() {
	forr(i, 0, m) {
		forr(j, 0, n) {
			save[i][j] = pos[i][j];
		}
	}
}

void printGrid() {
	forr(i, 0, m) {
		forr(j, 0, n) {
			if(save[i][j]) cout << "Q "; else cout << ". ";
		}
		cout << endl;
	}
}

void blossom(int r, int c, int val) {
	grid[r][c] += val;
	for(int i = 1, j = 1; r + i < m && c + j < n || r - i >= 0 && c - j >= 0 || r + i < m && c - j < n || r - i >= 0 && c + j >= 0; i++, j++) {
		//printf("(%d, %d)\n(%d, %d)\n", r + i, c + j, r - i, c - j);
		if(r + i < m && c + j < n) {
			grid[r + i][c + j] += val;
		}
		if(r - i >= 0 && c - j >= 0) {	
			grid[r - i][c - j] += val;
		}
		if(r + i < m && c - j < n) {
			grid[r + i][c - j] += val;
		}
		if(r - i >= 0 && c + j >= 0) {
			grid[r - i][c + j] += val;
		}
	}

	for(int i = 0; i < n; i++)
		grid[r][i] += val;

	for(int i = 0; i < m; i++)
		grid[i][c] += val;	
}

int best = 0;

void placeQueens(int r, int c, int depth) {
	if(grid[r][c] > 0)
		return;
	pos[r][c] = true;
	blossom(r, c, 1);
	if(depth > best) {
		saveGrid();
		best = depth;
	}
	if(r < m) {
		for(int i = 0; i < n; i++) {
			placeQueens(r + 1, i, depth + 1);
		}
	}
	blossom(r, c, -1);
	pos[r][c] = false;
}

void clearGrid() {
	forr(i, 0, 11)
		forr(j, 0, 11)
			grid[i][j] = false;
}


int main() {

	m = 7;
	n = 10;

	best = 0;

	for(int i = 0; i < n; i++) {
		placeQueens(0, i, 0);
	}

	printGrid();

	cout << best << endl;

	/*
	m = 6;
	n = 5;
	clearGrid();
	grid[2][1] = true;
	forr(i, 0, m)
		forr(j, 0, n)
			if(!isAttacked(i, j)) {
				printf("(%d, %d)\n", i, j);
			}
	*/
/*  
	int t;
	char p;
	int m, n;
	scanf("%d\n", &t);
	for(int i = 0; i < t; i++) {
		scanf("%c %d %d\n", &p, &m, &n);
		if(p == 'r') {
			cout << min(m, n) << endl;
		}

	}*/

}
