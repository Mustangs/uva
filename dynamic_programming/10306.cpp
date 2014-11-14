/**
 * UVA 10306 - eCoins
 */
#include <string>
#include <iostream>
#include <cstdio>
#include <cmath>
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
#define MAX 40

using namespace std;

const int oo = ~(1 << 31);
//typedef pair<int, int> ii;
//typedef vector<ii> vii;
//vector<vii> adj;

int main() {

	int n;
	int m, S;

	int a[MAX], b[MAX];
	int dp[301][301];

	si(n);
	for(int t = 0; t < n; t++) {
		scanf("%d %d", &m, &S);

		for(int i = 0; i <= S; i++)
			for(int j = 0; j <= S; j++)
				dp[i][j] = oo;

		dp[0][0] = 0;
		for(int i = 0; i < m; i++) {
			scanf("%d %d", &a[i], &b[i]);
		}

		for(int i = 0; i <= S; i++)
			for(int j = 0; j <= S; j++) {
				for(int k = 0; k < m; k++) {
					if(i - a[k] >= 0 && j - b[k] >= 0)
						if(dp[i - a[k]][j - b[k]] != oo)
							dp[i][j] = min(dp[i][j], dp[i - a[k]][j - b[k]] + 1);
				}
			}					
		
		int soln = oo;
		for(int i = 0; i <= S; i++) {
			double k = sqrt(S*S - i*i);
			if(floor(k) == k) {
				//printf("%d %d\n", i, (int)k);
				soln = min(soln, dp[i][(int)k]);
			}
		}

		if(soln == oo)
			cout << "not possible" << endl;
		else
			cout << soln << endl;

	}	



}
