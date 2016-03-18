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
# include <stdio.h>
# include <pwd.h>
# include <uuid/uuid.h>
# include <grp.h>

typedef	struct	s_options
{
	int			l;
	int			r;
	int			a;
	int			t;
	int			R;
}				t_options;

typedef struct	s_file
{
	struct stat *stat;
	char 		*name;
}				t_file;

void			ft_list_reverse(t_list **begin_list);
int				ft_ls(char *str, t_options *opt);
char			*add_path(char *path, char *rep);
void			stock(t_list **list, t_list **list_dir, DIR *rep, char *str);
void			print_rights(struct stat *s_stat);
void			print_l(t_file *file, int max1, int max2);
void			print(t_list *list, t_options *opt);
void			free_list(t_list *list, int flag);
void			init_opt(t_options *opt);
void			affect_option(t_options *opt, char c);
int				parser(char **tab_arg, t_options *opt, t_list **rep_list, t_list **fil_list);
t_list			*separer(t_list *list);
t_list			*fusion(t_list *lg, t_list *ld, int flag);
void			trier(t_list **list, int fag);
int				cmp(t_list *lg, t_list *ld, int flag);
#endif
