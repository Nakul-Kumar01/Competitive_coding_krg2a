class Solution {
public:

    int find(int i,int j,string &s1, string &s2,string curr,string &lc,vector<vector<int>>&dp){

        if(i<=0 || j<= 0){
            if(curr.size() > lc.size()) lc = curr;
            return 0;
        }

        if(dp[i][j] != -1) return dp[i][j];

        if(s1[i-1] == s2[j-1]) return dp[i][j]= 1 + find(i-1,j-1,s1,s2,curr + s1[i-1],lc,dp);

        return dp[i][j]= max(find(i-1,j,s1,s2,curr,lc,dp),find(i,j-1,s1,s2,curr,lc,dp));
    }

    string shortestCommonSupersequence(string s1, string s2) {
        
        string lc = "",curr = "";
        vector<vector<int>>dp(s1.size()+1,vector<int>(s2.size()+1,-1));
        int res = find(s1.size(),s2.size(),s1,s2,curr,lc,dp);

int n=s1.size(),m = s2.size();
        // Step 2: Build SCS
    int i=n, j=m;
    string ans = "";

    while(i>0 && j>0){
        if(s1[i-1] == s2[j-1]){
            ans += s1[i-1];
            i--; j--;
        }
        else if(dp[i-1][j] > dp[i][j-1]){
            ans += s1[i-1];
            i--;
        }
        else{
            ans += s2[j-1];
            j--;
        }
    }

    while(i>0){
        ans += s1[i-1];
        i--;
    }

    while(j>0){
        ans += s2[j-1];
        j--;
    }

    reverse(ans.begin(), ans.end());
    return ans;
    }
};