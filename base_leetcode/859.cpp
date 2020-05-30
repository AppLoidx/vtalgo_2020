class Solution {
public:
    bool buddyStrings(string A, string B) {
        if ( A.size() != B.size() ) {
            return false;
        }

        int freq[26] = {0};
        int first = -1;
        int second = -1;
        bool swap = false;
        for (size_t i = 0; i < A.size(); ++i) {
            if ( A[i] != B[i] ) {
                if ( first == -1 ) {
                    first = i;
                } else if ( second == -1 ) {
                    second = i;
                } else {
                    return false;
                }
            }

            ++freq[A[i] - 'a'];
            if ( freq[A[i] - 'a'] > 1 ) {
                swap = true;
            }
        }
        return (second != -1 && (A[first] == B[second] && A[second] == B[first]))
               || (first == -1 && swap);
    }
};
