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
const int nax = 1e3+200;
const ld pi = acos(-1);
const ld eps= 1e-9;

int dr[] = {1,-1,0, 0,1,-1,-1, 1};
int dc[] = {0, 0,1,-1,1, 1,-1,-1};

struct node{
    bitset<nax> val;
    string op;
    int a, b;
    node(){}
    bitset<nax> strToBitset(string& a){
        bitset<nax> ans;
        forn(i, sz(a)){
            char& c = a[i];
            ans[i] = a[i] == '1';
        }
        return ans;
    }
    node(string& sa){
        val = strToBitset(sa);
        op = "";
    }
    node(int ra, string& oper, int rb){
        a = ra;
        op = oper;
        b = rb;
    }
};

int n, m;

vi cnt(map<int, node>& operation){
    vi ans(m);
    for(auto& [ind, nd] : operation){
        if(nd.op == "")continue;
        if(nd.op == "AND"){
            nd.val = operation[nd.a].val & operation[nd.b].val;
        }else if(nd.op == "OR"){
            nd.val = operation[nd.a].val | operation[nd.b].val;
        }else if(nd.op == "XOR"){
            nd.val = operation[nd.a].val ^ operation[nd.b].val;
        }
        forn(i, m){
            ans[i] += nd.val[i];
        }
    }
    return ans;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    cout << setprecision(20)<< fixed;
    cin >> n >> m;
    string s;
    getline(cin, s);
    map<string, int> nmtind;
    map<int, node> ones;
    map<int, node> zeros;
    nmtind["?"] = n;
    forn(i, n){
        string line;
        getline(cin, line);
        stringstream strm = stringstream(line);
        vector<string> vc;
        while(strm >> s){
            vc.pb(s);
        }
        if(sz(vc) == 3){
            nmtind[vc[0]] = i;
            ones[i] = node(vc[2]);
        }
        if(sz(vc) == 5){
            nmtind[vc[0]] = i;
            ones[i] = node(nmtind[vc[2]], vc[3], nmtind[vc[4]]);
        }
    }
    zeros = ones;
    string one = string(m, '1');
    ones[n] = node(one);
    vi aones = cnt(ones);
    string zero = string(m, '0');
    zeros[n] = node(zero);
    vi azeros = cnt(zeros);
    string ansmn(m, '0');
    string ansmx(m, '0');
    forn(i, m){
        if(aones[i] < azeros[i])ansmn[i] = '1';
        if(azeros[i] < aones[i])ansmx[i] = '1';
    }
    cout << ansmn << el;
    cout << ansmx << el;
}