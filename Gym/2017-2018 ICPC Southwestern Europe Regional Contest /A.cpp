#include <bits/stdc++.h>
#define el '\n'
#define forn(i, n) for(int i = 0; i < (int)n; ++i)
#define for1(i, n) for(int i = 1; i <= (int)n; ++i)
#define all(a) a.begin(), a.end()
#define d(x) cerr<<#x<<" "<<x<<el
using namespace std;
typedef long long ll;
typedef vector<ll> vll;
typedef vector<int> vi;
int main(){
    int n, m;
    cin>>n>>m;
    

    vi a(n), b(m);

    forn(i,n)cin>>a[i];
    forn(i,m)cin>>b[i];
    map<int,int> cnt;
    forn(i,n){
        forn(j,m){
            if(b[j] < a[i])continue;
            ++cnt[b[j] - a[i]];
        }
    }
    int ans = 0, time = 0;
    for(auto [num, frec] : cnt){
        if(frec > ans){
            ans = frec;
            time = num;
        }
    }

    cout<<time<<el;
}