#include <iostream>
#include <unordered_map>

using namespace std;

int main(){
    int n, m;
    cin >> n >> m;
    int a[n], b[m];
    int maxA, maxB = 0;
    for(int i = 0; i < n; ++i){
        cin >> a[i];
        if(maxA < a[i]) maxA = a[i];
    }
    for(int i = 0; i < m; ++i){
        cin >> b[i];
        if(maxB < b[i]) maxB = b[i];
    }
    unordered_map<int, int> candidates;
    bool allPass;
    for(int i = 1; i <= maxB; ++i){
        allPass = true;
        for(int j = 0; j < n; ++j){
            if(i % a[j] != 0){allPass = false; break;}
        }
        if(allPass) candidates[i]++;
    }

    for(int i = 1; i <= maxB; ++i){
        allPass = true;
        for(int j = 0; j < m; ++j){
            if(b[j] % i != 0){allPass = false; break;}
        }
        if(allPass) candidates[i]++;
    }

    int count = 0;
    for( auto const& [key, val] : candidates ){
        if(val == 2){count++;}
    }
    cout << count << endl;
}