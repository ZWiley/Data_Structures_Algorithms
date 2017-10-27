// Given a string s and a dictionary of words dict, determine if s can be segmented into a space-separated sequence of one or more dictionary words.

// For example, given
// s ="leetcode",
// dict =["leet", "code"].

// Return true because"leetcode"can be segmented as"leet code". 
//用动态规划，dp[i]表示字符串s[0~i]是否可分的bool值。 
class Solution {
public:
    bool wordBreak(string s, unordered_set<string> &dict) {
		int len = s.length();
		vector<bool> dp(len+1,false);
		dp[0]=true;	
		for(int pos=0;pos<len;++pos)
    		for(int i=pos;dp[pos] && i<len;++i)
        		if (dict.find(s.substr(pos,i-pos+1))!=dict.end())
            		dp[i+1]=true;
		return dp[len];
    }
};