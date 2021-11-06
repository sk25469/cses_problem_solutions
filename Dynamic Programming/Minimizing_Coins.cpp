#include <bits/stdc++.h>
#define ll long long
using namespace std;

int main()
{
    int n, amt;
    cin >> n >> amt;

    vector<int> coins(n);

    for (auto &i : coins)
        cin >> i;

    ll dp[amt + 1];

    for (int i = 0; i <= amt; i++)
        dp[i] = INT_MAX;

    dp[0] = 0;

    for (int i = 1; i <= n; i++)
    {
        for (int weight = 0; weight <= amt; weight++)
        {
            if (weight - coins[i - 1] >= 0)
                dp[weight] = min(dp[weight], dp[weight - coins[i - 1]] + 1);
        }
    }

    if (dp[amt] == INT_MAX)
        cout << -1 << endl;
    else
        cout << dp[amt] << endl;
}