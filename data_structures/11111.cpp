/**
 * UVA 11111 - Generalized Matrioshka
 * Algorithm: Maintain a stack of matrioshkas containing their id and capacity remaining
 * Foreach number:
 * 		If you see a negative number, push a new matrioshka onto the stack
 * 		If you see a positive number, pop from the stack and compare.
 * 			If the id does not match or there is no capacity left, then not a matrioshka
 * 			Decrease the capacity remaining of the parent matrioshka (top of the stack) by the size of the current matrioshka
 */

#include <string>
#include <sstream>
#include <iostream>
#include <cstdio>
#include <stack>
#include <algorithm>
#include <vector>
#include <map>
#include <queue>

#define si(t) scanf("%d", &t)
#define sd(t) scanf("%f", &t)
#define forr(i, a, b) for(int i=a; i<b;i++)
#define foreach(it, container) \
	for(typeof(container.begin()) it = container.begin(); it != container.end(); it++)
#define MAX 1000000

using namespace std;

//const int oo = ~(1 << 31);
//typedef pair<int, int> ii;
//typedef vector<ii> vii;
//vector<vii> adj;

typedef struct matrioshka {
	int id;
	int cap;	//the capacity remaining
} mat;

int main() {

	string s;
	stack<mat> stk;
	int n;
	bool ok;

	while(getline(cin, s)) {
		ok = true;
		stringstream ss(s);
		//clear
		while(!stk.empty())
			stk.pop();
		while(ss >> n) {
			if(n < 0) {
				mat m;
				m.id = -n;
				m.cap = -n;
				stk.push(m);	//push a new matrioshka
			} else {
				if(stk.empty()) {
					ok = false;
					break;
				}
				mat cur = stk.top();
				stk.pop();
				if(cur.id != n || cur.cap <= 0) {
					ok = false;
					break;
				}
				if(!stk.empty()) {	//update the parent matrioshka
					mat &parent = stk.top();
					parent.cap -= cur.id;
				}
			}
		}
		if(stk.empty() && ok)
			cout << ":-) Matrioshka!" << endl;
		else
			cout << ":-( Try again." << endl;
	}

}
