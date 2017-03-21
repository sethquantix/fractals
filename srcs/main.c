/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cchaumar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/21 05:31:19 by cchaumar          #+#    #+#             */
/*   Updated: 2017/03/21 05:31:19 by cchaumar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "viewer.h"

t_env	e;

void	display_fps(GLFWwindow *win, char *name)
{
	static int		fps = 0;
	static int		frames = 0;
	static double	t0 = 0;
	double			t1;

	t1 = glfwGetTime();
	frames++;

	if (t1 - t0 > 1.0)
	{
		t0 = t1;
		if (fps != frames)
		{
			name = ft_strjoin(name, " : ");
			name = ft_strjoinfree(name, ft_itoa(frames), 3);
			name = ft_strjoinfree(name, " fps", 1);
			glfwSetWindowTitle(win, name);
			free(name);
		}
		fps = frames;
		frames = 0;
	}
}

int		init_vao(t_program *programs)
{
	const float	points[] = {
		-1.0f, -1.0f, -1.0f, 1.0f, 1.0f, 1.0f,
		1.0f, 1.0f, 1.0f, -1.0f, -1.0f, -1.0f};
	GLuint		vbo;
	GLuint		fragPos;
	GLuint		vao;

	glGenBuffers(1, &vbo);
	glBindBuffer(GL_ARRAY_BUFFER, vbo);
	glBufferData(GL_ARRAY_BUFFER, sizeof(points), points, GL_STATIC_DRAW);
	glGenVertexArray(1, &vao);
	glBindVertexArray(vao);
	glBindBuffer(GL_ARRAY_BUFFER, vbo);
	fragPos = glGetAttribLocation(program->id, "fragPosition");
	glEnableVertexAttribPointer(fragPos, 2, GL_FLOAT, GL_FALSE,
		sizeof(float) * 2, NULL);
	glBindVertexArray(0);
	return (vao);
}

void	loop(t_env *e)
{
	
}

int		main(int ac, char **av)
{
	char		*name;

	ft_bzero(&e, sizeof(t_env));
	(void)ac;
	name = av[1];
	e.win = init(name);
	e.window = (t_win){WIN_WIDTH, WIN_HEIGHT};
	e.vao = init_vao(e.program);
	while (!glfwWindowShouldClose(e.win))
	{
		display_fps(e.win, name);
		loop(&e);
		glfwPollEvents();
	}
}
