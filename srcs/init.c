/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cchaumar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/21 05:37:23 by cchaumar          #+#    #+#             */
/*   Updated: 2017/03/21 05:37:25 by cchaumar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "viewer.h"

static void glfw_error(int err, const char* desc)
{
	ft_dprintf(2, "error (%d) : %s\n", err, desc);
}

static void	glfw_resize(GLFWwindow *win, int w, int h)
{
	(void)win;
	e.window = (t_win){w, h};
}

GLFWwindow	*init(char *name)
{
	GLFWwindow *win;

	glfwSetErrorCallback(glfw_error);
	if (!glfwInit())
		die("glfwInit error !\n", EXIT_FAILURE);
	glfwWindowHint(GLFW_SAMPLES, 4);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
 	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 2);
 	glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE);
 	glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
	if (!(win = glfwCreateWindow(WIN_WIDTH, WIN_HEIGHT, name, NULL, NULL)))
		die("failed to create window !\n", EXIT_FAILURE);
	// glfwSetKeyCallback(win, key_callback);
	// glfwSetCursorPosCallback(win, mouse_callback);
	// glfwSetMouseButtonCallback(win, mouse_click_callback);
	// glfwSetScrollCallback(win, mouse_scroll_callback);
	glfwSetWindowSizeCallback(win, glfw_resize);
	glfwMakeContextCurrent(win);
	glfwSwapInterval(1);
	glfwSetInputMode(win, GLFW_CURSOR, GLFW_CURSOR_DISABLED);
	set_keys();
	return (win);
}
