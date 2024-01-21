#include <iostream>
#include <algorithm>
#define MAX 500001
using namespace std;

int cows[MAX], horses[MAX]; // 10**8 = 1억
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int T;
    cin >> T;
    for (int tc = 1; tc <= T; tc++)
    {
        int n, m, c1, c2;
        cin >> n >> m >> c1 >> c2;

        for (int i = 0; i < n; i++)
            cin >> cows[i];
        for (int i = 0; i < m; i++)
            cin >> horses[i];
        sort(cows, cows + n);
        sort(horses, horses + m);

        int ans = 100000001;
        int cnt = 0;
        for (int i = 0; i < n; i++)
        {
            int big = lower_bound(horses, horses + m, cows[i]) - horses;
            big = min(big, m - 1);
            int small = max(big - 1, 0);

            int left = abs(cows[i] - horses[small]),
                right = abs(cows[i] - horses[big]);
            int min_val = min(left, right);
            if (min_val < ans)
            {
                ans = min_val;
                cnt = 1;
                if (small != big && left == right)
                    cnt++;
            }
            else if (min_val == ans)
            {
                cnt++;
                if (small != big && left == right)
                    cnt++;
            }
        }
        cout << "#" << tc << " " << ans + abs(c1 - c2) << " " << cnt << "\n";
    }
    return 0;
}