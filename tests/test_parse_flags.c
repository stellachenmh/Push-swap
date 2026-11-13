
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

	char	*med_disorder_args[] = {"prog", "--bench", "--adaptive", "1",
			"4", "2", "3", "6", "5"};
	char	*high_disorder_args[] = {"prog", "--bench", "--adaptive", "6",
			"5", "4", "3", "2", "1"};

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
	tstcase("Valid - simple flag plus bench flag and int inputs")
	{
		char	*simple_bench_valid_args[] = {"prog", "--bench", "--simple", "1"};

		bzero(&meta, sizeof(meta));
		result = parse_args(4, simple_bench_valid_args, &meta);
		tstexpect(meta.bench == 1);
		tstexpect(meta.strategy == SIMPLE);
	}
	tstcase("Valid - medium flag plus bench flag and int inputs")
	{
		char	*medium_bench_valid_args[] = {"prog", "--bench", "--medium", "1"};

		bzero(&meta, sizeof(meta));
		result = parse_args(4, medium_bench_valid_args, &meta);
		tstexpect(meta.bench == 1);
		tstexpect(meta.strategy == MEDIUM);
	}
	tstcase("Valid - complex flag plus bench flag and int inputs")
	{
		char	*complex_bench_valid_args[] = {"prog", "--bench", "--complex", "1"};

		bzero(&meta, sizeof(meta));
		result = parse_args(4, complex_bench_valid_args, &meta);
		tstexpect(meta.bench == 1);
		tstexpect(meta.strategy == COMPLEX);
	}
	tstcase("Valid - adaptive flag plus bench flag and low disorder int inputs")
	{
		char	*adaptive_bench_valid_args[] = {"prog", "--bench", "--adaptive", "1"};

		bzero(&meta, sizeof(meta));
		result = parse_args(4, adaptive_bench_valid_args, &meta);
		tstexpect(meta.bench == 1);
		tstexpect(meta.strategy == ADAPTIVE);
	}
	tstcase("Valid - adaptive flag plus bench flag and medium disorder inputs")
	{
		bzero(&meta, sizeof(meta));
		result = parse_args(9, med_disorder_args, &meta);
		tstexpect(result != NULL);
		tstexpect(meta.bench == 1 && meta.strategy == ADAPTIVE);
		tstexpect(meta.count == 6);
		tstexpect(result[0] == 1 && result[1] == 4 && result[2] == 2
			&& result[3] == 3 && result[4] == 6 && result[5] == 5);
		free(result);
	}
	tstcase("Valid - adaptive flag plus bench flag and high disorder inputs")
	{
		bzero(&meta, sizeof(meta));
		result = parse_args(9, high_disorder_args, &meta);
		tstexpect(result != NULL);
		tstexpect(meta.bench == 1 && meta.strategy == ADAPTIVE);
		tstexpect(meta.count == 6);
		tstexpect(result[0] == 6 && result[1] == 5 && result[2] == 4
			&& result[3] == 3 && result[4] == 2 && result[5] == 1);
		free(result);
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
