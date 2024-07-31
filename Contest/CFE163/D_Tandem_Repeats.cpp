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

bool eq(char a, char b){
    if(a == '?' || b == '?')return true;
    return a == b;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    cout << setprecision(20)<< fixed;
    int t;
    cin >> t;
    while(t--){
        string s;
        cin >> s;
        int n = sz(s);
        int ans = 0;
        for(int i = 2; i <= n; i += 2){
            int dif = 0;
            int st = i / 2;
            // d(i);
            // d(st);
            for(int j = i / 2; j < i; ++j){
                if(!eq(s[j - st], s[j]))++dif;
            }
            // d(dif);
            if(dif == 0)ans = max(ans, i);
            int k = st;
            for(int j = i; j < n; ++j){
                if(!eq(s[k - st], s[k]))--dif;
                if(!eq(s[j - st], s[j]))++dif;
                if(dif == 0)ans = max(ans, i);
                ++k;
            }
        }
        cout << ans << el;
    }
}