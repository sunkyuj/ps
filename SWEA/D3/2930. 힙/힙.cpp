#include <iostream>
#include <queue>

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
        cout << "#" << tc << " ";

        int n;
        priority_queue<int> pq;
        cin >> n;
        for (int i = 0; i < n; i++)
        {
            int cmd, x;
            cin >> cmd;
            if (cmd == 1)
            {
                cin >> x;
                pq.push(x);
            }
            else
            {
                if (pq.empty())
                    cout << "-1 ";
                else
                {
                    cout << pq.top() << " ";
                    pq.pop();
                }
            }
        }
        cout << "\n";
    }

    return 0;
}