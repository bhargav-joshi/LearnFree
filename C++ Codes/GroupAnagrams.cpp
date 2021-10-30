/*

Input: strs = ["eat","tea","tan","ate","nat","bat"]
Output: [["bat"],["nat","tan"],["ate","eat","tea"]]

*/
class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        
        vector<vector<string>> ans;
        
        unordered_map<string, vector<string> > mp;
        
        for(int i = 0; i < strs.size(); ++i) {
            
            string temp = strs[i];
            sort(temp.begin(), temp.end());
            
            mp[temp].push_back(strs[i]);
        }
        if(mp.size()) {
        for(auto it = mp.begin(); it != mp.end(); ++it) {
            
            ans.push_back(it->second);            
        }
        }
        mp.clear();
        return ans;
    }
};
