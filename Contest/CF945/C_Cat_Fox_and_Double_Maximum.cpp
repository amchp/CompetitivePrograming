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
        vi p(n);
        forn(i, n)cin >> p[i];
        deque<ii> ene, one, ewe, owe;
        for(int i = 1; i < n; i += 2){
            if(i != n - 1)one.pb({p[i], i});
            owe.pb({p[i], i});
        }
        for(int i = 0; i < n; i += 2){
            if(i != 0 && i != n - 1)ene.pb({p[i], i});
            ewe.pb({p[i], i});
        }
        sort(all(ene));
        sort(all(one));
        sort(all(ewe));
        sort(all(owe));
        if((n - 1)&1)ewe.push_front({p[n - 1], n - 1});
        else owe.push_front({p[n - 1], n - 1});
        owe.push_front({p[0], 0});

        vi pos(n);
        forn(i, n)pos[i] = i + 1;
        vi anso(n), anse(n);
        for(auto& [_, ind] : one){
            anso[ind] = pos.back();
            pos.pop_back();
        }
        for(auto& [_, ind] : ewe){
            anso[ind] = pos.back();
            pos.pop_back();
        }

        // d(sz(pos));
        assert(!sz(pos));
        forn(i, n)pos.pb(i + 1);
        for(auto& [_, ind] : ene){
            anse[ind] = pos.back();
            pos.pop_back();
        }
        for(auto& [_, ind] : owe){
            anse[ind] = pos.back();
            pos.pop_back();
        }
        // d(sz(pos));
        assert(!sz(pos));

        vi ao(n), ae(n);
        forn(i, n)ae[i] = anse[i] + p[i];
        forn(i, n)ao[i] = anso[i] + p[i];

        int mxo = 0, mxe = 0;
        for1(i, n - 2){
            mxo += (ao[i - 1] < ao[i] && ao[i] > ao[i + 1]);
            mxe += (ae[i - 1] < ae[i] && ae[i] > ae[i + 1]);
        }

        if(mxe <= mxo){
            // d(mxo);
            for(int& v : anso)cout << v << ' ';
        }else{
            // d(mxe);
            for(int& v : anse)cout << v << ' ';
        }
        cout << el;
    }
}