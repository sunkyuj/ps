#include <iostream>

using namespace std;
typedef long long ll;

int main()
{
    int n;
    ll ans = 1;
    cin >> n;
    for (int i = 1; i <= n; i++)
        ans *= i;
    cout << ans;
    return 0;
}