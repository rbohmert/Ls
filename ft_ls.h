/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbohmert <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/21 01:35:54 by rbohmert          #+#    #+#             */
/*   Updated: 2016/04/21 01:39:54 by rbohmert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_LS_H
# define FT_LS_H

# include "libft/libft.h"
# include <sys/types.h>
# include <sys/stat.h>
# include <unistd.h>
# include <stdlib.h>
# include <time.h>
# include <dirent.h>
# include <errno.h>
# include <pwd.h>
# include <uuid/uuid.h>
# include <grp.h>
# include "/usr/include/linux/xattr.h"
# include <sys/acl.h>
# define L(a) ((t_file *)(a->content))
# define MAJOR(dev) ((unsigned int)(dev >> 24))
# define MINOR(dev) ((unsigned int)(dev & 0x00FFFFFF))

typedef	struct	s_options
{
	int			l;
	int			r;
	int			a;
	int			t;
	int			gr;
}				t_options;

typedef struct	s_file
{
	struct stat *stat;
	char		*path;
	char		*name;
}				t_file;

typedef	struct	s_align
{
	int			syml;
	int			usr;
	int			grp;
	int			size;
	int			min;
	int			maj;
	int			is;
}				t_align;

int				ft_ls(char *str, t_options *opt);
void			ls_r(t_list *list, char *str, t_options *opt);
void			stock(t_list **list, DIR *rep, char *str, t_options *opt);
void			multi_file(t_list *rep_list, t_list *fil_list, t_options *opt);

void			print_rights(struct stat *s_stat);
void			print_sp(t_file *file, t_align *al, int flag, int i);
void			print_l(t_file *file, t_align *al);
void			print_l_2(t_file *file);
void			print(t_list **list, t_options *opt, int flag);

void			affect_option(t_options *opt, char c);
void			build_list(char *str, t_list **rep_list, t_list **fil_list);
int				parser(char **tab_arg, t_options *opt,\
				t_list **rep_list, t_list **fil_list);

void			ft_list_reverse(t_list **begin_list);
t_list			*separer(t_list *list);
t_list			*fusion(t_list *lg, t_list *ld, int flag);
void			trier(t_list **list, int fag);
int				cmp(t_list *lg, t_list *ld, int flag);

int				max_list(t_list *list, t_align *al, t_options *opt);
void			get_len(t_align *al);
void			compare(t_file *file, t_align *al);

void			free_list(t_list *list, int flag);
int				nb_len(int nb);
char			*add_path(char *path, char *rep);
void			put_size(t_file *file, t_align *al);
#endif
