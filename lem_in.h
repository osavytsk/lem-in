/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lem_in.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: osavytsk <osavytsk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/28 23:39:40 by osavytsk          #+#    #+#             */
/*   Updated: 2018/10/28 23:39:51 by osavytsk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LEM_IN_H
# define LEM_IN_H

# include "libftprintf/get_next_line.h"

typedef struct		s_binds
{
	struct s_area	*bind;
	struct s_binds	*nxt;
}					t_binds;

typedef struct		s_area
{
	char			*ident;
	t_binds			*binds;
	int				condition;
	int				intent;
	int				coord_x;
	int				coord_y;
	struct s_area	*nxt_area;
}					t_area;

int					simply_number(char *s);
int					quantity_of_ants(char *s);
void				set_bind(t_area *area, char *from, char *in);
void				printing_comm(char *s);

int					check_area_specific(t_area *begin, char **array);
int					checking_coord(t_area *begin, int crd_x, int crd_y);
int					check_ident_area(t_area *begin, char *ident);
int					check_area_condition(int condition, t_area *area);
void				set_intent(t_area *areas);

void				print_error(char *s);
t_area				*setup_area(t_area *area);
void				delete_array(char **array);
int					is_area(char *s);
void				dlt_area(t_area *area);

int					read_begin(t_area *areas, char *s);
int					read_over(t_area *areas, char *s);
int					read_area(t_area *areas, char *s);
int					read_bind(t_area *areas, char *s);
void				reading_links(t_area *areas, char *s);

t_binds				**way_setup(t_area *begin, int paths);
int					best_way(t_area *begin, t_binds *way);
int					ft_routing(t_area *area, t_binds *way, int i, int max);
t_binds				**find_path(t_area *begin, t_area *area, int paths);

t_area				*get_area(t_area *begin, int condition);
int					numbers_of_area(t_area *area);

int					making_way(t_binds *way, t_area *bind);
void				delete_way(t_binds *way);
int					way_length(t_binds *way);

void				contin_relocation(t_binds **way,
									  int num_ants, int *finish, int n);
void				ants_anoth_paths(t_binds **way, int *nants,
									 int *finish, int *i);
void				relocation(t_binds *way, int *finish);
void				ants_in_action(int i, t_binds **way, int nants);

char				**check_bind_id(t_area *begin, t_area *area, char *s);
t_area				*setup_areas(void);

int					inspect_ants(char *s);
void				remove_data(t_area *area, t_area *areas, t_binds **way);
void				inspect_data(t_area *areas, char *s);
int					main(void);

#endif
