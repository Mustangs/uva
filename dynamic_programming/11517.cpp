/**
 * 11517 - Exact Change
 * Uses dp to solve the problem
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

const int oo = 101;
//typedef pair<int, int> ii;
//typedef vector<ii> vii;
//vector<vii> adj;

int A[101][10001];
int coins[101];

int main() {

	int tests, n, price;
	scanf("%d", &tests);

	for(int i = 0; i < tests; i++) {
		scanf("%d", &price);
		scanf("%d", &n);
		for(int i = 1; i <= n; i++) {
			scanf("%d", &coins[i]);
		}
		for(int i = 0; i <= n; i++)
			for(int j = 0; j < 10001; j++) {
				if(j == 0)
					A[i][j] = 0;
				else
					A[i][j] = oo;
			}
				
		for(int i = 1; i <= n; i++)
			for(int j = 1; j < 10001; j++) {
				if(j - coins[i] >= 0)
					A[i][j] = min(A[i - 1][j], A[i - 1][j - coins[i]] + 1);
				else
					A[i][j] = A[i - 1][j];
				/*  if(A[i][j] < oo)
					printf("A[%d][%d] = %d\n", i, j, A[i][j]);*/
			}

		for(int i = price; i <= 10000; i++) {
			if(A[n][i] < oo) {
				printf("%d %d\n", i, A[n][i]);
				break;
			}
		}

	}

}
