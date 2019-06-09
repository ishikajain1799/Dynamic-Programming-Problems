#include<bits/stdc++.h>
using namespace std;

int LCSlength(string X, string Y, int m, int n)
{
    // base case ---> if either of the string is empty then ans is 0
    if(m == 0 || n == 0)
        return 0;

    // if last ch of both the strings is same then last ch is included in LCS
    if(X[m-1] == Y[n-1])
        return 1 + LCSlength(X,Y,m-1,n-1);

    // else skip the last ch of one of the strings
    return max(LCSlength(X,Y,m,n-1), LCSlength(X,Y,m-1,n));
}

int LCSlength_topdown(string X, string Y, int m, int n, int memo[1000][1000])
{

     // base case ---> if either of the string is empty then ans is 0
    if(m == 0 || n == 0)
        return 0;

    // check if solution is already present in the memo[][]
    if(memo[m][n] != -1)
        return memo[m][n];

    // if last ch of both the strings is same then last ch is included in LCS
    if(X[m-1] == Y[n-1]){
        memo[m][n] = 1 + LCSlength(X,Y,m-1,n-1);
    }

    // else skip the last ch of one of the strings
    else{
        memo[m][n] =  max(LCSlength(X,Y,m,n-1), LCSlength(X,Y,m-1,n));
    }

    return memo[m][n];
}

int LCSlength_bottomup(string X, string Y)
{
    int m = X.length();
    int n = Y.length();

    int memo[m+1][n+1];

    memset(memo,-1,sizeof(memo));

    for(int i = 0; i <= m; i++)
    {
        for(int j = 0; j <= n; j++)
        {
            if(i == 0 || j == 0)
                memo[i][j] = 0;
            else
            {
                if(X[i-1] == Y[j-1])
                    memo[i][j] = 1 + memo[i-1][j-1];
                else
                    memo[i][j] = max(memo[i-1][j], memo[i][j-1]);
            }
        }
    }

    return memo[m][n];
}


int LCS_length_spaceoptimized(string X, string Y)
{
    int m = X.length(), n = Y.length();

    int prev[n+1] , current[n+1];

    for(int i = 0; i <= m; i++)
    {
        for(int j = 0; j <= n; j++)
        {
            if(i == 0 || j == 0)
                current[j] = 0;
            else{
                if(X[i-1] == Y[j-1])
                    current[j] = prev[j-1] + 1;
                else
                    current[j] = max(prev[j], current[j-1]);
            }
        }
        for(int i = 0; i <= n; i++)
            prev[i] = current[i];
    }

    return current[n];
}
int main()
{
    string X, Y;
    cin >> X >> Y;

    // function 1
    cout << LCSlength(X,Y,X.length(), Y.length()) << endl;

    // function 2
    int memo[1000][1000];
    memset(memo,-1,sizeof(memo));
    cout << LCSlength_topdown(X,Y,X.length(), Y.length(), memo) << endl;

    // function 3
    cout << LCSlength_bottomup(X,Y) << endl;

    // function 4
    cout << LCS_length_spaceoptimized(X,Y) << endl;

    return 0;
}
