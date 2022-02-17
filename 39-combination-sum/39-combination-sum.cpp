class Solution {
public:
    
    vector<vector<int>> res;
    void recc(int n, int target, vector<int>& ans, vector<int>& candidates){
        
        if(target<0 or n==-1)return; 
        if(target==0){
            res.emplace_back(ans);
            return;
        }
        
        if(candidates[n]<=target){
            ans.emplace_back(candidates[n]);
            recc(n, target-candidates[n], ans, candidates);
            ans.pop_back();
        }
        
        recc(n-1, target, ans, candidates);
        
    }
    
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        int n=candidates.size();
        vector<int> ans;
        recc(n-1, target, ans, candidates);
        
        return res;
    }
};