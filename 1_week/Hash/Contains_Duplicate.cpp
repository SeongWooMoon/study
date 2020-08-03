class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        int a;
        
        a = unordered_set<int>(nums.begin(),nums.end()).size();
        
        if( a == nums.size())
            return false;
        
        else
        return true;
    }
};
