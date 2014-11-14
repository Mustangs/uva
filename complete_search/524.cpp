/**
  * UVA 524 - Prime Ring Problem
  * Solution uses complete search.
  * Very annoying presentation requirements.
  * No need to use sieve since max prime number <= 32
  */

#include <string>
#include <iostream>
#include <cstdio>
#include <algorithm>
#include <vector>
#include <set>
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

int ring[20]; //array that stores the ring sequence
bool visited[20]; //visited[i] = true if i is in ring
bool primes[32]; //primes[i] = true if i is a prime number
int n;

void assembleRing(int depth) {
	if(depth == n - 1) {
		if(primes[ring[n - 1] + 1]) {
			printf("1");
			for(int i = 1; i < n; i++)
				printf(" %d", ring[i]);
			printf("\n");
		}
		return;
	}

	for(int i = 2; i <= n; i++) {
		if(visited[i])
			continue;

		if(primes[ring[depth] + i]) {
			ring[depth + 1] = i;
			visited[i] = true;
			assembleRing(depth + 1);
			visited[i] = false;
		}
	}
}

int main() {

	for(int i = 0; i <= 31; i++) {
		primes[i] = false;
		visited[i] = false;
	}

	//hope I didn't miss any
	primes[2] = primes[3] = primes[5] = primes[7] = primes[11] = primes[13]
		= primes[17] = primes[19] = primes[23] = primes[29] = primes[31] = true;

	int t = 1;
	while(si(n) != EOF) {
		if(t > 1)
			printf("\n");
		printf("Case %d:\n", t++);
		visited[1] = true;
		ring[0] = 1;
		assembleRing(0);
	}

}
