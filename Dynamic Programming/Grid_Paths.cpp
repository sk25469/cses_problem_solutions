#include <bits/stdc++.h>
using namespace std;

const int MOD = 1e9 + 7;
int main()
{
    int n;
    cin >> n;

    vector<string> grid(n);
    for (auto &i : grid)
        cin >> i;

    int dp[n][n];
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
            dp[i][j] = 0;
    }

    for (int i = 0; i < n; i++)
    {
        if (grid[i][0] == '*')
            break;
        else
            dp[i][0] = 1;
    }

    for (int i = 0; i < n; i++)
    {
        if (grid[0][i] == '*')
            break;
        else
            dp[0][i] = 1;
    }

    // for (int i = 0; i < n; i++)
    // {
    //     for (int j = 0; j < n; j++)
    //         cerr << dp[i][j] << " ";
    //     cerr << endl;
    // }

    for (int i = 1; i < n; i++)
    {
        for (int j = 1; j < n; j++)
        {
            if (grid[i][j] != '*')
                dp[i][j] = dp[i - 1][j] % MOD + dp[i][j - 1] % MOD;
            else
                dp[i][j] = 0;
            dp[i][j] %= MOD;
        }
    }

    cout << dp[n - 1][n - 1] << endl;
}