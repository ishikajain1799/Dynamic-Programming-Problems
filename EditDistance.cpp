#include <iostream>
#include<cstring>
using namespace std;

// levenshtein distance
// convert s1 to s2
int edit_distance(string s1, int m, string s2, int n)
{
    // base case : if any of the string is empty then edit distance is equal to the length of other string
    if(n == 0)
    {
        return m;
    }
    if(m == 0)
    {
        return n;
    }
    if(s1[m-1] == s2[n-1])
    {
        return edit_distance(s1,m-1,s2,n-1);
    }
    int insert = edit_distance(s1,m,s2,n-1);
    int del = edit_distance(s1,m-1,s2,n); 
    int replace = edit_distance(s1,m-1,s2,n-1);
    return 1 + min(insert,min(del,replace));
}
// top down dp or memoization
int memo[1000][1000];
int edit_distance_TD(string s1, int m, string s2, int n)
{
    if(m == 0)
        return n;

    if(n == 0)
        return m;

    if(memo[m][n] !=  -1)
     return memo[m][n];

    if(s1[m-1] == s2[n-1])
    {
        memo[m][n] = edit_distance_TD(s1,m-1,s2,n-1);
    }
    else
     memo[m][n] = 1 + min(edit_distance_TD(s1,m-1,s2,n-1),min(edit_distance_TD(s1,m,s2,n-1),edit_distance_TD(s1,m-1,s2,n)));

     return memo[m][n];
}

// bottom up dp
int edit_distance_BU(string s1, string s2)
{
    int m = s1.length(), n = s2.length();
    int memo[m+1][n+1];

    for(int i = 0; i <= n; i++)
    {
        memo[0][i] = i;
    }
    for(int i = 0; i <= m; i++)
    {
        memo[i][0] = i;
    }

    for(int i = 1; i <= m; i++)
    {
        for(int j = 1; j <= n; j++)
        {
            if(s1[i-1] == s2[j-1])
            {
                memo[i][j] = memo[i-1][j-1];
            }
            else
            {
                memo[i][j] = 1 + min(memo[i-1][j-1], min(memo[i-1][j], memo[i][j-1]));
            }
        }
    }

    return memo[m][n];
}
int main() {
    string s1, s2;
    cin >> s1 >> s2;

    memset(memo,-1,sizeof(memo));
    cout << edit_distance_TD(s1, s1.length(), s2, s2.length());

    cout << endl;
    cout << edit_distance_BU(s1,s2);
    return 0;
}
