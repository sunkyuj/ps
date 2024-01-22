#include <iostream>
#include <unordered_map>
#include <tuple>
#include <sstream>

using namespace std;
typedef tuple<char, int, int> tiii; // op_num, left, right

int valid(unordered_map<int, tiii> &tree, int id)
{
    char c;
    int l, r;
    tie(c, l, r) = tree[id];
    int lv = 1, rv = 1;

    if (c == '+' || c == '-' || c == '*' || c == '/') // 연산자
    {
        if (l == -1 || r == -1)
            return 0;
        lv = valid(tree, l);
        rv = valid(tree, r);
        if (lv == 0 || rv == 0)
            return 0;
    }
    else // 숫자
    {
        if (l != -1 || r != -1)
            return 0;
    }

    return 1;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    for (int tc = 0; tc < 10; tc++)
    {
        int n, id, l, r;
        char c;
        string input;
        cin >> n;
        cin.ignore();

        unordered_map<int, tiii> tree;
        for (int i = 0; i < n; i++)
        {
            getline(cin, input);
            istringstream iss(input);
            l = r = -1;
            iss >> id >> c >> l >> r;
            tree[id] = {c, l, r};
        }
        int ans = valid(tree, 1);
        cout << "#" << tc + 1 << " " << ans << "\n";
    }

    return 0;
}