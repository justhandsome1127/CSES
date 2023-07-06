#include <iostream>
using namespace std;

typedef long long ll;
#define MOD ((ll)1e9 + 7)


int main(){

    ll base = 2, power, ans=1;
    cin >> power;
    while(power){
        if(power & 1){
            ans *= base;
            ans %= MOD;
        }
        base *= base;
        base %= MOD;
        power >>= 1;
    }
    cout << ans << '\n';





    return 0;
}