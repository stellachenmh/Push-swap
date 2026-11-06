#include "tst.h"
#include "../push_swap.h"

tstsuite("Parser") {
	tstcase("parse_nonnumeric_args")
	{
		char *nonnum_args[] = {"1", "-2", "3three"};
		char *whitespace_args[] = {"1", " -2", "3"};
		char *emptystr_args[] = {"1", "44", ""};
		char *dashonly[] = {"1", "-", "3"};
		tstexpect(parse_ints(3, nonnum_args) == 0, "non-numeric args");
		tstexpect(parse_ints(3, whitespace_args) == 0, "non-numeric arg has whitespace");
		tstexpect(parse_ints(3, emptystr_args) == 0, "arg is empty string");
		tstexpect(parse_ints(3, dashonly) == 0, "arg is single dash");
	}

	tstcase("parse_valid_args inc 0, intmax, intmin")
	{
		char *validargs[] = {"progname", "6", "234234", "-4455555", "0", "2147483647", "-2147483648"};
		int *intarray = parse_ints(6, validargs);
		tstexpect(intarray != NULL, "Should create array for valid numeric inputs");

		// Check each element of array
		tstexpect(intarray[0] == 6);
		tstexpect(intarray[1] == 234234);
		tstexpect(intarray[2] == -4455555);
		tstexpect(intarray[3] == 0);
		tstexpect(intarray[4] == 2147483647);
		tstexpect(intarray[5] == -2147483648);
		// printf("%i\n", intarray[0]);
		// printf("%i\n", intarray[1]);
		// printf("%i\n", intarray[2]);
		// printf("%i\n", intarray[3]);
		// printf("%i\n", intarray[4]);
		// printf("%i\n", intarray[5]);
	}

	tstcase("parse_args_outside_int_range")
	{
		char *aboveintmax1[] = {"2147483648"};
		char *aboveintmax2[] = {"21474836480301010"};
		char *belowintmin1[] = {"-2147483649", "33"};
		char *belowintmin2[] = {"-4", "-2147483649442299"};
		tstexpect(parse_ints(1, aboveintmax1) == 0, "number above int max");
		tstexpect(parse_ints(1, aboveintmax2) == 0, "number above int max");
		tstexpect(parse_ints(2, belowintmin1) == NULL, "number below int min");
		tstexpect(parse_ints(2, belowintmin2) == NULL, "number below int min");
		// 	printf("%p", parse_ints(2, belowintmin));
	}

	// Not handled by parser.c, but main
	tst_case("parse_duplicates")
	{
	}

	tst_case("parse_empty")
	{
	}
}
