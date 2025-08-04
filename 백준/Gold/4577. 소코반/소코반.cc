#include<iostream>
#include<string>

using namespace std;

struct Pos{
    int y;
    int x;
    
    Pos(){
        
    }
    
    Pos(int inY, int inX):y(inY), x(inX){
        
    }
};

int r, c;
string board[16];
string operators;
Pos playerPosition;

bool isEnd = false;

int dy[4] = {-1, 0, 1, 0};
int dx[4] = {0, 1, 0, -1};
int successBoxCount = 0;

enum class Type{
    Blank,
    Wall,
    BlankGoal,
    Box,
    GoalBox,
    Player,
    GoalPlayer
};

int GetOperIndex(const char oper){
    if(oper == 'D')
        return 2;
    else if(oper == 'U')
        return 0;
    else if(oper == 'L')
        return 3;
    else if(oper == 'R')
        return 1;
    
    return -1;
}

Type GetType(int y, int x){
    Type type = Type::Blank;
    if(board[y][x] == '.')
        type = Type::Blank;
    else if(board[y][x] == '#')
        type = Type::Wall;
    else if(board[y][x] == '+')
        type = Type::BlankGoal;
    else if(board[y][x] == 'b')
        type = Type::Box;
    else if(board[y][x] == 'B')
        type = Type::GoalBox;
    else if(board[y][x] == 'w')
        type = Type::Player;
    else if(board[y][x] == 'W')
        type = Type::GoalPlayer;
    
    return type;
}

void MovePlayer(const Pos& next, const Type& nextType){
    if(nextType != Type::Blank && nextType != Type::BlankGoal)
        return;
    
    if(nextType == Type::Blank){
        board[next.y][next.x] = 'w';
    }
    if(nextType == Type::BlankGoal){
        board[next.y][next.x] = 'W';
    }
    
    Type currentType = GetType(playerPosition.y, playerPosition.x);
    if(currentType == Type::GoalPlayer)
        board[playerPosition.y][playerPosition.x] = '+';
    if(currentType == Type::Player)
        board[playerPosition.y][playerPosition.x] = '.';
    
    
    playerPosition = next;
}

// ULRURDDDUULLDDD
void MoveBox(const Pos& boxPos, const Type& boxType, const int direction){
    Pos next = Pos(boxPos.y + dy[direction], boxPos.x + dx[direction]);
    Type nextType = GetType(next.y, next.x);
    
    if(nextType != Type::Blank && nextType != Type::BlankGoal)
        return;
    
    
    if(nextType == Type::BlankGoal){
        board[next.y][next.x] = 'B';
    }
    if(nextType == Type::Blank)
        board[next.y][next.x] = 'b';
    
    if(boxType == Type::GoalBox){
        board[boxPos.y][boxPos.x] = '+';
    }
    if(boxType == Type::Box){
        board[boxPos.y][boxPos.x] = '.';
    }
    
}
// DLLUDLULUURDRDDLUDRR

void CalculateOper(const char oper){
    int direction = GetOperIndex(oper);
    Pos next = Pos(playerPosition.y + dy[direction], playerPosition.x + dx[direction]);
    
    Type nextType = GetType(next.y, next.x);
    if(nextType == Type::Wall){
        return;
    }
    
    if(nextType == Type::Box || nextType == Type::GoalBox){
        Type boxType = GetType(next.y, next.x);
        MoveBox(next, boxType, direction);
    }
    
    nextType = GetType(next.y, next.x);
    if(nextType == Type::Blank || nextType == Type::BlankGoal)
    {
        MovePlayer(next, nextType);
    }
}

bool IsEnd(){
    for(int i=0;i<r;i++){
        for(int j=0;j<c;j++){
            if(board[i][j] == 'W'||
               board[i][j] == 'b' ||
               board[i][j] == '+' )
                return false;
        }
    }
    
    return true;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    int gameCount = 0;
    while(true){
        isEnd = false;
        successBoxCount = 0;
        gameCount++;
        cin >> r >> c;
        if(r == 0 || c == 0)
            break;
        
        for(int i=0;i<r;i++){
            cin >> board[i];
            for(int j=0;j<c;j++){
                if(board[i][j] == 'w' || board[i][j] == 'W'){
                    playerPosition = Pos(i, j);
                }
                else if(board[i][j] == 'b')
                    successBoxCount--;
            }
        }
        
        // DDDLLLUUR
        
        cin >> operators;
        for(int i=0;i<operators.size();i++){
            CalculateOper(operators[i]);
            
            if(IsEnd() == true)
                break;
        }
        
        
        if(IsEnd()){
            cout << "Game " << gameCount << ": complete" << "\n";
        }
        else{
            cout << "Game " << gameCount << ": incomplete" << "\n";
        }
        
        for(int i=0;i<r;i++){
            cout << board[i] << "\n";
        }
        
        
    }
    
    
    return 0;
}
