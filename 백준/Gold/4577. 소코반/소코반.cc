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

enum class Type{
    Blank, // .
    Wall, // #
    BlankGoal, // +
    Box, // b
    GoalBox, // B
    Player, // w
    GoalPlayer  // W
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
    char c = board[y][x];
    if(c == '.')
        type = Type::Blank;
    else if(c == '#')
        type = Type::Wall;
    else if(c == '+')
        type = Type::BlankGoal;
    else if(c == 'b')
        type = Type::Box;
    else if(c == 'B')
        type = Type::GoalBox;
    else if(c == 'w')
        type = Type::Player;
    else if(c == 'W')
        type = Type::GoalPlayer;
    
    return type;
}

void MoveUpdatePlayer(const Type& type){
    if(type == Type::Player)
        board[playerPosition.y][playerPosition.x] = '.';
    else if(type == Type::GoalPlayer)
        board[playerPosition.y][playerPosition.x] = '+';
}

bool IsOut(const Pos& pos){
    if(pos.y < 0 || pos.x < 0 || pos.y >= r || pos.x >= c)
        return true;
    
    return false;
}
void CalculateOper(const char oper){
    int dir = GetOperIndex(oper);
    Pos next = Pos(playerPosition.y + dy[dir], playerPosition.x + dx[dir]);
    if(IsOut(next))
        return;
    
    Type nextType = GetType(next.y, next.x);
    Type currentType = GetType(playerPosition.y, playerPosition.x);
    if(nextType == Type::Wall){
        return;
    }
    
    if(nextType == Type::Blank){
        MoveUpdatePlayer(currentType);
        board[next.y][next.x] = 'w';
        playerPosition = next;
    }
    else if(nextType == Type::BlankGoal){
        MoveUpdatePlayer(currentType);
        board[next.y][next.x] = 'W';
        playerPosition = next;
    }
    else if(nextType == Type::Box){
        Pos nnext = Pos(next.y + dy[dir], next.x + dx[dir]);
        Type nnextType = GetType(nnext.y, nnext.x);
        if(IsOut(nnext))
            return;
        if(nnextType == Type::Blank){
            board[nnext.y][nnext.x] = 'b';
            board[next.y][next.x] = 'w';
            MoveUpdatePlayer(currentType);
            playerPosition = next;
        }
        else if(nnextType == Type::BlankGoal){
            board[nnext.y][nnext.x] = 'B';
            board[next.y][next.x] = 'w';
            MoveUpdatePlayer(currentType);
            playerPosition = next;
        }
    }
    else if(nextType == Type::GoalBox){
        Pos nnext = Pos(next.y + dy[dir], next.x + dx[dir]);
        Type nnextType = GetType(nnext.y, nnext.x);
        if(IsOut(nnext))
            return;
        
        if(nnextType == Type::Blank){
            board[nnext.y][nnext.x] = 'b';
            board[next.y][next.x] = 'W';
            MoveUpdatePlayer(currentType);
            playerPosition = next;
        }
        else if(nnextType == Type::BlankGoal){
            board[nnext.y][nnext.x] = 'B';
            board[next.y][next.x] = 'W';
            MoveUpdatePlayer(currentType);
            playerPosition = next;
        }
    }
}

bool IsEnd(){
    for(int i=0;i<r;i++){
        for(int j=0;j<c;j++){
            if(board[i][j] == 'b')
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
            }
        }
        
        cin >> operators;
        for(int i=0;i<operators.size();i++){
            if(IsEnd() == true)
                break;
            
            CalculateOper(operators[i]);
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
