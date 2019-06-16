#include <iostream>
#include<climits>
using namespace std;

// Longest Increasing Subsequence

int LIS_recursive(int arr[], int i, int n, int last_element){
	
	// base case --> if no elemeent is left in the array then LIS is of length 0
	if(i == n){
		return 0;
	}
	int include = 0;
	// check whether current indexed element can be a part of LIS
	if(arr[i] > last_element){
		include = 1 + LIS_recursive(arr, i+1,n,arr[i]);
	}
	
	// excluding the current index
	int exclude = LIS_recursive(arr,i+1,n,last_element);
	
	return max(include, exclude);
	
}

int memo[1000];
int LIS_memoization(int arr[], int i, int n, int last_element){
	
	if(i == n){
		return 0;
	}
	
	if(memo[i] != -1){
		return memo[i];
	}
	
	int include = 0;
	// check whether current indexed element can be a part of LIS
	if(arr[i] > last_element){
		include = 1 + LIS_recursive(arr, i+1,n,arr[i]);
	}
	
	// excluding the current index
	int exclude = LIS_recursive(arr,i+1,n,last_element);
	
	return memo[i] = max(include, exclude);
}
int LIS_tabulation(int arr[], int n){
	
	int memo[n]; // to store the LIS ending at index i 
	
	for(int i = 0; i < n; i++){
		memo[i] = 1;
	}
	for(int i = 1; i < n; i++){
		
		for(int j = i-1; j >= 0; j--){
			if(arr[j] < arr[i]){
				memo[i] = max(memo[i], 1 + memo[j]);
			} 
		}
	}
	
	return memo[n-1];
}


int main() {
	// your code goes here
	
	int arr[] = {32, 29, 21, 15, 11, 6 };
	int n = sizeof(arr)/sizeof(arr[0]);
	
	for(int i = 0; i < n; i++){
		memo[i] = -1;
	}
	cout << LIS_recursive(arr,0,n,INT_MIN) << endl;
	cout << LIS_tabulation(arr,n) << endl;
	cout << LIS_memoization(arr,0,n,INT_MIN) << endl;


	return 0;
}
