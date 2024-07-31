#include <bits/stdc++.h>
#define el '\n'
using namespace std;
typedef long long ll;
int main(){
    int W, N;
    cin>>W>>N;
    ll sum = 0;
    while(N--){
        int li, wi;
        cin>>li>>wi;
        sum += 1LL*li*wi;
    }
    sum/=W;
    cout<<sum<<el;
}