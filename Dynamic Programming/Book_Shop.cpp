#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n, amt;
    cin >> n >> amt;
    int price[n], pages[n];

    for (int i = 0; i < n; i++)
        cin >> price[i];

    for (int i = 0; i < n; i++)
        cin >> pages[i];

    int dp[n + 1][amt + 1];
    memset(dp, 0, sizeof(dp));

    for (int i = 1; i <= n; i++)
    {
        for (int j = 0; j <= amt; j++)
        {
            dp[i][j] = dp[i - 1][j];
            int left = j - price[i - 1];
            if (left >= 0)
                dp[i][j] = max(dp[i][j], dp[i - 1][left] + pages[i - 1]);
        }
    }
    cout << dp[n][amt] << endl;
}