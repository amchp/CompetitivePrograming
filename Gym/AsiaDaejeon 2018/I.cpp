#include<bits/stdc++.h>

#define el '\n'
#define db(x) cerr << #x << ' ' << x << el
#define forn(i,n) for(int i= 0; i < (int)n;++i)
#define for1(i,n) for(int i= 1; i <= (int)n;++i)
#define fore(i, l, r) for(int i = (int)l; i <= (int)r; ++i)
#define pb push_back
#define sz(a) (int) a.size()
#define all(a) a.begin(), a.end()
using namespace std;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef long long ll;
typedef double ld;


vi get_phi(vector<string> &s){
    int j = 0, n = sz(s); vi pi(n);
    for1(i,n-1){
        while(j > 0 && s[i]!=s[j]) j = pi[j-1];
        j+=(s[i]==s[j]);
        pi[i]=j;
    }
    return pi;
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    int n;
    cin>>n;
    vector<string> vs(n);
    forn(i,n){
        cin>>vs[i];
    }
    reverse(all(vs));
    vi phi = get_phi(vs);
    int ans = n, k = n-1,p=1;
    
    auto eval = [&](int k1, int p1) {
        if(k1+p1 <= ans){
            if(p1 < p || k1+p1 < ans){
                ans = k1+p1, k = k1, p = p1;
            }
        }
    };
    // for(int x : phi){
    //     cout<<x<<", ";
    // }cout<<el;
    vi arr;
    for(int i = 0; i < n;++i){
        if(!phi[i]){continue;}
        if((i+1) % (i+1-phi[i]) == 0){
            int x = i+1 - phi[i];
            arr.pb(x);
        }
    }
    for(int x : arr){
        forn(i,n){
            if(vs[i] == vs[i%x]){
                eval(n-i-1, x);
            }
        }
    }

    
    cout<<k<<" "<<p<<el;
}