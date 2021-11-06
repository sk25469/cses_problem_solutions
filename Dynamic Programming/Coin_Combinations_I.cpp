#include <bits/stdc++.h>
using namespace std;

const int MOD = 1e9 + 7;

int main()
{
    int n, amt;
    cin >> n >> amt;

    vector<int> coins(n);

    for (auto &i : coins)
        cin >> i;

    int dp[amt + 1];
    memset(dp, 0, sizeof(dp));

    dp[0] = 1;

    for (int weight = 0; weight <= amt; weight++)
    {
        for (int i = 1; i <= n; i++)
        {
            if (weight - coins[i - 1] >= 0)
            {
                dp[weight] += dp[weight - coins[i - 1]];
                dp[weight] %= MOD;
            }
        }
    }

    cout << dp[amt] << endl;
}