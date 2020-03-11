/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   t_lst.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: awoimbee <awoimbee@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/05 23:56:12 by awoimbee          #+#    #+#             */
/*   Updated: 2020/03/11 19:22:24 by awoimbee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef T_LST_H
# define T_LST_H

# include <stddef.h>
# include <sys/types.h>

typedef void		t_listed;

typedef struct	s_list
{
	t_listed		*content;
	size_t			content_size;
	struct s_list	*next;
}				t_list;

t_list			*ft_lstnew(void const *content, size_t content_size);
void			ft_lstdelone(t_list **alst, void (*del)(t_listed*, size_t));
void			ft_lstdel(t_list **alst, void (*del)(t_listed*, size_t));
void			ft_lstadd(t_list **alst, t_list *new);
void			ft_lstiter(t_list *lst, void (*f)(t_list *elem));
t_list			*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem));
t_list			*ft_lst_push_back(t_list **lst, t_listed *data, size_t d_size);
t_list			*ft_list_at(t_list *begin_list, unsigned int nbr);
int				ft_lst_free_link(t_list **lst, t_list *link);

#endif
