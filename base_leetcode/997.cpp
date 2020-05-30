class Solution {
public:
    int findJudge(int N, vector<vector<int>>& trust) {
        if( N == 1 && trust.empty())
            return N;

        int size = trust.size();
        vector<int> rating(N+1, 0);

        for(int i = 0; i<size; i++)
        {
            rating[trust[i][0]]--;
            rating[trust[i][1]]++;
        }

        for(int i = 0 ; i<= N ; i++)
        {
            if( rating[i] == N-1)
                return i;
        }
        return -1;
    }
};
