/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdavid <rdavid@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/05/02 21:25:50 by rdavid            #+#    #+#             */
/*   Updated: 2015/05/02 21:25:50 by rdavid           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <fcntl.h>
#include <stdlib.h>
#include <unistd.h>
#include "core.h"

void		error_callback(int error, const char *description)
{
	int		v;

	v = write(2, description, slen(description));
	(void)v;
	(void)error;
}

void		key_callback(GLFWwindow *window, int key, int scancode,
						int action, int mods)
{
	(void)scancode;
	(void)mods;
	if (key == GLFW_KEY_ESCAPE && action == GLFW_PRESS)
		glfwSetWindowShouldClose(window, GL_TRUE);
}

int			fill_font_letter(t_font *f, unsigned char l, char *buf)
{
	int		x;
	int		y;

	y = -1;
	while (++y < f->ch)
	{
		x = -1;
		while (++x < f->cw)
			f->c[l][y][x] = buf[y * (f->cw + 1) + x];
	}
	return (1);
}

int			parse_font(t_font *f, char *n)
{
	int const		lsize = f->cw * f->ch + f->ch;
	char			p[2];
	char			l[lsize];
	int				fd;
	int				e[2];

	if ((fd = open(n, O_RDONLY, 0755)) == -1)
		return (0);
	while (42)
	{
		e[0] = read(fd, p, 2);
		e[1] = read(fd, l, lsize);
		if (e[0] == -1 || e[1] == -1)
			return (close(fd));
		if (!e[0] || !e[1] || e[0] != 2 || e[1] != lsize)
			break;
		if (!fill_font_letter(f, p[0], l))
			return (close(fd));
	}
	return (!close(fd));
}

t_font		*load_font(char *filename)
{
	t_font	*nf;

	if (!(nf = malloc(sizeof(t_font))))
		return (NULL);
	nf->cw = 5;
	nf->ch = 5;
	nf->s = 5;
	nf->p = 2;
	if (!parse_font(nf, filename))
		return (NULL);
	return (nf);
}

void		draw_text(t_font *f, char const *t, float x, float y)
{
	int		i;
	int		j;
	int		px;
	int		py;

	glBegin(GL_QUADS);
	px = x;
	py = y;
	while (*t)
	{
		j = -1;
		while (++j < f->ch)
		{
			i = -1;
			while (++i < f->cw)
			{
				if (f->c[(unsigned char)*t][j][i] == '#')
				{
					glVertex2f(px + i * f->s, py + j * f->s);
					glVertex2f(px + i * f->s + f->s, py + j * f->s);
					glVertex2f(px + i * f->s + f->s, py + j * f->s + f->s);
					glVertex2f(px + i * f->s, py + j * f->s + f->s);
				}
			}
		}
		++t;
		px += f->cw * f->s + f->p;
	}
	glEnd();
}

void		release_resources(t_core *c)
{
	glfwDestroyWindow(c->window);
	glfwTerminate();
}

void		gl_enable_2d(int cam_x, int cam_y)
{
	int			v_port[4];

	glDisable(GL_DEPTH_TEST);
	glGetIntegerv(GL_VIEWPORT, v_port);
	glMatrixMode(GL_PROJECTION);
	glPushMatrix();
	glLoadIdentity();
	glOrtho(cam_x, v_port[2] + cam_x, v_port[3] + cam_y, cam_y, -0.001, 0.001);
	glMatrixMode(GL_MODELVIEW);
	glPushMatrix();
	glLoadIdentity();
}

void		gl_disable_2d(void)
{
	glMatrixMode(GL_PROJECTION);
	glPopMatrix();
	glMatrixMode(GL_MODELVIEW);
	glPopMatrix();
	glEnable(GL_DEPTH_TEST);
}

void		set_vec(t_vec *v, float x, float y)
{
	v->x = x;
	v->y = y;
}

void		init_player(t_core *c)
{
	c->player.lives = 3;
	c->player.x = (LEVEL_WIDTH / 2) - (PLAYER_WIDTH / 2);
	c->player.y = LEVEL_HEIGHT - BLOC_HEIGHT;
}

void		init_ui(t_core *c)
{
	c->ui.x = 0;
	c->ui.y = 0;
}

void		init_ball(t_core *c)
{
	c->ball.c.r = BALL_RADIUS;
	c->ball.c.p.x = c->player.x + PLAYER_WIDTH / 2;
	c->ball.c.p.y = c->player.y - c->ball.c.r;
	set_vec(&c->ball.v, BALL_SPEED, -BALL_SPEED);
}

void		init_color(float *c, float r, float g, float b)
{
	c[0] = r;
	c[1] = g;
	c[2] = b;
}

void		init_left_border(t_border *b)
{
	init_color(b->c, 0.6f, 0.6f, 0.6f);
	b->x = 0;
	b->y = BLOC_HEIGHT;
	b->w = BLOC_WIDTH / 2;
	b->h = LEVEL_HEIGHT;
}

void		init_right_border(t_border *b)
{
	init_color(b->c, 0.6f, 0.6f, 0.6f);
	b->x = LEVEL_WIDTH + BLOC_WIDTH / 2;
	b->y = BLOC_HEIGHT;
	b->w = BLOC_WIDTH / 2;
	b->h = LEVEL_HEIGHT;
}

void		init_up_border(t_border *b)
{
	init_color(b->c, 0.6f, 0.6f, 0.6f);
	b->x = 0;
	b->y = 0;
	b->w = LEVEL_WIDTH + BLOC_WIDTH;
	b->h = BLOC_HEIGHT;
}

void		init_borders(t_core *c)
{
	init_left_border(&c->b[0]);
	init_right_border(&c->b[1]);
	init_up_border(&c->b[2]);
}

int			init_font(t_core *c)
{
	if (!(c->rdf = load_font("font.rdf")))
		return (!write(2, "Failed to load font !\n", 22));
	return (1);
}

int			init(t_core *c)
{
	if (!glfwInit())
		return (0);
	c->window = glfwCreateWindow(WINDOW_WIDTH, WINDOW_HEIGHT,
								"Arkanoid", NULL, NULL);
	if (!c->window)
	{
		glfwTerminate();
		return (0);
	}
	glfwMakeContextCurrent(c->window);
	glfwSwapInterval(1);
	glfwSetKeyCallback(c->window, key_callback);
	c->score = 0;
	c->cl = 0;
	c->levels = NULL;
	init_player(c);
	init_ui(c);
	init_ball(c);
	init_borders(c);
	if (!init_font(c))
		return (0);
	if (!init_levels(c))
		return (0);
	return (1);
}

float		op_pow2(float v)
{
	return (v * v);
}

float		op_abs(float v)
{
	if (v < 0)
		return (-v);
	return (v);
}

int			intersects(t_circle *c, t_rect *r)
{
	float	corner_dist;
	t_vec	dist;

	dist.x = op_abs(c->p.x - r->p.x);
	dist.y = op_abs(c->p.y - r->p.y);
	if (dist.x > (r->w / 2.0f + c->r))
		return (0);
	if (dist.y > (r->h / 2.0f + c->r))
		return (0);
	if (dist.x <= (r->w / 2.0f))
		return (1);
	if (dist.y <= (r->h / 2.0f))
		return (1);
	corner_dist = op_pow2(dist.x - r->w / 2.0f) +
					op_pow2(dist.y - r->h / 2.0f);
	return (corner_dist <= (op_pow2(c->r)));
}

int			check_line_errors(char *line)
{
	(void)line;
	return (1);
}

void		fill_level_line(t_bloc *bline, char *line)
{
	int					i;
	int					id;
	static float const	c[NB][3] =

	{ { 1.0f, 0.0f, 0.0f }, { 0.0f, 1.0f, 0.0f }, { 0.0f, 0.0f, 1.0f } };
	i = -1;
	while (++i < GRID_WIDTH)
	{
		if (line[i] != '.')
		{
			id = line[i] - 48;
			bline[i].color[0] = c[id - 1][0];
			bline[i].color[1] = c[id - 1][1];
			bline[i].color[2] = c[id - 1][2];
			bline[i].type = id;
			bline[i].life = id;
		}
		else
		{
			bline[i].type = 0;
			bline[i].life = 0;
		}
	}
}

int			allocate_level(t_level *l)
{
	int		i;

	if (!(l->grid = (t_bloc **)malloc(sizeof(t_bloc *) * GRID_HEIGHT)))
		return (0);
	i = -1;
	while (++i < GRID_HEIGHT)
	{
		if (!(l->grid[i] = (t_bloc *)malloc(sizeof(t_bloc) * GRID_WIDTH)))
			return (0);
	}
	return (1);
}

void		draw_bloc(t_bloc *b, float x, float y)
{
	glColor3f(b->color[0], b->color[1], b->color[2]);
	glBegin(GL_QUADS);
	glVertex2f(x + 1, y + 1);
	glVertex2f(x + BLOC_WIDTH - 2, y + 1);
	glVertex2f(x + BLOC_WIDTH - 2, y + BLOC_HEIGHT - 2);
	glVertex2f(x + 1, y + BLOC_HEIGHT - 2);
	glEnd();
}

void		draw_bloc_borders(float x, float y)
{
	glColor3f(1.0f, 1.0f, 1.0f);
	glBegin(GL_LINES);
	glVertex2f(x, y);
	glVertex2f(x + BLOC_WIDTH, y);
	glVertex2f(x + BLOC_WIDTH, y);
	glVertex2f(x + BLOC_WIDTH, y + BLOC_HEIGHT);
	glVertex2f(x + BLOC_WIDTH, y + BLOC_HEIGHT);
	glVertex2f(x, y + BLOC_HEIGHT);
	glVertex2f(x, y + BLOC_HEIGHT);
	glVertex2f(x, y);
	glEnd();
}

int			intersect_up(t_circle *c, float x, float y, float s)
{
	if (c->p.x >= x && c->p.x <= x + s
		&& c->p.y + c->r > y && c->p.y - c->r < y)
		return (1);
	return (0);
}

int			intersect_down(t_circle *c, float x, float y, float s)
{
	if (c->p.x >= x && c->p.x <= x + s
		&& c->p.y + c->r < y && c->p.y - c->r > y)
		return (1);
	return (0);
}

int			intersect_left(t_circle *c, float x, float y, float s)
{
	if (c->p.y >= y && c->p.y <= y + s
		&& c->p.x + c->r > x && c->p.x - c->r < x)
		return (1);
	return (0);
}

int			intersect_right(t_circle *c, float x, float y, float s)
{
	if (c->p.y >= y && c->p.y <= y + s
		&& c->p.x + c->r < x && c->p.x - c->r > x)
		return (1);
	return (0);
}

int			intersect_block(t_circle *c, float x, float y, float s)
{
	if (intersect_up(c, x, y, s)
		|| intersect_down(c, x, y, s)
		|| intersect_left(c, x, y, s)
		|| intersect_right(c, x, y, s))
		return (1);
	return (0);
}
/*
void		new_ball_direction(t_circle *c, float x, float y)
{

}
*/
void		update_ball(t_core *c)
{
	// int					x;
	// int					y;

	// x = c->ball.c.p.x / BLOC_WIDTH - 1;
	// y = c->ball.c.p.y / BLOC_HEIGHT - 1;
/*	dprintf(2, "x: %d, y: %d\n", x, y);
	if (x > 0 && y > 0 && x < GRID_WIDTH && y < GRID_HEIGHT)
		draw_bloc_borders(LEVEL_X + x * BLOC_WIDTH, LEVEL_Y + y * BLOC_HEIGHT);*/
	c->ball.c.p.x += c->ball.v.x;
	c->ball.c.p.y += c->ball.v.y;
}

