#include<iostream>
#include<vector>

using namespace std;

typedef long long ll;
typedef vector<ll> vi;
#define F0R(i, a) for (int i=0; i<(a); i++)

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

int match(string s, string t) {
    vector <int> f = build(t); 
    int k = 0, ans = 0;
    for(int i = 0; i < s.size(); ++i) {
        while(k && s[i] != t[k]) 
            k = f[k];
        if(s[i] == t[k])   
            k++;
        if(k == t.size()) 
            ans++, k = f[k]; 
    }
    return ans; 
}

int main(){
    string s,t ;
    cin >> s >> t;
    cout << match(s, t);

    return 0;
}
