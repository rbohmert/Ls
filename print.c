/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbohmert <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/16 12:02:59 by rbohmert          #+#    #+#             */
/*   Updated: 2016/04/21 00:54:02 by rbohmert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void	print_rights(struct stat *stat)
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
	if (stat->st_mode & S_IXUSR)
		(stat->st_mode & S_ISUID) ? ft_putchar('s') : ft_putchar('x');
	else
		(stat->st_mode & S_ISUID) ? ft_putchar('S') : ft_putchar('-');
	((stat->st_mode & S_IRGRP)) ? ft_putchar('r') : ft_putchar('-');
	((stat->st_mode & S_IWGRP)) ? ft_putchar('w') : ft_putchar('-');
	if (stat->st_mode & S_IXGRP)
		(stat->st_mode & S_ISGID) ? ft_putchar('s') : ft_putchar('x');
	else
		(stat->st_mode & S_ISGID) ? ft_putchar('S') : ft_putchar('-');
	((stat->st_mode & S_IROTH)) ? ft_putchar('r') : ft_putchar('-');
	((stat->st_mode & S_IWOTH)) ? ft_putchar('w') : ft_putchar('-');
	if (stat->st_mode & S_IXOTH)
		(stat->st_mode & S_ISVTX) ? ft_putchar('t') : ft_putchar('x');
	else
		(stat->st_mode & S_ISGID) ? ft_putchar('T') : ft_putchar('-');
}

void	print_sp(t_file *file, t_align *al, int flag, int i)
{
	int				len;
	struct group	*grp;
	struct passwd	*passwd;

	passwd = getpwuid(file->stat->st_uid);
	grp = getgrgid(file->stat->st_gid);
	len = nb_len(file->stat->st_nlink);
	if (flag == 0)
	{
		while (i++ <= al->syml - len)
			ft_putchar(' ');
	}
	else
	{
		ft_putstr(passwd->pw_name);
		len = ft_strlen(passwd->pw_name);
		while (i++ + len <= al->usr + 1)
			ft_putchar(' ');
		ft_putstr(grp->gr_name);
		i = -1;
		len = ft_strlen(grp->gr_name);
		while (i++ + len < al->grp)
			ft_putchar(' ');
	}
}

void	print_l_2(t_file *file)
{
	char			str[100];

	if (file->stat->st_mtimespec.tv_sec < time(NULL) \
		&& (time(NULL) - file->stat->st_mtimespec.tv_sec) < 15811200LL)
		write(1, ctime(&(file->stat->st_mtimespec.tv_sec)) + 4, 12);
	else
	{
		write(1, ctime(&(file->stat->st_mtimespec.tv_sec)) + 4, 7);
		write(1, ctime(&(file->stat->st_mtimespec.tv_sec)) + 19, 5);
	}
	ft_putstr(" ");
	ft_putstr(file->name);
	if (S_ISLNK(file->stat->st_mode))
	{
		str[readlink(file->path, str, 100)] = 0;
		ft_putstr(" -> ");
		ft_putstr(str);
	}
	ft_putchar('\n');
}

void	print_l(t_file *file, t_align *al)
{
	acl_t			acl;
	struct passwd	*passwd;

	acl = NULL;
	passwd = getpwuid(file->stat->st_uid);
	print_rights(file->stat);
	if (listxattr(file->path, NULL, 0, XATTR_NOFOLLOW) > 0)
		ft_putchar('@');
	else if ((acl = acl_get_file(file->path, ACL_TYPE_EXTENDED)))
		ft_putchar('+');
	else
		ft_putchar(' ');
	print_sp(file, al, 0, 0);
	ft_putnbr(file->stat->st_nlink);
	ft_putchar(' ');
	print_sp(file, al, 1, 0);
	put_size(file, al);
	ft_putstr(" ");
	print_l_2(file);
}

void	print(t_list **list, t_options *opt, int flag)
{
	t_align		al;
	int			tot;
	t_list		*tmp;

	ft_bzero(&al, sizeof(t_align));
	tmp = *list;
	tot = (opt->l) ? max_list(tmp, &al, opt) : 0;
	if (opt->l && flag)
	{
		write(1, "total ", 6);
		ft_putnbr(tot);
		write(1, "\n", 1);
	}
	while (tmp)
	{
		if (L(tmp)->name[0] != '.' || opt->a)
		{
			if (opt->l)
				print_l(tmp->content, &al);
			else
				ft_putendl(L(tmp)->name);
		}
		tmp = tmp->next;
	}
}
