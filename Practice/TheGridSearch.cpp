#include <iostream>
#include <cmath>

using namespace std;

int main(){
    int t;
    cin >> t;
    while(t--){
        int R, C, r, c;
        string s;
        cin >> R >> C;
        int arr[R][C];
        getchar();
        for(int i = 0; i < R; ++i){
            getline(cin, s);
            for(int j = 0; j < C; ++j){
                arr[i][j] = s.at(j) - '0';
            }
        }
        cin >> r >> c;
        int P[r][c];
        getchar();
        for(int i = 0; i < r; ++i){
            getline(cin, s);
            for(int j = 0; j < c; ++j){
                P[i][j] = s.at(j) - '0';
            }
        }
        bool pass, found = false;;
        for(int i = 0; i < R - r + 1; ++i){
            for(int j = 0; j < C - c + 1; ++j){
                pass = true;
                for(int k = 0; k < r; ++k){
                    for(int l = 0; l < c; ++l){
                        if(arr[i+k][j+l] != P[k][l]){
                            pass = false;
                            goto stop;
                        }
                    }
                }
                stop:;
                if(pass){ 
                    found = true;
                    goto sstop;
                }
            }
        }
        sstop:;
        if(found) cout << "YES" << endl;
        else cout << "NO" << endl;
    }
}