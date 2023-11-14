#include <iostream>

using namespace std;

int main()
{
    int h, w, x, y;
    cin >> h >> w >> x >> y;

    int a[h][w];
    for (int i = 0; i < h; i++)
    {
        for (int j = 0; j < w; j++)
        {
            a[i][j] = -1;
        }
    }

    int b[h + x][w + y];
    for (int i = 0; i < h + x; i++)
    {
        for (int j = 0; j < w + y; j++)
        {
            cin >> b[i][j];
        }
    }

    for (int i = 0; i < h + x; i++)
    {
        for (int j = 0; j < w + y; j++)
        {
            if (i >= x && i < h && j >= y && j < w) // center
                a[i][j] = b[i][j] - a[i - x][j - y];
            else if ((i < x && j >= w) || (i >= h && j < y)) // 0
                continue;
            else
            {
                if (i < h && j < w)
                    a[i][j] = b[i][j];
                else
                    a[i - x][j - y] = b[i][j];
            }
        }
    }

    for (int i = 0; i < h; i++)
    {
        for (int j = 0; j < w; j++)
        {
            cout << a[i][j] << " ";
        }
        cout << "\n";
    }

    return 0;
}