#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define mod 1000000007
const ll inf=1e18;
 int dp[2001][2001]; 
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
  int n;
  cin>>n;
  int v[n+1];
  for(int i=1;i<=n;i++)
    cin>>v[i];
  memset(dp,-1,sizeof(dp));
  for(int i=1;i<=n;i++){
    for(int j=1;j<=n;j++){
      if(i==j)
        dp[i][i]=v[i]*n;
    }
  }
  for(int i=n;i>=1;i--){
    for(int j=i;j<=n;j++){
      if(i!=j){
        dp[i][j]=max(v[i]*(i-1+(n-j)+1)+dp[i+1][j],v[j]*(i-1+(n-j)+1)+dp[i][j-1]);
      }
    }
  }
  cout<<dp[1][n]<<"\n";
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