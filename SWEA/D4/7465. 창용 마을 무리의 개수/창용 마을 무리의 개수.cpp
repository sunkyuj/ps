#include <iostream>
#include <vector>
#include <unordered_map>
#include <queue>
using namespace std;

queue<int> q;
void bfs(int start, unordered_map<int, vector<int>> &conn, bool visited[])
{
    q.push(start);
    visited[start] = true;
    while (!q.empty())
    {
        int cur = q.front();
        q.pop();
        for (int next : conn[cur])
        {
            if (!visited[next])
            {
                q.push(next);
                visited[next] = true;
            }
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int T;
    cin >> T;

    for (int tc = 0; tc < T; tc++)
    {
        int n, m;
        cin >> n >> m;
        unordered_map<int, vector<int>> conn;
        for (int i = 1; i <= n; i++)
            conn[i] = vector<int>();
        for (int i = 0; i < m; i++)
        {
            int a, b;
            cin >> a >> b;
            conn[a].push_back(b);
            conn[b].push_back(a);
        }
        bool visited[101] = {0};
        int ans = 0;
        for (int i = 1; i <= n; i++)
        {
            if (!visited[i])
            {
                bfs(i, conn, visited);
                ans++;
            }
        }

        cout << "#" << tc + 1 << " " << ans << "\n";
    }

    return 0;
}