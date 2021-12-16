class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string, vector<string>> anagrams; 
        vector<vector<string>> res; 
        
        for(auto i = 0; i<strs.size(); i++){
                string p = strs[i]; 
                sort(p.begin(), p.end()); 
                anagrams[p].push_back(strs[i]);
        }
        
        for(auto it= anagrams.begin(); it!=anagrams.end(); it++){
            res.push_back(it->second);
        }

        return res;
    }
};