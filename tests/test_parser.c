#include "../push_swap.h"
#include "tst.h"

tstsuite("Parser")
{
	char		*nonnum_args[] = {"prog", "1", "-2", "3three"};
	char		*whitespace_args[] = {"prog", "1", " -2", "3"};
	char		*emptystr_args[] = {"prog", "1", "44", ""};
	char		*dashonly[] = {"prog", "1", "-", "3"};
	char		*validargs[] = {"progname", "6", "234234", "-4455555", "0",
				"2147483647", "-2147483648"};
	int			*intarray;
	int			count;
	t_metadata	meta;
	char		*aboveintmax1[] = {"prog", "2147483648"};
	char		*aboveintmax2[] = {"prog", "21474836480301010"};
	char		*belowintmin1[] = {"prog", "-2147483649", "33"};
	char		*belowintmin2[] = {"prog", "-4", "-2147483649442299"};

	tstcase("parse_nonnumeric_args")
	{
		tstexpect(parse_args(4, nonnum_args, &meta, &count) == 0, "non-numeric args");
		tstexpect(parse_args(4, whitespace_args, &meta, &count) == 0,
			"non-numeric arg has whitespace");
		tstexpect(parse_args(4, emptystr_args, &meta, &count) == 0,
			"arg is empty string");
		tstexpect(parse_args(4, dashonly, &meta, &count) == 0, "arg is single dash");
	}
	tstcase("parse_valid_args inc 0, intmax, intmin")
	{
		intarray = parse_args(7, validargs, &meta, &count);
		tstexpect(intarray != NULL,
			"Should create array for valid numeric inputs");
		tstexpect(count == 6, "expected 6 values, got %d", count);
		// Check each element of array
		tstexpect(intarray[0] == 6);
		tstexpect(intarray[1] == 234234);
		tstexpect(intarray[2] == -4455555);
		tstexpect(intarray[3] == 0);
		tstexpect(intarray[4] == 2147483647);
		tstexpect(intarray[5] == -2147483648);
		free(intarray);
	}
	tstcase("parse_args_outside_int_range")
	{
		tstexpect(parse_args(2, aboveintmax1, &meta, &count) == 0,
			"number above int max");
		tstexpect(parse_args(2, aboveintmax2, &meta, &count) == 0,
			"number above int max");
		tstexpect(parse_args(3, belowintmin1, &meta, &count) == NULL,
			"number below int min");
		tstexpect(parse_args(3, belowintmin2, &meta, &count) == NULL,
			"number below int min");
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
