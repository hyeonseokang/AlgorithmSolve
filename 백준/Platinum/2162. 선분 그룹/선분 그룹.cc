#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
struct Point{
    int x = 0;
    int y = 0;
};

struct Line{
    Point a;
    Point b;
};

bool isOverlap(Point a, Point b, Point c, Point d) {
        // x와 y 좌표 범위로 겹치는지 확인
        return max(a.x, b.x) >= min(c.x, d.x) && max(c.x, d.x) >= min(a.x, b.x) &&
               max(a.y, b.y) >= min(c.y, d.y) && max(c.y, d.y) >= min(a.y, b.y);
}

int ccw(Point a, Point b, Point c){
        long long result = ((long long)b.x - a.x) * (c.y - a.y) - ((long long)c.x - a.x) * (b.y - a.y);
        
        if(result < 0)
            return -1;
        else if(result > 0)
            return 1;
        
        return 0;
    }

bool IsCrossLine(const Line& a, const Line& b){
    const Point& a1 = a.a;
    const Point& a2 = a.b;
    const Point& b1 = b.a;
    const Point& b2 = b.b;
    
    int abc = ccw(a1, a2, b1);
    int abd = ccw(a1, a2, b2);
    int cda = ccw(b1, b2, a1);
    int cdb = ccw(b1, b2, a2);
    
    if(abc * abd == -1 && cda * cdb == -1)
        return true;
    else if(abc == 0 && abd == 0){
        if(isOverlap(a1, a2, b1, b2))
            return true;
    }
    
    else if(abc * abd <= 0 && cdb * cda <= 0)
    {
        return true;
    }
    else if(abc * abd == 0 && cdb * cda <= 0)
    {
        return true;
    }
    
    return false;
}

int n;
int parents[3000];
int sizes[3000] = {0};

int Find(int i){
    int parent = parents[i];
    if(parent == i)
        return parent;
    
    return parents[i] = Find(parent);
}

void Merge(int a, int b){
    int aParent = Find(a);
    int bParent = Find(b);
    
    if(aParent < bParent){
        parents[bParent] = aParent;
    }
    else{
        parents[aParent] = bParent;
    }
}

long long CCW(int x1, int y1, int x2, int y2, int x3, int y3) {
    return (x2 - x1) * (y3 - y2) - (y2 - y1) * (x3 - x2);
}

bool isCross(Line L1, Line L2) {
    int x1 = L1.a.x, y1 = L1.a.y, x2 = L1.b.x, y2 = L1.b.y;
    int x3 = L2.a.x, y3 = L2.a.y, x4 = L2.b.x, y4 = L2.b.y;

    long long ccw1 = CCW(x1, y1, x2, y2, x3, y3) * CCW(x1, y1, x2, y2, x4, y4);
    long long ccw2 = CCW(x3, y3, x4, y4, x1, y1) * CCW(x3, y3, x4, y4, x2, y2);

    if (ccw1 <= 0 && ccw2 <= 0) {
        if (max(x1, x2) >= min(x3, x4) && min(x1, x2) <= max(x3, x4) &&
            max(y1, y2) >= min(y3, y4) && min(y1, y2) <= max(y3, y4))
            return true;
    }
    return false;
}


Line lines[3000];
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    cin >> n;
    for(int i=0;i<n;i++){
        cin >> lines[i].a.x >> lines[i].a.y >> lines[i].b.x >> lines[i].b.y;
        parents[i] = i;
        sizes[i] = 0;
    }
    
    int maxSize = 1;
    int groupCount = 0;
    for(int i=0;i<n;i++){
        for(int j=0;j<i;j++){
            if(i == j)
                continue;
            if(isCross(lines[i], lines[j]) == false)
                continue;
            
            Merge(i, j);
        }
    }
    
    for(int i=0;i<n;i++){
        sizes[Find(i)]++;
    }
    
    for(int i=0;i<n;i++){
        if(sizes[i] != 0){
            groupCount++;
            maxSize = max(maxSize, sizes[i]);
        }
    }
    
    cout << groupCount << "\n" << maxSize << "\n";
    
    return 0;
}
