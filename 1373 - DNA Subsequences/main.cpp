#include <iostream>
#include <string>
#include <cstring>

using namespace std;

int dp[1001][1001];

int max (int a, int b)
{
    if(a > b)return a;
    else return b;
}

int maxSubsequence(int a, int b, string w1, string w2, short k, bool sum1)
{
    if(dp[a][b] == -1)
    {
        if (w1[a+k] == '\0' || w2[b+k] == '\0')
        {
            dp[a][b] = 0;
        }
        else if(w1.substr(a,k) == w2.substr(b,k) )
        {
            dp[a][b] = ((sum1) ? 1 : k) + maxSubsequence(a+1, b+1, w1, w2, k, true);
        } 
        else
        {
            dp[a][b] = max(maxSubsequence(a+1,b,w1,w2,k, false), maxSubsequence(a,b+1,w1,w2,k, false));
        }
    }

    return dp[a][b];
}


int main()
{

    short k;
    cin >> k;

    string w1;
    string w2;

    while(k != 0)
    {
        cin >> w1 >> w2;
        memset(dp,-1,sizeof dp);        
        cout << maxSubsequence(0,0,w1,w2,k,false);

        cin >> k;
    }

    return 0;
}
