/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: coremart <coremart@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/06 05:55:46 by coremart          #+#    #+#             */
/*   Updated: 2019/06/15 05:03:03 by coremart         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <string.h>

# define SA 0x1
# define SB 0x2
# define SS 0x4
# define PA 0x8
# define PB 0x10
# define RA 0x20
# define RB 0x40
# define RR 0x80
# define RRA 0x100
# define RRB 0x200
# define RRR 0x400
# define ROT 0x360

typedef struct	s_arr
{
	int	*arr;
	int	size;
}				t_arr;

typedef struct	s_llist
{
	struct s_llist	*next;
	struct s_llist	*prev;
	int				nb;
}				t_llist;

typedef struct	s_llist_tmp
{
	struct s_llist_tmp	*next;
	struct s_llist_tmp	*prev;
	int					nb;
	int					dest;
}				t_llist_tmp;

typedef struct	s_piles
{
	t_llist		*a;
	t_llist_tmp	*b;
}				t_piles;

typedef struct	s_data_buff
{
	int		buff[1024];
	ssize_t	index;
}				t_data_buff;

typedef struct	s_all_data
{
	t_data_buff *buff;
	t_piles		*piles;
	t_llist		*lis;
}				t_all_data;

typedef struct	s_fun_match_op
{
	void	(*p)(t_data_buff *buff);
	int		op;
}				t_fun_match_op;

/*
**	parsing.c
*/
t_arr			*pars(const char *const *const tab, const int nb_elem);
/*
**	get_lis.c
*/
int				*get_lis_index(int *const arr, int size);
/*
**	list_op.c
*/
t_llist			*transform_to_ll_lis(t_arr *arr, int *lis);
t_piles			*transform_to_pile(t_arr *arr);
void			add_to_lis(t_llist *lis, int nb);
/*
**	pile_op.c
*/
void			push_a(t_piles *piles, t_data_buff *buff);
void			push_b(t_all_data *all_data);
void			rot_a_til_order(t_llist **ptr_a, int len, t_data_buff *buff);

/*
**	put_non_lis_on_b.c
*/
void			start_sort_pile(t_all_data *data, size_t size);
int				pusha_if_destof(t_all_data *all_data, int max_elem, int rev);
void			put_non_lis_on_b(t_all_data *all_data, t_llist *end_a,
												size_t rot_count, int rev);
/*
**	fill_buffer.c
*/
void			fill_buffer(t_data_buff *buff, int op);
/*
**	write_buff.c
*/
void			write_buff(t_data_buff *buff);
/*
**	fun_fill_rot.c
*/
void			fill_rot_a(t_data_buff *buff);
void			fill_rot_b(t_data_buff *buff);
void			fill_rev_rot_a(t_data_buff *buff);
void			fill_rev_rot_b(t_data_buff *buff);
/*
**	fun_fill_push.c
*/
void			fill_push_a(t_data_buff *buff);
void			fill_push_b(t_data_buff *buff);
/*
**	empty_b.c
*/
void			empty_b(t_all_data *data, size_t size);

/*
**	rot_count.c
*/
size_t			rot_count_til_push(t_llist *a, t_llist *lis, size_t size,
									int rev);
size_t			lst_len(t_llist *lst);
size_t			transformed_r_to_rr(int rot_to_first_pa, t_data_buff *buff,
									int rev);
size_t			count_rot_to_end_of_pa(int *arr, ssize_t rot_to_last,
										t_llist_tmp *b, int rev);

/*
**	ssp_custom_rot.c
*/
void			ssp_custom_rot(t_all_data *data, size_t size);
size_t			max_rot_bw_non_lis(t_llist *a, t_llist *lis);

/*
**	pusha_custom_rot.c
*/
size_t			max_rot_bw_non_pusha(int *arr);
void			pusha_custom_rot(t_all_data *data, t_arr *arr, int rev);

/*
**	pile_utils.c
*/
t_llist			*rot_pile(size_t rot_count, t_llist *pile, int rev);
int				len_b(t_llist_tmp *b);
int				is_destof(t_llist_tmp *b, int dest);

/*
**	error.c
*/
void			error(void);

/*
**	get_lis_utils.c
*/
void			squeeze_lis(int *arr, int size, int *index_arr);
void			ft_tabcpy_n_add(int *const dst, const int *const src,
								int size, const int add);
int				ft_max(int a, int b);

/*
**	push_a_tab_rot.c
*/
void			push_a_tab_rot(size_t len_arr, int *arr, t_all_data *all_data);
void			push_a_tab_reverse_rot(size_t len_arr, t_arr *arr,
										t_all_data *all_data);

/*
**	push_a_tab.c
*/
int				push_a_tab(t_arr *arr, t_all_data *all_data, int rev);

/*
**	rot_op.c
*/
void			rot_a(t_all_data *data, int rev);
void			rot_b(t_all_data *data, int rev);

#endif
