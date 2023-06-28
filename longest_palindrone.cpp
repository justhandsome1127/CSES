#include <iostream>
using namespace std;

string expand(string s){
    string str = "*#";
    for(int i=0; i<s.size(); i++){
        str += s[i];
        str += '#';
    }
    return str;
}

string Manacher(string s){
    string str = expand(s);
    int index = 0, max = 0, len[2000005], start = 0, maxlen = 0;
    for(int i=0; i<str.length(); i++){
        if(i<max) 
            len[i] = min(len[2*index-i], max-i);
        else 
            len[i] = 1;
        for(; str[i+len[i]] == str[i-len[i]] && i+len[i]<str.size() && i-len[i]>0; len[i]++);
        if(len[i]+i > max){
            max = len[i] + i;
            index = i;
        }
        if(len[i]-1 > maxlen){
            maxlen = len[i] - 1;
            start = (index-maxlen) / 2;
        }
    }
    return s.substr(start, maxlen);
}


int main(){
    string s;
    cin >> s;
    cout << Manacher(s);

    return 0;
}