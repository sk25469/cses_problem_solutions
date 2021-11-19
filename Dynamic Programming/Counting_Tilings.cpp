/* Code by - Sahil Sarwar */

#include <algorithm>
#include <bits/stdc++.h>
#include <time.h>
#include <numeric>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;

using namespace std;

// Debug templates

void __print(int x) { cerr << x; }
void __print(long x) { cerr << x; }
void __print(long long x) { cerr << x; }
void __print(unsigned x) { cerr << x; }
void __print(unsigned long x) { cerr << x; }
void __print(unsigned long long x) { cerr << x; }
void __print(float x) { cerr << x; }
void __print(double x) { cerr << x; }
void __print(long double x) { cerr << x; }
void __print(char x) { cerr << '\'' << x << '\''; }
void __print(const char *x) { cerr << '\"' << x << '\"'; }
void __print(const string &x) { cerr << '\"' << x << '\"'; }
void __print(bool x) { cerr << (x ? "true" : "false"); }

template <typename T, typename V>
void __print(const pair<T, V> &x)
{
    cerr << '{';
    __print(x.first);
    cerr << ',';
    __print(x.second);
    cerr << '}';
}
template <typename T>
void __print(const T &x)
{
    int f = 0;
    cerr << '{';
    for (auto &i : x)
        cerr << (f++ ? "," : ""), __print(i);
    cerr << "}";
}
void _print() { cerr << "]\n"; }
template <typename T, typename... V>
void _print(T t, V... v)
{
    __print(t);
    if (sizeof...(v))
        cerr << ", ";
    _print(v...);
}
#ifndef ONLINE_JUDGE
#define debug(x...)               \
    cerr << "[" << #x << "] = ["; \
    _print(x)
#else
#define debug(x...)
#endif

// debug template ends

template <typename T>
using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;

#define nl endl
#define ll long long
#define w(t) while (t--)
#define vec vector
#define vi vector<int>
#define pqmax priority_queue<int>
#define pqmin priority_queue<int, vector<int>, greater<int>>
#define ins insert
#define fbo(a) find_by_order(a) // will give a-th largest element
#define ook(a) order_of_key(a)  // will give no. of elements strictly lesser than a
#define pii pair<int, int>
#define _decint greater<int>()
#define _decll greater<ll>()
#define mem(a, x) memset(a, x, sizeof(a))
#define vll vector<long long>
#define pll pair<long long, long long>
#define pb push_back
#define all(c) c.begin(), c.end()
#define all_ar(ar, n) ar, ar + n
#define For(i, a, b) for (size_t i = a; i < b; ++i)
#define Rof(i, a, b) for (size_t i = a; i >= b; i--)
#define print_ar(ar, n)            \
    for (size_t i = 0; i < n; i++) \
    {                              \
        cout << ar[i] << " ";      \
    }
#define out(x) cout << x << endl
#define out__(x, y) cout << x << " " << y << endl
#define inarr(arr, n) For(i, 0, n) cin >> arr[i]
#define mx_a(arr, n) max_element(arr, arr + n)
#define mn_a(arr, n) min_element(arr, arr + n)
#define mx_c(container) max_element(container.begin(), container.end())
#define mn_c(container) min_element(container.begin(), container.end())
#define un_m unordered_map
#define not_found string::npos
#define vec_2d vector<vector<int>>

#define fast_io()                     \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);                    \
    cout.tie(NULL);

const ll INF = 9e18;
const int MOD = 1e9 + 7;

inline int64_t mul(int64_t a, int64_t b)
{
    return (INF / a > b ? a * b : INF);
}

inline int64_t add(int64_t a, int64_t b)
{
    return (a + b >= INF ? INF : a + b);
}

void generate_next_masks(int current_mask, int i, int next_mask, int n,
                         vector<int> &next_masks)
{
    if (i == n + 1)
    {
        next_masks.push_back(next_mask);
        return;
    }

    if ((current_mask & (1 << i)) != 0)
        generate_next_masks(current_mask, i + 1, next_mask, n, next_masks);

    if (i != n)
        if ((current_mask & (1 << i)) == 0 && (current_mask & (1 << (i + 1))) == 0)
            generate_next_masks(current_mask, i + 2, next_mask, n, next_masks);

    if ((current_mask & (1 << i)) == 0)
        generate_next_masks(current_mask, i + 1, next_mask + (1 << i), n, next_masks);
}

int dp[1001][1 << 11];
int repeat(int col, int mask, const int m, const int n)
{
    // BASE CASE
    if (col == m + 1)
    {
        if (mask == 0)
            return 1;
        return 0;
    }

    if (dp[col][mask] != -1)
        return dp[col][mask];

    int answer = 0;
    vector<int> next_masks;
    generate_next_masks(mask, 1, 0, n, next_masks);

    for (int next_mask : next_masks)
    {
        answer = (answer + repeat(col + 1, next_mask, m, n)) % MOD;
    }

    return dp[col][mask] = answer;
}

void solve()
{
    int row, col;
    cin >> row >> col;

    mem(dp, -1);

    cout << repeat(1, 0, row, col) << nl;
}

int main()
{
    fast_io();
    int t = 1;
    // cin >> t;

    clock_t p;
    p = clock();
    w(t)
    {

        // each iteration takes this time
        // p = clock() - p;
        // cerr << "time : " << float(p)/CLOCKS_PER_SEC << " sec\n";
        solve();
    }

    return 0;
}