void		draw_current_level(t_core *c)
{
	int		x;
	int		y;

	y = -1;
	while (++y < GRID_HEIGHT)
	{
		x = -1;
		while (++x < GRID_WIDTH)
		{
			if (c->levels[c->cl].grid[y][x].type != 0)
			{
				draw_bloc(&c->levels[c->cl].grid[y][x],
						LEVEL_X + x * BLOC_WIDTH, LEVEL_Y + y * BLOC_HEIGHT);
			}
		}
	}
}

void		draw_borders(t_border *b, int n)
{
	int		i;

	glBegin(GL_QUADS);
	i = -1;
	while (++i < n)
	{
		glColor3f(b[i].c[0], b[i].c[1], b[i].c[2]);
		glVertex2f(b[i].x, b[i].y);
		glVertex2f(b[i].x + b[i].w, b[i].y);
		glVertex2f(b[i].x + b[i].w, b[i].y + b[i].h);
		glVertex2f(b[i].x, b[i].y + b[i].h);
	}
	glEnd();
}

void		draw_player(t_player *p)
{
	glColor3f(1.0f, 0.67f, 0.0f);
	glBegin(GL_QUADS);
	glVertex2f(p->x, p->y);
	glVertex2f(p->x + PLAYER_WIDTH, p->y);
	glVertex2f(p->x + PLAYER_WIDTH, p->y + PLAYER_HEIGHT);
	glVertex2f(p->x, p->y + PLAYER_HEIGHT);
	glEnd();
}

