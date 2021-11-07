#include <bits/stdc++.h>
#define ll long long
using namespace std;

set<int> digits(int n)
{
    set<int> dig;
    while (n)
    {
        int x = n % 10;
        n /= 10;
        if (x)
            dig.insert(x);
    }

    return dig;
}

int main()
{
    int n;
    cin >> n;

    int dp[n + 1];
    for (int i = 0; i <= n; i++)
        dp[i] = INT_MAX;
    dp[0] = 0;
    for (int i = 1; i <= 9; i++)
        dp[i] = 1;

    if (n <= 9)
        cout << dp[n] << endl;
    else
    {
        // for (int i = 0; i <= n; i++)
        //     cerr << dp[i] << " ";
        // cerr << endl;
        for (int i = 10; i <= n; i++)
        {
            set<int> dig = digits(i);

            for (int digits : dig)
                dp[i] = min(dp[i], dp[i - digits] + 1);
            // cerr << "dp[" << i << "] is " << dp[i] << endl;
        }

        cout << dp[n] << endl;
    }
}