#include <iostream>
#include <cmath>
using namespace std;

int main(){
    int n, diff, pointsD;
    cin >> n;
    int r[n];
    int b[n];
    for(int i = 0; i < n; ++i){
        cin >> r[i];
    }
    for(int i = 0; i < n; ++i){
        cin >> b[i];
    }
    pointsD = 1;
    for(int i = 0; i < n; ++i){
        if(r[i] == 1 && b[i] == 0){
            diff++;
            pointsD--;
        }
        if(b[i] == 1 && r[i] == 0){
            pointsD++;
        }
    }
    if(diff == 0) cout << -1;
    else if(pointsD <= 0) cout << 1;
    else{
        pointsD+=diff;
        cout << ceil((double)(pointsD) / diff);
    }
}