#include <iostream>
#include <algorithm>
#include <cmath>

using namespace std;

int maximum, minimum, middle;

bool compareCenter(int a, int b){
    int middle = ((maximum - minimum) / 2) + minimum;
    return (abs(a - middle) < abs(b - middle));
}

int main(){
    int l, n, sum, min, max;
    cin >> l;
    while(l != 0){
        cin >> n;
        int lengths[n];
        int cuts[n][n];
        middle = l / 2;
        for(int i = 0; i < n; ++i){
            cin >> lengths[i];
        }
        maximum = l;
        minimum = 0;
        sort(lengths, lengths + n, compareCenter);
        min = lengths[0];
        max = lengths[0];
        sum = l;
        for(int i = 1; i < n; ++i){
            if(lengths[i] < min){
                sum += min;
                min = lengths[i];
            }
            else{
                sum += l - max;
                max = lengths[i];
            }
        }
        cout << sum << endl;
        cin >> l;
    }
}