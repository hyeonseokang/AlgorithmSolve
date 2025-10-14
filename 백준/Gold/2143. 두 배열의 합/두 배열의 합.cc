#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

int t;
int n, m;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    cin >> t;
    cin >> n;
    vector<int> a(n+1, 0);
    for(int i=1;i<=n;i++){
        cin >> a[i];
        a[i] += a[i-1];
    }
    cin >> m;
    vector<int> b(m+1, 0);
    for(int i=1;i<=m;i++){
        cin >> b[i];
        b[i] += b[i-1];
    }
    
    unsigned long long int result = 0;
    vector<int> bSum;
    for(int i=0;i<m;i++){
        for(int j=i+1;j<=m;j++){
            int temp = b[j] - b[i];
            bSum.emplace_back(temp);
        }
    }
    sort(bSum.begin(), bSum.end());
    for(int i=0;i<n;i++){
        for(int j=i+1;j<=n;j++){
            int target = t - (a[j] - a[i]);
            
            int l = lower_bound(bSum.begin(), bSum.end(), target) - bSum.begin();
            int u = upper_bound(bSum.begin(), bSum.end(), target) - bSum.begin();
            
            result += (u - l);
        }
    }
    
    cout << result << "\n";
    return 0;
}
