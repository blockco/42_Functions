#include <stdlib.h>

int findsize(int value, int base)
{
	int size;

	size = 0;
	while (value)
	{
		size++;
		value = value / base;
	}
	return size;
}

char *ft_itoa_base(int value, int base)
{
	char hex[16] = "0123456789ABCDEF";
	long n = value;
	int size;
	char *ret;
	if (value == 0)
		return ("0");
	if (value < 0)
		n = -1 * n;
	size = findsize(n, base);
	if (value < 0 && base == 10)
		size++;
	ret = (char*)malloc(size + 1);
	ret[size] = '\0';
	size--;
	while (n)
	{
		ret[size] = hex[n % base];
		n = n / base;
		size--;
	}
	if (value < 0 && base == 10)
		ret[0] = '-';
	return ret;
}
