#ifndef CORE_H
# define CORE_H

# include <GLFW/glfw3.h>

# define PI					(3.14159265)
# define BLOC1				(1)
# define BLOC2				(2)
# define BLOC3				(3)
# define NB					(3)
# define NLEVEL				(3)
# define GRID_WIDTH			(15)
# define GRID_HEIGHT		(30)
# define BLOC_WIDTH			(48)
# define BLOC_HEIGHT		(16)
# define PLAYER_WIDTH		(96)
# define PLAYER_HEIGHT		(16)
# define PLAYER_SPEED		(6)
# define LEVEL_X			(BLOC_WIDTH / 2)
# define LEVEL_Y			(BLOC_HEIGHT)
# define LEVEL_WIDTH		((GRID_WIDTH) * (BLOC_WIDTH))
# define LEVEL_HEIGHT		((GRID_HEIGHT) * (BLOC_HEIGHT))
# define SCORE_WIDTH		(220)
# define WINDOW_WIDTH		(LEVEL_WIDTH + BLOC_WIDTH + SCORE_WIDTH)
# define WINDOW_HEIGHT		(LEVEL_HEIGHT + BLOC_HEIGHT)
# define BALL_SPEED			(5)
# define BALL_RADIUS		(3.0f)

typedef struct			s_vec
{
	float				x;
	float				y;
}						t_vec;

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
	float				color[3];
	int					type;
	int					life;
}						t_bloc;

typedef struct			s_level
{
	float				x;
	float				y;
	t_bloc				**grid;
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
	t_vec				v;
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
	int					score;
	GLFWwindow			*window;
	int					cl;
	t_level				*levels;
	t_player			player;
	t_ui				ui;
	t_ball				ball;
	t_border			b[3];
}						t_core;

int						init(t_core *c);
void					error_callback(int error, const char *description);
int						slen(char const *str);
void					release_resources(t_core *c);
char					*itoa(int n);
int						load_level(t_core *c, char const *name, int l);
int						intersects(t_circle *c, t_rect *r);
int						init_levels(t_core *c);
void					init_player(t_core *c);
void					init_ui(t_core *c);
void					init_ball(t_core *c);
void					fill_level_line(t_bloc *bline, char *line);
int						check_line_errors(char *line);
int						allocate_level(t_level *l);
float					op_abs(float v);
float					op_pow2(float v);

#endif