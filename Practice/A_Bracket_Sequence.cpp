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
typedef array<ll, 2> v2;
typedef array<ll, 3> v3;


const int inf = 1e9;
const int nax = 1e5+200;
const ld pi = acos(-1);
const ld eps= 1e-9;

int dr[] = {1,-1,0, 0,1,-1,-1, 1};
int dc[] = {0, 0,1,-1,1, 1,-1,-1};

void sol(){
    string s;
    cin >> s;
    int n = sz(s);
    stack<pair<char, int>> st;
    vector<v3> ans;
    auto reset = [&](){
        while(!st.empty())st.pop();
    };
    auto add = [&](v3 nans){
        while(
            ans.size() && 
            nans[0] <= ans.back()[0] && 
            ans.back()[1] <= nans[1]
        ){
            nans[2] += ans.back()[2];
            ans.pop_back();
        }
        ans.push_back(nans);
    };
    forn(i, n){
        char c = s[i];
        if(c == '(' || c == '['){
            st.push({c, i});
            continue;
        }
        if(c == ')'){
            if(st.empty() || st.top().fi != '('){
                reset();
                continue;
            }
            auto pr = st.top(); st.pop();
            add({pr.se, i, 0});
            continue;
        }
        if(c == ']'){
            if(st.empty() || st.top().fi != '['){
                reset();
                continue;
            }
            auto pr = st.top(); st.pop();
            add({pr.se, i, 1});
            continue;
        }
    }
    sort(all(ans));
    v3 fans = {0, 0, -1};
    v3 pv = {-1, -2, -1};
    for(auto [l, r, cnt] : ans){
        if(pv[1] + 1 == l){
            pv[1] = r;
            pv[2] += cnt;
            continue;
        }
        fans = max(fans, {pv[2], pv[1] - pv[0] + 1, pv[0]});
        pv = {l, r, cnt};
    }
    fans = max(fans, {pv[2], pv[1] - pv[0] + 1, pv[0]});
    if(fans[2] == -1){
        cout << 0 << el;
        return;
    }
    cout << fans[0] << el;
    // db(fans[2]);
    // db(fans[0]);
    cout << s.substr(fans[2], fans[1]);
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    cout << setprecision(20)<< fixed;
    int t = 1;
    // cin >> t;
    while(t--){
        sol();
    }
}