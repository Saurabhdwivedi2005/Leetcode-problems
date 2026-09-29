class Solution {
public:
    int matchPlayersAndTrainers(vector<int>& players, vector<int>& trainers) {
        sort(players.begin(),players.end());
        sort(trainers.begin(),trainers.end());
        int left=0;
        int right=0;
        int n=players.size();
        int m=trainers.size();
        while(left<n && right<m){
            if(players[left]<=trainers[right]){
                left++;
            }
            right++;
        }
        return left;
        
    }
};