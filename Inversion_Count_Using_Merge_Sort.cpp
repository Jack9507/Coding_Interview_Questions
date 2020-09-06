#include<bits/stdc++.h>
using namespace std;
#define int long long
#define endl '\n'
const int mod=1e9+7;

int merge(int left[], int right[], int arr[], int ln, int rn, int n)
{
    int i=0, j=0, k=0;
    int invcnt=0;
    while(i <ln && j <rn)
    {
        if(left[i] <= right[j])
            arr[k++] =left[i++];
        else
        {
            arr[k++] = right[j++];

            // here left[i] > right[j]     which is a valid condition for inversion pair
            //  inversion count will be equal to the number of elements (including current element )greater than the current element
            //  on the right side of current element  in left array.
            //  so the number of elements on the right of current element in left array can be calculated as = size of left array - index of current element
//            int res=distance(upper_bound(left, left+ln, left[i]), left+ln ) + 1;
//            invcnt += res;
            // or just write O(1) statement below instead of using distance and upper bound which consumes time.
            invcnt += (ln-i);
        }
    }
    while(i < ln)
        arr[k++] =left[i++];
    while(j < rn)
        arr[k++] =right[j++];

    return invcnt;

}
int mergesort(int arr[], int n)
{
    if(n < 2)             //  if array has just one element then it is already sorted and inversion count is also zero.
        return 0;        //  base case

    int mid=n/2;
    int left[mid];          // create a left array of size 'mid'
    int right[n-mid];       // create a right array of size 'n-mid'

    for(int i=0; i<mid; i++)
        left[i] =arr[i];
    for(int i=mid; i<n; i++)
        right[i-mid]= arr[i];

    int invcnt =0;
       invcnt += mergesort(left, mid);
       invcnt += mergesort(right, n-mid);

    invcnt += merge(left, right, arr, mid, n-mid, n);

    return invcnt;
}

int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;

        int arr[n];
        for(int i=0; i<n; i++)
         cin>>arr[i];

         int inv_cnt=0;

         inv_cnt=mergesort(arr,n);
//
//        for(int x :arr)
//            cout<<x<<"  ";
//        cout<<endl;

         cout<<inv_cnt<<endl;

    }

    return 0;
}
















