#include <bits/stdc++.h>
using namespace std;

int main()
{
    int r, c;
    cin >> r >> c;

    int dp[r + 1][c + 1];
    memset(dp, 0, sizeof(dp));

    for (int row = 0; row <= r; row++)
    {
        for (int col = 0; col <= c; col++)
        {
            if (row == col)
                dp[row][col] = 0;
            else
            {
                dp[row][col] = 1e9;
                for (int k = 1; k <= row - 1; k++)
                {
                    dp[row][col] = min(dp[row][col], dp[k][col] + dp[row - k][col] + 1);
                }

                for (int k = 1; k <= col - 1; k++)
                {
                    dp[row][col] = min(dp[row][col], dp[row][k] + dp[row][col - k] + 1);
                }
            }
        }
    }

    cout << dp[r][c] << endl;
}