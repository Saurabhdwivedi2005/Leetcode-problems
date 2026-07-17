class Solution {
public:
    string frequencySort(string s) {
        
        unordered_map<char,int>mp;
        for(char ch:s){
            mp[ch]++;
        }
       priority_queue<pair<int,char>> maxheap;
        for(auto it:mp){
            char key = it.first;
            int value = it.second;
            maxheap.push({value,key});
        }
        string str="";
        while(!maxheap.empty()){
            int temp=maxheap.top().first;
            int ch=maxheap.top().second;
            maxheap.pop();
            while(temp--){
                str.push_back(ch);

            }
        }
        return str;     

            
    }
};