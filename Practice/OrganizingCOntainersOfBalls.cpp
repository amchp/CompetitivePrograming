#include <iostream>
#include <cmath>

using namespace std;

int main(){
    int q, n;
    cin >> q;
    while(q--){
        cin >> n;
        int M[n][n];
        long long sum, rsum;
        bool possible = true;
        for(int i = 0; i < n; ++i){
            sum = 0;
            for(int j = 0; j < n; ++j){
                cin >> M[i][j];
            }
            if(i == 0)rsum = sum;
            else if(rsum != sum) possible = false;
        }
        for(int i = 0; i < n; ++i){
            sum = 0;
            for(int j = 0; j < n; ++j){
                sum += M[j][i];
            }
            if(i == 0)rsum = sum;
            else if(rsum != sum) possible = false;
        }
        if(possible) cout << "Possible" << endl;
        else cout << "Impossible" << endl;
    }
}