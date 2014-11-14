/*
   UVA 10706 - Number Sequence
   Main observation is that S[k + 1] = S[k] + ndigits(k)
   where S[k] is the size of the set S sub k
   We subtract S[k] from the index until index > S[k] indicating
   that the position lies within S[k].
   Along the same idea as above, loop from i = 1 to k,
   subtracting ndigit(i) from the index until index <= ndigit(i)
   suggesting that the digit we're interested in is within i.
   Finally, return the digit within i corresponding to the index.
   */
#include <string>
#include <sstream>
#include <iostream>
#include <cstdio>
#include <algorithm>
#include <vector>
#include <map>
#include <queue>
#include <stack>
#include <cmath>
#define si(t) scanf("%d", &t)
#define sd(t) scanf("%f", &t)
#define forr(i, a, b) for(int i=a; i<b;i++)

using namespace std;

//const int oo = ~(1 << 31);
//typedef pair<int, int> ii;
//typedef vector<ii> vii;
//vector<vii> adj;

//Finds the number of digits in num
int ndigits(int num) {
    return log10(num) + 1;
}

//Finds the ith digit of num
int ith_digit(int num, int i) {
    int right = (int)pow(10, ndigits(num) - i - 1);
    return (num / right) % 10;
}

int main() {

    //t = number of test cases
    //index = the index we're looking for
	int t, index;
	si(t);	

	while(t--) {
		si(index);
		int k = 1; //subscript of S
        int S = 1; //this stores the size of S[k]
		while(index > S) {
            index -= S;
			S = S + ndigits(k + 1);
            k++;
		}

        //printf("In subset %d, index %d\n", k, index);
        int length = 0;
        int answer = -1;
        for(int i = 1; i <= k; i++) {
           if(index <= ndigits(i)) {
               answer = ith_digit(i, index - 1);
               break;
           } else {
               index -= ndigits(i);
           }    
        }
        cout << answer << endl;

	}
}
