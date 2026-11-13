

#include "../push_swap.h"
#include "tst.h"


tstsuite("Test decide sort")
{
	int			low_disorder[] = {1, 2, 3, 4, 5, 6};
	int			med_disorder[] = {1, 4, 2, 3, 6, 5};
	int			high_disorder[] = {6, 5, 4, 3, 2, 1};
	t_stack		*a;
	t_metadata	metadata;
	
	tstcase("Explicit adaptive with low disorder")
	{
		metadata = (t_metadata){0};
		metadata.strategy = ADAPTIVE;
		a = stack_init(low_disorder, 6, 6);
		decide_sort(a, &metadata);
		tstexpect(metadata.disorder == 0.0f);
		tstexpect(metadata.strategy_used == SIMPLE);
		stack_destroy(&a);
	}
	tstcase("Explicit adaptive with medium disorder")
	{
		metadata = (t_metadata){0};
		metadata.strategy = ADAPTIVE;
		a = stack_init(med_disorder, 6, 6);
		decide_sort(a, &metadata);
		tstexpect(metadata.disorder >= 0.2f && metadata.disorder < 0.5f);
		tstexpect(metadata.strategy_used == MEDIUM);
		stack_destroy(&a);
	}

	tstcase("Explicit adaptive with high disorder")
	{
		metadata = (t_metadata){0};
		metadata.strategy = ADAPTIVE;
		a = stack_init(high_disorder, 6, 6);
		decide_sort(a, &metadata);
		tstexpect(metadata.disorder == 1.0f);
		tstexpect(metadata.strategy_used == COMPLEX);
		stack_destroy(&a);
	}
	tstcase("No strategy choice, low disorder")
	{
		metadata = (t_metadata){0};
		a = stack_init(low_disorder, 6, 6);
		decide_sort(a, &metadata);
		tstexpect(metadata.strategy == ADAPTIVE);
		tstexpect(metadata.strategy_used == SIMPLE);
		stack_destroy(&a);

	}
	tstcase("No strategy choice, medium disorder")
		
	{
		metadata = (t_metadata){0};
		a = stack_init(med_disorder, 6, 6);
		decide_sort(a, &metadata);
		tstexpect(metadata.strategy == ADAPTIVE);
		tstexpect(metadata.strategy_used == MEDIUM);
		stack_destroy(&a);
	}
	tstcase("No strategy choice, high disorder")
	{
		metadata = (t_metadata){0};
		a = stack_init(high_disorder, 6, 6);
		decide_sort(a, &metadata);
		tstexpect(metadata.strategy == ADAPTIVE);
		tstexpect(metadata.strategy_used == COMPLEX);
		stack_destroy(&a);
	}
	tstcase("Explicit simple")
	{
		metadata = (t_metadata){0};
		metadata.strategy = SIMPLE;
		a = stack_init(low_disorder, 6, 6);
		decide_sort(a, &metadata);
		tstexpect(metadata.strategy == SIMPLE);
		tstexpect(metadata.strategy_used == SIMPLE);
		stack_destroy(&a);
	}
	tstcase("Explicit medium")
	{
		metadata = (t_metadata){0};
		metadata.strategy = MEDIUM;
		a = stack_init(med_disorder, 6, 6);
		decide_sort(a, &metadata);
		tstexpect(metadata.strategy == MEDIUM);
		tstexpect(metadata.strategy_used == MEDIUM);
		stack_destroy(&a);
	}
	tstcase("Explicit complex")
	{
		metadata = (t_metadata){0};
		metadata.strategy = COMPLEX;
		a = stack_init(high_disorder, 6, 6);
		decide_sort(a, &metadata);
		tstexpect(metadata.strategy == COMPLEX);
		tstexpect(metadata.strategy_used == COMPLEX);
		stack_destroy(&a);
	}
}