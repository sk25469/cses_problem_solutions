#include <bits/stdc++.h>
using namespace std;

int cnt;
int n, m;
string s[1001];
bool vis[1001][1001];

int dx[4] = {-1, 1, 0, 0};
int dy[4] = {0, 0, -1, 1};

void dfs(int x, int y)
{
    if (vis[x][y])
        return;

    vis[x][y] = 1;

    for (int i = 0; i < 4; i++)
    {
        int xx = x + dx[i], yy = y + dy[i];

        if (xx < 0 || xx >= n || yy < 0 || yy >= m || s[xx][yy] == '#')
            continue;

        dfs(xx, yy);
    }
}

int main()
{
    cin >> n >> m;

    for (int i = 0; i < n; i++)
        cin >> s[i];

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (s[i][j] != '#' && !vis[i][j])
                dfs(i, j), cnt++;
        }
    }

    cout << cnt << endl;
}