#include <stdio.h>
#include "./includes/ft_printf.h"

int main()
{

	ft_printf("11 %#5X ", 44);
	printf("%#5X\n", 44);
	ft_printf("    11   %#5o ", 44);
	printf("%#5o", 44);
	//printf("\n%5d", 44.434);
	return(0);
}
