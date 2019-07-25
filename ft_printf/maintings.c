/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   maintings.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vdauverg <vdauverg@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/25 00:20:15 by vdauverg          #+#    #+#             */
/*   Updated: 2019/07/24 17:08:57 by vdauverg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdio.h>

int main(void)
{
    char    *str = "String";
    int         len;
    // int     i = 50000;
    
//     while (i--)
 len = ft_printf("\n%5.0% %#-  10.4LF %08u %8.4s {%03c} %+lld %11p %#x %#X %#o\n", (long double)-10.476, 159449, str, 0, (long long)846452456054, str, 4967295, 42947295, 42);
    ft_printf("%d\n", len);
    len = printf("\n%5.0% %#-  10.4LF %08u %8.4s {%03c} %+lld %-11p %#x %#X %#o\n", (long double)-10.476, 159449, str, 0, (long long)846452456054, str, 4967295, 42947295, 42);
    ft_printf("%d\n", len);
    // len = ft_printf("{%05.*lld}", 15, 75808);
    // ft_printf("\n%d\n", len);
    // len = printf("{%05.*lld}", 15, 75808);
    // ft_printf("\n%d\n", len);
    return (0);
}
