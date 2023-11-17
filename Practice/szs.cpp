#include<bits/stdc++.h>

#define forn(i,n) for(int i = 0; i< (int)n ;++i)
#define for1(i,n) for(int i = 1; i<= (int)n ;++i)
#define el '\n'
#define sz(x) x.size()
#define pb push_back
#define all(x) x.begin(), x.end()


using namespace std;

typedef vector<int> vi;
typedef long long ll;
const int L = 27;
int main(){
    ios_base::sync_with_stdio(false);
  cin.tie(NULL); cout.tie(NULL);
    int n;
    cin >> n;
    vi a(n+3);
    for1(i, n){
        int v;
        cin >> v;
        a[v] = i;

    }
    int cnt = 0;
    for1(i, n - 1){
        // cout << i << ' ' << m[i] << ' ' << m[i + 1] << el;
        if(a[i] > a[i + 1]){
            cnt++;
        }
    }
    // cout << cnt << el;
    int curr = 1,idx = 0;
    forn(i,L+1){
        if(curr > cnt){
            idx = i;
            break;
        }
        curr*=2;
    }

    cout<<idx<<el;
    return 0;
}