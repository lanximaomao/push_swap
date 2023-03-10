int	is_init(int *num, int count)
{
	int	i;

	i = 0;
	while (i < count)
	{
		if (num[i] != 0)
			return (1);
		i++;
	}
	return (0);
}


void level_b_init(t_ps *ps)
{
	int i;

	i = 0;
	while (i < ps->lvl + 1)
	{
		ps->lvl_b[i] = 0;
		i++;
	}
}
