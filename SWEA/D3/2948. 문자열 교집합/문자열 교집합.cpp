#include <iostream>
#include <unordered_map>
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
        int n, m;
        cin >> n >> m; // 10만, 10만
        int ans = 0;
        string s;
        unordered_map<string, int> mp;
        for (int i = 0; i < n; i++)
        {
            cin >> s;
            mp[s] = 1;
        }
        for (int i = 0; i < m; i++)
        {
            cin >> s;
            if (mp[s] == 1)
                ans++;
        }
        cout << "#" << tc << " " << ans << "\n";
    }
    return 0;
}