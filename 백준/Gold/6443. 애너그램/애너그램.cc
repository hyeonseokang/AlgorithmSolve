#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
#include<unordered_set>

using namespace std;

vector<pair<char, int>> alphabets;
char word[20];

void SolveAnagram(const string& s, vector<string>& anagram, int len){
    if(len == s.size()){
        anagram.emplace_back(word, word + len);
        return;
    }
    
    for(int i=0;i<alphabets.size();i++){
        if(alphabets[i].second == 0)
            continue;
        
        alphabets[i].second--;
        word[len] = alphabets[i].first;
        SolveAnagram(s, anagram, len + 1);
        alphabets[i].second++;
    }
}

void solve(const string& s){
    vector<string> anagram;
    SolveAnagram(s, anagram, 0);
    //sort(anagram.begin(), anagram.end());
    
    for(int i=0;i<anagram.size();i++){
        cout << anagram[i] << "\n";
    }
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    int t;
    cin >> t;
    while(t--){
        string s;
        cin >> s;
        sort(s.begin(), s.end());
        alphabets.clear();
        char prev = ' ';
        for(int i=0;i<s.size();i++){
            char c = s[i];
            if(prev != c){
                alphabets.emplace_back(c, 1);
                prev = c;
            }
            else{
                alphabets.back().second++;
            }
        }
        
        solve(s);
    }
    
    return 0;
}
