#include <stdio.h>
#include "./includes/ft_printf.h"

int main()
{

	// %hh d - пропуск ненужных символов
//	ft_printf(" %hh d ", 44);
//	printf("%hh d\n", 44);
/*	ft_printf("    11   %#5o ", 44);
	printf("%#5o", 44);*/


	ft_printf("%19a ",44.1);
	printf("%19a", 44.1);
	//printf("\n%5d", 44.434);
	return(0);
}
