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
        int k, ans = 0;
        cin >> k;
        string s;
        cin >> s;
        vector<string> v;
        for (int i = 0; i < s.size(); i++)
            v.push_back(s.substr(i));
        sort(v.begin(), v.end());

        cout << "#" << tc << " " << v[k - 1] << "\n";
    }
    return 0;
}