#include <stdio.h>
#include "./includes/ft_printf.h"

int main()
{

/*	ft_printf("11 %#5ld ", 44);
	printf("%#5hd\n", 44);
	ft_printf("    11   %#5o ", 44);
	printf("%#5o", 44);*/


	ft_printf("%e ",44.1);
	printf("%e", 44.1);
	//printf("\n%5d", 44.434);
	return(0);
}
