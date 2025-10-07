#include<iostream>
#include<vector>
#include<stack>
#include<algorithm>

using namespace std;

typedef long long PointType;

template<typename T>
struct Point{
    T y, x;
    
    Point(T _x, T _y):x(_x), y(_y){
        
    }
    
    void swap(Point& other){
        swap(x, other.x);
        swap(y, other.y);
    }
};
Point<PointType> pivot = {0, 0};
int n;
vector<Point<PointType>> points;
stack<Point<PointType>> st;

PointType ccw(Point<PointType> a, Point<PointType> b, Point<PointType> c){
    return a.x * b.y + b.x * c.y + c.x * a.y - a.x * c.y - b.x * a.y - c.x * b.y;
}

bool compare(Point<PointType> a, Point<PointType> b){
    PointType value = ccw(pivot, a, b);
    if(value) return value > 0;
    else if(a.y != b.y) return a.y < b.y;
    
    return a.x < b.x;
}

void Sort(){
    sort(points.begin(), points.end(), compare);
}
void Input(){
    cin >> n;
    points.reserve(n);
    for(int i=0;i<n;i++){
        PointType x, y;
        cin >> x >> y;
        points.emplace_back(Point(x, y));
        
        if(i == 0)
            pivot = points[i];
        else if(pivot.y > points[i].y || (pivot.y == points[i].y && pivot.x > points[i].x)){
            pivot = points[i];
        }
    }
}

int Solve(){
    st.push(points[0]);
    st.push(points[1]);
    
    for(int i=2;i<n;i++){
        while(st.size() >= 2){
            Point<PointType> a = st.top();
            st.pop();
            Point<PointType> b = st.top();
            if(ccw(b, a, points[i]) > 0){
                st.push(a);
                break;
            }
        }
        st.push(points[i]);
    }
    
    return st.size();
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    Input();
    Sort();
    int result = Solve();
    cout << result << "\n";
    
    return 0;
}
