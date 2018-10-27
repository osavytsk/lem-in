/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lemin.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: osavytsk <osavytsk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/01 13:53:52 by osavytsk          #+#    #+#             */
/*   Updated: 2018/10/27 05:12:14 by osavytsk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LEMIN_H
# define LEMIN_H

# define FD 0
# define MAP_SZ 80
# define INFIN 100000

# include "../libft/libft.h"

typedef struct	s_crd
{
	int			x;
	int			y;
}				t_crd;

typedef struct	s_ants
{
	int			ids;
	int			path;
	int			turn;
}				t_ants;

typedef struct	s_path
{
	int			*path;
	int			lenght;
	int			ants;
}				t_path;

typedef struct	s_rooms
{
	char		*ids;
	int			crdX;
	int			crdY;
}				t_rooms;

typedef struct	s_links
{
	int			roomFirst;
	int			roomSecond;
}				t_links;

typedef struct	s_diff
{
	int			*paths;
	int			lenght;
}				t_diff;

typedef struct	s_data
{
	int			antsIndex;
	int			begin;
	int			over;
	t_rooms		**rooms;
	t_links		**nodes;
	t_path		**paths;
	t_path		**allWays;
	t_ants		**ants;
	t_diff		**diff;
	char		**input;
	int			**mtx;
	int			size;
	int			putMap;
	int			putMoves;
	int			putWays;
	int			putAllWays;
	int			putHide;
	int			putClean;
	int			putAntMove;
	int			putAnt;
}				t_data;

int				isCommand(char *s);
int				isComment(char *s);
int				isInt(char *s);
int				roomExists(t_data *its, char **array);
t_data			*createInfo(char **fl);
char			**readFile(void);
void			outputFile(t_data *its, char **fl, int lstLine);
int				addLink(t_data *its, int roomFirst, int roomSecond);
int				addRoom(t_data *its, char **array);
int				addWay(t_data *its, int *path, int lenght);
int				addCommand(t_data *its, int i, int room);
int				addDiff(t_data *its, int *array, int maxLenght);
int				parseInput(t_data *its);
void			outputAllPaths(t_data *its);
void			outputPaths(t_data *its);
void			outputResults(t_data *its, int lst, char **fl);
int				outputAntMoves(t_data *its);
void			outputResult(t_data *its, int turns, int **antMoves);
void			createAnts(t_data *its, int lst);
int				removeAll(t_data *its);
void			removeNext(t_data *its);
void			removeTwoNext(t_data *its);
int				findAllPaths(t_data *its, int lst);
void			getBestWays(t_data *its, int lst);
void			buildMatrix(t_data *its);
void			searchDiff(t_data *its, int lst);
void			parseCom(t_data *its, int lstLine, char **fl);
int				vsDiagLine(t_rooms *roomOne, t_rooms *roomTwo, char **map);
int				vsCheck(int y, int x, char **map);
int				vsCheckLeft(int y, int x, char **map);
int				vsCheckRight(int y, int x, char **map);
int				vsPutLink(t_data *its, char **map, t_links *node);
void			vsPutMap(t_data *its);
void			vsAddLines(int *nodes, t_data *its, char **map);
int				vsRdd(int i, t_rooms *roomOne, t_rooms *roomTwo, char **map);
int				vsRud(int i, t_rooms *roomOne, t_rooms *roomTwo, char **map);
int				vsLdd(int i, t_rooms *roomOne, t_rooms *roomTwo, char **map);
int				vsLud(int i, t_rooms *roomOne, t_rooms *roomTwo, char **map);

#endif
