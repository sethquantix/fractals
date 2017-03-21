/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   inputs.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cchaumar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/21 06:37:08 by cchaumar          #+#    #+#             */
/*   Updated: 2017/03/21 06:37:08 by cchaumar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "viewer.h"

static t_key	*new_key(int keycode, int action, t_key_f f)
{
	t_key	*k;

	k = try(sizeof(t_key));
	k->keycode = keycode;
	k->action = action;
	k->func = f;
	return (k);
}

static void		add_key(t_list *keys, int keycode, int action, t_key_f f)
{
	t_list	*node;

	node = ft_lstnew(NULL, 0);
	node->content = new_key(keycode, action, f);
	ft_lstadd_end(&keys, node);
}

static void		quit(t_env *e, int keycode)
{
	(void)keycode;
	glfwSetWindowShouldClose(e->win, GLFW_TRUE);
}

static void		move(t_env *e, int keycode)
{
	const t_vec3	vectors[] = {{-1, 0, 0, 0}, {0, -1, 0, 0}, {1, 0, 0, 0},
		{0, 1, 0, 0}, {0, 0, -1, 0}, {0, 0, 1, 0}};
	const int		keys[] = {GLFW_KEY_A, GLFW_KEY_S, GLFW_KEY_D, GLFW_KEY_W,
		GLFW_KEY_Q, GLFW_KEY_E};
	int				i;
	t_vec4			v;

	i = 0;
	while (i < 6)
		if (keys[i] == keycode)
		{
			v = vectors[i];
			break ;
		}
		else
			i++;
	(void)e;
}

void			set_keys(void)
{
	add_key(e.keys, GLFW_KEY_ESCAPE, PRESS, quit);
	add_key(e.keys, GLFW_KEY_A, REPEAT, move);
	add_key(e.keys, GLFW_KEY_S, REPEAT, move);
	add_key(e.keys, GLFW_KEY_D, REPEAT, move);
	add_key(e.keys, GLFW_KEY_W, REPEAT, move);
	add_key(e.keys, GLFW_KEY_Q, REPEAT, move);
	add_key(e.keys, GLFW_KEY_E, REPEAT, move);
}
