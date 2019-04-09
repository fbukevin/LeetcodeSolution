#include<stdio.h>
#include<stdlib.h>

int dominantIndex(int* nums, int numsSize) {
	if(numsSize < 1 || numsSize > 50)
		return -1;

	int current_max=0, prev_max=0;
	int max_index=0;
	int i = 0;
	for(i = 0; i < numsSize; i++){
		if(nums[i] > current_max){
			prev_max = current_max;
			current_max = nums[i];
			max_index = i;
		} else if(nums[i] > prev_max){
			// check if last number is prev_max but not current_max
			prev_max = nums[i];	
		}
	}
	
	if(current_max >= prev_max * 2)
		return max_index;
	else
		return -1;
}

int main()
{
	int nums[4] = {3, 6, 1, 0};
	int index = dominantIndex(nums, 4);
	printf("%d\n", index);	// expected 1

	int nums2[4] = {1, 2, 3, 4};
	index = dominantIndex(nums2, 4);
	printf("%d\n", index);  // expected -1

	int nums3[4] = {0,0,3,2};
	index = dominantIndex(nums3, 4);
	printf("%d\n", index);  // expected -1	


}