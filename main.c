#include <stdio.h>
#include "./includes/ft_printf.h"

int main()
{
	double  t;
	// %hh d - пропуск ненужных символов
//	ft_printf(" %hh d ", 44);
//	printf("%hh d\n", 44);
/*	ft_printf("    11   %#5o ", 44);
	printf("%#5o", 44);*/

//	ft_printf("%19a ",44.1);
//	printf("%19a", 44.1);
	//printf("\n%5d", 44.434);
//	ft_printf("%5c", 42);
//	printf("\n%5c", 42);
//	printf("%+");

//	ft_printf("%  5q%\n");
//	printf("%  5q%");

//	ft_printf("% 50hh10[Z %");
//	printf("\n% 50hh10[Z%");

//	ft_printf("%.37ld", -22337203685477l);
//	printf("\n%.37ld", -22337203685477l);

//	ft_printf("%.0f   ", -0.0);

	t = -5.0;
	ft_printf("% #-5.1f.", -7.3);
	printf("\n% #-5.1f.", -7.3);
//	ft_printf("%f %lf %Lf", 1.42, 1.42, 1.42l);
//	printf("\n%f %lf %Lf", 1.42, 1.42, 1.42l);

//	printf("\n%.0f   ", -0.0);
//	printf("%f", -0.000001);

//	ft_printf("%.1f", 23.00041);
//	printf("\n%.1f", 23.00041);

	return(0);
}
