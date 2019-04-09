#include<stdio.h>
#include<stdlib.h>

/**
 * Return an array of size *returnSize.
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* plusOne(int* digits, int digitsSize, int* returnSize) {
	*returnSize=digitsSize+1;
  while(digitsSize!=0)
  {
      digitsSize--;
      if(++digits[digitsSize]>9)
      {digits[digitsSize]=0;}
      else
      {
          (*returnSize)--;
          return digits;
      }
  }
  int *result=(int*)malloc(sizeof(int)*(*returnSize));
  result[0]=1;
  for(int i=1;i<*returnSize;i++)
  {
      result[i]=digits[i-1];
  }
  return result;
}

void print_result(int *result, int returnSize){
	printf("%d\n", returnSize);

	for(int i = 0; i < returnSize; i++){
		printf("%d", result[i]);
	}

	puts("");
}

int main()
{
	int nums[3] = {1,2,3};
	int returnSize = 3;
	int* result = plusOne(nums, 3, &returnSize);
	print_result(result, returnSize);

	int num2[4] = {4,4,2,1};
	returnSize = 4;
	int* result2 = plusOne(num2, 4, &returnSize);
	print_result(result2, returnSize);

	return 0;
}