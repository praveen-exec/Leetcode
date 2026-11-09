class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        int n = heights.size(),max_area=INT_MIN;
        vector<int> left(n);
        vector<int> right(n);
        stack<int> s;

        //For left smallest
        for(int i=0; i<n; i++){

            if(s.empty()){
             left[i] = 0;
             s.push(i); //push the current element index
            }
            else{
                while(!s.empty() && heights[s.top()] >= heights[i])
                  s.pop();
                
                left[i] = s.empty() ? 0 : s.top() + 1;
                s.push(i);
            }
        }
        //empty the stack for right smallest
        while(!s.empty())
              s.pop();

        for(int i=n-1; i>=0 ;i--){
          if(s.empty()){ 
            right[i] = n-1;
            s.push(i);
          }
          else{
            while(!s.empty() && heights[s.top()] >= heights[i])
              s.pop();
            
            right[i] = s.empty() ? n-1 : s.top()-1;
            s.push(i);
          }
        }

        for(int i=0; i < n; i++){
        max_area=max(max_area,(right[i] - left[i] + 1)*heights[i]);
        }

        return max_area;
        
    }
};