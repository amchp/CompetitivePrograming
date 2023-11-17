#include <iostream>
#include <cmath>


using namespace std;

int main(){
    int n, r, c;
    string s;
    int sides[4][2] = {{0, -1}, {-1, 0}, {1, 0}, {0, 1}};
    cin >> r >> c >> n;
    char bomb[r][c];
    char obomb[r][c];
    char fbomb[r][c];
    getchar();
    for(int i = 0; i < r; ++i){
        getline(cin, s);
        cout << s << endl;
        for(int j = 0; j < c; ++j){
            bomb[i][j] = s.at(c);
            fbomb[i][j] = 'O';
            obomb[i][j] = 'O';
            if(bomb[i][j] = 'O'){
                obomb[i][j] = '.';
                for(int k = 0; k < 4; ++k){
                    int x = i + sides[k][0];
                    int y = j + sides[k][1];
                    bool canX = (x > -1 && x < r);
                    bool canY = (y > -1 && y < c);
                    if(canX && canY){
                        obomb[x][y] = '.';
                    }
                }
            }
        }
    }
    if(n == 1 || n == 0 || n % 4 == 1){
        for(int i = 0; i < r; ++i){
            for(int j = 0; j < c; ++j){
                cout << bomb[i][j];
            }
            cout << endl;
        }
    }else if(n % 2 == 0){
        for(int i = 0; i < r; ++i){
            for(int j = 0; j < c; ++j){
                cout << fbomb[i][j];
            }
            cout << endl;
        }
    }else if(n % 4 == 3){
        for(int i = 0; i < r; ++i){
            for(int j = 0; j < c; ++j){
                cout << obomb[i][j];
            }
            cout << endl;
        }
    }

}