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
#define fbo(a) find_by_order(a) // will give a-th largest element
#define ook(a) order_of_key(a)  // will give no. of elements strictly lesser than a
#define pii pair<int, int>
#define decint greater<int>()
#define decll greater<ll>()
#define mem(a, x) memset(a, x, sizeof(a))
#define vll vector<long long>
#define pll pair<long long, long long>
#define pb push_back
#define all(c) c.begin(), c.end()
#define all_ar(ar, n) ar, ar + n
#define For(i, a, b) for (size_t i = a; i < b; ++i)
#define Rof(i, a, b) for (size_t i = a; i >= b; i--)
#define out(x) cout << x << endl
#define out2(x, y) cout << x << " " << y << endl
#define inarr(arr, n) For(i, 0, n) cin >> arr[i]
#define mx_a(arr, n) max_element(arr, arr + n)
#define mn_a(arr, n) min_element(arr, arr + n)
#define mx_c(container) max_element(container.begin(), container.end())
#define mn_c(container) min_element(container.begin(), container.end())
#define un_m unordered_map
#define read1(x) cin >> x
#define read2(x, y) cin >> x >> y
#define read3(x, y, z) cin >> x >> y >> z
#define NOT_FOUND string::npos
#define vec_2d vector<vector<int>>

#define fast_io()                     \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);                    \
    cout.tie(NULL);

const ll INF = 1e18;
const int MOD = 1e9 + 7;

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

const int N = 1e5 + 2;
int parent[N], siz[N];
int n, m;

void make_set(int x)
{
    parent[x] = x;
    siz[x] = 1;
}

int find_set(int x)
{
    if (x == parent[x])
        return x;
    return find_set(parent[x]);
}

bool areSame(int x, int y)
{
    return find_set(x) == find_set(y);
}

void union_sets(int a, int b)
{
    a = find_set(a);
    b = find_set(b);
    if (a != b)
    {
        if (siz[a] < siz[b])
            swap(a, b);
        parent[b] = a;
        siz[a] += siz[b];
    }
}

void solve()
{
    read2(n, m);
    int mx = 1, ini = n;
    for (int i = 1; i <= n; i++)
        make_set(i);

    for (int i = 0; i < m; i++)
    {
        int x, y;
        read2(x, y);

        if (!areSame(x, y))
        {
            union_sets(x, y);
            int a = find_set(x), b = find_set(y);
            mx = max({siz[a], siz[b], mx});
            ini--;
        }
        out2(ini, mx);
    }
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
        solve();
    }

    return 0;
}