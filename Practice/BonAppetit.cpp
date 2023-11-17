#include <iostream>

using namespace std;

int main(){
    int n, k, charge, actualPrice;
    cin >> n >> k;
    int bill[n];
    int sum = 0;
    for(int i = 0; i < n; ++i){
        cin >> bill[i];
        if(k != i) sum += bill[i];
    }
    cin >> charge;
    actualPrice = sum / 2;
    if(actualPrice != charge) cout << (charge - actualPrice) << endl;
    else cout << "Bon Appetit" << endl;
}