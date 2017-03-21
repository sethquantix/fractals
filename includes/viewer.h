/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   viewer.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cchaumar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/21 05:31:07 by cchaumar          #+#    #+#             */
/*   Updated: 2017/03/21 05:31:11 by cchaumar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VIEWER_H
# define VIEWER_H

# include <stdarg.h>
# include <stdlib.h>
# include <unistd.h>
# include "GL/glew.h"
# include <OpenGL/opengl.h>
# include "GLFW/glfw3.h"
# include "libft.h"

# define WIN_WIDTH	2560
# define WIN_HEIGHT	1440

# define PRESS		GLFW_PRESS
# define RELEASE	GLFW_RELEASE
# define REPEAT		GLFW_REPEAT

typedef struct	s_win
{
	int		w;
	int		h;
}				t_win;

typedef struct	s_env
{
	GLFWwindow	*win;
	t_win		window;
	t_win		fbuffer;
	t_list		*keys;
}				t_env;

typedef struct	s_key
{
	int		keycode;
	int		action;
	void	(*func)(t_env *, int);
	GLuint	vao;
}				t_key;

typedef void	(*t_key_f)(t_env *, int);

extern t_env	e;

GLFWwindow		*init(char *name);
void			set_keys(void);
void			die(const char *format, int exit_code, ...);

#endif
