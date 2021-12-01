#include <bits/stdc++.h>
using namespace std;

using ll = long long;
const int MX = 2e5 + 5;

int n, q;
vector<ll> bit(MX), x(MX);

void upd(int i, ll v)
{
    for (; i <= n; i += i & (-i))
        bit[i] += v;
}

ll qry(int i)
{
    ll sum = 0;
    for (; i > 0; i -= i & (-i))
        sum += bit[i];
    return sum;
}

int main()
{
    cin >> n >> q;
    for (int i = 1; i <= n; i++)
    {
        cin >> x[i];
        upd(i, x[i]);
    }
    for (int i = 1; i <= q; i++)
    {
        int t, a, b;
        cin >> t >> a >> b;
        if (t == 1)
        {
            upd(a, b - x[a]); // remove its current value
            x[a] = b;
        }
        else
        {
            cout << qry(b) - qry(a - 1) << "\n";
        }
    }
}