void		draw_ui(t_core *c)
{
	draw_borders(c->b, 3);
}

void		draw_ball(t_ball *b)
{
	glColor3f(1.0f, 1.0f, 1.0f);
	glBegin(GL_QUADS);
	glVertex2f(b->c.p.x - b->c.r, b->c.p.y - b->c.r);
	glVertex2f(b->c.p.x + b->c.r, b->c.p.y - b->c.r);
	glVertex2f(b->c.p.x + b->c.r, b->c.p.y + b->c.r);
	glVertex2f(b->c.p.x - b->c.r, b->c.p.y + b->c.r);
	glEnd();
}

int			load_level(t_core *c, char const *name, int l)
{
	int		fd;
	int		i;
	char	buf[GRID_WIDTH + 1];
	int		ret;

	if (!allocate_level(&c->levels[l]))
		return (0);
	if ((fd = open(name, O_RDONLY, 0755)) == -1)
		return (0);
	i = -1;
	while (++i < GRID_HEIGHT + 2)
	{
		ret = read(fd, buf, GRID_WIDTH + 1);
		if (buf[GRID_WIDTH] != '\n')
			return (close(fd));
		if (ret == -1)
			return (close(fd));
		if (ret == 0)
			return (!close(fd));
		if (!check_line_errors(buf))
			return (close(fd));
		fill_level_line(c->levels[l].grid[i], buf);
	}
	return (!close(fd));
}

