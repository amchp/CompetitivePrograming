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
const int nax = 2e5+200;
const ld pi = acos(-1);
const ld eps= 1e-9;

int dr[] = {1,-1,0, 0,1,-1,-1, 1};
int dc[] = {0, 0,1,-1,1, 1,-1,-1};


ll cans = 0;
ll a[nax], b[nax];
set<int> prg, tst, wprg, wtst;

void insert(int i, int to){
    if(to == 0){
        cans += a[i];
        prg.insert(i);
        if(a[i] < b[i])wprg.insert(i);
    }else{
        cans += b[i];
        tst.insert(i);
        if(b[i] < a[i])wtst.insert(i);
    }
}

void erase(int i, int to){
    if(to == 0){
        cans -= a[i];
        prg.erase(i);
        if(a[i] < b[i])wprg.erase(i);
    }else{
        cans -= b[i];
        tst.erase(i);
        if(b[i] < a[i])wtst.erase(i);
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    cout << setprecision(20)<< fixed;
    int t;
    cin >> t;
    while(t--){
        int n, m;
        cin >> n >> m;
        int szs = n + m + 1;
        forn(i, szs)cin >> a[i];
        forn(i, szs)cin >> b[i];

        cans = 0;
        prg.clear();
        tst.clear();
        wprg.clear();
        wtst.clear();

        for1(i, szs - 1){
            if(sz(tst) == m || (sz(prg) < n && a[i] > b[i])){
                insert(i, 0);
            }else{
                insert(i, 1);
            }
        }

        forn(i, szs - 1){
            cout << cans << ' ';
            if(a[i] > b[i]){
                if(prg.count(i + 1)){
                    erase(i + 1, 0);

                    insert(i, 0);
                    continue;
                }
                erase(i + 1, 1);

                if(!sz(prg)){
                    insert(i, 1);
                    continue;
                }

                if(sz(wprg)){
                    int chg = *wprg.begin();
                    erase(chg, 0);
                    insert(chg, 1);

                    insert(i, 0);
                    continue;
                }

                int chg = (*prg.rbegin());
                if(chg < i){
                    insert(i, 1);
                    continue;
                }

                erase(chg, 0);
                insert(chg, 1);

                insert(i, 0);
                continue;
            }else{
                if(tst.count(i + 1)){
                    erase(i + 1, 1);

                    insert(i, 1);
                    continue;
                }

                erase(i + 1, 0);

                if(!sz(tst)){
                    insert(i, 0);
                    continue;
                }

                if(sz(wtst)){
                    int chg = *wtst.begin();
                    erase(chg, 1);
                    insert(chg, 0);

                    insert(i, 1);
                    continue;
                }

                int chg = (*tst.rbegin());
                if(chg < i){
                    insert(i, 0);
                    continue;
                }

                erase(chg, 1);
                insert(chg, 0);

                insert(i, 1);
                continue;
            }
        }
        cout << cans << ' ';
        cout << el;
    }
}