/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ssl.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vdauverg <vdauverg@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/16 17:01:54 by vdauverg          #+#    #+#             */
/*   Updated: 2019/10/23 14:04:20 by vdauverg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ssl.h"

void	safe_exit(char *arg)
{
	ft_printf("ft_ssl: Error: '%s' is an invalid command.\n\n\
Standard commands:\n\nMessage Digest commands:\nmd5\nsha256\nsha512\n\n\
Cipher commands:\n\n", arg);
	exit(0);
}

int		chk_flags(int count, char ***args, t_metadata *meta)
{
	int			i;
	int			j;
	char		*flags;

	flags = ft_strdup("pqrs");
	i = 0;
	while (i < count)
	{
		if (*(*args)[i] == '-')
		{
			(*args)[i]++;
			j = 0;
			while (*(*args)[i] && flags[j])
			{
				if (flags[j] == *(*args)[i])
				{
					meta->flags[j] = 1;
					break ;
				}
				j++;
			}
		}
		i++;
	}
	return (count);
}

void	*disp_tab(char *arg)
{
	int				i;
	char			*commands[] = {"md5", "sha256", "sha512", NULL};
	unsigned char	*(*funcs[])(char *str, t_metadata meta) = {md5, sha256, sha512};

	i = 0;
	while (commands[i])
	{
		if (!ft_strcmp(arg, commands[i]))
			return (funcs[i]);
		i++;
	}
	return (NULL);
}

void	*chk_args(int *count, char ***args, t_metadata *meta)
{
	int			c;
	char		**a;
	void		*func;

	c = *count;
	a = *args;
	func = disp_tab(*a);
	if (!func)
		safe_exit(*a);
	a++;
	if (--c)
		c = chk_flags(c, &a, meta);
	*count = c;
	*args = a;
	return (func);
}

int		main(int argc, char **argv)
{
	int				i;
	int				j;
	unsigned char	*res;
	char			**strs;
	unsigned char	*(*func)(char *, t_metadata);
	t_metadata		meta;

	if (argc > 2)
	{
		argc--;
		argv++;
		func = chk_args(&argc, &argv, &meta);
		strs = read_files(argc, argv);
		i = 0;
		while (i < argc)
		{
			res = func(strs[i], meta);
			j = 0;
			while (res[j])
				ft_printf("%02x", res[j++]);
			i++;
		}
	}
	else
		ft_putstr("usage: ft_ssl command [command opts] [command args]");
	return (0);
}
