#include <bits/stdc++.h>

#define forn(i, n) for(int i = 0; i < (int)n; ++i)
#define for1(i, n) for(int i = 1; i <= (int)n; ++i)
#define ford(i, n) for(int i = (int)n - 1; i >= 0; --i)
#define all(x) x.begin(), x.end()
#define sz(x) x.size()
#define el '\n'
#define d(x) cerr<<#x<<" "<<x<<el
#define pb push_back

using namespace std;

typedef vector<int> vi;
typedef pair<int,int> ii;
typedef long long ll;
int dx[] = {0,-1, 1, 0};
int dy[] = {-1,0, 0, 1};
ll inf = 2e18;





int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    ll a, b, c, d;
    string sa, sb;
    map<char, int> sta, stb;
    map<char, vi> apos;

    cin >> a >> b >> c >> d;
    sa = to_string(a), sb = to_string(b);
    ll gcd = __gcd(c, d);
    ll cp = c / gcd;
    ll dp = d / gcd;

    forn(i, sz(sa)){
        apos[sa[i]].pb(i);
    }
    for(char& ch : sa)++sta[ch];
    for(char& ch : sb)++stb[ch];
    int e = sz(sb);
    for1(bts , (1 << e) - 1){
        string sbp = "";
        forn(i, e){
            if(bts & (1 << i))sbp.pb(sb[i]);
        }
        if(sbp[0] == '0')continue;
        ll bp = stoll(sbp);
        if(bp == 0)continue;
        if(bp % dp != 0)continue;
        ll x = bp / dp;
        if(cp > (inf / x))continue;
        ll ap = cp * x;
        string sap = to_string(ap);
        int cur = -1;
        bool pass = true;
        for(char& ch : sap){
            int pos = upper_bound(all(apos[ch]), cur) - apos[ch].begin();
            if(pos == sz(apos[ch])){
                pass = false;
                break;
            }
            cur = apos[ch][pos];
        }
        if(!pass)continue;

        map<char, int> da = sta;
        map<char, int> db = stb;
        for(char& ch : sap){
            --da[ch];
            if(da[ch] == 0)da.erase(ch);
        }
        for(char& ch : sbp){
            --db[ch];
            if(db[ch] == 0)db.erase(ch);
        }
        if(da == db){
            cout << "possible" << el;
            cout << sap << ' ' << sbp << el;
            return 0;
        }
    }
    cout << "impossible" << el;
}