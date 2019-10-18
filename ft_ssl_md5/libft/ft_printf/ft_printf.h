/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vdauverg <vdauverg@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/24 15:25:33 by vdauverg          #+#    #+#             */
/*   Updated: 2019/08/11 19:18:08 by vdauverg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include <stdarg.h>
# include "../libft.h"
# define F_HANDLE (va_list args,t_printf *node)={flag_i,flag_i,flag_o,F_HANDLE2
# define F_HANDLE2 flag_u,flag_x, flag_xupper, flag_f, flag_f, flag_c,F_HANDLE3
# define F_HANDLE3 flag_s,flag_b,flag_p}
# define S_HANDLE (const char *format,va_list args,t_printf *node)=S_HANDLE2
# define S_HANDLE2 {spec_prec,spec_alt,spec_zpad,spec_left,spec_sign,S_HANDLE3
# define S_HANDLE3 spec_space,spec_h,spec_l,spec_capl,spec_j,spec_z}

typedef struct		s_printf
{
	int	l;
	int	h;
	int	j;
	int	z;
	int	length;
	int	alt;
	int	step;
	int	align;
	int	zero;
	int	sign;
	int	space;
	int	pad;
}					t_printf;

int					ft_printf(const char *restrict format, ...);
char				*check_format(const char *format, va_list args, \
						t_printf *node);
char				*flag_i(va_list args, t_printf *node);
long long			signed_vars(va_list args, t_printf node);
char				*flag_o(va_list args, t_printf *node);
char				*flag_u(va_list args, t_printf *node);
char				*flag_x(va_list args, t_printf *node);
char				*flag_xupper(va_list args, t_printf *node);
unsigned long long	unsigned_vars(va_list args, t_printf node);
char				*flag_f(va_list args, t_printf *node);
char				*flag_c(va_list args, t_printf *node);
char				*flag_s(va_list args, t_printf *node);
char				*flag_b(va_list args, t_printf *node);
char				*flag_p(va_list args, t_printf *node);
char				*spec_prec(const char *format, va_list args, \
						t_printf *node);
char				*spec_alt(const char *format, va_list args, \
						t_printf *node);
char				*spec_zpad(const char *format, va_list args, \
						t_printf *node);
char				*spec_left(const char *format, va_list args, \
						t_printf *node);
char				*spec_sign(const char *format, va_list args, \
						t_printf *node);
char				*spec_space(const char *format, va_list args, \
						t_printf *node);
char				*spec_pad(const char *format, va_list args, \
						t_printf *node);
char				*spec_h(const char *format, va_list args, \
						t_printf *node);
char				*spec_l(const char *format, va_list args, \
						t_printf *node);
char				*spec_capl(const char *format, va_list args, \
						t_printf *node);
char				*spec_j(const char *format, va_list args, \
						t_printf *node);
char				*spec_z(const char *format, va_list args, \
						t_printf *node);
char				*spec_star(const char *format, va_list args, \
						t_printf *node);
char				*ft_itoabase(unsigned long long num, int base, int upper);
unsigned long long	ft_exponent(unsigned long long num, int exp);
char				*ft_ftoa(long double num, int precision, int alt);
char				*ftoa_precmod(int precision, long double num);
char				*ft_strscat(char *dst, char *src, int start);
char				*ft_strldup(const char *src, int len);
char				*ft_pad(char *str, int padlen, int zero, int align);
char				*ft_prec(char *str, int prec);
#endif
