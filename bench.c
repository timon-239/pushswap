#include "push_swap.h"

void	bench_init(t_bench *b)
{
	b->sa = 0;
	b->sb = 0;
	b->ss = 0;
	b->pa = 0;
	b->pb = 0;
	b->ra = 0;
	b->rb = 0;
	b->rr = 0;
	b->rra = 0;
	b->rrb = 0;
	b->rrr = 0;
	b->total = 0;
}

static char	*bench_helper(t_mode mode, double disorder)
{
	if (mode == MODE_SIMPLE)
		return ("Simple / O(n²)");
	if (mode == MODE_MEDIUM)
		return ("Medium / O(nsqrtn)");
	if (mode == MODE_COMPLEX)
		return ("Complex / O(n log n)");
	if (disorder < 0.2)
		return ("Adaptive / O(n²)");
	if (disorder < 0.5)
		return ("Adaptive / O(nsqrtn)");
	return ("Adaptive / O(n log n)");
}

void	print_bench(t_bench *b, double disorder, t_mode mode)
{
	char *mode_str;

	if (!b)
		return ;

	mode_str = bench_helper(mode, disorder);

	disorder = disorder * 100;

	ft_printf(2, "[bench] disorder: %f%\n", disorder);
	ft_printf(2, "[bench] strategy: %s\n", mode_str);
	ft_printf(2, "[bench] total ops: %d\n", b->total);
	ft_printf(2, "[bench] sa: %d sb: %d ss: %d pa: %d pb: %d\n", b->sa, b->sb,
		b->ss, b->pa, b->pb);
	ft_printf(2, "[bench] ra: %d rb: %d rr: %d rra: %d rrb: %d rrr: %d\n",
		b->ra, b->rb, b->rr, b->rra, b->rrb, b->rrr);
}
