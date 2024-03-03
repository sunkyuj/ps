#include <iostream>
#define MAX 2000
#define HASH (1 << 30)
#define MOD (HASH - 1)
using namespace std;

typedef long long ll;
int h, w, n, m;

int my_pic[MAX][MAX], sam_pic[MAX][MAX];
int sam_hash[MAX][MAX], tmp[MAX][MAX];

int calc_mul(int num, int shift)
{
    ll rev = 1;
    for (int i = 1; i < num; i++)
        rev = (rev << shift) + rev;
    return rev & MOD;
}

int get_hash(int *arr, int num, int shift)
{
    ll hash = 0;
    for (int i = 0; i < num; i++)
        hash = (hash << shift) + hash + *arr++;
    return hash & MOD;
}

int get_next(int prev, int sub, int mul, int add, int shift)
{
    ll hash = prev - (sub * mul);
    hash = (hash << shift) + hash + add;
    return hash & MOD;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin >> t;
    for (int tc = 1; tc <= t; tc++)
    {
        cin >> h >> w >> n >> m;
        for (int i = 0; i < h; i++)
            for (int j = 0; j < w; j++)
            {
                char a;
                cin >> a;
                if (a == 'o')
                    my_pic[i][j] = 1;
                else
                    my_pic[i][j] = 0;
            }
        for (int i = 0; i < n; i++)
            for (int j = 0; j < m; j++)
            {
                char a;
                cin >> a;
                if (a == 'o')
                    sam_pic[i][j] = 1;
                else
                    sam_pic[i][j] = 0;
            }

        for (int i = 0; i < h; i++)
            tmp[0][i] = get_hash(my_pic[i], w, 4);
        int my_hash = get_hash(tmp[0], h, 5);

        int mul_c = calc_mul(w, 4);
        int mul_r = calc_mul(h, 5);
        for (int i = 0; i < n; i++)
        {
            tmp[0][i] = get_hash(sam_pic[i], w, 4);
            for (int j = 1; j < m - w + 1; j++)
                tmp[j][i] = get_next(tmp[j - 1][i], sam_pic[i][j - 1], mul_c, sam_pic[i][j + w - 1], 4);
        }
        for (int i = 0; i < m - w + 1; i++)
        {
            sam_hash[0][i] = get_hash(tmp[i], h, 5);
            for (int j = 1; j < n - h + 1; j++)
                sam_hash[j][i] = get_next(sam_hash[j - 1][i], tmp[i][j - 1], mul_r, tmp[i][j + h - 1], 5);
        }

        int cnt = 0;
        for (int i = 0; i < n - h + 1; i++)
            for (int j = 0; j < m - w + 1; j++)
                if (sam_hash[i][j] == my_hash)
                    cnt++;
        cout << '#' << tc << ' ' << cnt << '\n';
    }
    return 0;
}
