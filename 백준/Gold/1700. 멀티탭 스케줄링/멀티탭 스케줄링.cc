#include<iostream>
#include<vector>
#include<set>
using namespace std;

vector<int> useOrders[101];
int n, k;
set<int> used;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    cin >> n >> k;
    vector<int> numbers;
    for (int i = 0; i < k; i++) {
        int num;
        cin >> num;
        numbers.emplace_back(num);

        if (useOrders[num].empty()) {
            useOrders[num].emplace_back(1);
        }

        useOrders[num].emplace_back(i);
    }


    int eraseCount = 0;
    for (int i = 0; i < k; i++) {
        int num = numbers[i];
        if (used.size() < n) {
            used.insert(num);
            useOrders[num][0]++;
            continue;
        }

        if (used.find(num) != used.end()) {
            useOrders[num][0]++;
            continue;
        }

        int lastUsed = -1;
        int lastNum = -1;
        for (int plug : used) {
            int index = useOrders[plug][0];
            if (useOrders[plug].size() <= index) {
                lastNum = plug;
                break;
            }
            if (useOrders[plug][index] > lastUsed) {
                lastUsed = useOrders[plug][index];
                lastNum = plug;
            }
        }

        eraseCount++;
        useOrders[num][0]++;
        used.erase(lastNum);
        used.insert(num);
    }

    cout << eraseCount << "\n";
    return 0;
}
