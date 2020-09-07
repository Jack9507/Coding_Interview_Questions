#include<bits/stdc++.h>
using namespace std;
#define int long long
#define endl '\n'
const int mod=1e9+7;



void  merge(vector<int> &left, vector<int> &right, vector<int> &arr, int ln, int rn, int n)
{
    int i=0, j=0, k=0;
    while(i <ln && j <rn)
     {
        if(left[i] <= right[j])
            arr[k++] =left[i++];
        else
        {
            arr[k++] = right[j++];
        }
     }
    while(i < ln)
        arr[k++] =left[i++];
    while(j < rn)
        arr[k++] =right[j++];

}
int mergesort(vector<int> &arr, int n)
{
    if(n < 2)
       return 0;

    int mid=n/2;
    vector<int> left(mid);         // create a left array of size 'mid'
    vector<int> right(n-mid);      // create a right array of size 'n-mid'

    for(int i=0; i<mid; i++)
        left[i] =arr[i];
    for(int i=mid; i<n; i++)
        right[i-mid]= arr[i];


    int invcnt =0;
       invcnt += mergesort(left, mid);                 //   sort the left sub array
       invcnt += mergesort(right, n-mid);              //   sort the right sub array

        int i=0, j=0;
        int ln=mid;      // size of left array
        int rn=n-mid;    // size of right array

        while(i<ln && j<rn)
        {
            if(left[i] > 2LL * right[j])
            {
                invcnt += ln-i;  // since arrays are sorted so numbers on the right of current element will also form an inversion pair
                j++;
            }
            else
                i++;
        }

     merge(left, right, arr, mid, n-mid, n);           // merge back the sorted arrays

    return invcnt;
}

    int reversePairs(vector<int>& nums)
    {
        if(nums.size() < 2)
            return 0;
        int n=nums.size();
        int inv_cnt =mergesort(nums, n);

        return inv_cnt;

    }
int32_t main()
{
    vector<int> nums ={2,4,3,5,1};
    cout<<"Reverse pairs / INversion count = "<<reversePairs(nums)<<endl;


    // printing the array after sorting
    for(int x: nums)
        cout<<x<<"  ";
    cout<<endl;


    return 0;
}
