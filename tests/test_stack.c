#include "../push_swap.h"
#include "tst.h"

tstsuite("stack init")
{
	int		arr[] = {1, 4, 7};
	t_stack	*result;
	int		capacity;

	tstcase("invalid init")
	{
		tstexpect(stack_init(arr, 0) == NULL, "capacity cannot be zero");
		tstexpect(stack_init(arr, -7) == NULL, "capacity cannot be negative");
	}
	tstcase("valid init")
	{
		capacity = sizeof(arr) / sizeof(arr[0]);
		result = stack_init(arr, capacity);
		tstexpect(result != NULL, "init success with %d items", capacity);
		for (int i = 0; i < capacity; i++)
		{
			tstexpect(result->data[i] == arr[i]);
		}
	}
}
