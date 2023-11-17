#include <iostream>
#include <string>

using namespace std;

int n, k; // 1000, 1000
string wheel[1001];
int top[1001] = {0};

// idx 2 = 오른쪽, idx 6 = 왼쪽
// rot_dir == 1 -> 시계
void rotate(int idx, int rot_dir, int move)
{
    int cur_top = top[idx];
    if ((move == 0 || move == -1) && idx - 1 >= 0 && wheel[idx - 1][2] != wheel[idx][6])
    {
        rotate(idx - 1, -rot_dir, -1);
    }

    if ((move == 0 || move == 1) && idx + 1 < n && wheel[idx][2] != wheel[idx + 1][6])
    {
        rotate(idx + 1, -rot_dir, 1);
    }

    if (rot_dir == 1)
    {
        string c = "";
        c += wheel[idx][7];
        wheel[idx] = c + wheel[idx].substr(0, 7);
    }
    else
    {
        string c = "";
        c += wheel[idx][0];
        wheel[idx] = wheel[idx].substr(1, 7) + c;
    }
}

int main()
{
    cin >> n;

    for (int i = 0; i < n; i++)
        cin >> wheel[i];
    cin >> k;

    for (int i = 0; i < k; i++) // 1000
    {
        int num, rot_dir;
        cin >> num >> rot_dir;
        rotate(num - 1, rot_dir, 0); // both
    }

    int ans = 0;
    for (int i = 0; i < n; i++)
        ans += wheel[i][0] - '0';
    cout << ans;
    return 0;
}