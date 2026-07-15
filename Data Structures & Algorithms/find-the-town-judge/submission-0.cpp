class Solution {
public:
    int findJudge(int n, vector<vector<int>>& trust) {
        vector<int> trust_rating(n+1,0);
        vector<int> trusts(n+1,0);

        trust_rating[0] = -1;
        trusts[0] = -1;

        for(int i=0;i<trust.size();i++){
            trusts[trust[i][0]]++;
            trust_rating[trust[i][1]]++;
        }

        for(int i=0; i<n+1;i++){
            if(trusts[i]==0 && trust_rating[i]==n-1) return i;
        }
        return -1;
    }
};