#include "../push_swap.h"
#include "tst.h"

tstsuite("stack init")
{
	int		arr[] = {1, 4, 7};
	t_stack	*result;
	int		capacity;
	t_stack	**result_ptr;

	tstcase("invalid init")
	{
		tstexpect(stack_init(arr, 0) == NULL, "capacity cannot be zero");
		tstexpect(stack_init(arr, -7) == NULL, "capacity cannot be negative");
		tstexpect(stack_init(NULL, 42) == NULL, "arr cannot be negative");
	}
	tstcase("valid init")
	{
		capacity = sizeof(arr) / sizeof(arr[0]);
		result = stack_init(arr, capacity);
		tstexpect(result != NULL, "init success with %d items", capacity);
		for (int i = 0; i < capacity; i++)
		{
			tstexpect(result->data[i] == arr[i], "no match on index %d", i);
		}
		stack_destroy(&result);
	}
	tstcase("stack free null has no issues")
	{
		stack_destroy(NULL);
		result = NULL;
		result_ptr = &result;
		stack_destroy(result_ptr);
		tstexpect(result == NULL, "result should be NULL");
	}
	tstcase("double destroy is ok")
	{
		capacity = sizeof(arr) / sizeof(arr[0]);
		result = stack_init(arr, capacity);
		tstexpect(result != NULL, "result should not be NULL");
		result_ptr = &result;
		stack_destroy(result_ptr);
		tstexpect(result == NULL, "result should be NULL");
		stack_destroy(result_ptr);
	}
}
