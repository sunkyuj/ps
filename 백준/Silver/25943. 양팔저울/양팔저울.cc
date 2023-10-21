#include <iostream>

using namespace std;

int main()
{
    int n, arr[10001];
    int l = 0, r = 0;
    int choo[7] = {1, 2, 5, 10, 20, 50, 100};
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
        if (l <= r)
            l += arr[i];
        else
            r += arr[i];
    }
    int diff = abs(l - r);
    int ans = 0;
    for (int i = 6; i >= 0; i--)
    {
        if (diff == 0)
            break;
        ans += diff / choo[i];
        diff %= choo[i];
    }
    cout << ans;
    return 0;
}