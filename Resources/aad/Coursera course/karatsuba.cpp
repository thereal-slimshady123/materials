#include <bits/stdc++.h>
using namespace std;

string add(string a, string b){
    int n1=a.size();
    int n2=b.size();
    if(n1<n2) swap(a,b);
    n1=a.size();
    n2=b.size();
    string ans="";
    int carry=0;
    for(int i=0;i<n1;i++){
        int sum=carry;
        if(i<n2) sum+=b[n2-i-1]-'0';
        sum+=a[n1-i-1]-'0';
        carry=sum/10;
        ans+=sum%10+'0';
    }
    if(carry) ans+=carry+'0';
    reverse(ans.begin(),ans.end());
    return ans;
}

string subtract(string a, string b){
    int n1 = a.size();
    int n2 = b.size();
    if (n1 < n2 || (n1 == n2 && a < b)) swap(a, b); // ensure a >= b
    n1 = a.size();
    n2 = b.size();
    string ans = "";
    int borrow = 0;
    for (int i = 0; i < n1; i++) {
        int sub = (a[n1 - i - 1] - '0') - borrow;
        if (i < n2) sub -= (b[n2 - i - 1] - '0');
        if (sub < 0) {
            sub += 10;
            borrow = 1;
        } else {
            borrow = 0;
        }
        ans += sub + '0';
    }
    while (ans.size() > 1 && ans.back() == '0') ans.pop_back(); // remove leading zeros
    reverse(ans.begin(), ans.end());
    return ans;
}

// string karatsuba(string p, string q){
string karatsuba(string p, string q){
    // Pad the shorter string with leading zeros
    while (p.size() < q.size()) p = "0" + p;
    while (q.size() < p.size()) q = "0" + q;
    int len = p.size();
    if (len == 1) return to_string((p[0] - '0') * (q[0] - '0'));
    if (len % 2) { // make length even
        p = "0" + p;
        q = "0" + q;
        len++;
    }
    int half = len / 2;
    string a = p.substr(0, half);
    string b = p.substr(half, len - half);
    string c = q.substr(0, half);
    string d = q.substr(half, len - half);
    string ac = karatsuba(a, c);
    string bd = karatsuba(b, d);
    string ab = add(a, b);
    string cd = add(c, d);
    string abcd = karatsuba(ab, cd);
    abcd = subtract(subtract(abcd, ac), bd);
    // Shift ac by 2*half, abcd by half
    for (int i = 0; i < 2 * (len - half); i++) ac += '0';
    for (int i = 0; i < (len - half); i++) abcd += '0';
    string ans = add(add(ac, abcd), bd);
    // Remove leading zeros
    int pos = 0;
    while (pos < ans.size() - 1 && ans[pos] == '0') pos++;
    ans = ans.substr(pos);
    return ans;
}
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);

    string a="3141592653589793238462643383279502884197169399375105820974944592";
    string b="2718281828459045235360287471352662497757247093699959574966967627";

    cout<<karatsuba(a, b)<<endl;
    return 0;
}