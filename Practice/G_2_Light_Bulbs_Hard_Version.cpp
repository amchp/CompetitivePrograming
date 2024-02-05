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
const int mod = 998244353;

int dr[] = {1, -1, 0, 0, 1, -1, -1, 1};
int dc[] = {0, 0, 1, -1, 1, 1, -1, -1};

mt19937_64 rnd(98275314);

long long gen()
{
    long long x = 0;
    while (x == 0)
        x = rnd();
    return x;
}

int mlt(int a, int b)
{
    return 1LL * a * b % mod;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cout << setprecision(20);
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        vector<ii> itvl(n, {-1, -1});
        vl val(n);
        forn(i, n)val[i] = gen();
        int n2 = 2 * n;
        vl a(n2);
        forn(i, n2)
        {
            cin >> a[i];
            if (itvl[a[i] - 1].fi == -1)
                itvl[a[i] - 1].fi = i;
            else
                itvl[a[i] - 1].se = i;
            a[i] = val[a[i] - 1];
        }
        sort(all(itvl));
        vector<ii> citvl;
        vi icnt;
        int cl = itvl[0].fi;
        int mr = itvl[0].se;
        int cnt = 1;
        for1(i, n - 1)
        {
            if (itvl[i].fi > mr)
            {
                citvl.pb({cl, mr});
                icnt.pb(cnt);
                cl = itvl[i].fi;
                mr = itvl[i].se;
                cnt = 1;
                continue;
            }
            mr = max(mr, itvl[i].se);
            ++cnt;
        }
        icnt.pb(cnt);
        citvl.pb({cl, mr});
        vi mrk(n2, 0);
        forn(i, sz(citvl))
        {
            auto &[l, r] = citvl[i];
            map<ll, int> pxr;
            ll xr = 0;
            fore(j, l, r)
            {
                xr ^= a[j];
                if (pxr.count(xr))
                {
                    mrk[pxr[xr]] = 1;
                    // d(pxr[xr]);
                    mrk[j] = 2;
                    // d(j);
                }
                pxr[xr] = j + 1;
            }
            int inside = 0;
            int ccnt = 0;
            fore(j, l, r){
                if(mrk[j] == 1)++inside;
                if(inside > 0)++ccnt;
                if(mrk[j] == 2)--inside;
            }
            // d(ccnt);
            icnt[i] -= ccnt / 2;
        }
        int ans = 1;
        for (int &v : icnt)
        {
            ans = mlt(ans, mlt(2, v));
        }
        cout << sz(citvl) << ' ' << ans << el;
    }
}
