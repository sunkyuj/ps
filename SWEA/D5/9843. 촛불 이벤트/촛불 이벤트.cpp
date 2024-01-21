#include <iostream>
#include <math.h>
using namespace std;
typedef unsigned long long ll;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int T;
    cin >> T;
    for (int tc = 1; tc <= T; tc++)
    {
        ll n;
        cin >> n; // 10**18 = 100경
        ll ans;
        ll root = sqrt(8 * n + 1);
        ll k = root / 2;
        if (k * (k + 1) / 2 == n)
            cout << "#" << tc << " " << k << "\n";

        else
            cout << "#" << tc << " " << -1 << "\n";
    }
    return 0;
}
