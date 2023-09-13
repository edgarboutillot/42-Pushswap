/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edboutil <edboutil@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/19 16:39:17 by edboutil          #+#    #+#             */
/*   Updated: 2023/05/12 15:32:08 by edboutil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

// INCLUDE ------------------------------------------------
# include <stdlib.h>
# include <limits.h>
# include <unistd.h>

// TYPEDEF ------------------------------------------------
typedef long long int	t_ll;
typedef struct s_list	t_list;
typedef enum e_exit		t_exit;
typedef enum e_bool		t_bool;

// STRUCT -------------------------------------------------
struct s_list
{
	int		data;
	t_list	*next;
};

// ENUM ---------------------------------------------------
enum e_bool
{
	FALSE,
	TRUE
};

enum e_fd
{
	STDIN,
	STDOUT,
	STDERR,
};

enum e_exit
{
	SUCCESS,
	ERROR,
	ERROR_MALLOC,
};

// PARSING ------------------------------------------------
t_exit		parsing(char **av, t_list **lst);

// ALGO ---------------------------------------------------
void		find_min(t_list *top_a);
t_exit		set_index(t_list *top_a);
t_bool		nth_bit_is_set(int n, int number);
void		solve_radix(t_list **top_a, t_list **top_b);
void		for_each(t_list **top_a, t_list **top_b, int n);
void		solve(t_list **top_a, t_list **top_b);

// INSTRUCTIONS -------------------------------------------
void		swap_a(t_list **top_a);
void		push_all_a(t_list **top_a, t_list **top_b);
void		swap_b(t_list **top_b);
void		swap_both(t_list **top_a, t_list **top_b);
void		reverse_rotate_a(t_list **top_a);
void		reverse_rotate_b(t_list **top_b);
void		reverse_rotate_both(t_list **top_a, t_list **top_b);
void		rotate_a(t_list **top_a);
void		rotate_b(t_list **top_b);
void		rotate_both(t_list **top_a, t_list **top_b);
void		push_a(t_list **top_a, t_list **top_b);
void		push_b(t_list **top_a, t_list **top_b);

// UTILS --------------------------------------------------
t_ll		ft_atoi(const char *str);
t_bool		is_number(char *str);

void		put_str_fd(char *str, int fd);

t_list		*ft_lst_new(int data);
t_list		*ft_lstlast(t_list *lst);
int			ft_lst_size(t_list *top_a);
void		ft_lstadd_front(t_list **lst, t_list *new);
t_bool		ft_lst_is_sort(t_list *top_a);
int			ft_lst_max(t_list *top_a);
int			ft_lst_get_index(t_list *top_a, int value);
void		ft_lstadd_back(t_list **lst, int data);
void		ft_lstclear(t_list *lst);

#endif
