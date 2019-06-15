/* find no. of ways to fill a nX4 matrix with 1X4 sized tiles */

#include <bits/stdc++.h>
using namespace std;

// recursive solution
int n_ways(int n){
	
	if(n < 4){
		return 1;
	}
	
	if(n == 4){
		return 2;
	}
	
	return n_ways(n-1) + n_ways(n-4);
}


// memoization
int n_ways_1(int n, int memo[10001]){
	
	if(n < 4){
		return 1;
	}
	if(n == 4){
		return 2;
	}
	
	if(memo[n] != -1){
		return memo[n];
	}
	
	return memo[n] = n_ways_1(n-1,memo) + n_ways_1(n-4,memo);
}

// tabulation
int n_ways_2(int n){
	
	int memo[n+1];
	memo[0] = memo[1] = memo[2] = memo[3] = 1;
	memo[4] = 2;
	
	for(int i = 5; i <= n; i++){
		memo[i] = memo[i-1] + memo[i-4];
	}
	
	return memo[n];
}

int main() {
	// your code goes here
	cout << n_ways(6) << endl;
	int memo[10001];
	memset(memo,-1,sizeof(memo));
	cout << n_ways_1(6, memo) << endl;
	cout << n_ways_2(6);
	return 0;
}
