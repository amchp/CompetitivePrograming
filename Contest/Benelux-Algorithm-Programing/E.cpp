#include <algorithm>
#include <array>
#include <cassert>
#include <complex>
#include <cstdlib>
#include <cstring>
#include <fstream>
#include <iomanip>
#include <iostream>
#include <map>
#include <math.h>
#include <numeric>
#include <queue>
#include <set>
#include <sstream> // istringstream buffer(myString);
#include <stack>
#include <unordered_map>
#include <utility>
#include <vector>
#include <assert.h>


using namespace std;


#define ford(i,n) for(int i = n-1; i>= 0 ; i--)
#define forn(i,n) for(int i = 0; i<n ; i++)
#define fore(i, l, r) for(int i = l; i <= r; i++)
#define fored(i, l, r) for(int i = l; i >= r; i--)
#define el '\n'
#define se second
#define fi first
#define pb push_back
#define all(v) v.begin(), v.end()
#define d(x) cout << #x << " " << x << el

typedef long long ll;
typedef vector<int> vi;
typedef pair<int,int> ii;

const int nax = 100000 + 5;
const ll inf = 1e15;

int n;
ll dp[nax];
pair<ii, ii> groups[nax];

ll sol(int ind){
    if(ind == n)return 0;
    ii f = groups[ind].first;
    ii s = groups[ind].second;
    if(ind == n - 1){
        if(f.second == s.second){
            return inf;
        }
        else{
            return abs(s.first - f.first);
        }
    }
    ll& v = dp[ind];
    if(v != inf)return v;
    if(f.second != s.second){
        v = min(v, sol(ind + 1) + abs((ll)f.first - s.first));
    }
    ii nF = groups[ind + 1].first;
    ii nS = groups[ind + 1].second;
    v = min(v, sol(ind + 2) + abs((ll)f.first - nF.first) + abs((ll)s.first - nS.first));
    if(ind < n - 2){
        ii nNF = groups[ind + 2].first;
        ii nNS = groups[ind + 2].second;
        if(nF.second != nS.second){
            v = min(v, sol(ind + 3) + 
            abs((ll)f.first - nNF.first) + 
            abs((ll)s.first - nNS.first));
        }
        v = min(v, sol(ind + 3) + 
            abs((ll)f.first - nF.first) + 
            abs((ll)s.first - nNF.first) + 
            abs((ll)nS.first - nNS.first));
    }
    return v;
}

void solve(){
    cin >> n;
    vector<ii> c(2*n);
    forn(i, n){
        dp[i] = inf;
    }
    forn(i, 2*n){
        cin >> c[i].first;
        c[i].second = i / 2;
    }
    sort(all(c));
    forn(i, n){
        groups[i].first = c[2*i];
        groups[i].second = c[2*i + 1];
    }
    cout << sol(0) << el;
    // forn(i, n){
    //     cout << dp[i] << el;
    // }
}

int main(){
    int tt = 1;
    while(tt--){
        solve();
    }
}