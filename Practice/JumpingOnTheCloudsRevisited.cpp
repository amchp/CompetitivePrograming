#include <iostream>

using namespace std;

int main(){
    int n, k, energy = 100;
    cin >> n >> k;
    int arr[n];
    for(int i = 0; i < n; ++i){
        cin >> arr[i];
    }
    int i = 0;
    do{
        i = (i + k) % n;
        energy--;
        if(arr[i] == 1)energy -=2;
    }while(i != 0);
    cout << energy << endl;
}