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
#define d(x) cout<< #x<< " " << x<<el
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

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    cout << setprecision(20)<< fixed;
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        string s;
        cin >> s;
        int nrt = 0, sth = 0, est = 0, wst = 0;
        for(char& c : s){
            if(c == 'N')++nrt;
            if(c == 'S')++sth;
            if(c == 'E')++est;
            if(c == 'W')++wst;
        }
        if(((nrt + sth)&1) || ((est + wst)&1) || (nrt == 1 && sth == 1 && (est + wst == 0)) || (est == 1 && wst == 1 && (nrt + sth) == 0)){
            cout << "NO" << el;
            continue;
        }
        int snrt = 0, ssth = 0, sest = 0, swst = 0;
        if(nrt == 1 && sth == 1 && est == 1 && wst == 1){
            snrt = 1, ssth = 1;
        }
        vector<char> ans(n, 'R');
        forn(i, n){
            char& c = s[i];
            if(c == 'N'){
                if(snrt)ans[i] = 'H';
                snrt = !snrt;
            }
            if(c == 'S'){
                if(ssth)ans[i] = 'H';
                ssth = !ssth;
            }
            if(c == 'E'){
                if(sest)ans[i] = 'H';
                sest = !sest;
            }
            if(c == 'W'){
                if(swst)ans[i] = 'H';
                swst = !swst;
            }
        }
        for(char& c : ans)cout << c;
        cout << el;
    }
}