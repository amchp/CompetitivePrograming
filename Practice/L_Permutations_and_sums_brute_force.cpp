#include <bits/stdc++.h>

#define fi first
#define se second
#define forn(i,n) for(int i=0; i< (int)n; ++i)
#define for1(i,n) for(int i=1; i<= (int)n; ++i)
#define fore(i,l,r) for(int i=(int)l; i<= (int)r; ++i)
#define ford(i,n) for(int i=(int)(n) - 1; i>= 0; --i)
#define fored(i,l,r) for(int i=(int)r; i>= (int)l; --i)
#define pb push_back
#define el '\n'
#define db(x) cout<< #x<< " " << x<<el
#define ri(n) scanf("%d",&n)
#define sz(v) int(v.size())
#define all(v) v.begin(),v.end()

using namespace std;

typedef long long ll;
typedef double ld;
typedef pair<int,int> ii;
typedef pair<ll,ll> pll;
typedef tuple<int, int, int> iii;
typedef vector<int> vi;
typedef vector<ii> vii;
typedef vector<ll> vll;
typedef vector<ld> vd;


const int inf = 1e9;
const int nax = 1e5+200;
const ld pi = acos(-1);
const ld eps= 1e-9;

int dr[] = {1,-1,0, 0,1,-1,-1, 1};
int dc[] = {0, 0,1,-1,1, 1,-1,-1};

ll n;
ll bn;
ll ans1, ans2;

char selectnum(char c1, char c2){
    if((c1 - '0') % 2 == 0){
        return ((c2 - '0') / 2) + '0';
    }else{
        return ((c2 - '0') / 2 + 5) + '0';
    }
}

bool checkans(ll x, ll y){
    if(x == 0 || y == 0)return false;
    if(x > n || y > n)return false;
    if(x == y)return false;
    ll sm = bn - x - y;
    string s = to_string(x) + to_string(y);
    ll cn = stoll(s);
    return sm == cn;
}

bool check(string sx){
    ll x = stoll(sx);
    if(x > n + 1)return false;
    ll trg = bn - x;
    string strg = to_string(trg);
    if(sz(strg) <= sz(sx))return false;
    string nr = strg.substr(sz(sx));
    if((nr.back() - '0') % 2 == 1){
        --x;
        sx = to_string(x);
        ++trg;
        strg = to_string(trg);
        if(sz(strg) <= sz(sx))return false;
        nr = strg.substr(sz(sx));
    }
    if(x > n)return false;
    assert((nr.back() - '0') % 2 == 0);
    string sy1 = "";
    string sy2 = "";
    sy1.pb(selectnum('0', nr[0]));
    sy2.pb(selectnum('1', nr[0]));
    forn(i, sz(nr) - 1){
        sy1.pb(selectnum(nr[i], nr[i + 1]));
        sy2.pb(selectnum(nr[i], nr[i + 1]));
    }
    ll y1 = stoll(sy1);
    ll y2 = stoll(sy2);
    if(checkans(x, y1)){
        ans1 = x;
        ans2 = y1;
        return true;
    }
    if(checkans(x, y2)){
        ans1 = x;
        ans2 = y2;
        return true;
    }
    return false;
}

void sol(){
    if(n < 3){
        cout << 0 << el;
        return;
    }
    if(n == 3){
        cout << "1 3" << el;
        return;
    }
    bn = 1LL*n*(n + 1) / 2;
    for1(x, n){
        for1(y, n){
            if(checkans(x, y)){
                cout << "2 " << x << ' ' << y << el;
                return;
            }
        }
    }
    cout << "0" << el;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    cout << setprecision(20)<< fixed;
    // freopen("output2.txt", "w", stdout);
    int t;
    // t = 1;
    // t = 100;
    for1(i, t){
        // cin >> n;
        n = i;
        // db(i);
        sol();
    }
}