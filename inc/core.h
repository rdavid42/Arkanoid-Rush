/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   core.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdavid <rdavid@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/05/03 22:48:43 by rdavid            #+#    #+#             */
/*   Updated: 2015/05/03 22:48:47 by rdavid           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CORE_H
# define CORE_H

# include <GLFW/glfw3.h>

# define PI				(3.14159265)
# define BLOC1			(1)
# define BLOC2			(2)
# define BLOC3			(3)
# define NB				(4)
# define NLEVEL			(3)
# define GRID_WIDTH		(15)
# define GRID_HEIGHT	(30)
# define BLOC_WIDTH		(48)
# define BLOC_HEIGHT	(24)
# define PLAYER_WIDTH	(96)
# define PLAYER_HEIGHT	(16)
# define PLAYER_SPEED	(6)
# define LEVEL_X		(BLOC_WIDTH / 2)
# define LEVEL_Y		(BLOC_HEIGHT)
# define LEVEL_WIDTH	((GRID_WIDTH) * (BLOC_WIDTH))
# define LEVEL_HEIGHT	((GRID_HEIGHT) * (BLOC_HEIGHT))
# define SCORE_WIDTH	(220)
# define WINDOW_WIDTH	(LEVEL_WIDTH + BLOC_WIDTH + SCORE_WIDTH)
# define WINDOW_HEIGHT	(LEVEL_HEIGHT + BLOC_HEIGHT)
# define BALL_INI_SPEED	(6)
# define BALL_RADIUS	(3.0f)
# define MASS_FACTOR	(0.5)
# define ANGULAR_FACTOR	(0.3f)
# define FRICTION		(1.0f)
# define INI_LIVES		(3)

typedef struct			s_vec
{
	float				x;
	float				y;
}						t_vec;

typedef struct			s_font
{
	unsigned char		c[128][5][5];
	int					cw;
	int					ch;
	int					s;
	int					p;
}						t_font;

typedef struct			s_circle
{
	t_vec				p;
	float				r;
}						t_circle;

typedef struct			s_rect
{
	t_vec				p;
	float				w;
	float				h;
}						t_rect;

typedef struct			s_bloc
{
	int					life;
}						t_bloc;

typedef struct			s_level
{
	float				x;
	float				y;
	t_bloc				**grid;
	int					current_blocks;
}						t_level;

typedef struct			s_player
{
	int					lives;
	float				x;
	float				y;
}						t_player;

typedef struct			s_ball
{
	t_circle			c;
	t_vec				d;
}						t_ball;

typedef struct			s_ui
{
	int					x;
	int					y;
}						t_ui;

typedef struct			s_border
{
	float				c[3];
	float				x;
	float				y;
	float				w;
	float				h;
}						t_border;

typedef struct			s_core
{
	int					win;
	int					game_over;
	int					lives;
	t_font				*rdf;
	int					score;
	GLFWwindow			*window;
	int					cl;
	t_level				*levels;
	t_player			player;
	t_ui				ui;
	t_ball				ball;
	t_border			b[3];
}						t_core;

int						check_blocks_around(t_core *c, int x, int y);
int						check_block_return(t_bloc **g, t_core *c, int px, int py);
int						check_block(int x, int y, int i, t_core *c);
int						allocate_level(t_level *l);
char					*itoa(int n);
int						check_line_errors(char *line);
int						check_platform(t_core *c);
float					dot_product(t_vec const *v1, t_vec const *v2);
void					draw_ball(t_ball *b);
void					draw_bloc(float x, float y);
void					draw_bloc_borders(float x, float y);
void					draw_borders(t_border *b, int n);
void					draw_current_level(t_core *c);
void					draw_game_over(t_core *c);
void					draw_letter_quad(float x, float y, float s);
void					draw_player(t_player *p);
void					draw_text(t_font *f, char const *t, float x, float y);
void					draw_ui(t_core *c);
void					draw_win(t_core *c);
void					error_callback(int error, const char *description);
int						fill_font_letter(t_font *f, unsigned char l, char *buf);
void					fill_level_line(t_level *l, t_bloc *bline, char *line);
t_vec					get_vec(float x, float y);
void					gl_disable_2d(void);
void					gl_enable_2d(int cam_x, int cam_y);
int						init(t_core *c);
void					init_ball(t_core *c);
void					init_borders(t_core *c);
void					init_color(float *c, float r, float g, float b);
int						init_core(t_core *c);
int						init_font(t_core *c);
void					init_left_border(t_border *b);
int						init_levels(t_core *c);
void					init_player(t_core *c);
void					init_right_border(t_border *b);
void					init_ui(t_core *c);
void					init_up_border(t_border *b);
void					inputs(t_core *c);
int						intersects(t_circle *c, t_rect *r);
int						itrs_block(t_circle *c, float x, float y, t_vec s);
int						itrs_h(t_circle *c, float x, float y, float s);
int						itrs_v(t_circle *c, float x, float y, float s);
void					key_callback(GLFWwindow *window, int key, int scancode,
									int action, int mods);
t_font					*load_font(char *filename);
int						load_level(t_core *c, char const *name, int l);
void					loop(t_core *c);
t_vec					new_ball_direction(t_ball *b, t_vec const n);
void					new_ball_direction_paddle(t_ball *b);
float					op_abs(float v);
float					op_pow2(float v);
int						parse_font(t_font *f, char *n);
void					release_levels(t_core *c);
void					release_resources(t_core *c);
void					render(t_core *c);
void					set_vec(t_vec *v, float x, float y);
int						slen(char const *str);
void					update(t_core *c);
void					update_ball(t_core *c);


#endif
