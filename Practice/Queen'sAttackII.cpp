#include <iostream>
#include <cmath>
#include <vector>

using namespace std;

int main(){
    int n, k, qx, qy, x, y, count, diffx, diffy;
    std::cin >> n >> k >> qx >> qy;
    qx--;
    qy--;
    int dist[8] = {min(qx, qy), qy, min(n-1-qx,qy), qx, n-1-qx, min(qx, n-1-qy), n-1-qy, min(n-1-qx,n-1-qy)};
    for(int i = 0; i < k; ++i){
        std::cin >> x >> y;
        x--;
        y--;
        if(qx == x){
            if(qy > y){
                dist[1] = min(dist[1] , qy - y - 1);
            }else{
                dist[6] = min(dist[6],y - qy);
            }
        }else if(qy == y){
            if(qx > x){
                dist[3] = min(dist[3],qx - x - 1);
            }else{
                dist[4] = min(dist[4], x - qx);
            }
        }else if(y - x != 0 && (double)(qy - qx)/(y - x) == 1.0){
            if(qy > y){
                dist[2] = min(dist[2], qy-y-1);
            }else if(qx > x){
                dist[5] = min(dist[5], qx-x-1);
            }else if(qy < y){
                dist[5] = min(dist[5], y-qy);
            }
            else{
                dist[2] = min(dist[2], x - qx);
            }
        }else if(y - x != 0 && (double)(qy - qx)/(y - x)  == -1.0){
            if(qy > y){
                dist[0] = min(dist[2], qy-y-1);
            }else if(qx > x){
                dist[0] = min(dist[5], qx-x-1);
            }else if(qy < y){
                dist[8] = min(dist[5], y-qy);
            }
            else{
                dist[8] = min(dist[2], x - qx);
            }
        }
    }
    count = 0;
    for(int i = 0; i < 8; ++i){
        // cout << i << " " << dist[i] << endl;
        count += dist[i];
    }
    // for(int i = 0; i < 8; ++i){
    //     x = qx + moves[i][0];
    //     y = qy + moves[i][1];
    //     while(x > -1 && x < n &&
    //           y > -1 && y < n &&
    //           board[x][y] != 1){
    //               count++;
    //               x += moves[i][0];
    //               y += moves[i][1];
    //     }
    // }
    cout << count << endl;
}