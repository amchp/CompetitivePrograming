#include <iostream>

using namespace std;

int main(){
    int n;
    int maxCount = 0,
    minCount = 0;
    cin >> n;
    int points[n];
    cin >> points[0];
    int max = points[0],
    min = points[0];
    for(int i = 1; i < n; ++i){
        cin >> points[i];
        if(max < points[i]){max = points[i]; maxCount++;}
        if(min > points[i]){min = points[i]; minCount++;}
    }
    cout << maxCount << " " << minCount << endl;
}