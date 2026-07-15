class Solution {
public:
    int openLock(vector<string>& deadends, string target) {
        if(target == "0000") return 0;

        unordered_set<string> visit(deadends.begin(),deadends.end());

        if(visit.count("0000")) return -1;

        queue<string> q;
        q.push("0000");
        visit.insert("0000");
        int steps = 0;
        while(!q.empty()){
            steps++;
            int size = q.size();
            for(int i=0;i<size;i++){
                string curr = q.front(); q.pop();
                if(curr==target){
                    return steps-1;
                }

                for(int i =0;i<4;i++){
                    char original = curr[i];
                    curr[i]= (original == '9')? '0':original +1;

                    if(!visit.count(curr)){
                        visit.insert(curr);
                        q.push(curr);
                    }

                    curr[i] = (original=='0')? '9':original -1;

                    if(!visit.count(curr)){
                        visit.insert(curr);
                        q.push(curr);
                    }
                    curr[i] = original;
                }
                
            }
        }
        return -1;

    }
};