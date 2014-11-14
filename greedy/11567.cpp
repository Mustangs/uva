/**
 * UVA 11567 - Moliu Number Generator
 * Note that the input does not fit in a signed int!
 * Signed int only holds up to 2^31 - 1, whereas input can go up to 2^31.
 * Easy to miss and very annoying...
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

int countPowersOfTwo(int n) {
	int i = 0;
	while(n % 2 == 0) {
		n = n/2;
		i++;
	}
	return i;
}

int main() {
	
	unsigned int n;
	while(si(n) != EOF) {
		int cnt = 0;
		while(n > 0) {
			if(n <= 3) {
				cnt += n;
				n = 0;
				break;
			} else if(n % 2 == 0) {
				n = n/2;
			} else if(countPowersOfTwo(n + 1) > countPowersOfTwo(n - 1)) {
				n = n + 1;
			} else {
				n = n - 1;
			}
			cnt++;
		}
		cout << cnt << endl;
	}
}
