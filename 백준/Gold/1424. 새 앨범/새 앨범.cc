#include <iostream>
using namespace std;

int main() {
    int n, l, c, capacity = 1;
    cin >> n >> l >> c;

    while((capacity + 1) * l + capacity <= c && capacity < n) {
        capacity++;
    }

    if(capacity % 13 == 0) capacity--;

    if(n % capacity == 0) {
        cout << n / capacity << endl;
    }
    else if((n % capacity) % 13 == 0 && capacity - (n % capacity) == 1) {
        cout << n / capacity + 2 << endl;
    }
    else {
        cout << n / capacity + 1 << endl;
    }
}