#include<iostream>
#include<vector>

using namespace std;

int boards[9][9] = {0};
int diagonals[9] = {0};
int rows[9] = {0};
int columns[9] = {0};
vector<pair<int, int>> zeroBlanks;


int GetPossibleNumber(int y, int x, const int& diagonal, const int& row, const int& column){
    int bit = 0;
    
    bit = diagonal | row | column;
    int possibleBit = 0;
    
    for(int i=0;i<9;i++){
        int temp = bit & (1 << i);
        if(temp == 0){
            possibleBit |= (1 << i);
        }
    }
    
    return possibleBit;
}

bool solve(int len){
    if(len == zeroBlanks.size()){
        return true;
    }
    
    int y = zeroBlanks[len].first;
    int x = zeroBlanks[len].second;
    
    int& diagonal = diagonals[(y/3)*3 + (x/3)];
    int& row = rows[x];
    int& column = columns[y];
    int prevDiagonal = diagonal;
    int prevRow = row;
    int prevColumn = column;
    
    int bit = GetPossibleNumber(y, x, diagonal, row, column);
    for(int i=0;i<9;i++){
        int flag = (1 << i);
        int temp = bit & flag;
        if((bit & temp) > 0){
            diagonal |= flag;
            row |= flag;
            column |= flag;
            boards[y][x] = i + 1;
            if(solve(len + 1))
                return true;
            diagonal = prevDiagonal;
            row = prevRow;
            column = prevColumn;
        }
    }
    
    
    return false;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    for(int i=0;i<9;i++){
        for(int j=0;j<9;j++){
            cin >> boards[i][j];
            
            if(boards[i][j] == 0){
                zeroBlanks.emplace_back(i, j);
            }
            else{
                int bit = (1 << (boards[i][j] - 1));
                diagonals[(i/3)*3 + (j/3)] |= bit;;
                rows[j] |= bit;
                columns[i] |= bit;
            }
        }
    }
    
    solve(0);
    for(int i=0;i<9;i++){
        for(int j =0;j<9;j++){
            cout << boards[i][j] << " ";
        }
        cout << "\n";
    }
    
    return 0;
}
