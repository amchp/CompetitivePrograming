#include <iostream>
#include <cmath>

using namespace std;



int main(){
    int cur[9];
    int magic[8][9] = {{8, 1, 6, 3, 5, 7, 4, 9, 2}, {6, 1, 8, 7, 5, 3, 2, 9, 4},
            {4, 3, 8, 9, 5, 1, 2, 7, 6}, {2, 7, 6, 9, 5, 1, 4, 3, 8},
            {2, 9, 4, 7, 5, 3, 6, 1, 8}, {4, 9, 2, 3, 5, 7, 8, 1, 6},
            {6, 7, 2, 1, 5, 9, 8, 3, 4}, {8, 3, 4, 1, 5, 9, 6, 7, 2}};
    for(int i = 0; i < 9; ++i) cin >> cur[i];
    int diff = 1000;
    int curDiff;
    for(int i = 0; i < 8; ++i){
        curDiff = 0;
        for(int j = 0; j < 9; ++j){
            curDiff += abs(cur[j] - magic[i][j]);
        }
        if(curDiff < diff) diff = curDiff;
    }
    cout << diff << endl;
}