#include <iostream>
#include <algorithm>

using namespace std;

int top_val(int index) {
    if (index == 0) return 5;
    if (index == 1) return 3;
    if (index == 2) return 4;
    if (index == 3) return 1;
    if (index == 4) return 2;
    if (index == 5) return 0;
    return 0;
}

int main() {
    int N;
    int map[10000][6];
    cin >> N;
    for (int i = 0; i < N; i++) {
        for (int s = 0; s < 6; s++) {
            cin >> map[i][s];
        }
    }
    int ans = 0;

    for (int a = 0; a < 6; a++) {
        int temp_ans = 0;
        int index = a;
        int max_val = 0;
        for (int i = 0; i < N - 1; i++) {
            max_val = 0;

            index = top_val(index);
            for (int s = 0; s < 6; s++) {
                if (map[i + 1][s] == map[i][index]) {
                    for (int x = 0; x < 6; x++) {
                        if (x == index || x == top_val(index)) { continue; }
                        else max_val = max(max_val, map[i][x]);
                    }
                    index = s;
                    break;
                }
            }

            temp_ans += max_val;
        }
        max_val = 0;
        index = top_val(index);
        for (int x = 0; x < 6; x++) {
            if (x == index || x == top_val(index)) { continue; }
            else max_val = max(max_val, map[N - 1][x]);
        }
        temp_ans += max_val;
        ans = max(temp_ans, ans);
    }
    cout << ans;
    return 0;
}