int			init_levels(t_core *c)
{
	int						i;
	static char const		*n[NLEVEL] =

	{ "levels/1", "levels/2", "levels/3" };
	if (!(c->levels = (t_level *)malloc(sizeof(t_level) * NLEVEL)))
		return (0);
	i = -1;
	while (++i < NLEVEL)
	{
		if (!load_level(c, n[i], i))
		{
			if (write(2, "Missing level !\n", 16) == -1)
				return (0);
			return (0);
		}
	}
	return (1);
}

void		inputs(t_core *c)
{
	if (glfwGetKey(c->window, GLFW_KEY_LEFT) == GLFW_PRESS)
	{
		if (c->player.x >= LEVEL_X + PLAYER_SPEED)
			c->player.x -= PLAYER_SPEED;
	}
	if (glfwGetKey(c->window, GLFW_KEY_RIGHT) == GLFW_PRESS)
	{
		if (c->player.x + PLAYER_WIDTH <= LEVEL_X + LEVEL_WIDTH - PLAYER_SPEED)
			c->player.x += PLAYER_SPEED;
	}
}

void		update(t_core *c)
{
	update_ball(c);
}

void		render(t_core *c)
{
	draw_ui(c);
	draw_current_level(c);
	draw_player(&c->player);
	draw_ball(&c->ball);
	glColor3f(1.0f, 1.0f, 1.0f);
	draw_text(c->rdf, "SCORE", LEVEL_WIDTH + BLOC_WIDTH + 20, BLOC_HEIGHT);
}

void		loop(t_core *c)
{
	gl_enable_2d(0, 0);
	while (!glfwWindowShouldClose(c->window))
	{
		glClear(GL_COLOR_BUFFER_BIT);
		inputs(c);
		update(c);
		render(c);
		glfwSwapBuffers(c->window);
		glfwPollEvents();
	}
	gl_disable_2d();
}

int			main(int argc, char **argv)
{
	t_core		c;

	if (!init(&c))
		return (0);
	loop(&c);
	release_resources(&c);
	(void)argc;
	(void)argv;
	return (1);
}
