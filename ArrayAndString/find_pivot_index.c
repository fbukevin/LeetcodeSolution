#include<stdio.h>
#include<stdlib.h>

int pivotIndex(int* nums, int numsSize) {
    if(numsSize < 0 || numsSize > 10000) {
        return -1;
    }
    
    for(int i = 0; i < numsSize; i++) {
    		int left_sum = 0, right_sum = 0;

    		// left side
        for(int j = 0; j < i; j++){
        	left_sum += nums[j];
        }

        // right side
        for(int j = i+1; j < numsSize; j++){
        	right_sum += nums[j];
        }

        if(left_sum == right_sum)
        	return i;
    }

    return -1;
}


int main(){

	int nums[6] = {1, 7, 3, 6, 5, 6};
	int pivot = pivotIndex(nums, 6);
	printf("Pivot index is %d\n", pivot);

	int nums2[3] = {1, 2, 3};
	pivot = pivotIndex(nums2, 3);
	printf("Pivot index is %d\n", pivot);

	int nums3[6] = {-1,-1,-1,0,1,1};
	pivot = pivotIndex(nums3, 6);
	printf("Pivot index is %d\n", pivot);

	return 0;
}