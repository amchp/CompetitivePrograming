#include <iostream>
#include <cmath>

using namespace std;

int main(){
    string s;
    getline(cin, s);
    int length = s.length();
    int row = floor(sqrt(length));
    int col = ceil(sqrt(length));
    if(row * col < length){row++;}
    char encrypt[row][col];
    int ind = 0;
    int l = col - (row*col - length);
    for(int i = 0;  i < row; ++i){
        for(int j = 0; j < col; ++j){
            if(ind == s.length()){
                goto stop;
            }
            encrypt[j][i] = s.at(ind);
            ind++;
        }
    }
    stop:
    for(int i = 0;  i < col; ++i){
        for(int j = 0; j < row; ++j){
            if(j + 1 == row && i == l){
                break;
            }
            cout << encrypt[i][j];
        }
        if(i + 1 < col)cout << ' ';
    }
    cout << endl;
}