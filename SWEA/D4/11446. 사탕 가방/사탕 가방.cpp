#include <iostream>
#include <vector>
using namespace std;

typedef long long ll;

ll binSearch(vector<ll> arr, ll max, ll m)
{
    ll l = 1, r = max;
    while (l <= r)
    {
        ll mid = (l + r) / 2;
        ll cnt = 0;
        for (ll x : arr)
            cnt += x / mid;

        if (cnt < m)
            r = mid - 1;
        else
            l = mid + 1;
    }
    return r;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int T;
    cin >> T;
    for (int tc = 1; tc <= T; tc++)
    {
        ll n, m, max = 0;
        cin >> n >> m; // m: 10**18 = 100경
        vector<ll> arr(n);
        for (int i = 0; i < n; i++)
        {
            cin >> arr[i]; // arr[i]: 10**18 = 100경
            if (max < arr[i])
                max = arr[i];
        }
        ll ans = binSearch(arr, max, m);

        cout << "#" << tc << " " << ans << "\n";
    }
    return 0;
}