class Solution {
public:
    bool buddyStrings(string A, string B) {
        // first stupid check :)
        if ( A.size() != B.size() ) {
            return false;
        }

        int freq[26] = {0}; // chars frequency
        pair <int , int> wrongIndexes (-1, -1);
        pair <string , string> strings (A, B);


        bool noop_swap = false;
        for (size_t i = 0; i < A.size(); ++i) {
            if ( notEqualAt(i, strings) ) {
                if (isSet(wrongIndexes.first) && isSet(wrongIndexes.second)) {
                    return false;
                }
                
                addWrongIndex(wrongIndexes, i);
                
            }
                
            noop_swap = ++freq[charIndex(A[i])] > 1;
        }

        return (!isSet(wrongIndexes.first) && noop_swap) || isCanSwapForSolve(strings, wrongIndexes);
    }

    int charIndex(char c) {
        return c - 'a';
    }

    bool notEqualAt(int index, pair<string, string> strings) {
        return strings.first[index] != strings.second[index];
    }

    void addWrongIndex(pair <int , int>& wrongIndexes, int index) {
        if ( !isSet(wrongIndexes.first)) {
            wrongIndexes.first = index;
        } else {
            wrongIndexes.second = index;
        }
    }

    bool isSet(int value) {
        return value != -1;
    }

    bool isCanSwapForSolve(pair<string, string> strings, pair<int, int> indexes) {
        return (isSet(indexes.second) && (isSwapEqual(strings, indexes)));
    }

    bool isSwapEqual(pair<string, string> strings, pair<int , int> indexes) {
        string A = strings.first;
        string B = strings.second;
        return A[indexes.first] == B[indexes.second] && A[indexes.second] == B[indexes.first];
    }
};
