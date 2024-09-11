
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

// guess this was in vain
void	print_bits(unsigned int octet)
{
	int i;
	char bit[32];
	i = 31;
	bit[i] = '\0';
	while (i > 0)
	{
		i--;
		if ((octet % 2) == 0)
			bit[i] = '0';
		else
			bit[i] = '1';
		octet = octet >> 1;
	}
	write(1, bit, 31);
}

void	int_to_bin(unsigned int nb)
{
	char			bin[33];
	unsigned long	n;
	int				i;
//	unsigned int	k;

	i = 0;
	n = (unsigned long)nb;
	bin[32] = '\0';
	while (i < 32)
	{
		if (n & (1 << i))
			bin[32 - i] = '1';
		else
			bin[32 - i] = '0';
		i++;
	}
}

int main()
{
	unsigned int n = 2147483646;
	print_bits(n);
	//int_to_bin(n);
}