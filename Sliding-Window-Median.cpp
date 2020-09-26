class Solution {
public:
    vector<double> medianSlidingWindow(vector<int>& nums, int k)
    {
        queue<int> q;    // stores at-most k elements
        vector<int> list;
        vector<double> median;

        for(int i=0; i<nums.size(); i++)
        {
            if(q.size() >=k)      //  makes sure that elements in list and queue are from current window
            {
                list.erase(find(list.begin(), list.end(), q.front()));   // erases the leftmost element in the list
                q.pop();                                                // also delete it from queue
            }
            q.push(nums[i]);

          //  insert elements in sorted order
           list.insert(lower_bound(list.begin(), list.end(), nums[i]), nums[i]);    //  v.insert(position, value);

           if(list.size() == k)
           {
               // find median now
               if(k%2 == 0)
               {
                   // if k is even
                   median.push_back(list[k/2]/2.0 + list[k/2 -1]/ 2.0);
               }
               else
               {
                   // if k is odd
                   median.push_back(list[k/2]);
               }
           }


        }
            return median;
    }
};
