#include<bits/stdc++.h>

#define forn(i,n) for(int i = 0; i < n; ++i)
#define for1(i, n) for(int i = 1; i <= n; ++i)
#define el '\n'
#define all(x) x.begin(), x.end()
#define pb push_back
#define sz(x) x.size()
#define db(x) cout << #x << ' ' << x << el;

using namespace std;

typedef long long ll;
typedef vector<int> vi;

string ans;

bool sol(){
    ans.clear();
    int n, k, m;
    cin >> n >> k >> m;
    string s;
    cin >> s;
    vector<vi> mp(k);
    forn(i, m){
        int ind = s[i] - 'a';
        mp[ind].pb(i);
    }
    forn(i, k)mp[i].pb(m);
    int cur = -1;
    forn(_, n){
        int nxt = cur;
        forn(i, k){
            int cnxt = *upper_bound(all(mp[i]), cur);
            nxt = max(nxt, cnxt);
            if(nxt == m){
                ans.pb(char(i + 'a'));
                while(sz(ans) < n)ans.pb('a');
                return false;
            }
        }
        // db(nxt);
        ans.pb(s[nxt]);
        cur = nxt;
    }
    return true;
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    int t;
    cin >> t;
    while(t--){
        if(sol())cout << "YES" << el;
        else{
            cout << "NO" << el;
            cout << ans << el;
        }
    }
}