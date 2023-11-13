#include <iostream>

using namespace std;
typedef long long ll;

void set_garosero(string garo[], string sero[], int s)
{
    string g0 = "";
    for (int i = 0; i < s + 2; i++)
        g0 += " ";

    string g1 = " ";
    for (int i = 0; i < s; i++)
        g1 += "-";
    g1 += " ";
    garo[0] = g0;
    garo[1] = g1;

    string s0 = "";
    for (int i = 0; i < s + 2; i++)
        s0 += " ";
    string s1 = "";
    for (int i = 0; i < s + 1; i++)
        s1 += " ";
    s1 += "|";
    string s2 = "|";
    for (int i = 0; i < s + 1; i++)
        s2 += " ";
    string s3 = "|";
    for (int i = 0; i < s; i++)
        s3 += " ";
    s3 += "|";

    sero[0] = s0;
    sero[1] = s1;
    sero[2] = s2;
    sero[3] = s3;
}

int main()
{
    int s;
    string n;
    cin >> s >> n;
    int number[10][5] = {
        {1, 3, 0, 3, 1},
        {0, 1, 0, 1, 0},
        {1, 1, 1, 2, 1},
        {1, 1, 1, 1, 1},
        {0, 3, 1, 1, 0},
        {1, 2, 1, 1, 1},
        {1, 2, 1, 3, 1},
        {1, 1, 0, 1, 0},
        {1, 3, 1, 3, 1},
        {1, 3, 1, 1, 1},
    };
    // 탑 0~1
    // 사이 0~3
    // 미드 0~1
    // 사이 0~3
    // 바텀 0~1
    string garo[2];
    string sero[4];
    set_garosero(garo, sero, s);

    int top = 0, mid = s + 1, bot = 2 * s + 2;
    for (int i = 0; i < bot + 1; i++)
    {
        for (auto &x : n)
        {
            if (i == top)
            {
                cout << garo[number[x - '0'][0]] << " ";
            }
            else if (i < mid)
            {
                cout << sero[number[x - '0'][1]] << " ";
            }
            else if (i == mid)
            {
                cout << garo[number[x - '0'][2]] << " ";
            }
            else if (i < bot)
            {
                cout << sero[number[x - '0'][3]] << " ";
            }
            else // i==bot
            {
                cout << garo[number[x - '0'][4]] << " ";
            }
        }
        cout << "\n";
    }

    return 0;
}
/*

0~3
4~7
8~11
...

s=1, 가로=3, 세로=5

     -   -
  |   |   |
     -   -
  | |     |
     -   -



      --   --        --   --   --   --   --   --
   |    |    | |  | |    |       | |  | |  | |  |
   |    |    | |  | |    |       | |  | |  | |  |
      --   --   --   --   --        --   --
   | |       |    |    | |  |    | |  |    | |  |
   | |       |    |    | |  |    | |  |    | |  |
      --   --        --   --        --   --   --


*/