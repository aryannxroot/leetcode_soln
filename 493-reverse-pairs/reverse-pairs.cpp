class Solution {
public:
    int cnt = 0; //Global variable to count the pairs
    void merge(vector<long long> &arr, int low, int mid, int high) {
        vector<long long> temp; // temporary array
        int left = low;      // starting index of left half of arr
        int right = mid + 1;   // starting index of right half of arr

        //storing elements in the temporary array in a sorted manner//

        while (left <= mid && right <= high) {
            if (arr[left] <= arr[right]) {
                temp.push_back(arr[left]);
                left++;
            }
            else {
                temp.push_back(arr[right]);
                right++;
            }
        }

        // if elements on the left half are still left //

        while (left <= mid) {
            temp.push_back(arr[left]);
            left++;
        }

        //  if elements on the right half are still left //
        while (right <= high) {
            temp.push_back(arr[right]);
            right++;
        }

        // transfering all elements from temporary to arr //
        for (int i = low; i <= high; i++) {
            arr[i] = temp[i - low];
        }
    }
    // function to count the pairs before merging
    void countPairs(vector<long long> &arr, int low, int mid, int high)
    {
        int right = mid + 1;
        for(int i=low;i<=mid;i++)
        {
            while(right <= high && arr[i] > (2*arr[right]))     
                right++;
            cnt += (right - (mid + 1));
        }
    }
    void mergeSort(vector<long long> &arr, int low, int high) {
        if (low >= high) return;
        int mid = (low + high) / 2 ;
        mergeSort(arr, low, mid);  // left half
        mergeSort(arr, mid + 1, high); // right half
        countPairs(arr,low,mid,high);
        merge(arr, low, mid, high);  // merging sorted halves
    }
    int reversePairs(vector<int> &num) {
        int n = num.size();
        vector<long long> nums;
        for(int i : num){
            nums.push_back((long long) i);
        }
        mergeSort(nums,0,n-1);
        return cnt;
    }
};