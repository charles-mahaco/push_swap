#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdlib.h>
# include <unistd.h>
# include "get_next_line.h"

typedef struct s_stack
{
	int			*val;
	int			len;
	int			len_max;
	int			midpoint;
	int			highest;
	int			lowest;
	int			high_path;
	int			low_path;
	int			real_high_path;
	int			real_low_path;
	int			sorted_ahead;
	int			high_sorted_ahead;
	int			possible_rr;
	int			bottom;
	char		stack_id;
	float		sort_turn;
	float		sort_step;
	int			previous_midpoint;
}				t_stack;

size_t			ft_strlen(char *s);
int				abs_value(int a);
void			*ft_calloc(size_t count, size_t size);
void			*ft_memcpy(void *dst, const void *src, size_t n);
int				ft_atoi(const char *str);
void			malloc_error(void);
int				ft_strcmp(const char *s1, const char *s2);
void			stack_init(t_stack *s, int len, char id);
int				check_duplicates(t_stack *s_a, t_stack *s_b);
int				check_int_overflow(char *str);
int				check_argv(char *str, t_stack *s_a, t_stack *s_b);
void			sort_three(t_stack *s_a);
void			sort_four(t_stack *s_a, t_stack *s_b);
void			sort_five(t_stack *s_a, t_stack *s_b);
void			short_sort(t_stack *s_a, t_stack *s_b, int len);
int				is_next_low_high(t_stack *s_b, int high);
void			sab(t_stack *s_a);
void			pab(t_stack *s_a, t_stack *s_b);
void			rab(t_stack *s_a);
void			rrab(t_stack *s_a);
void			ss(t_stack *s_a, t_stack *s_b);
void			rr(t_stack *s_a, t_stack *s_b);
void			rrr(t_stack *s_a, t_stack *s_b);
void			sort_median(t_stack *s_a, int len);
void			get_limits(t_stack *s_a, int len);
void			shortest_path(t_stack *s_a, int len);
int				get_to_be_sorted(t_stack *s_b);
void			do_shortest_path(t_stack *s_a, t_stack *s_b, int to_be_sorted);
void			do_sorted_ahead(t_stack *s_a, t_stack *s_b, int to_be_sorted);
void			fill_b(t_stack *s_a, t_stack *s_b);
void			quick_sort(t_stack *s_a, t_stack *s_b, int len);
void			quick_sort_b(t_stack *s_a, t_stack *s_b, int len);
void			large_sort(t_stack *s_a, t_stack *s_b);
void			large_sort_b(t_stack *s_a, t_stack *s_b);
int				is_sorted(t_stack *s_a, t_stack *s_b, int to_free);

#endif