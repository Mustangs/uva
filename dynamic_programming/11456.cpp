/**
  Trainsorting
  Hint: Which car is optimal to be the first car of her train?
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
#define MAX 2001

using namespace std;

//const int oo = ~(1 << 31);
//typedef pair<int, int> ii;
//typedef vector<ii> vii;
//vector<vii> adj;
int lis[MAX]; //lis[i] = lis beginning at index i
int lds[MAX]; //lds[i] = lds beginning at index i

int trainsort(int * a, int size) {
	//Find the longest increasing subsequence
	for(int i = size - 1; i >= 0; i--) {
		lis[i] = 1;
		for(int j = size - 1; j > i; j--) {
			if(a[i] < a[j] && lis[j] + 1 > lis[i]) {
				lis[i] = lis[j] + 1;
			}
		}
	}

	//Find the longest decreasing subsequence
	for(int i = size - 1; i >= 0; i--) {
		lds[i] = 1;
		for(int j = size - 1; j > i; j--) {
			if(a[i] > a[j] && lds[j] + 1 > lds[i]) {
				lds[i] = lds[j] + 1;
			}
		}
	}

	int res = 0; //necessary. I guess the train could have length 0

	//Find the maximum of lds[i] + lis[i] - 1
	//Subtract 1 since you're counting a[i] twice
	for(int i = 0; i < size; i++) {
		res = max(res, lds[i] + lis[i] - 1);
	}

	return res;	
}

int main() {
	int arr[MAX];
	int tests, n;
	si(tests);
	for(int t = 0; t < tests; t++) {
		si(n);
		for(int i = 0; i < n; i++)
			si(arr[i]);
		cout << trainsort(arr, n) << endl;
	}
	
}
