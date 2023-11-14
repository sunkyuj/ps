#include <iostream>

using namespace std;

int main()
{
    int n, m;
    cin >> n >> m;
    int board[n][m];
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cin >> board[i][j];
        }
    }

    int ans = n * m * 2;
    for (int i = 0; i < n; i++)
    {
        int cur = 0;
        for (int j = 0; j < m; j++)
        {
            ans += abs(board[i][j] - cur);
            cur = board[i][j];
        }
        ans += board[i][m - 1];
    }
    for (int j = 0; j < m; j++)
    {
        int cur = 0;
        for (int i = 0; i < n; i++)
        {
            ans += abs(board[i][j] - cur);
            cur = board[i][j];
        }
        ans += board[n - 1][j];
    }
    cout << ans;
    return 0;
}