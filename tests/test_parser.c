#include "tst.h"
#include "../push_swap.h"

tstsuite("Parser") {
	t_metadata meta = {0};
	tstcase("parse_nonnumeric_args")
	{
		char *nonnum_args[] = {"prog", "1", "-2", "3three"};
		char *whitespace_args[] = {"prog", "1", " -2", "3"};
		char *emptystr_args[] = {"prog", "1", "44", ""};
		char *dashonly[] = {"prog", "1", "-", "3"};
		tstexpect(parse_args(4, nonnum_args, &meta) == 0, "non-numeric args");
		tstexpect(parse_args(4, whitespace_args, &meta) == 0, "non-numeric arg has whitespace");
		tstexpect(parse_args(4, emptystr_args, &meta) == 0, "arg is empty string");
		tstexpect(parse_args(4, dashonly, &meta) == 0, "arg is single dash");
	}

	tstcase("parse_valid_args inc 0, intmax, intmin")
	{
		char *validargs[] = {"progname", "6", "234234", "-4455555", "0", "2147483647", "-2147483648"};
		int *intarray = parse_args(7, validargs, &meta);
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
		char *aboveintmax1[] = {"prog", "2147483648"};
		char *aboveintmax2[] = {"prog", "21474836480301010"};
		char *belowintmin1[] = {"prog", "-2147483649", "33"};
		char *belowintmin2[] = {"prog", "-4", "-2147483649442299"};
		tstexpect(parse_args(2, aboveintmax1, &meta) == 0, "number above int max");
		tstexpect(parse_args(2, aboveintmax2, &meta) == 0, "number above int max");
		tstexpect(parse_args(3, belowintmin1, &meta) == NULL, "number below int min");
		tstexpect(parse_args(3, belowintmin2, &meta) == NULL, "number below int min");
		// 	printf("%p", parse_args(2, belowintmin, &meta));
	}

	// Not handled by parser.c, but main
	tst_case("parse_duplicates")
	{
	}

	tst_case("parse_empty")
	{
	}
}
