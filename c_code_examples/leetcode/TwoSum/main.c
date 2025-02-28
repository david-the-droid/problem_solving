/*
 * s
 * 
 * 
*/


#include <stdio.h>
#include <stdlib.h>

#define TARGET (9U)

int* twoSum(int* nums, int numsSize, int target, int* returnSize);

int main() {
    int nums[] = {2, 7, 11, 15};
    int* returnSize = 0U;
	int returnedSummation = 0U;

    int* result = twoSum(nums, sizeof(nums), TARGET, returnSize);

	for(int index = 0; index < sizeof(result); index++)
	{
		printf("Result is formed of index value: %d", (*(result + index)));
		returnedSummation += *(result + index);
	}

	if(returnedSummation == TARGET)
	{
		printf("Which gives correct target of %d\n", TARGET); 
	}
	else
	{
		printf("Gives incorrect target of %d\n", returnedSummation); 
	}

	printf("Result is index values %d & %d which give the target of %d\n", (*result), (*(result + 1)), TARGET);

    return 0;
}

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */

int* twoSum(int* nums, int numsSize, int target, int* returnSize) {

	for(int index = 0; index < numsSize; index++)
	{
		int comparisonValue = *(nums + index);
		for(int comparisonIndex = 0; comparisonIndex < numsSize; comparisonIndex++)
		{	
			if(comparisonIndex == index)
			{
				/* Prevents code looking comparing against the same value */
				break; 
			}

			const int summation = comparisonValue + *(nums + comparisonIndex); 
			
			if(summation == target)
			{
				int *result = (int*)malloc(numsSize * sizeof(int));
				result[0] = index;
				result[1] = comparisonIndex;

				return result;
			}
		}
	}
}