
#include "../push_swap.h"
#include "tst.h"

tstsuite("Test parse flags")
{
	int			count;
	t_metadata	meta;
	int			*result;
	char		*bench_valid_args[] = {"prog", "--bench", "1"};
	char		*simple_valid_args[] = {"prog", "--simple", "1"};
	char		*medium_valid_args[] = {"prog", "--medium", "1"};
	char		*complex_valid_args[] = {"prog", "--complex", "1"};
	char		*adaptive_valid_simp_args[] = {"prog", "--adaptive",
				"1 2 4 3 5 6 7"};
	char		*adaptive_valid_med_args[] = {"prog", "--adaptive",
				"1 4 3 2 5 6 7"};
	char		*adaptive_valid_complx_args[] = {"prog", "--adaptive",
				"7 6 5 4 3 2 1"};
	char		*bench_only_args[] = {"prog", "--bench"};

	// tstcase("Invalid - no flags because typo in flag")
	// {
	// }
	tstcase("Valid - bench flag plus int inputs")
	{
		bzero(&meta, sizeof(meta));
		result = parse_args(3, bench_valid_args, &meta, &count);
		tstexpect(meta.bench == 1);
	}
	tstcase("Valid - simple flag plus int inputs")
	{
		bzero(&meta, sizeof(meta));
		result = parse_args(3, simple_valid_args, &meta, &count);
		tstexpect(meta.strategy == SIMPLE);
		tstexpect(meta.strategy_used == SIMPLE);
	}
	tstcase("Valid - medium flag plus int inputs")
	{
		bzero(&meta, sizeof(meta));
		result = parse_args(3, medium_valid_args, &meta, &count);
		tstexpect(meta.strategy == MEDIUM);
		tstexpect(meta.strategy_used == MEDIUM);
	}
	tstcase("Valid - complex flag plus int inputs")
	{
		bzero(&meta, sizeof(meta));
		result = parse_args(3, complex_valid_args, &meta, &count);
		tstexpect(meta.strategy == COMPLEX);
		tstexpect(meta.strategy_used == COMPLEX);
	}
	tstcase("Valid - adaptive flag plus int inputs w simple disorder")
	{
		bzero(&meta, sizeof(meta));
		result = parse_args(3, adaptive_valid_simp_args, &meta, &count);
		tstexpect(meta.strategy == ADAPTIVE);
		tstexpect(meta.strategy_used == SIMPLE);
	}
	tstcase("Valid - adaptive flag plus int inputs w medium disorder")
	{
		bzero(&meta, sizeof(meta));
		result = parse_args(3, adaptive_valid_med_args, &meta, &count);
		tstexpect(meta.strategy == ADAPTIVE);
		tstexpect(meta.strategy_used == MEDIUM);
	}
	tstcase("Valid - adaptive flag plus int inputs w complex disorder")
	{
		bzero(&meta, sizeof(meta));
		result = parse_args(3, adaptive_valid_complx_args, &meta, &count);
		tstexpect(meta.strategy == ADAPTIVE);
		tstexpect(meta.strategy_used == COMPLEX);
	}
	// tstcase("Valid - both flags, correct order, plus int inputs")
	// tstcase("- strategy flag before bench")
	// {
	// }
	// tstcase("Invalid - more than one of same flag")
	// {
	// 	// 2-0
	// 	// 2-1
	// }
	tstcase("Invalid - one or two non-duplicate flags but no ints")
	{
		bzero(&meta, sizeof(meta));
		result = parse_args(2, bench_only_args, &meta, &count);
		tstexpect(meta.bench == 0);
		tstexpect(result == NULL);
	}
}
