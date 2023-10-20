#include <iostream>

using namespace std;
typedef long long ll;

int used[21], arr[21];

void f1(int n, ll k, ll nfac)
{
    if (n == 0)
        return;

    ll chunk = nfac / n;
    int i;
    for (i = 1; i <= n; i++)
    {
        if (k <= chunk * i)
            break;
    }
    int cnt = 0;
    for (int num = 1; num <= 20; num++)
    {
        if (used[num])
            continue;
        cnt++;
        if (cnt == i)
        {
            used[num] = 1;
            cout << num << " ";
            break;
        }
    }
    f1(n - 1, k - (i - 1) * chunk, chunk);
}

ll f2(int idx, int n, ll nfac)
{
    if (n == 0)
        return 1;
    ll chunk = nfac / n;
    int cnt = 0;
    int i;
    for (i = 1; i <= 20; i++)
    {
        if (used[i])
            continue;
        cnt++;
        if (i == arr[idx])
        {
            used[i] = 1;
            break;
        }
    }
    return chunk * (cnt - 1) + f2(idx + 1, n - 1, chunk);
}

int main()
{
    int n, qnum;
    ll k, nfac = 1;
    cin >> n;
    for (int i = 1; i <= n; i++)
        nfac *= i;

    cin >> qnum;
    if (qnum == 1)
    {
        cin >> k;
        f1(n, k, nfac);
    }
    else
    {
        for (int i = 1; i <= n; i++)
            cin >> arr[i];
        cout << f2(1, n, nfac);
    }
}
