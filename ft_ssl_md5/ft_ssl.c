/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ssl.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vdauverg <vdauverg@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/16 17:01:54 by vdauverg          #+#    #+#             */
/*   Updated: 2019/11/17 16:17:43 by vdauverg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ssl.h"

void	safe_exit(int err, char *arg)
{
	if (err == USAGE)
		ft_printf("usage: ft_ssl command [command opts] [command args]");
	else if (err == INV_COM)
		ft_printf("ft_ssl: Error: '%s' is an invalid command.\n\n\
Standard commands:\n\nMessage Digest commands:\nmd5\nsha256\nsha512\n\n\
Cipher commands:\n\n", arg);
	else if (err == ILL_OPT)
		ft_printf("md5: illegal option -- %.1s", arg);
	exit(0);
}

void	s_handler(char **arg, t_metadata *meta)
{
	int		i;
	char	*str;

	if (arg[0][2])
		str = ft_strdup(arg[0] + 2);
	else
		str = ft_strdup(arg[1]);
	meta->str = str;
}

int		chk_flag(char *arg, t_metadata *meta)
{
	int			i;
	int			j;
	int			chk;
	char		*flags;

	chk = 0;
	meta->flags[3] = 0;
	if (arg[0] == '-' && (flags = ft_strdup("pqrs")))
	{
		i = 1;
		if (!(meta->chk) && arg[1] == 's')
			return (2);
		while (arg[i])
		{
			chk = 0;
			j = 0;
			while (flags[j])
			{
				if (flags[j] == arg[i])
				{
					chk = 1;
					meta->flags[j] = 1;
					break ;
				}
				j++;
			}
			if (!chk)
				safe_exit(ILL_OPT, arg + i);
			i++;
		}
	}
	return (chk);
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
	safe_exit(INV_COM, arg);
	return (NULL);
}

int		main(int argc, char **argv)
{
	int				i;
	int				j;
	unsigned char	*res;
	char			*str;
	unsigned char	*(*func)(char *, t_metadata);
	t_metadata		meta;

	if (argc > 2)
	{
		argc--;
		argv++;
		func = disp_tab(*argv);
		meta.chk = 0;
		i = 1;
		while (i < argc)
		{
			while (argv[i] && (j = chk_flag(argv[i], &meta)))
			{
				if (j == 2)
					s_handler(argv + i, &meta);
				i += 1 + meta.flags[3];
			}
			if (!argv[i])
				safe_exit(USAGE, NULL);
			str = read_file(argv[i]);
			// res = func(strs[i], meta);
			// j = 0;
			// while (j < 16)
			// 	ft_printf("%02x", res[j++]);
			ft_printf("%s\n", str);
			i++;
		}
	}
	else
		safe_exit(USAGE, NULL);
	return (0);
}
