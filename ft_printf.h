#ifndef LIBRARY_H
# define LIBRARY_H

# include <stdlib.h>
# include <unistd.h>
# include <stdarg.h>
# include <ctype.h>
# include "./libft/libft.h"

# define PLUS		(1 << 0)
# define MINUS		(1 << 1)
# define SHARP		(1 << 2)
# define ZERO		(1 << 3)
# define SPACE		(1 << 4)
# define WILDCARD 	(1 << 5)

# define SHORT		(1 << 6)
# define SSHORT		(1 << 7)
# define LONG		(1 << 8)
# define LLONG		(1 << 9)
# define UPPER		(1 << 10)
# define INTMAX		(1 << 11)
# define SIZE_T		(1 << 12)
# define LDOUBLE	(1 << 13)
# define MIN_LEN	(1 << 13)
# define PRECISION	(1 << 14)
# define POINTER	(1 << 15)

# define LD_MASK 	0xFFF
# define LD_CHECK	0x7FF

# define LD_FRAC	0x000FFFFFFFFFFFFF
# define LD_MASK_LONG 0x7FFFFFFFFFFFFFFF

typedef void (*print_func)(*t_format, *t_buffer);

typedef struct	s_format
{
	int			fl;
	int			fd;
	int 		len;
	int 		width;
	int 		prec;
	int 		base;
	int 		to_print;
	char 		spec;
	char		*prefix;
	va_list 	ap;
	print_func	func;
}				t_format;

typedef struct	s_buffer
{
	char		buffer[64] __attribute__((__aligned__(8)));
	size_t		buffer_index;
	uintmax_t	bytes_written;
	int8_t		undefined_behaviour;
}				t_buffer;

int				ft_printf(const char *format, ...);

/*
 * Parsing each argument's format string
 */
char			*parser(char *str, va_list *ap, t_buffer *buf);
void			flag_and_width(char *str, t_format *frmt);
void			precision_parser(char *str, t_format *frmt);
void			length_parser(char *str, t_format *frmt);
void			base_parser(t_format *frmt);
void			mode_parser(t_format *frmt);
void			spec_parser(char *string, t_format *format);

/*
 * ITOA W/ BASE
 */
void			ft_itoa_base(t_format *format, uintmax_t n, char *str, int mode, size_t len);
void			print_itoa_base(uintmax_t n, t_format *frmt, t_buffer *buf);
void			ft_strup(char *str);

/*
 * printing with spec D, I
 */
void			print_di(t_format *frmt, t_buffer *buf);
void			add_sign(intmax_t n, t_format *frmt, char *str);
void			set_width(intmax_t n, t_format *frmt);
void			settings_d(intmax_t n, t_format *frmt, t_buffer *buf);

/*
 * printhing spec B, X, O, U
 */
void			print_bxou(t_format *frmt, t_buffer *buf);
void			settings_bxou(uintmax_t n, t_format *frmt, t_buffer *buf);
void			set_width_base(t_format *frmt, uintmax_t n);
void			print_prefix(uintmax_t n, t_format *frmt, t_buffer *buf);

/*
 * prining floats: A, F, G, E
 */
void			print_aefg(t_format *frmt, t_buffer *buf);

/*
 * print F
 */
void			print_f(t_format *frmt,  long double d, t_buffer *buf);
int				check_spec_val(t_format *frmt, long double n, t_buffer *buf);
void			print_sign(long double d, t_format *frmt, t_buffer *buf);
void			print_fraction(long double fraction, t_format *frmt, t_buffer *buf);

/*
 * print A, E
 */
void			print_ae(t_format *frmt, long double d, t_buffer *buf);
void			set_exp(t_format *frmt, int64_t *exp, long double n);
void			print_exp(int64_t exp, uintmax_t n, t_format *frmt, t_buffer *buf);
void			set_width_ae(long double d, uint64_t integer, t_format *frmt);

/*
 * print G
 */
void			print_g(long double d, t_format *frmt, t_buffer *buf);
int32_t 		compare_fe(long double d, t_format *frmt);

/*
 * print C and lC
 */
void			*print_c(t_format *frmt);
void			print_wchar(wint_t c, t_format *frmt);
static void		oct_2(wint_t c);
static void		oct_3(wint_t c);
static void		oct_4(wint_t c);

/*
 * print S
 */
void 			print_s(t_format *frmt);

/*
 * print WS
 */
size_t			ft_wcharlen(wint_t c, t_format *frmt);
void			print_wstring(wchar_t *wstr, t_format *frmt, int64_t strlen);
int64_t			wslen(wchar_t *wstr, t_format *frmt);


/*
 * HELP FUNCTIONS FOR FLOAT
 */
long double 	ft_fabsl(long double d);
intmax_t 		ft_roundl(long double d);
uintmax_t		ft_imaxabs(intmax_t n);

/*
 * HELP FUNCTIONS
 */
static void		init_format(t_format *format);
static void		init_buffer(t_buffer *buffer);
int8_t			ft_isupper(char c);
void			padding(char *c, int32_t padding, t_buffer *buffer);
int 			ft_max(a, b);
size_t			length_base(uintmax_t n, int8_t base);

#endif