#include<iostream>
#include<string>

using namespace std;

int n, m, t;
int k, a, b;
string gameMap[100];
enum class State{
    None,
    Survival,   // 생존
    Lonely,  // 고독
    Overcrowded, // 과밀
    Birth       // 탄생
};

State stateMap[100][100];

bool IsOutSide(int y, int x){
    return x < 0 || y < 0 || x >= m || y >= n;
}

bool IsCreature(int y, int x){
    if(IsOutSide(y, x))
        return false;
    
    return gameMap[y][x] == '*'?true:false;
}

void SetState(int y, int x, int cnt){
    if(IsCreature(y, x) == true){
        cnt--;
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

void Scan(){
    int y = 0, x = 0;
    int dx = 1;
    
    int cnt = 0;
    for(int i=y-k;i<=y+k;i++){
        for(int j=x-k;j<=x+k;j++){
            if(IsCreature(i, j))
                cnt++;
        }
    }
    
    for(;y<n;y++){
        while(true){
            SetState(y, x, cnt);
            x += dx;
            if(IsOutSide(y, x) == true){
                x -= dx;
                dx *= -1;
                break;
            }
            
            for(int cy = y - k;cy <= y + k;cy++){
                if(IsCreature(cy, x - ((k + 1)* dx)))
                    cnt--;
                if(IsCreature(cy, x + (k * dx)))
                    cnt++;
            }
        }
        
        for(int cx = x - k;cx <= x + k;cx++){
            if(IsCreature(y-k, cx))
                cnt--;
            if(IsCreature(y+k+1, cx))
                cnt++;
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
        Scan();
        Excute();
        
    }
    
    
    for(int i=0;i<n;i++){
        cout << gameMap[i] << "\n";
    }
    
    
    
    return 0;
}
