#include "../push_swap.h"
#include "test.h"
#include "tst.h"

tstsuite("stack init")
{
	int		arr[] = {1, 4, 7};
	t_stack	*result;
	size_t	capacity;
	t_stack	**result_ptr;

	tstcase("invalid init")
	{
		tstexpect(stack_init(arr, 0, 0) == NULL, "capacity cannot be zero");
		tstexpect(stack_init(NULL, 0, 42) == NULL, "arr cannot be negative");
		tstexpect(stack_init(arr, 5, 3) == NULL, "size cannot exceed capacity");
	}
	tstcase("valid init")
	{
		capacity = sizeof(arr) / sizeof(arr[0]);
		result = stack_init(arr, capacity, capacity);
		tstexpect(result != NULL, "init success with %zu items", capacity);
		tstexpect(check_stack(result, arr[0], arr[1], arr[2]) == 0,
			"swap correct");
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
		result = stack_init(arr, capacity, capacity);
		tstexpect(result != NULL, "result should not be NULL");
		result_ptr = &result;
		stack_destroy(result_ptr);
		tstexpect(result == NULL, "result should be NULL");
		stack_destroy(result_ptr);
	}
}
