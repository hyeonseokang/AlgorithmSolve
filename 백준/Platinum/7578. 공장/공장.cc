#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

int n;
int numbers[1000001];
int nums[500001];

class FenwickTree {
public:
    std::vector<int> bit;
    int size;

    FenwickTree(int n) {
        size = n;
        bit.assign(n + 1, 0);
    }

    void update(int idx, int delta) {
        while (idx <= size) {
            bit[idx] += delta;
            idx += idx & -idx;
        }
    }

    int query(int idx) {
        int sum = 0;
        while (idx > 0) {
            sum += bit[idx];
            idx -= idx & -idx;
        }
        return sum;
    }
};

long long countInversions() {
    std::vector<std::pair<int, int>> indexedArr;
    for (int i = 0; i < n; i++) {
        indexedArr.emplace_back(nums[i], i + 1);  // 값, 원래 인덱스 저장
    }

    // 값 기준으로 정렬 (내림차순)
    std::sort(indexedArr.begin(), indexedArr.end(), std::greater<>());

    FenwickTree ft(n);
    long long totalCount = 0;

    for (auto [value, idx] : indexedArr) {
        totalCount += (long long)ft.query(idx - 1);  // 자기보다 작은 인덱스 중 큰 값 개수
        ft.update(idx, 1);  // 현재 값을 Fenwick Tree에 추가
    }

    return totalCount;
}



int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    cin >> n;
    for(int i=1;i<=n;i++){
        int num;
        cin >> num;
        numbers[num] = i;
    }
    
    long long result = 0;
    for(int i=0;i<n;i++){
        int num;
        cin >> num;
        nums[i] = numbers[num];
    }
    
    cout << countInversions() << "\n";
    
    return 0;
}
