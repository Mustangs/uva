/**
  UVA 10003 - Cutting Sticks
  Dynamic programming and memoization.

  CUT-COST(p, q)
  	if q - p == 1
		return 0
	if memo[p][q] exists
		return memo[p][q]
	
	for all k where p < k < q
		m = min(m, C[q] - C[p] + CUT-COST(p, k) + CUT-COST(k, q))
	
	memo[p][q] = m
	return m
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

const int oo = ~(1 << 31);
//typedef pair<int, int> ii;
//typedef vector<ii> vii;
//vector<vii> adj;

int cuts[55];
int memo[55][55]; // stores the lowest cost
int l, n;

/**
  Gives the optimal cost of cutting a stick from the pth cut position to the qth cut position.
  */
int cut_cost(int p, int q) {
	if(memo[p][q] != oo) {
		return memo[p][q];
	}

	int m = oo;
	for(int i = p + 1; i < q; i++) {
		m = min(m, cuts[q] - cuts[p] + cut_cost(p, i) + cut_cost(i, q));
	}

	return (memo[p][q] = m);
}
			

int main() {

	while(si(l) != EOF) {
		if(l == 0)
			break;
		si(n);
		
		//insert artificial/boundary cuts at 0 and l
		cuts[0] = 0;
		for(int i = 1; i <= n; i++) {
			si(cuts[i]);
		}
		cuts[n + 1] = l;

		for(int i = 0; i <= n + 1; i++)
			for(int j = 0; j <= n + 1; j++) {
				if(j - i == 1)
					memo[i][j] = 0; //base case
				else
					memo[i][j] = oo;
			}

		printf("The minimum cutting is %d.\n", cut_cost(0, n + 1));
	}
}
