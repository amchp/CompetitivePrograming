#include <iostream>
#include <queue>
#include <array>


using namespace std;

int dx[] = {-1, -1, -1, 0, 0, 1, 1, 1};
int dy[] = {-1, 0, 1, -1, 1, -1, 0, 1};

int main(){
    int n, m, count, max, nextX, nextY;
    int x, y;
    array<int, 2> a;
    cin >> n >> m;

    int arr[n][m];
    bool visited[n][m];

    for(int i = 0; i < n; ++i){
        for(int j = 0; j < m; ++j){
            cin >> arr[i][j];
            visited[i][j] = false;
        }
    }
    max = 0;

    for(int i = 0; i < n; ++i){
        for(int j = 0; j < m; ++j){
            if(arr[i][j] == 1 && !visited[i][j]){
                queue< array<int, 2> > s;
                count = 0;
                visited[i][j] = true;
                a[0] = i;
                a[1] = j;
                s.push(a);
                while(!s.empty()){
                    count++;
                    x = s.front()[0];
                    y = s.front()[1];
                    s.pop();
                    for(int k = 0; k < 8; k++){
                        nextX = x + dx[k];
                        nextY = y + dy[k];
                        if((nextX > -1 && nextX < n && nextY > -1 && nextY < m)&&
                        arr[nextX][nextY] == 1 &&
                        !visited[nextX][nextY]){
                            visited[nextX][nextY] = true;
                            a[0] = nextX;
                            a[1] = nextY;
                            s.push(a);
                        }
                    }
                    if(max < count) max = count;
                }
            }
        }
    }
    cout << max << endl;
}