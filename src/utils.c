#include <string.h>

int		ft_is_power_of_two(size_t nb)
{
	size_t	i;

	if (nb == 0 || nb == 1 || nb == 2 || nb == 4 || nb == 8 ||
			nb == 16 || nb == 32 || nb == 64 || nb == 128 || nb == 256 ||
			nb == 512 || nb == 1024 || nb == 2048 || nb == 4096 ||
			nb == 8192 || nb == 16384 || nb == 32768)
		return (1);
	i = 65536;
	while (i < nb)
		i <<= 1;
	return (i == nb);
}
