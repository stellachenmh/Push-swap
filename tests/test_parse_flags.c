
#include "../push_swap.h"
#include "tst.h"

tstsuite("Test parse flags")
{
	t_metadata	meta;
	int			*result;
	char		*bench_valid_args[] = {"prog", "--bench", "1"};
	char		*simple_valid_args[] = {"prog", "--simple", "1"};
	char		*medium_valid_args[] = {"prog", "--medium", "1"};
	char		*complex_valid_args[] = {"prog", "--complex", "1"};
	char		*adaptive_valid_args[] = {"prog", "--adaptive", "1"};
	char		*bench_only_args[] = {"prog", "--bench"};

	// tstcase("Invalid - no flags because typo in flag")
	// {
	// }
	tstcase("Valid - bench flag plus int inputs")
	{
		bzero(&meta, sizeof(meta));
		result = parse_args(3, bench_valid_args, &meta);
		tstexpect(meta.bench == 1);
	}
	tstcase("Valid - simple flag plus int inputs")
	{
		bzero(&meta, sizeof(meta));
		result = parse_args(3, simple_valid_args, &meta);
		tstexpect(meta.strategy == SIMPLE);
	}
	tstcase("Valid - medium flag plus int inputs")
	{
		bzero(&meta, sizeof(meta));
		result = parse_args(3, medium_valid_args, &meta);
		tstexpect(meta.strategy == MEDIUM);
	}
	tstcase("Valid - complex flag plus int inputs")
	{
		bzero(&meta, sizeof(meta));
		result = parse_args(3, complex_valid_args, &meta);
		tstexpect(meta.strategy == COMPLEX);
	}
	tstcase("Valid - adaptive flag plus int inputs")
	{
		bzero(&meta, sizeof(meta));
		result = parse_args(3, adaptive_valid_args, &meta);
		tstexpect(meta.strategy == ADAPTIVE);
	}
	// tstcase("Valid - both flags, correct order, plus int inputs")
	// {
	// }
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
		result = parse_args(2, bench_only_args, &meta);
		tstexpect(meta.bench == 0);
		tstexpect(result == NULL);
	}
	tstcase("Valid - parsed count excludes flags")
	{
		char	*mixed_args[] = {"prog", "--bench", "4", "67", "3", "87",
				"23"};

		bzero(&meta, sizeof(meta));
		result = parse_args(7, mixed_args, &meta);
		tstexpect(result != NULL);
		tstexpect(meta.count == 5);
		tstexpect(result[0] == 4 && result[1] == 67 && result[2] == 3
			&& result[3] == 87 && result[4] == 23);
		free(result);
	}
	tstcase("Valid - strategy flag does not shift parsed numbers")
	{
		char	*strategy_args[] = {"prog", "--simple", "5", "4", "3", "2",
				"1"};

		bzero(&meta, sizeof(meta));
		result = parse_args(7, strategy_args, &meta);
		tstexpect(result != NULL);
		tstexpect(meta.strategy == SIMPLE);
		tstexpect(meta.count == 5);
		tstexpect(result[0] == 5 && result[1] == 4 && result[2] == 3
			&& result[3] == 2 && result[4] == 1);
		free(result);
	}
	tstcase("Valid - flags may appear in either order")
	{
		char	*reversed[] = {"prog", "--simple", "--bench", "5", "4",
				"3", "2", "1"};
		char	*forward[] = {"prog", "--bench", "--simple", "5", "4",
				"3", "2", "1"};

		bzero(&meta, sizeof(meta));
		result = parse_args(8, reversed, &meta);
		tstexpect(result != NULL);
		tstexpect(meta.bench == 1 && meta.strategy == SIMPLE);
		tstexpect(meta.count == 5);
		tstexpect(result[0] == 5 && result[1] == 4 && result[2] == 3
			&& result[3] == 2 && result[4] == 1);
		free(result);
		bzero(&meta, sizeof(meta));
		result = parse_args(8, forward, &meta);
		tstexpect(result != NULL);
		tstexpect(meta.bench == 1 && meta.strategy == SIMPLE);
		tstexpect(meta.count == 5);
		free(result);
	}
}
