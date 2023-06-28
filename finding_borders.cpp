#include <iostream>
#include <vector>
using namespace std;

vector <int> build(string s){
    vector <int> f(s.size() + 1, 0);
    int k = 0;
    for(int i = 1; i < s.size(); ++i){
        while(k && s[k] != s[i]) 
            k = f[k];
        if (s[k] == s[i]) 
            k++;
        f[i + 1] = k; 
    }
    return f; 
}

int main(){
    string s;
    cin >> s;
    vector<int> board = build(s);
    board.erase(board.begin());
    vector<int> ans;
    int n = board.size();
    while(n>0){
        if(board[n]>0){
            ans.push_back(board[n]);
            n = board[n]-1;
        }
        else break;
    }
    for(int i=ans.size()-1; i>=0; i--){
        cout << ans[i] << ' ';
    }
    cout << '\n';
    
 
    return 0;
}