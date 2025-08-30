#include <iostream>
#include <queue>

using namespace std;

int n;
priority_queue<int, vector<int>, greater<int>> rooms;
priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;

int main(void)
{
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        int number, s, e;
        cin >> number >> s >> e;
        pq.push({ s, e });
    }
    rooms.push(pq.top().second);
    pq.pop();

    while (pq.size())
    {
        if (rooms.top() <= pq.top().first)
        {
            rooms.push(pq.top().second);
            rooms.pop();
        }
        else
        {
            rooms.push(pq.top().second);
        }
        pq.pop();
    }

    cout << rooms.size() << endl;
}