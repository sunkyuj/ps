#include <iostream>
#include <algorithm>
#include <queue>
#define MOD 20171109

using namespace std;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int T;
    cin >> T;
    for (int tc = 1; tc <= T; tc++)
    {
        int n, mid;
        cin >> n >> mid;
        int ans = 0;
        priority_queue<int> maxh;
        priority_queue<int, vector<int>, greater<int>> minh;
        for (int i = 0; i < n; i++)
        {
            int x, y;
            cin >> x >> y;
            if (x > mid)
                minh.push(x);
            else
                maxh.push(x);
            if (y > mid)
                minh.push(y);
            else
                maxh.push(y);

            if (minh.size() > maxh.size())
            {
                maxh.push(mid);
                mid = minh.top();
                minh.pop();
            }
            else if (minh.size() < maxh.size())
            {
                minh.push(mid);
                mid = maxh.top();
                maxh.pop();
            }
            ans += mid;
            ans %= MOD;
        }
        cout << "#" << tc << " " << ans << "\n";
    }

    return 0;
}