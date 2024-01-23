#include <iostream>
#include <unordered_map>
#include <tuple>
#include <sstream>

using namespace std;
typedef tuple<string, int, int> node; // mid, left, right

int calc(unordered_map<int, node> &tree, int id)
{
    string mid;
    int l, r;
    tie(mid, l, r) = tree[id];
    int lv, rv;

    if (mid == "+" || mid == "-" || mid == "*" || mid == "/") // 연산자
    {
        lv = calc(tree, l);
        rv = calc(tree, r);
        if (mid == "+")
            return lv + rv;
        else if (mid == "-")
            return lv - rv;
        else if (mid == "*")
            return lv * rv;
        else
            return lv / rv;
    }
    else
        return stoi(mid);
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    for (int tc = 0; tc < 10; tc++)
    {
        int n, id, l, r;
        string mid;
        string input;
        cin >> n;
        cin.ignore();

        unordered_map<int, node> tree;
        for (int i = 0; i < n; i++)
        {
            getline(cin, input);
            istringstream iss(input);
            l = r = -1;
            iss >> id >> mid >> l >> r;
            tree[id] = {mid, l, r};
        }
        int ans = calc(tree, 1);
        cout << "#" << tc + 1 << " " << ans << "\n";
    }

    return 0;
}
/*
5
1 - 2 3
2 - 4 5
3 + 6 7
4 9
5 4
*/