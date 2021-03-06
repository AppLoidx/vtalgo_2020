class Solution {
public:
    vector<int> sortArrayByParity(vector<int>& A) {
        int leftIndex = 0;
        int rightIndex = A.size() - 1;
        while (leftIndex < rightIndex) {
            if (A[leftIndex] % 2 != 0) {
                swap(A[leftIndex], A[rightIndex]);
                --rightIndex;
            } else {
                ++leftIndex;
            }
        }
        return A;
    }
};
