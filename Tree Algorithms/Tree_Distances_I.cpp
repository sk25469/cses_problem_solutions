/* Code by - Sahil Sarwar 😎😎*/

#include <bits/stdc++.h>
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

#define nl '\n'
#define ll long long
#define vec vector
#define vi vector<int>
#define pqmax priority_queue<int>
#define pqmin priority_queue<int, vector<int>, greater<int>>
#define fbo(a) find_by_order(a) // will give a-th largest element
#define ook(a) order_of_key(a)  // will give no. of elements strictly lesser than a
#define pii pair<int, int>
#define mem(a, x) memset(a, x, sizeof(a))
#define vll vector<long long>
#define pll pair<long long, long long>
#define pb push_back
#define all(c) c.begin(), c.end()
#define For(i, a, b) for (size_t i = a; i < b; ++i)
#define pf(x) cout << x << '\n'
#define pf2(x, y) cout << x << " " << y << '\n'
#define pf3(x, y, z) cout << x << " " << y << " " << z << '\n';
#define inarr(arr, n) For(i, 0, n) cin >> arr[i]
#define mx_c(container) max_element(container.begin(), container.end())
#define mn_c(container) min_element(container.begin(), container.end())
#define un_m unordered_map
#define in(x) cin >> x
#define in2(x, y) cin >> x >> y
#define in3(x, y, z) cin >> x >> y >> z
#define NF string::npos
#define vec_2d vector<vector<int>>
#define sz(x) x.size()

#define fast_io()                     \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);                    \
    cout.tie(NULL);

const ll INF = 1e18;
const int MOD = 1e9 + 7;
const int dx[4] = {-1, 1, 0, 0};
const int dy[4] = {0, 0, -1, 1};

inline int64_t mul(int64_t a, int64_t b)
{
    return (INF / a > b ? a * b : INF);
}

inline int64_t add(int64_t a, int64_t b)
{
    return (a + b >= INF ? INF : a + b);
}

vector<bool> sieve(ll n)
{
    vector<bool> isPrime(n + 1, 0);
    isPrime[0] = isPrime[1] = true;
    for (int i = 2; i * i <= n; i++)
    {
        if (isPrime[i])
        {
            for (int j = i * i; j <= n; j += i)
                isPrime[j] = false;
        }
    }
    // after this, all the numbers which are primes are marked as 1
    return isPrime;
}

bool isPerfectSquare(ll x)
{
    if (x >= 0)
    {
        long long sr = sqrt(x);
        return (sr * sr == x);
    }
    return false;
}

bool isPrime(ll n)
{
    if (n == 0 || n == 1)
        return false;
    for (int i = 2; i * i <= n; i++)
    {
        if (n % i == 0)
            return false;
    }
    return true;
}

// a to power b
ll binpow(ll a, ll b)
{
    ll res = 1;
    while (b > 0)
    {
        if (b & 1)
            res = res * a;
        a = a * a;
        b >>= 1;
    }
    return res;
}

const int MAXM = 2e5 + 1;
vi adj[MAXM];

// we find the 2 edges with most distance from the root, a and b
// dp[0][i] => distance from a to i
// dp[1][i] => distance from b to i
int dp[2][MAXM];

int dfs(int curr, int par, int depth, int i)
{
    dp[i][curr] = depth;
    int opt = -1;
    for (int next : adj[curr])
    {
        if (next != par)
        {
            int x = dfs(next, curr, depth + 1, i);

            // we are storing the depth of curr node
            if (opt == -1 || dp[i][x] > dp[i][opt])
                opt = x;
        }
    }

    return opt == -1 ? curr : opt;
}

void solve()
{
    int n;
    cin >> n;

    for (int i = 0; i < n - 1; i++)
    {
        int x, y;
        in2(x, y);
        adj[x].pb(y);
        adj[y].pb(x);
    }

    int a = dfs(1, 1, 0, 0);

    // in this dfs, we will also calculate the distance from a to each node
    int b = dfs(a, a, 0, 0);

    // we say that max distance from each node will be one of the 2 nodes
    // at the most length from the root

    // distance from b to every node
    dfs(b, b, 0, 1);

    for (int i = 1; i <= n; i++)
        cout << max(dp[0][i], dp[1][i]) << " \n"[i == n];
}

int main()
{
    fast_io();
    int t = 1;
    // cin >> t;

    while (t--)
    {
        solve();
    }

    return 0;
}