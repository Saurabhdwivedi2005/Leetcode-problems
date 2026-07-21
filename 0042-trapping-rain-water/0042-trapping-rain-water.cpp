class Solution {
public:
    int trap(vector<int>& height) {
        stack<int>st;
        int waterheight=0;
        for(int i=0;i<height.size();i++){
            while(!st.empty() && height[st.top()]<height[i]){

                int bottom=st.top();
                st.pop();
                if(!st.empty()){
                    int h = min(height[i], height[st.top()]) - height[bottom];
                    int width = i - st.top() - 1;

                    waterheight += h * width;

                }

            
            }
            st.push(i);
        }
        return waterheight ;

        
    }
};