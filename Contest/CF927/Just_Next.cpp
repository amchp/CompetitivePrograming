#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cout << setprecision(20);
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        vector<int> a(n);
        for(int i = 0; i < n; ++i)cin >> a[i];
        int mx = 0;
        vector<int> ans(n);
        ans[0] = -1;
        int ind = 0;
        for(ind = n - 1; ind >= 0; --ind){
            mx = max(a[ind], mx);
            if(a[ind] < mx){
                for(int j = 0; j < ind; ++j){
                    ans[j] = a[j];
                }
                break;
            }
        }
        if(ind < 0){
            cout << -1 << '\n';
            continue;
        }
        for(int j = n - 1; j >= ind; --j){
            if(a[ind] < a[j]){
                ans[ind] = a[j];
                swap(a[ind], a[j]);
                ++ind;
                reverse(a.begin() + ind, a.end());
                for(;ind < n; ++ind){
                    ans[ind] = a[ind];
                }
            }
        }
        for(int& v : ans)cout << v;
        cout << '\n';
    }
}


#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cout << setprecision(20);
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        vector<int> a(n);
        for(int i = 0; i < n; ++i)cin >> a[i];
        multiset<int> s;
        int mx = 0;
        vector<int> ans(n);
        ans[0] = -1;
        for(int i = n - 1; i >= 0; --i){
            mx = max(a[i], mx);
            if(a[i] < mx){
                // d(a[i]);
                for(int j = 0; j < i; ++j){
                    ans[j] = a[j];
                }
                auto it = s.upper_bound(a[i]);
                ans[i] = (*it);
                s.erase(it);
                s.insert(a[i]);
                int ind = i + 1;
                for(int v : s){
                    ans[ind] = v;
                    ++ind;
                }
                break;
            }
            s.insert(a[i]);
        }
        if(ans[0] == -1){
            cout << -1 << '\n';
            continue;
        }
        for(int& v : ans)cout << v;
        cout << '\n';
    }
}
