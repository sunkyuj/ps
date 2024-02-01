#include <iostream>
#include <algorithm>
#include <vector>

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
        int k;
        cin >> k;
        string s, ans;
        cin >> s;
        vector<string> v;
        for (int i = 0; i < s.size(); i++)
        {
            for (int l = 1; l <= s.size() - i; l++)
                v.push_back(s.substr(i, l));
        }
        sort(v.begin(), v.end());
        unique(v.begin(), v.end());
        ans = (v.size() > k) ? v[k - 1] : "none";
        cout << "#" << tc << " " << ans << "\n";
    }
    return 0;
}