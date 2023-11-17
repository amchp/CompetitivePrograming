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
        int t;
        cin >> t;
        while (t--){
            ll C, R, S;
            cin >> C >> R >> S;
            ll ans;
            if(R == 0){
                ans = ceil((double)C / S);
            }else{
                ans = C / S;
            }
            ll ans2 = max((ll)0, (ll)ceil((double)(C + R) / S) - R);
            cout << ans << ' ' << ans2 << el;
        }
    }