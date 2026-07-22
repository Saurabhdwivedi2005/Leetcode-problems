class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& nums) {
        int n=nums.size();
        stack<int>st;
        vector<int>res(n,-1);
        for(int i=2*n;i>=0;i--){
            int index=i%n;
            while(!st.empty() && nums[index]>=nums[st.top()]){
                st.pop();

            }if(i<n){
                if(!st.empty()){
                    res[i]=nums[st.top()];
                }else{
                    res[i]=-1;
                }
                
            }
            st.push(i%n);
        }
        return res;
        
    }
};