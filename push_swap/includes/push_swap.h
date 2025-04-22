/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilarhrib <ilarhrib@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/20 15:16:43 by ilarhrib          #+#    #+#             */
/*   Updated: 2025/03/05 20:42:08 by ilarhrib         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <stdarg.h>
# include <limits.h>

typedef struct s_list
{
	int				nb;
	int				index;
	int				pos;
	int				target_pos;
	int				cost_a;
	int				cost_b;
	struct s_list	*next;
}	t_stack;

void	pa(t_stack **a, t_stack **b);
void	pb(t_stack **a, t_stack **b);
void	sa(t_stack **a);
void	sb(t_stack **b);
void	ss(t_stack **a, t_stack **b);
void	ra(t_stack **a);
void	rb(t_stack **b);
void	rr(t_stack **a, t_stack **b);
void	rra(t_stack **a);
void	rrb(t_stack **b);
void	rrr(t_stack **a, t_stack **b);
void	ft_assign_pos(t_stack **stack_a, t_stack **stack_b);
int		is_sorted(t_stack *s_a);
int		ft_abs(int n);
void	sort_small(t_stack **a);
void	sort_exe(t_stack **a, t_stack **b);
void	sort_tree(t_stack **a);
void	push_b(t_stack **a, t_stack **b);
int		ft_lstsize(t_stack *lst);
void	assign_index(t_stack **s_a);
t_stack	*ft_lstlast(t_stack *lst);
t_stack	*ft_lstnew(int value);
void	handle_node(t_stack *new_node);
void	dup_arg_check(t_stack **stack_a);
void	ft_assign_pos(t_stack **stack_a, t_stack **stack_b);
void	push_a(t_stack **s_a, int ac, char **av);
void	ft_lstclear(t_stack **lst);
void	ft_lstadd_back(t_stack **lst, t_stack *new);
char	**ft_split(char const *s, char c);
void	ft_free(char **ptr);
void	input_check(int ac, char **av);
void	close_error(void);
long	ft_atoi(const char *str);
void	check_range(char *str);
void	handle_failure(char **str);
void	digit_check(char *str);
int		ft_strcmp(const char *s1, const char *s2);
void	dup_check(char **str);
size_t	ft_strlen(const char *str);
int		ft_printf(const char *format, ...);
int		ft_putchar(char c);
int		ft_putstr(char *str);
int		ft_putnbr(int nb);
int		ft_put_unsigned(unsigned int nb);
int		ft_put_hexa(unsigned int num, const char format);
void	ft_hexa_converter(unsigned int num, const char format);
int		ft_hexa_len(unsigned int num);
int		ft_put_ptr(unsigned long num);
void	final_rotate(t_stack **a);
void	ft_best_move(t_stack **stack_a, t_stack **stack_b,
			int a_cost, int b_cost);
void	ft_positon(t_stack **stack);
void	ft_fill_stack(char **str, t_stack **stack);
void	ft_free_stack(t_stack **stack);
t_stack	*ft_last(t_stack *stack);
t_stack	*ft_before_last(t_stack *stack);
t_stack	*ft_lst_new(int value);
void	ft_lst_add_back(t_stack **stack, t_stack *new);
void	ft_push_to_b(t_stack **stack_a, t_stack **stack_b);
void	ft_putchar_fd(char c, int fd);
void	ft_putstr_fd(char *s, int fd);
void	check_what_to_sort(t_stack **first, t_stack **second,
			t_stack **third, t_stack **a);
int		ft_is_digit(char c);
void	ft_stack_shift(t_stack **stack_a);
void	ft_cost(t_stack **stack_a, t_stack **stack_b);
void	ft_cheapest(t_stack **stack_a, t_stack **stack_b);

#endif
