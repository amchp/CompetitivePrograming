#include <iostream>
#include <cmath>

using namespace std;

int main(){
    int sides[4][2] = {{0,-1}, {-1, 0}, {1, 0}, {0, 1}};
    int n;
    string s;
    cin >> n;
    int map[n][n];
    char output[n][n];
    getchar();
    for(int i = 0; i < n; ++i){
        getline(cin, s);
        for(int j = 0; j < n; ++j){
            map[i][j] = s.at(j) - '0';
        }
    }
    bool pass;
    for(int i = 0; i < n; ++i){
        for(int j = 0; j < n; ++j){
            pass = true;
            bool corner = (i == 0 || j == 0) || (i == n -1 || j == n -1);
            if(!corner){
                for(int k = 0; k < 4; ++k){
                    bool lessN = (n > i + sides[k][0]) && (n > j + sides[k][1]);
                    bool notNegative = (-1 < i + sides[k][0]) && (-1 < j + sides[k][1]);
                    if(lessN && notNegative && map[i][j] <= map[i + sides[k][0]][j + sides[k][1]]){
                        pass = false;
                        cout << map[i][j];
                        break;
                    }
                }
            }
            else{
                pass = false;
                cout << map[i][j];
            }
            if(pass)cout << 'X';
        }
        cout << '\n';
    }
    
}