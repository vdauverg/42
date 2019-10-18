/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ssl.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vdauverg <vdauverg@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/16 17:01:54 by vdauverg          #+#    #+#             */
/*   Updated: 2019/10/16 23:36:22 by vdauverg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ssl.h"

void	safe_exit(char *arg)
{
	ft_printf("ft_ssl: Error: '%s' is an invalid command.\n\nStandard \
			commands:\n\nMessage Digest commands:\nmd5\nsha256\n\nCipher \
			commands:\n\n", arg);
	exit(0);
}

int		chk_strs(int count, char **args)
{
	int	i;

	i = 0;
	return (count);
}

int		chk_flags(int count, char **args)
{
	int		i;
	int		j;
	char	flags[] = "pqrs";

	i = 0;
	while (i < count)
	{
		if (*args[i] == '-')
		{
			args[i]++;
			j = 0;
			while (*args[i] && flags[j])
			{
				if (flags[j] == *args[i])
				{
					// Put flags in a struct
					break ;
				}
				j++;
			}
		}
	}
	return (count);
}

void	*disp_tab(char *arg)
{
	int		i;
	char	*commands[] = {"md5", "sha256", "whirlpool"};
	char	*(*funcs[])() = {md5, sha256, whirlpool};

	i = 0;
	while (commands[i])
	{
		if (!ft_strcmp(arg, commands[i]))
			return (funcs[i]);
		i++;
	}
	return (NULL);
}

void	*chk_args(int count, char **args)
{
	void	*func;

	func = disp_tab(*args);
	if (!func)
		safe_exit(*args);
	args++;
	if (--count)
		count = chk_flags(count, args);
	if (count)
		count = chk_strs(count, args);
	return (func);
}

int		main(int argc, char **argv)
{
	void	*func;

	if (argc > 2)
	{
		func = chk_args(argc--, argv++);
	}
	else
		ft_putstr("usage: ft_ssl command [command opts] [command args]");
	return (0);
}
