#include <iostream>
#include <algorithm>
#include <queue>
#include <vector>
#define MAX 50000001

using namespace std;

typedef pair<int, int> pii;

int main()
{
    int n, m;
    cin >> n >> m;

    int dist[n + 1];
    dist[1] = 0;
    for (int i = 2; i <= n; i++)
        dist[i] = MAX;

    vector<pii> conn[n + 1];
    for (int i = 0; i < m; i++)
    {
        int a, b, c;
        cin >> a >> b >> c;
        conn[a].push_back(make_pair(b, c));
        conn[b].push_back(make_pair(a, c));
    }

    priority_queue<pii> pq;
    pq.push(make_pair(0, 1)); // -cost,v

    while (!pq.empty())
    {
        int cost = -pq.top().first, v = pq.top().second;
        pq.pop();
        if (cost > dist[v])
            continue;


        for (auto &[nxt, ncost] : conn[v])
        {
            if (dist[nxt] > cost + ncost)
            {
                dist[nxt] = cost + ncost;
                pq.push(make_pair(-dist[nxt], nxt));
            }
        }
    }

    cout << dist[n];
    return 0;
}