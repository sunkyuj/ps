#include <iostream>
#include <queue>
#define MAX 10000001

using namespace std;

typedef pair<int, int> pii;
typedef pair<int, pii> node;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int T;
    cin >> T;
    string board[101];
    pii dydx[4] = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};
    for (int tc = 1; tc <= T; tc++)
    {
        int n;
        cin >> n;
        int ans = 0;
        for (int i = 0; i < n; i++)
            cin >> board[i];

        priority_queue<node> pq; // {-cost, {x,y}}
        pq.push({0, {0, 0}});
        int dist[n][n];
        for (int i = 0; i < n; i++)
            for (int j = 0; j < n; j++)
                dist[i][j] = 987654321;

        while (!pq.empty())
        {
            int cost = -pq.top().first;
            int x = pq.top().second.first;
            int y = pq.top().second.second;
            pq.pop();

            if (x == n - 1 && y == n - 1)
            {
                ans = cost;
                break;
            }

            for (int k = 0; k < 4; k++)
            {
                auto [dy, dx] = dydx[k];
                int ny = y + dy, nx = x + dx;
                if (ny < 0 || nx < 0 || ny >= n || nx >= n)
                    continue;
                int ncost = cost + (board[ny][nx] - '0');
                if (dist[ny][nx] > ncost)
                {
                    dist[ny][nx] = ncost;
                    pq.push({-ncost, {nx, ny}});
                }
            }
        }

        cout << "#" << tc << " " << ans << "\n";
    }
    return 0;
}