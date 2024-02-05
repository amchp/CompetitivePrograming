#include <bits/stdc++.h>

#define fi first
#define se second
#define forn(i, n) for (int i = 0; i < (int)n; ++i)
#define for1(i, n) for (int i = 1; i <= (int)n; ++i)
#define fore(i, l, r) for (int i = (int)l; i <= (int)r; ++i)
#define ford(i, n) for (int i = (int)(n)-1; i >= 0; --i)
#define fored(i, l, r) for (int i = (int)r; i >= (int)l; --i)
#define pb push_back
#define el '\n'
#define d(x) cout << #x << " " << x << el
#define ri(n) scanf("%d", &n)
#define sz(v) ((int)v.size())
#define all(v) v.begin(), v.end()
#define allr(v) v.rbegin(), v.rend()

using namespace std;

typedef long long ll;
typedef double ld;
typedef pair<int, int> ii;
typedef pair<char, int> pci;
typedef pair<ll, ll> pll;
typedef vector<int> vi;
typedef vector<ll> vl;

const int inf = 1e9;
const int nax = 1e5 + 200;
const ld pi = acos(-1);
const ld eps = 1e-9;

int dr[] = {1, -1, 0, 0, 1, -1, -1, 1};
int dc[] = {0, 0, 1, -1, 1, 1, -1, -1};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cout << setprecision(20);
    long long i,t,n,k,p,q;
    cin>>t;
    while(t--){
        cin>>n>>k;
        vector<long long> v(n);
        forn(i, n){
            cin>>v[i];
        }
        if(k>=3){
            cout<<0<<endl;
            continue;
        }
        sort(v.begin(),v.end());
        long long m=1e18;
        for1(i,n){
            m=min(m,abs(v[i]-v[i-1]));
        }
        if(k)cout<<m<<endl;
        m=1e18;
        forn(i,n){
            for(int j=0; j<n;j++){
                if(i==j)continue;
                q=abs(v[i]-v[j]);
                p=lower_bound(v.begin(),v.end(),m)-v.begin();
                if(p!=-1)m=min(m,q-v[p]);
                p=upper_bound(v.begin(),v.end(),m)-v.begin();
                m=min(m,q-v[p]);
                m=min(m,q);
            }
        }
        cout<<m<<endl;
    }
}
