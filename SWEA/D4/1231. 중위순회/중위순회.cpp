#include <iostream>
#include <unordered_map>
#include <tuple>
#include <sstream>

using namespace std;
typedef tuple<char, int, int> tcii; // char, left, right

void inorder(unordered_map<int, tcii> &tree, int id, string &ans)
{
    char c;
    int l, r;
    tie(c, l, r) = tree[id];
    if (l != -1)
        inorder(tree, l, ans);
    ans += c;
    if (r != -1)
        inorder(tree, r, ans);
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
        unordered_map<int, tcii> tree;
        for (int i = 0; i < n; i++)
        {
            getline(cin, input);
            istringstream iss(input);
            l = r = -1;
            iss >> id >> c >> l >> r;
            tree[id] = {c, l, r};
        }

        string ans = "";
        inorder(tree, 1, ans);
        cout << "#" << tc + 1 << " " << ans << "\n";
    }

    return 0;
}