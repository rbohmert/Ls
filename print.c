/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbohmert <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/16 12:02:59 by rbohmert          #+#    #+#             */
/*   Updated: 2016/02/18 23:52:23 by rbohmert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void				max_list(t_list *list, int *max1, int *max2, t_options *opt)
{
	int		i;
	int		tmp;

	*max1 = 0;
	*max2 = 0;
	while (list)
	{
		if (((t_file *)list->content)->name[0] != '.' || opt->a)
		{
			i = 0;
			tmp = ((t_file *)list->content)->stat->st_nlink;
			while ((tmp = tmp / 10))
				i++;
			*max1 = *max1 < i ? i : *max1;
			i = 0;
			tmp = ((t_file *)list->content)->stat->st_size;
			while ((tmp = tmp / 10))
				i++;
			*max2 = *max2 < i ? i : *max2;
		}
		list = list->next;
	}
}


void				print_rights(struct stat *stat)
{
	(S_ISDIR(stat->st_mode)) ? ft_putchar('d') : 0;
	(S_ISSOCK(stat->st_mode)) ? ft_putchar('s') : 0;
	(S_ISFIFO(stat->st_mode)) ? ft_putchar('p') : 0;
	(S_ISBLK(stat->st_mode)) ? ft_putchar('b') : 0;
	(S_ISCHR(stat->st_mode)) ? ft_putchar('c') : 0;
	(S_ISLNK(stat->st_mode)) ? ft_putchar('l') : 0;
	(S_ISREG(stat->st_mode)) ? ft_putchar('-') : 0;
	((stat->st_mode & S_IRUSR)) ? ft_putchar('r') : ft_putchar('-');
	((stat->st_mode & S_IWUSR)) ? ft_putchar('w') : ft_putchar('-');
	((stat->st_mode & S_IXUSR)) ? ft_putchar('x') : ft_putchar('-');
	((stat->st_mode & S_IRGRP)) ? ft_putchar('r') : ft_putchar('-');
	((stat->st_mode & S_IWGRP)) ? ft_putchar('w') : ft_putchar('-');
	((stat->st_mode & S_IXGRP)) ? ft_putchar('x') : ft_putchar('-');
	((stat->st_mode & S_IROTH)) ? ft_putchar('r') : ft_putchar('-');
	((stat->st_mode & S_IWOTH)) ? ft_putchar('w') : ft_putchar('-');
	((stat->st_mode & S_IXOTH)) ? ft_putchar('x') : ft_putchar('-');
}

void				print_l(t_file *file, int max1, int max2)
{
	char			*mtime;
	struct passwd	*passwd;
	struct group	*grp;
	int				i;
	int				tmp;

	i = 0;
	passwd = getpwuid(file->stat->st_uid);
	print_rights(file->stat);
	tmp = file->stat->st_nlink;
	while ((tmp = tmp / 10))
		i++;
	while (tmp++ <= max1 + 1 - i )
		ft_putchar(' ');
	ft_putnbr(file->stat->st_nlink);
	ft_putchar(' ');
	ft_putstr(passwd->pw_name);
	ft_putstr("  ");
	grp = getgrgid(file->stat->st_gid);
	ft_putstr(grp->gr_name);
	tmp = file->stat->st_size;
	i = 0;
	while ((tmp = tmp / 10))
		i++;
	while (tmp++ <= max2 + 1 - i )
		ft_putchar(' ');
	ft_putnbr(file->stat->st_size);
	ft_putstr(" ");
	mtime = ctime(&(file->stat->st_mtimespec.tv_sec));
	write(1, mtime + 4, 12);
	ft_putstr(" ");
	ft_putstr(file->name);
	ft_putchar('\n');
}

void	print(t_list *list, t_options *opt)
{
	int			max[2];

	if (opt->l)
		max_list(list, &max[0], &max[1], opt);
	if (opt->t)
		trier(&list, 3);
	else
		trier(&list, 2);
	if (opt->r)
		ft_list_reverse(&list);
	while (list)
	{
		if (((t_file *)list->content)->name[0] != '.' || opt->a)
		{
			if (opt->l)
				print_l(list->content, max[0], max[1]);
			else
				ft_putendl(((t_file *)list->content)->name);
		}
		list = list->next;
	}
	ft_putstr("\n");
}

