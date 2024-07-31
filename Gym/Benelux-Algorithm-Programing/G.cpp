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

const int nax = 500000 + 5;

int n;
ll ans[nax];
ll x[nax];
ll mx = 0;

bool sol(int ind, int val, unordered_map<ll, int>& m){
    vector<ll> undo;
    ans[ind] = val;
    m[val]--;
    undo.pb(val);
    fore(i, ind + 1, n - 1){
        ll nxt = (x[i] - x[i - 1]) - ans[i - 1];
        if(m[nxt] == 0){
            forn(i, undo.size()){
                m[undo[i]]++;
            }
            return false;
        }
        m[nxt]--;
        ans[i] = nxt;
        undo.pb(nxt);
    }
    fored(i, ind - 1, 0){
        ll nxt = (x[i + 1] - x[i]) - ans[i + 1];
        if(m[nxt] == 0){
            forn(i, undo.size()){
                m[undo[i]]++;
            }
            return false;
        }
        m[nxt]--;
        ans[i] = nxt;
        undo.pb(nxt);
    }
    return true;
}

bool car(int st, unordered_map<ll, int>& m){
    vector<pair<ll, int>> a;
    a.pb({0, st});
    ll cur = 0;
    ll mCur = 0;
    ll ind = 0;
    for(int i = st; i < n - 2; i += 2){
        ll d2 = x[i + 2] - x[i + 1];
        ll d1 = x[i + 1] - x[i];
        cur += d2 - d1;
        if(mCur < cur){
            ind = i + 2;
            mCur = cur;
        }
    }
    return sol(ind, mx, m);
}

void solve(){
    cin >> n;
    forn(i, n){
        cin >> x[i];
    }
    unordered_map<ll, int> m;
    forn(i, n){
        int v;
        cin >> v;
        mx = max((ll)v, mx);
        m[v]++;
    }
    if(!car(0, m)){
        if(!car(1, m)){
            assert(false);
        }
    }
    forn(i, n){
        cout << ans[i] << ' ';
    }
    cout << el;
}

int main(){
    int tt = 1;
    while(tt--){
        solve();
    }
}