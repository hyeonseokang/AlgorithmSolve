#include<iostream>
#include<string>

using namespace std;

int n, m, t;
int k, a, b;
string gameMap[100];
int prefixSums[100][100] = {0};
enum class State{
    None,
    Survival,   // 생존
    Lonely,  // 고독
    Overcrowded, // 과밀
    Birth       // 탄생
};

State stateMap[100][100];

bool IsCreature(int y, int x){
    return gameMap[y][x] == '*'?true:false;
}

void SetState(int y, int x, int cnt){
    if(IsCreature(y, x) == true){
        if(a <= cnt && cnt <= b)
            stateMap[y][x] = State::Survival;
        else if(cnt < a)
            stateMap[y][x] = State::Lonely;
        else if(cnt > b)
            stateMap[y][x] = State::Overcrowded;
    }
    else if(a < cnt && cnt <= b){
        stateMap[y][x] = State::Birth;
    }
    else{
        stateMap[y][x] = State::None;
    }
}

void SetPrefix(){
    prefixSums[0][0] = IsCreature(0, 0);
    for(int i=1;i<n;i++){
        prefixSums[i][0] = prefixSums[i-1][0] + IsCreature(i, 0);
    }
    for(int i=1;i<m;i++){
        prefixSums[0][i] = prefixSums[0][i-1] + IsCreature(0, i);
    }
    
    for(int i=1;i<n;i++){
        for(int j=1;j<m;j++){
            int up = prefixSums[i-1][j];
            int left = prefixSums[i][j-1];
            
            prefixSums[i][j] = up + left - prefixSums[i-1][j-1];
            prefixSums[i][j] += IsCreature(i, j);
        }
    }
}

int GetCnt(int y, int x){
    int luY = y - k, luX = x - k;
    int rdY = y + k, rdX = x + k;
    if(rdY >= n)
        rdY = n - 1;
    if(rdX >= m)
        rdX = m - 1;
    
    int up = 0, left = 0;
    if(luY > 0)
        up = prefixSums[luY - 1][rdX];
    if(luX > 0)
        left = prefixSums[rdY][luX - 1];
    
    int my = IsCreature(y, x);
    
    if(luY <= 0 || luX <= 0)
        return prefixSums[rdY][rdX] - up - left - my;
    else
        return prefixSums[rdY][rdX] - up - left + prefixSums[luY-1][luX-1] - my;
}

void Scan(){
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            int cnt = GetCnt(i, j);
            SetState(i, j, cnt);
        }
    }
    
}

void Excute(){
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(stateMap[i][j] == State::Lonely || stateMap[i][j] == State::Overcrowded){
                gameMap[i][j] = '.';
            }
            else if(stateMap[i][j] == State::Birth)
                gameMap[i][j] = '*';
        }
    }
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    cin >> n >> m >> t;
    cin >> k >> a >> b;
    
    for(int i=0;i<n;i++){
        cin >> gameMap[i];
    }
    
    while(t--){
        SetPrefix();
        Scan();
        Excute();
    }
    
    for(int i=0;i<n;i++){
        cout << gameMap[i] << "\n";
    }
    
    
    
    return 0;
}
