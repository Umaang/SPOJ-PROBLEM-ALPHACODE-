#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define mod 1000000007
const ll inf=1e18;
ll dp[5000]; 
 bool ispalindrome(string s){
    int i=0,j=s.length()-1;
    while(i<=j){
        if(s[i]==s[j])
        {
            i++;
            j--;
        }
        else
            return false;
    }
    return true;
 } 
 ll gcd(ll a, ll b)
 {
     if (b == 0)
        return a;
     return gcd(b, a % b);
     
 }
void test(){
  while(true){
    string s;
    cin>>s;
    if(s=="0")
      break;
    int n=s.length();
    memset(dp,0,sizeof(dp));
    string res="";
    dp[0]=1;
    res.push_back(s[0]);
    res.push_back(s[1]);
    if(stoi(res)>26)
      dp[1]=1;
    else{
      if(s[1]=='0')
        dp[1]=1;
      else
        dp[1]=2;
    }
    for(int i=2;i<n;i++){
       res="";
      if(s[i]=='0')
      {
         dp[i]=dp[i-2];
      }
      else if(s[i-1]=='0')
      {
        dp[i]=dp[i-1];
      }
      else{
      res.push_back(s[i-1]);
      res.push_back(s[i]);
      if(stoi(res)>26){
        dp[i]=dp[i-1];
      }
      else{
          dp[i]=dp[i-1]+dp[i-2];
      }
     }
    }
      
     
      cout<<dp[n-1]<<"\n";  
  }
 
 //cout<<"Hello World"<<"\n";   
 
  //cout<<fixed<<setprecision(9)<<ans;
}
signed main(){
    ios::sync_with_stdio(false);
    #ifndef ONLINE_JUDGE
            freopen("input.txt", "r", stdin);freopen("output.txt", "w", stdout);
    #endif 
    test();   
} 