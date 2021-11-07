#include <bits/stdc++.h>
#define ll long long
using namespace std;

const int MOD = 1e9 + 7;

int main()
{
    int n, amt;
    cin >> n >> amt;

    vector<int> coins(n);
    for (auto &i : coins)
        cin >> i;

    ll dp[amt + 1];
    memset(dp, 0, sizeof(dp));
    dp[0] = 1;

    for (int i = 1; i <= n; i++)
    {
        for (int j = 0; j <= amt; j++)
        {
            if (j - coins[i - 1] >= 0)
            {
                dp[j] += dp[j - coins[i - 1]];
                dp[j] %= MOD;
            }
        }
    }

    cout << dp[amt] << endl;
}