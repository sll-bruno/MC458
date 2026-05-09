#include <iostream>
#include <vector>
#include <algorithm> 
#define INF 2000000000

using namespace std;


int main(){
    int V,n, aux;
    cin >> V >> n;
    
    vector<int> v(n + 1);
    v[0] = 0;
    //Lê o vetor de valores das notas
    for (int j = 1; j <= n; j++){
        cin >> aux;
        v[j] = aux;
    }

    bool found = false;
    //Loop da DP
    while(!found){
        vector<vector<int>> dp(n + 1, vector<int>(V + 1));

        for (int i = 0; i <= n; i++){
            for (int j = 0; j <= V; j++){
                if (i == 0){
                    dp[i][j] = INF;
                    continue;
                }
                else if (j == 0){
                    dp[i][j] = 0;
                    continue;
                }
                
                dp[i][j] = dp[i-1][j];

                if (v[i] <= j && dp[i][j - v[i]] + 1 < dp[i-1][j]){ 
                    dp[i][j] = dp[i][j - v[i]] + 1; 
                }
            }
        }

        if (dp[n][V] != INF){
            cout << V << " " << dp[n][V] << endl;
            found = true;
        }
        else{
            V = V + 1;
        }
    }
}