#include <iostream>

using namespace std;

int n, m, r;
int tmp[301][301];
int board[301][301];
int dy[] = {1, 0, -1, 0};
int dx[] = {0, 1, 0, -1};

void rotate()
{
    int yl = n - 1, xl = m - 1;
    for (int start = 0; start < n / 2 && start < m / 2; start++)
    {
        int dir = 0;
        int y = start, x = start;
        for (int i = 0; i < yl; i++)
        {
            tmp[y + 1][x] = board[y][x];
            y += 1;
        }
        for (int i = 0; i < xl; i++)
        {
            tmp[y][x + 1] = board[y][x];
            x += 1;
        }
        for (int i = 0; i < yl; i++)
        {
            tmp[y - 1][x] = board[y][x];
            y -= 1;
        }
        for (int i = 0; i < xl; i++)
        {
            tmp[y][x - 1] = board[y][x];
            x -= 1;
        }

        yl -= 2;
        xl -= 2;
    }

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
            board[i][j] = tmp[i][j];
    }
}

int main()
{
    cin >> n >> m >> r;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
            cin >> board[i][j];
    }

    while (r--)
        rotate();

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
            cout << board[i][j] << " ";
        cout << "\n";
    }
    return 0;
}