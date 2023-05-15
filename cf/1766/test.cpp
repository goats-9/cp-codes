#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull; 
typedef pair<int, int> pii;
typedef pair<long long, long long> pll;
typedef vector<int> vi;
typedef vector<long long> vll;
typedef map<int, int> mii;
typedef vector<vector<int>> vvi;
typedef vector<vector<long long>> vvll;
#define f(i, a, b, j) for(int i = int(a); i < int(b); i = i + int(j))
#define M map
#define V vector
#define P pair
#define all(a) a.begin(), a.end() 
#define nl "\n"
#define pb push_back
#define mp make_pair
#define reset(a, b) memset(a, int(b), sizeof(a))
const int MOD = 1e9+7;
const int N = 1e6+7;

int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL); cout.tie(NULL);
  int t; cin>>t;
  while(t--){
    int n,fl=1; cin>>n;
    int vis[2][n] = {0}; char arr[2][n];
    for(int i=0; i<2; i++){
      for(int j=0; j<n; j++){
        cin>>arr[i][j];
      }  
    }
    pii p; if(arr[0][0] == 'B'){p = mp(0,0);} else{p = mp(1,0);}
    while(p.second != n-1){
      vis[p.first][p.second] = 1;
      if(p.first == 0){
        if(arr[1][p.second] != 'W' && vis[1][p.second] != 1){p.first = 1;}
        else if(arr[0][p.second+1] != 'W'){p.second++;}
        else {fl = 0; break;}
      }
      else{
        if(arr[0][p.second] != 'W' && vis[0][p.second] != 1){p.first = 0;}
        else if(arr[1][p.second+1] != 'W'){p.second++;}
        else {fl = 0; break;}
      }
    }
    if(fl) cout<<"YES"<<nl;
    else cout<<"NO"<<nl;  
  }
  return 0;
}