#include <stdio.h>
#include <stdlib.h>

#define TARGET (9U)
#define ZERO (0U)
#define TWO_ARRAY_POSITIONS_ANSWER (2U)

int* twoSum(int* nums, int numsSize, int target, int* returnSize);

int main() {
    // variable names match as requested in example
    int nums[] = {2, 7, 11, 15};
    int* returnSize = 0U;
	  int returnedSummation = 0U;
    
    int* result = twoSum(nums, sizeof(nums), TARGET, returnSize);

    int calculatedTarget = nums[*result] + nums[*result+1];

    if(calculatedTarget == TARGET)
    {
        printf("Result is correct with array values %d & %d which give the target of %d\n", (*result), (*(result + 1)), TARGET);
    }
    else
    {
        printf("Result was incorrect, calculated target: %d\n", calculatedTarget);
    }    

    return 0;
}

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */

int* twoSum(int* nums, int numsSize, int target, int* returnSize) 
{
  int *storeComparedValues = (int*)malloc(numsSize * sizeof(int));
  
	for(int index = ZERO; index < numsSize; index++)
	{
    storeComparedValues[index] = (target - nums[index]); 
    for(int innerIndex = ZERO; innerIndex < index; innerIndex++)
    {
      if((storeComparedValues[innerIndex] - nums[index]) == ZERO)
      {
        int *result = (int*)malloc(2 * sizeof(int));
        result[ZERO] = innerIndex;
        result[ZERO + 1] = index;
        *returnSize = 2; // not strictly needed but needed to work with Leet code example
        return result;
      }
    }
  }  
}