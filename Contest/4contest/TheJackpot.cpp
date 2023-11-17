#include <iostream>
#include <vector>

using namespace std;

int main(){
    int n, v, winStreak, mWS;
    vector<int> arr;
    cin >> n;
    while(n != 0){
        vector<int> arr(n);
        for(int i = 0; i < n; ++i){
            cin >> arr[i];
        }
        winStreak = 0;
        mWS = 0;
        for(int i = 0; i < n; ++i){
            winStreak = 0;
            for(int j = i; j < n; ++j){
                winStreak += arr[j];
                if(mWS < winStreak) mWS = winStreak;
            }
        }
        if(mWS < winStreak) mWS = winStreak;
        if(mWS != 0) cout << "The maximum winning streak is " << mWS << "." << endl;
        else cout << "Losing streak." << endl;
        cin >> n;
    }
}