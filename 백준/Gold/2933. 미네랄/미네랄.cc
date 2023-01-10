#include <iostream>
#include <queue>
using namespace std;


int r,c,n;
int dy[4] = { 1,0,-1,0 };
int dx[4] = { 0,1,0,-1 };
int cluster[100][100]{};

int floatY, floatX;

string cave[100];


void set_cluster() {
    for (int i = 0; i < r; i++) {
        for (int j = 0; j < c; j++) cluster[i][j] = 0;
    }
    queue<pair<int, int>> q;
    int cluster_n = 0;
    bool visited[100][100]{};

    for (int i = r - 1; i >= 0; i--) {
        for (int j = 0; j < c; j++) {
            if (cave[i][j] == 'x'&&!visited[i][j]) {
                cluster_n++;
                
                q.push({ i,j });
                visited[i][j] = true;
                cluster[i][j] = cluster_n;
                while (!q.empty()) {
                    int y = q.front().first, x = q.front().second;
                    q.pop();

                    for (int k = 0; k < 4; k++) {
                        int ny = y + dy[k], nx = x + dx[k];
                        if (ny >= 0 && ny < r && nx >= 0 && nx < c && cave[ny][nx] == 'x'&& !cluster[ny][nx]) {
                            q.push({ ny,nx });
                            cluster[ny][nx] = cluster_n;
                            visited[ny][nx] = true;
                        }
                    }
                }

            }
        }
    }

    /**
    for (int i = 0; i < r; i++) {
        for (int j = 0; j < c; j++) cout << cluster[i][j];
        cout << "\n";
    }
   // */

}

bool is_floating(int startY, int startX, bool visited[][100]) {
    queue<pair<int, int>> q;
    bool is_float = true;
    //bool visited[100][100]{};
    q.push({ startY,startX });
    visited[startY][startX] = true;

    while (!q.empty()) {
        int y = q.front().first, x = q.front().second;
        if (y == r-1) is_float= false;
        q.pop();

        for (int k = 0; k < 4; k++) {
            int ny = y + dy[k], nx = x + dx[k];
            if ( ny >= 0 && ny < r && nx >= 0 && nx < c && cave[ny][nx] == 'x' && !visited[ny][nx]) {
                q.push({ ny,nx });
                visited[ny][nx] = true;
            }
        }
    }
    return is_float;
}

bool all_grounded() {
    bool visited[100][100]{};
    for (int i = r - 1; i >= 0; i--) {
        for (int j = 0; j < c; j++) {
            if (cave[i][j] == 'x' && !visited[i][j]) {
                if (is_floating(i, j,visited)) {
                    floatY = i; floatX = j;
                    return false;
                }
            }
        }
    }
    return true;
}

void fall(int startY, int startX) {
    int minL = 100;
    queue<pair<int, int>> q;
    bool visited[100][100]{};
    
    q.push({ startY,startX });
    visited[startY][startX] = true;
    while (!q.empty()) {
        int i;
        int y = q.front().first, x = q.front().second;
        q.pop();
        for (i = y + 1; i < r; i++) {
            if (cave[i][x]=='x' && cluster[i][x] != cluster[y][x]) break; //reached ice or ground
        }
        if (minL > i - y-1) minL = i - y-1;

        for (int k = 0; k < 4; k++) {
            int ny = y + dy[k], nx = x + dx[k];
            if ( ny >= 0 && ny < r && nx >= 0 && nx < c && cave[ny][nx] == 'x' && !visited[ny][nx]) {
                q.push({ ny,nx });
                visited[ny][nx] = true;
            }
        }
    }


    int cluster_idx = cluster[startY][startX];
    for (int i = r - 1; i >= 0; i--) { //아래에서부터 확인
        for (int j = 0; j < c; j++) {
            if (cluster[i][j] == cluster_idx) {
                cave[i][j] = '.';
                cave[i + minL][j] = 'x';
            }
        }
    }
    //여기 수정해야됨!!!!!!!!!
    /*
    q.push({ startY,startX });
    visited[startY][startX] = false;
    while (!q.empty()) {
        int y = q.front().first, x = q.front().second;
        q.pop();
        cave[y][x] = '.'; 
        cave[y + minL][x] = 'x';

        for (int k = 0; k < 4; k++) {
            int ny = y + dy[k], nx = x + dx[k];
            if ( ny >= 0 && ny < r && nx >= 0 && nx < c && cave[ny][nx] == 'x' && visited[ny][nx]) {
                q.push({ ny,nx });
                visited[ny][nx] = false;
            }
        }
    }*/


    
}


int main()
{
    cin >> r >> c;
    for (int i = 0; i < r; i++)  cin >> cave[i];
    set_cluster();

    cin >> n;
    bool left = true;
    while (n--) {
        int stickY;
        cin >> stickY;


        if (left) {
            left = false; 
            for (int j = 0; j < c; j++) {
                if (cave[r-stickY][j] == 'x') {
                    cave[r - stickY][j] = '.';
                    cluster[r - stickY][j] = 0;
                    break;
                }
                
            }
            set_cluster();    
            if (!all_grounded())
                fall(floatY, floatX);
        }
        else {
            left = true;
            for (int j = c-1; j >= 0; j--) {
                if (cave[r - stickY][j] == 'x') {
                    cave[r - stickY][j] = '.';
                    cluster[r - stickY][j] = 0;
                    break;
                }
                
            }
            set_cluster();
            if (!all_grounded())
                fall(floatY, floatX);
        }

    }

    for (int i = 0; i < r; i++) {
        cout << cave[i] << "\n";
    }

}
