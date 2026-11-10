
#include "../push_swap.h"
#include "tst.h"

tstsuite("Test parse flags")
{
	tstcase("Invalid - no flags, ints only")
	{

	}
	tstcase("Invalid - no flags because typo in flag")
	{

	}
	tstcase("Valid - one flag plus int inputs")
	{
		// Create metadata struct and check initial values
		t_metadata meta;
		meta.bench = 0;
		meta.strategy = 0;
		(void)meta;
	}
	tstcase("Valid - both flags, correct order, plus int inputs")
	{

	}
	tstcase("Invalid - strategy flag before bench")
	{

	}
	tstcase("Invalid - more than one of same flag")
	{
		// 2-0
		// 2-1
	}
	tstcase("Invalid - one or two non-duplicate flags but no ints")
	{

	}
}