    #include <vector>
    #include <map>
    #include <cstdlib>
    #include <fstream>
    #include <iomanip>
    #include <iostream>
    #include <sstream> // istringstream buffer(myString);
    #include <stack>
    #include <algorithm>
    #include <cstring>
    #include <cassert>
    #include <math.h>
    #include <unordered_map>
    #include <queue>
    #include <array>
    #include <set>
    #include <numeric>

    using namespace std;

    typedef long long ll;

    #define el '\n'

    int main(){
        ios_base::sync_with_stdio(false);
        cin.tie(0);
        cout.tie(0);
        int n;
        ll m;
        string s;
        cin >> n;
        cin >> s;
        m = stoll(s.substr(0, s.size() - 1));
        char c = s[s.size() - 1];
        if(c == 'G')m *= 1e3;
        if(c == 'T')m *= 1e6;
        vector<ll> a(n);
        vector<ll> pS(n + 1);
        cin >> a[0];
        pS[0] = 0;
        for(int i = 1; i < n; ++i){
            cin >> a[i];
            pS[i] = a[i - 1] + pS[i - 1];
        }
        pS[n] = a[n - 1] + pS[n - 1];
        int ind = -1;
        int ans = n;
        for(int i = 0; i < n; ++i){
            int up = upper_bound(pS.begin(), pS.end(), m + pS[i]) - pS.begin();
            if(up >= n + 1)break;
            if(i != up)up--;
            if(up - i < ans){
                ans = up - i;
                ind = i + 1;
            }
        }
        cout << ans << ' ' << ind << el;
    }