#include <iostream>
#include <list>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    for (int tc = 0; tc < 10; tc++)
    {
        int n, m, x, y, s, el;
        char cmd;
        cin >> n;
        list<int> li;
        auto it = li.begin();
        int idx = 0;
        for (int i = 0; i < n; i++)
        {
            cin >> el;
            li.emplace_back(el);
        }

        cin >> m;
        for (int i = 0; i < m; i++)
        {
            it = li.begin();
            cin >> cmd;
            if (cmd == 'I')
            {
                cin >> x >> y;
                for (int j = 0; j < x; j++)
                    it++;
                for (int j = 0; j < y; j++)
                {
                    cin >> s;
                    it = li.insert(it, s);
                    it++;
                }
                n += y;
            }
            else if (cmd == 'D')
            {
                cin >> x >> y;
                for (int j = 0; j < x; j++)
                    it++;
                for (int j = 0; j < y; j++)
                {
                    if (it == li.end())
                        break;
                    it = li.erase(it);
                    n--;
                }
            }
            else
            {
                cin >> y;
                for (int j = 0; j < y; j++)
                {
                    cin >> s;
                    li.emplace_back(s);
                }
                n += y;
            }
        }
        cout << "#" << tc + 1 << " ";
        it = li.begin();
        for (int i = 0; i < 10 && it != li.end(); i++)
            cout << *it++ << " ";
        cout << "\n";
    }
    return 0;
}