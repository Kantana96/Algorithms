#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;
int main(){
    string word1, word2;
    cout<<"Enter first word:";
    cin>>word1;
    cout<<"Enter second word:";
    cin>>word2;
    vector< vector<int> > dp(word2.size()+1, vector<int>(word1.size()+1,0));
    for (int i = 0; i < dp.size(); i++)
    {
        dp[i][0]=i;
    }
    for (int i = 1; i < dp[0].size(); i++)
    {
        dp[0][i]=i;
    }
    for (int row = 1; row < dp.size(); row++)
    {
        for (int col = 1; col < dp[0].size(); col++)
        {
            if(word2[row-1]==word1[col-1]){
                dp[row][col]=dp[row-1][col-1];
            }
            else{
                dp[row][col]=min(dp[row][col-1],min(dp[row-1][col],dp[row-1][col-1]))+1;
            }
        }
    }
    cout<<"The edit distance between two words is "<<dp[dp.size()-1][dp[0].size()-1];
    return 0;    
}