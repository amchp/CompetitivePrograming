#include <iostream>

using namespace std;

int main(){
    string initial, desired;
    int k;
    bool weird = false;
    cin >> initial >> desired;
    cin >> k;
    if(initial.length() + desired.length() < k) weird = true;
    while(initial != desired.substr(0, initial.length()) && k > 0){
        initial = initial.substr(0, initial.length() - 1);
        k--;
    }
    if(k)
    if(desired.length() >= initial.length()){
        k -= desired.length() - initial.length();
        initial = initial + desired.substr(initial.length(), desired.length() - initial.length());
    }
    if(k == 0 && desired == initial || (k > 0 && k % 2 == 0) || weird) cout << "Yes" << endl;
    else cout << "No" << endl;
}