/**
  UVA 193 - Graph Coloring
  Generalizes to the NP-hard problem of maximum independent set of a graph.

	General Algorithm:
	MAXINDSETSIZE(G, v)
		if G is empty
			return 0
		else
			withv = 1 + MAX-IND-SET(G \ adj(v))
			withoutv = MAX-IND-SET(G \ {v})
			return max(withv, withoutv)
  
  In this implementation, coloring white is equivalent to removing from G.
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
#define MAX 101
#define BLACK -1
#define WHITE 1

using namespace std;

//const int oo = ~(1 << 31);
//typedef pair<int, int> ii;
//typedef vector<ii> vii;
//vector<vii> adj;

bool adj[MAX][MAX]; //adjacency matrix
int color[MAX]; //color[i] = 0 if not coloured, else BLACK/WHITE
int solution[MAX]; //stores the best solution so far
int best = 0; //the size of the best IND so far
int m, n, k;

/**
  v is the node we are inspecting (to see if it's in the MIS)
  size is the size of the MIS so far
*/
void maxSet(int v, int size) {

	//base case: exhausted all vertices, record solution if best
	if(v > n) {
		if(size > best) {
			best = size;
			copy(color, color + n + 1, solution);
		}
		return;
	}

	if(color[v] != 0) {
		maxSet(v + 1, size);
		return;
	}

	//if v is black, color its neighbours white
	bool check = true;
	vector<int> N;
	for(int i = 1; i <= n; i++) {
		if(adj[v][i]) {
			if(color[i] == BLACK) {
				check = false;
				break;
			} else if(color[i] == 0)
				N.push_back(i);
		}
	}

	if(check) {
		color[v] = BLACK;
		for(int i = 0; i < N.size(); i++)
			color[N[i]] = WHITE;
		maxSet(v + 1, size + 1);
		for(int i = 0; i < N.size(); i++)
			color[N[i]] = 0;
	}

	//if v is white, no action necessary
	color[v] = WHITE;
	maxSet(v + 1, size);
	color[v] = 0;
	
}


int main() {

	si(m);

	while(m--) {

		forr(i, 1, MAX)
			color[i] = 0;
		
		scanf("%d %d", &n, &k); // n = vertices, k = edges

		forr(i, 1, n + 1)
			forr(j, 1, n + 1)
				adj[i][j] = false;	
		
		best = 0;

		int a, b;
		for(int i = 0; i < k; i++) {
			scanf("%d %d", &a, &b);
			adj[a][b] = true;
			adj[b][a] = true;
		}
		
		maxSet(1, 0);
		printf("%d\n", best);
		bool flag = false;
		for(int i = 1; i <= n; i++) {
			if(solution[i] == BLACK) {
				printf(flag ? " %d" : "%d", i);
				flag = true;
			}
		}
		printf("\n");

	}


}
