#include <iostream>
#include <queue>
#define MAX 1001

using namespace std;
typedef long long ll;
typedef pair<int, int> pii;

int root[MAX];
int find(int v)
{
    if (root[v] == v)
        return v;
    return root[v] = find(root[v]);
}
void uni(int v1, int v2)
{
    int p1 = find(v1);
    int p2 = find(v2);

    if (p1 < p2)
        root[p2] = p1;
    else if (p1 > p2)
        root[p1] = p2;
}

int main()
{
    int T;
    pii loc[MAX];

    scanf("%d", &T);
    for (int tc = 1; tc <= T; tc++)
    {
        double ans = 0;
        int n, x, y;
        double e;
        scanf("%d", &n); // 1000
        for (int i = 0; i < n; i++)
            scanf("%d", &loc[i].first);
        for (int i = 0; i < n; i++)
            scanf("%d", &loc[i].second);
        scanf("%lf", &e);

        for (int i = 0; i < n; i++)
            root[i] = i;
        priority_queue<pair<ll, pii>> pq; // {-cost, {v1, v2}}
        for (int i = 0; i < n; i++)
        {
            for (int j = i; j < n; j++)
            {
                ll dx = loc[i].first - loc[j].first;
                ll dy = loc[i].second - loc[j].second;

                pq.push({-(dx * dx + dy * dy), {i, j}});
            }
        }

        int cnt = 0;
        while (!pq.empty() && cnt < n - 1)
        {
            ll cost = -pq.top().first;
            int v1 = pq.top().second.first;
            int v2 = pq.top().second.second;
            pq.pop();
            if (find(v1) == find(v2))
                continue;
            uni(v1, v2);
            ans += cost;
            cnt++;
        }
        ans *= e;
        printf("#%d %.0lf\n", tc, ans);
    }

    return 0;
}