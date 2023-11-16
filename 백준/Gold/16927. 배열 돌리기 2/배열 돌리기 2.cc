#include <iostream>

using namespace std;

int n, m, r;
int board[301][301];

void swap(int &x, int &y)
{
    int tmp = y;
    y = x;
    x = tmp;
}

void rotate(int sy, int sx, int yl, int xl)
{
    int dir = 0;
    int y = sy, x = sx;

    for (int i = 0; i < xl; i++)
    {
        swap(board[y][x + 1], board[y][x]);
        x += 1;
    }
    for (int i = 0; i < yl; i++)
    {
        swap(board[y + 1][x], board[y][x]);
        y += 1;
    }

    for (int i = 0; i < xl; i++)
    {
        swap(board[y][x - 1], board[y][x]);
        x -= 1;
    }
    for (int i = 0; i < yl - 1; i++)
    {
        swap(board[y - 1][x], board[y][x]);
        y -= 1;
    }
}

int main()
{
    cin >> n >> m >> r; // r <= 10억
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
            cin >> board[i][j];
    }

    for (int i = 0; i < min(n / 2, m / 2); i++)
    {
        int ey = n - 1 - i, ex = m - 1 - i;
        int l = 2 * (ey - i + ex - i);
        for (int rot = 0; rot < r % l; rot++)
        {
            rotate(i, i, ey - i, ex - i);
        }
    }

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
            cout << board[i][j] << " ";
        cout << "\n";
    }
    return 0;
}
