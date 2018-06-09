/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   assembler.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akaseris <akaseris@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/27 20:57:57 by ffloris           #+#    #+#             */
/*   Updated: 2018/06/07 17:55:42 by akaseris         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ASSEMBLER_H
# define ASSEMBLER_H

# include "libft.h"

# define IND_SIZE 2
# define REG_SIZE 4
# define DIR_SIZE REG_SIZE

# define REG_CODE 1
# define DIR_CODE 2
# define IND_CODE 3

# define MAX_ARGS_NUMBER 4
# define MAX_PLAYERS 4
# define MEM_SIZE (4 * 1024)
# define IDX_MOD (MEM_SIZE / 8)
# define CHAMP_MAX_SIZE (MEM_SIZE / 6)

# define COMMENT_CHAR '#'
# define LABEL_CHAR ':'
# define DIRECT_CHAR '%'
# define SEPARATOR_CHAR ','

# define LABEL_CHARS "abcdefghijklmnopqrstuvwxyz_0123456789"

# define NAME_CMD_STRING ".name"
# define COMMENT_CMD_STRING ".comment"

# define REG_NUMBER 16

# define CYCLE_TO_DIE 1536
# define CYCLE_DELTA 50
# define NBR_LIVE 21
# define MAX_CHECKS 10

typedef char	t_arg_type;

# define T_REG 1
# define T_DIR 2
# define T_IND 4
# define T_LAB 8

# define PROG_NAME_LENGTH (128)
# define COMMENT_LENGTH (2048)
# define COREWAR_EXEC_MAGIC 0xea83f3

typedef struct	s_header
{
	unsigned int	magic;
	char			*prog_name;
	unsigned int	prog_size;
	char			*comment;
}				t_header;

typedef struct	s_line
{
	char			*label;
	char			*opname;
	char			*param[3];
	int				*param_type[3];
	struct s_line	*next;
	struct s_line	*prev;
}				t_line;

typedef struct	s_label
{
	char			*name;
	size_t			dist;
	struct s_label	*next;
}				t_label;

typedef struct	s_frame
{
	t_header	*header;
	t_line		*lines;
	t_label		*request;
	t_label		*declare;
	size_t		bytecount;
}				t_frame;

int				ft_input(int fd, t_frame **frame);
int				ft_line(char *s, t_frame *frame);
int				ft_header(char *s, int name, t_frame **frame);
int				ft_initline(t_line **line);
int				ft_get_opname(char **s, char **opname);
int 			ft_get_label(char **s, char **label);
void			ft_push_line(t_line *line, t_frame *frame);
int				ft_get_arguments(char *s, t_line *line);
void			ft_free_lines(t_line *line);
void			ft_free_frame(t_frame *frame);
#endif
