#ifndef CORE_H
# define CORE_H

# include <GLFW/glfw3.h>

# define BLOC1			1
# define BLOC2			2
# define BLOC3			3

# define NB				3

# define GRID_WIDTH		15
# define GRID_HEIGHT	30

# define BLOC_WIDTH		48
# define BLOC_HEIGHT	16

# define LEVEL_WIDTH	((GRID_WIDTH) * (BLOC_WIDTH))
# define LEVEL_HEIGHT	((GRID_HEIGHT) * (BLOC_HEIGHT))

typedef struct			s_vec
{
	float				x;
	float				y;
}						t_vec;

typedef struct			s_level
{
	char				*grid;
}						t_level;

typedef struct			s_bloc
{
	int					type;
	int					life;
}						t_bloc;

typedef struct			s_player
{
	int					size;
	int					x;
	int					y;
}						t_player;

typedef struct			s_ball
{
	int					x;
	int					y;
	t_vec				v;
}						t_ball;

typedef struct			s_core
{
	GLFWwindow			*window;
	t_level				*current_level;

}						t_core;

// to implement

void					load_level(t_core *c, int i);
void					draw_level(t_core *c);

//

void					error_callback(int error, const char *description);
int						slen(char const *str);
void					release_resources(t_core *c);
int						init(t_core *c);

#endif