#include<iostream>
#include<queue>
#include<vector>
#include<algorithm>
#include<cstring>

using namespace std;
int n;

class Room{
public:
    vector<int> nextRooms;
    
    virtual int Excute(int money){
        return money;
    }
};

class LeprechaunRoom:public Room{
private:
    int minMoney;
public:
    LeprechaunRoom(int minMoney):minMoney(minMoney){
        
    }
    
    int Excute(int money) override{
        return max(minMoney, money);
    }
};

class TrollRoom:public Room{
private:
    int cost;
public:
    TrollRoom(int cost):cost(cost){
        
    }
    
    int Excute(int money) override{
        return money - cost;
    }
};

vector<Room*> rooms;
int visited[1001] = {0};

bool solve(int s, int money){
    money = rooms[s]->Excute(money);
    if(money < 0)
        return false;
    
    if(s == n)
        return true;
    
    
    bool result = false;
    vector<int>& nextRooms = rooms[s]->nextRooms;
    for(int i=0;i<nextRooms.size();i++){
        int e = nextRooms[i];
        
        if(visited[e] == 1)
            continue;
        
        visited[e] = 1;
        if(solve(e, money) == true){
            result = true;
            break;
        }
        visited[e] = 0;
    }
    
    return result;
}

void Init(){
    for(int i=0;i<n;i++){
        delete rooms[i];
    }
    rooms.clear();
    rooms.emplace_back(new Room());
    
    memset(visited, 0, sizeof(visited));
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    while(true){
        Init();
        cin >> n;
        if(n == 0)
            break;
        
        for(int i=0;i<n;i++){
            Room* room = nullptr;
            char c;
            int roomMoney;
            cin >> c >> roomMoney;
            if(c == 'L')
                room = new LeprechaunRoom(roomMoney);
            else if(c == 'T')
                room = new TrollRoom(roomMoney);
            else
                room = new Room();
            
            
            while(true){
                int e;
                cin >> e;
                if(e == 0)
                    break;
                room->nextRooms.emplace_back(e);
            }
            
            rooms.emplace_back(room);
        }
        
        if(solve(1, 0) == true)
            cout << "Yes\n";
        else
            cout << "No\n";
    }
    
    return 0;
}
