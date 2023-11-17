#include <iostream>
#include <vector>
#include <stack>
#include <array>


using namespace std;

int main(){
    int t, n, a;
    vector<int> v, vv;
    cin >> t;
    for(int k = 1; k < t + 1; ++k){
        cin >> n;
        vector<int> g[n];
        vector<int> gi[n];
        int visited[n];
        int nonDom[n];
        for(int i = 0; i < n; ++i){
            visited[i] = 0;
            nonDom[i] = 0;
            for(int j = 0; j < n; ++j){
                cin >> a;
                if(a == 1){g[i].push_back(j); gi[j].push_back(i);}
            }
        }

        stack<int> s;
        visited[0] = 1;
        s.push(0);
        while(!s.empty() && n != 1){
            a = s.top();
            s.pop();
            v = g[a];
            for(int i = 0; i < v.size(); ++i){
                visited[v[i]]++;
                s.push(v[i]);
            }
        }
        for(int i = 1; i < n; ++i){
            if(visited[i] != visited[i-1]){
                vv = gi[i];
                for(int j = 0; j < vv.size(); ++j){
                    nonDom[vv[j]] = 1;
                }
            }
        }

        cout << "Case " << k << ":" << endl;
        for(int i = 0; i < n; ++i){
            cout << "+";
            for(int j = 0; j < 2*n - 1; ++j){ cout << "-";}
            cout << "+" << endl;
            for(int j = 0; j < n; ++j){
                cout << "|";
                if((visited[i] <= visited[j] && nonDom[i] != 1) || i == j) cout << "Y";
                else cout << "N";
            }
            cout << "|" << endl;
        }
        cout << "+";
        for(int j = 0; j < 2*n - 1; ++j){ cout << "-";}
        cout << "+" << endl;
    }
}