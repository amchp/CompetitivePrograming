#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cout << setprecision(20);
    int t, nA, nB, k;
    string a, b, c;
    cin >> t;
    while(t--){
        cin >> nA >> nB >> k;
        cin >> a >> b;
        sort(a.begin(), a.end());
        sort(b.begin(), b.end());
        int i = 0;
        int j = 0;
        int cA = 0;
        int cB = 0;
        c = "";
        while(i < nA && j < nB){
            if(cA < k && (a.at(i) < b.at(j) || cB == k)){
                c += a.at(i);
                i++;
                cA++;
                cB = 0;
            }else{
                c += b.at(j);
                j++;
                cB++;
                cA = 0;
            }
        }
        cout << c << '\n';
    }
}
