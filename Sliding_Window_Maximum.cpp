
//Time Complexity  :  O(n^2)

class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) 
    {
        if(k > nums.size())
        {
            vector<int> empty;
            return empty;
        }
       int n=nums.size();
        vector<int> max;
        for(int i=0; i<=n-k; i++)
        {
            vector<int> res;
            for(int j=i; j<i+k; j++)
            {
                res.push_back(nums[j]);
            }
            max.push_back(*max_element(res.begin(), res.end()));
        }
        return max;
    }
};

// Can improve time complexity by using deque data structure .

Time Complexity : O(N)
Space Complexity  : O(K), because deque always stores atmost k elements

class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) 
    {
        
       int n=nums.size(); 
       deque<int> dq;       // deque data structure allows constant access to both front and back element .
 
        for(int i=0; i<k; i++)
        {
            while(!dq.empty() && nums[i] > nums[dq.back()])   // if current element is greater than the prev element, pop and then push.                                                           stored then pop_back and then push
            {
                dq.pop_back();       // this while loop makes sure that the index of max element in the window is  always in front of deque.
            }
            dq.push_back(i);
        }
        
        vector<int> res;
        for(int i=k; i<n; i++)
        {
            res.push_back(nums[dq.front()]);
            
            while(!dq.empty() && dq.front() <= i-k)      // this loop makes  sure that index stored in front of deque is always from the current window.
            {
                dq.pop_front();
            }
            while(!dq.empty() && nums[i] > nums[dq.back()])              // loop copied from above
            {
                dq.pop_back();
            }
            dq.push_back(i);
            
        }
        res.push_back(nums[dq.front()]);
        return res;
        
    }
};
