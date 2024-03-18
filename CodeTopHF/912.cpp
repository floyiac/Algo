class Solution {
public:
    vector<int> sortArray(vector<int>& nums){
        int n = nums.size();
        for(int i = n/2 - 1; i >= 0; i--){
            heapify(nums,n,i);
        }
        for(int i=n-1;i>0;i--){
            swap(nums[0],nums[i]);
            heapify(nums,i,0);
        }
        return nums;
    }

    void heapify(vector<int>&nums, int n, int i){
        int largest = i;
        int left = 2*i + 1;
        int right =  2*i + 2;
        if(left < n && nums[left] > nums[largest]){
            largest = left;
        }
        if(right < n && nums[right] > nums[largest]){
            largest = right;
        }
        if(largest != i){
            swap(nums[i],nums[largest]);
            heapify(nums,n,largest);
        }
    }


    void merge(vector<int>&nums, int left, int mid, int right){
        int n1 = mid-left+1;
        int n2= right-mid;

        vector<int> L(n1), R(n2);

        for(int i=0;i<n1;i++){
            L[i] = nums[left+i];
        }
        for(int j=0;j<n2;j++){
            R[j] = nums[mid+1+j];
        }

        int i=0,j=0,k=left;
        while(i<n1 && j<n2){
            if(L[i] <= R[j]){
                nums[k] = L[i];
                i++;
            }
            else{
                nums[k] = R[j];
                j++;
            }
            k++;
        }

        while(i<n1){
            nums[k] =L[i];
            k++;
            i++;
        }

        while(j<n2){
            nums[k] = R[j];
            j++;
            k++;
        }

    }

    void mergeSort(vector<int>&nums, int left, int right){
        if(left >= right){
            return ;
        }
        int mid = left + (right-left)/2;
        mergeSort(nums,left,mid);
        mergeSort(nums,mid+1,right);
        merge(nums,left,mid,right);
    }
    vector<int> sortArray(vector<int>& nums) {
        // merge sort implementation
        mergeSort(nums,0,nums.size()-1);
        return nums;
    }
};