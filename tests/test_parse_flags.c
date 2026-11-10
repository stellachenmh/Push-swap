
#include "../push_swap.h"
#include "tst.h"

tstsuite("Test parse flags")
{
	t_metadata	meta;
	int			count;
	int			*result;
	char		*bench_valid_args[] = {"prog", "--bench", "1"};
	char		*simple_valid_args[] = {"prog", "--simple", "1"};
	char		*medium_valid_args[] = {"prog", "--medium", "1"};
	char		*complex_valid_args[] = {"prog", "--complex", "1"};
	char		*adaptive_valid_args[] = {"prog", "--adaptive", "1"};
	char		*bench_only_args[] = {"prog", "--bench"};
	char		*flagged_values[] = {"prog", "--simple", "3", "1", "2"};
	char		*both_flags[] = {"prog", "--simple", "--bench", "3", "1"};

	// tstcase("Invalid - no flags because typo in flag")
	// {
	// }
	tstcase("Valid - bench flag plus int inputs")
	{
		bzero(&meta, sizeof(meta));
		result = parse_args(3, bench_valid_args, &meta, &count);
		tstexpect(meta.bench == 1);
		tstexpect(count == 1 && result[0] == 1);
		free(result);
	}
	tstcase("Valid - simple flag plus int inputs")
	{
		bzero(&meta, sizeof(meta));
		result = parse_args(3, simple_valid_args, &meta, &count);
		tstexpect(meta.strategy == SIMPLE);
		tstexpect(count == 1 && result[0] == 1);
		free(result);
	}
	tstcase("Valid - medium flag plus int inputs")
	{
		bzero(&meta, sizeof(meta));
		result = parse_args(3, medium_valid_args, &meta, &count);
		tstexpect(meta.strategy == MEDIUM);
		free(result);
	}
	tstcase("Valid - complex flag plus int inputs")
	{
		bzero(&meta, sizeof(meta));
		result = parse_args(3, complex_valid_args, &meta, &count);
		tstexpect(meta.strategy == COMPLEX);
		free(result);
	}
	tstcase("Valid - adaptive flag plus int inputs")
	{
		bzero(&meta, sizeof(meta));
		result = parse_args(3, adaptive_valid_args, &meta, &count);
		tstexpect(meta.strategy == ADAPTIVE);
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
		result = parse_args(2, bench_only_args, &meta, &count);
		tstexpect(meta.bench == 1);
		tstexpect(result == NULL);
	}
	tstcase("Flagged values are compacted")
	{
		bzero(&meta, sizeof(meta));
		result = parse_args(5, flagged_values, &meta, &count);
		tstexpect(result != NULL);
		tstexpect(count == 3);
		if (result)
		{
			tstexpect(result[0] == 3 && result[1] == 1 && result[2] == 2,
				"got %d %d %d", result[0], result[1], result[2]);
			free(result);
		}
	}
	tstcase("Both flags are accepted in either order")
	{
		bzero(&meta, sizeof(meta));
		result = parse_args(5, both_flags, &meta, &count);
		tstexpect(result != NULL && count == 2);
		tstexpect(meta.bench == 1 && meta.strategy == SIMPLE);
		if (result)
			free(result);
	}
}
