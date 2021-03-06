class Solution {
public:
    TreeNode* sortedArrayToBST(vector<int>& nums) {
        return buildBST(nums,0,nums.size()-1);
    }
private:
    TreeNode* buildBST(vector<int>& nums,int left,int right) {
        if(left>right) return NULL;

        int mid = left+(right-left)/2;
        TreeNode* current = new TreeNode(nums[mid]);
        current -> left = buildBST(nums,left,mid-1);
        current -> right = buildBST(nums,mid+1,right);
        return current;
    }
};
