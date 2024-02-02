#include <iostream>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int n, m, M, t, r;
    cin >> n >> m >> M >> t >> r;
    if (m + t > M)
    {
        cout << -1;
        return 0;
    }

    int ans = 0, pulse = m, trained = 0;
    while (trained < n)
    {
        if (pulse + t <= M)
        {
            pulse += t;
            trained++;
        }
        else
        {
            pulse -= r;
            if (pulse < m)
                pulse = m;
        }
        ans++;
    }
    cout << ans;

    return 0;
}