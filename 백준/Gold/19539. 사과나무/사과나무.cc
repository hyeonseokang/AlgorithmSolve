#include<iostream>

using namespace std;

int n;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    cin >> n;
    
    int sum = 0;
    int even = 0;
    for (int i = 0; i < n; i++) {
        int num;
        cin >> num;
        
        sum += num;
        even += num / 2;
    }
    
    if(sum % 3 == 0 && sum / 3 <= even){
        cout << "YES\n";
    }
    else{
        cout << "NO\n";
    }
    

    return 0;
}
