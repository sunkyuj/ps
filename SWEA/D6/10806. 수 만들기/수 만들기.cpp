#include <iostream>
#include <algorithm>
#include <queue>
using namespace std;
typedef unsigned long long ll;
typedef pair<ll, ll> pll;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int T;
    cin >> T;
    for (int tc = 1; tc <= T; tc++)
    {
        int n, k;
        ll x = 0, d = 1;
        cin >> n;
        int arr[n];

        for (int i = 0; i < n; i++)
            cin >> arr[i];
        sort(arr, arr + n);
        cin >> k;
        ll ans = k;

        priority_queue<pll, vector<pll>, greater<pll>> pq; // {cnt, rem}
        pq.push({0, k});

        while (!pq.empty())
        {
            ll cnt = pq.top().first;
            ll rem = pq.top().second;
            pq.pop();

            if (rem == 0)
            {
                ans = cnt;
                break;
            }
            pq.push({cnt + rem, 0});
            for (int i = 0; i < n; i++)
            {
                pq.push({cnt + rem % arr[i], rem / arr[i]});
            }
        }

        cout << "#" << tc << " " << ans << "\n";
    }
    return 0;
}