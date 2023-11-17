#include <iostream>
#include <algorithm>

using namespace std;

int main(){
    int n, count, pos, l;
    cin >> n;
    int sticks[n];
    for(int i = 0; i < n; ++i){
        cin >> sticks[i];
    }
    sort(sticks, sticks + n);
    pos = 1;
    while(pos <= n){
        count  = 0;
        while(sticks[pos] == sticks[pos-1]){
            count++;
            sticks[pos - 1] = 0;
            pos++;
            if(pos == n){
                sticks[pos - 1] = 0; 
                break;
            }
        }
        pos++;
        count += n - pos + 2;
        cout << count << endl;
        
    }
}