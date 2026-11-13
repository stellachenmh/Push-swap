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
	t_metadata	meta;
	char		*aboveintmax1[] = {"prog", "2147483648"};
	char		*aboveintmax2[] = {"prog", "21474836480301010"};
	char		*belowintmin1[] = {"prog", "-2147483649", "33"};
	char		*belowintmin2[] = {"prog", "-4", "-2147483649442299"};
	char		*longoverflow1[] = {"prog", "18446744073709551616"};
	char		*longoverflow2[] = {"prog", "18446744073709551620", "0"};
	char		*longoverflow3[] = {"prog", "-18446744073709551620"};
	char		*paddedvalid[] = {"prog", "0000000000000000000005",
				"-0000000000000000000002147483648", "0000000000000000000"};
	char		*paddedover[] = {"prog", "000000000000000000002147483648"};

	tstcase("parse_nonnumeric_args")
	{
		tstexpect(parse_args(4, nonnum_args, &meta) == 0, "non-numeric args");
		tstexpect(parse_args(4, whitespace_args, &meta) == 0,
			"non-numeric arg has whitespace");
		tstexpect(parse_args(4, emptystr_args, &meta) == 0,
			"arg is empty string");
		tstexpect(parse_args(4, dashonly, &meta) == 0, "arg is single dash");
	}
	tstcase("parse_valid_args inc 0, intmax, intmin")
	{
		intarray = parse_args(7, validargs, &meta);
		tstexpect(intarray != NULL,
			"Should create array for valid numeric inputs");
		// Check each element of array
		tstexpect(intarray[0] == 6);
		tstexpect(intarray[1] == 234234);
		tstexpect(intarray[2] == -4455555);
		tstexpect(intarray[3] == 0);
		tstexpect(intarray[4] == 2147483647);
		tstexpect(intarray[5] == -2147483648);
	}
	tstcase("parse_args_outside_int_range")
	{
		tstexpect(parse_args(2, aboveintmax1, &meta) == 0,
			"number above int max");
		tstexpect(parse_args(2, aboveintmax2, &meta) == 0,
			"number above int max");
		tstexpect(parse_args(3, belowintmin1, &meta) == NULL,
			"number below int min");
		tstexpect(parse_args(3, belowintmin2, &meta) == NULL,
			"number below int min");
		// 	printf("%p", parse_args(2, belowintmin, &meta));
	}
	tstcase("parse_args_long_overflow")
	{
		tstexpect(parse_args(2, longoverflow1, &meta) == NULL,
			"number overflows long");
		tstexpect(parse_args(3, longoverflow2, &meta) == NULL,
			"first number overflows long");
		tstexpect(parse_args(2, longoverflow3, &meta) == NULL,
			"negative number overflows long");
	}
	tstcase("parse_args_leading_zeros")
	{
		intarray = parse_args(4, paddedvalid, &meta);
		tstexpect(intarray != NULL,
			"zero-padded args within int range are accepted");
		tstexpect(intarray[0] == 5);
		tstexpect(intarray[1] == -2147483648);
		tstexpect(intarray[2] == 0);
		tstexpect(parse_args(2, paddedover, &meta) == NULL,
			"zero-padded number above int max is rejected");
	}
	// Not handled by parser.c, but main
	tst_case("parse_duplicates")
	{
	}
	tst_case("parse_empty")
	{
	}
}
