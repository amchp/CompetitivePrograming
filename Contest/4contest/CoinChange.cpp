#include <iostream>

using namespace std;

int main(){
    string s;
    getline(cin, s);
    while(!s.empty()){
        int a  = stoi(s);
        int coins[5] = {1, 5, 10, 25, 50};
        int values[a+1];
        for(int i = 1; i < a+1; ++i){
            values[i] = 1;
        }
        for(int i = 1; i < 5 && coins[i] <= a; ++i){
            values[coins[i]] += 1;
            for(int j = coins[i] + 1; j < a+1; ++j){
                values[j] += values[j - coins[i]];
            }
        }
        cout << values[a] << endl;
        getline(cin, s);
    }
}