class Solution {
public:
    bool isNStraightHand(vector<int>& hand, int groupSize) {
        priority_queue<int, vector<int>, greater<int>> maxheap;
        vector<int>arr;
        // bool flag= true;
        if(hand.size() % groupSize != 0) return false;
        unordered_map<int,int>mp;
        for(auto it :hand){
            mp[it]++;
        }
        for(auto it : mp){
            int key = it.first;
            maxheap.push(key);
        }
       
        while(!maxheap.empty()){
            int temp=maxheap.top();
            // int expected=temp+1;
            if (mp[temp] == 0) {
                maxheap.pop();
                continue;
            }

            for (int i = 0; i < groupSize; i++) {

                int card= temp + i;

                if (mp[card] == 0)
                    return false;

                mp[card]--;
            }
               
        }
        return true;
        
    }
};