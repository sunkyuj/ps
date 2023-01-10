#include <iostream>
#include <algorithm>
#include <limits.h>
#include <cstring>
#include <vector>
#include <cmath>


#define FIO ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL)


using namespace std;

string memo[11][3073];

//void f(int n) {
    
//}

int my_log(int x) {
    int cnt = 0;
    while (x>1) {
        x /= 2;
        cnt++;
    }

    return cnt;
}


int main()
{
	FIO;
	int n;
    cin >> n;
    int k = my_log(n / 3);
    

    memo[0][1] = {"  *  "};
    memo[0][2] = {" * * "};
    memo[0][3] = {"*****"};

    for (int i = 1; i <= k; i++) {
        int margin_n = 3 * pow(2, i - 1);
        string margin = "";
        for (int j = 1; j <= margin_n; j++) margin += " ";

        int Y = 3 * pow(2, i);
        int half_Y = Y / 2;

        for (int y = 1; y <= half_Y; y++) { // up
            memo[i][y] = margin + memo[i - 1][y] + margin;
        }

        for (int y = half_Y + 1; y <= Y; y++) { // down
            memo[i][y] = memo[i - 1][y - half_Y] + " " + memo[i - 1][y - half_Y];
        }
    }

 

   

    for (int y = 1; y <= n; y++) {
        cout << memo[k][y] << "\n";
    }

}

/*
3*2^k

  k=0, 3
__*__             <-0
_* *_ 
*****     

   k=1, 6                ...<-3
...__*__...                           
..._* *_...
...*****...
__*__ __*__ 
_* *_ _* *_ 
***** *****


        k=2, 12            .....<-6
......_____*_____......                      
......____* *____......
......___*****___......
......__*     *__......
......_* *   * *_......
......***** *****......
_____*_____ _____*_____ 
____* *____ ____* *____
___*****___ ___*****___   
__*     *__ __*     *__   
_* *   * *_ _* *   * *_  
***** ***** ***** *****



                   k=3, 24       ............<-12
............___________*
............__________* *
............_________*****
............________*     *
............_______* *   * *
............______***** *****
............_____*           *
............____* *         * *
............___*****       *****
............__*     *     *     *
............_* *   * *   * *   * *
............***** ***** ***** *****
___________*                       *
__________* *                     * *
_________*****                   *****
________*     *                 *     *
_______* *   * *               * *   * *
______***** *****             ***** *****
_____*           *           *           *
____* *         * *         * *         * *
___*****       *****       *****       *****
__*     *     *     *     *     *     *     *
_* *   * *   * *   * *   * *   * *   * *   * *
***** ***** ***** ***** ***** ***** ***** *****
*/