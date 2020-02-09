/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validator.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdonnie <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/15 01:21:42 by pdonnie           #+#    #+#             */
/*   Updated: 2019/12/15 07:35:35 by pdonnie          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef INC_42_LEM_IN_VALIDATOR_H
# define INC_42_LEM_IN_VALIDATOR_H

# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>
# include <sys/types.h>
# include <sys/stat.h>
# include <sys/uio.h>

# define BUFF_SIZE 100

typedef struct		s_child
{
	int				num;
	struct s_child	*next;
	struct s_child	*prev;
}					t_child;

typedef struct		s_ant
{
	int				i;
	int				j;
	int				name;
	struct s_ant	*next;
	struct s_ant	*prev;
}					t_ant;

typedef struct		s_room
{
	int				num;
	char			*name;
	int				x;
	int				y;
	int				level;
	int				input;
	int				output;
	struct s_room	*next;
	t_child			*child;
	t_child			*parent;
}					t_room;

typedef struct		s_link
{
	int				a;
	int				b;
	struct s_link	*next;
	struct s_link	*prev;
}					t_link;

typedef struct		s_lines
{
	char			*line;
	struct s_lines	*next;
}					t_lines;

typedef struct		s_data
{
	int				ants;
	int				ants_max;
	int				ants_min;
	t_link			*links;
	t_room			*rooms;
	t_room			*start;
	t_room			*end;
	int				total_rooms;
	int				total_paths;
	int				k;
	int				ant_order;
	int				order;
	t_lines			*first_line_print;
}					t_data;

typedef struct		s_list
{
	void			*content;
	size_t			content_size;
	struct s_list	*next;
}					t_list;

int					validator(t_data *data, int fd);
int					check_links(t_link *link, t_link *temp_link);
int					ft_create_link(t_link **temp_link, t_data *data);
int					ft_fill_link(t_link *temp_link, t_data *data,
							t_lines *lines, int i);
int					get_links(t_data *data, t_lines *lines);
int					get_commande(t_data *data, t_lines **lines);
int					get_rooms(int i, t_data *data, t_lines *lines);
int					bfs(t_data *data, t_room **array, int **queue);
int					fill_array_rooms(t_data *data, t_room **array);
int					algo_prepare_graph(t_data *data, t_room **array,
												int ***queue);
int					get_path(t_data *data, t_room **array, int **paths);
void				move_ants(t_data *data, t_room **array, int **paths,
										t_ant *ant);
int					ft_free(t_data *data, t_room ***array, int ***numbers);
int					get_next_line(const int fd, char **line);
char				*ft_strjoin(char const *s1, char const *s2);
size_t				ft_strlen(const char *s);
char				*ft_strsub(char const *s, unsigned int start, size_t len);
t_list				*ft_lstnew(void const *content, size_t content_size);
char				*ft_strchr(const char *s, int c);
void				*ft_memcpy(void *restrict dst, const void *restrict src,
														size_t n);
int					ft_atoi(const char *str);
int					ft_isdigit(int c);
int					ft_strcmp(const char *s1, const char *s2);
int					ft_check_comment(t_lines **lines);
int					create_array_rooms(t_data *data, t_room ***array);
int					print_error(void);
void				move_ant(t_data *data, t_room **array, int **paths);
void				del_child_or_parent(t_child **child, int y,
										t_room **array, int i);
int					print_error(void);
void				print_ants_rooms_links(t_data *data);
void				fill_data(t_data *data);
int					ft_create_queue(t_data *data, int ***queue);
int					create_paths(t_data *data, int ***paths);
int					skip_comments(int status, t_data *data,
									t_lines **lines, int fd);
void				ft_fill_room(t_room *room);
void				del_input_forks(t_data *data, t_room **array,
										int i, int **queue);
void				calculate_input_and_output(t_room **array,
												int **queue);
void				check_path(t_room **array, int start,
							t_child *parent, int end);
void				sort_childs(t_room **array, t_room *end,
										t_child *parent);
int					ft_clean_buf(char **temp);
int					ft_free_queue(int ***queue);
void				delete_no_one_link_a(t_data *data, t_room **array,
												int **queue, int i);
void				delete_no_one_link(t_data *data, t_room **array,
												int **queue, int i);
int					rev(void);
void				free_temp_link(t_link **temp_link, t_data *data);
int					get_y(int *i, t_room *temp, t_lines *lines);
int					get_x(int *i, t_room *temp, t_lines *lines);
int					ft_printf(const char *format, ...);

#endif
