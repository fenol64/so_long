#include "../src/includes/so_long.h"

void free_split(char **splitted)
{
    int i = 0;
    while (splitted[i])
    {
        free(splitted[i]);
        i++;
    }
    free(splitted);
}

int main()
{
    void *mlx_ptr;
    void *win_ptr;
    mlx_ptr = mlx_init();
	win_ptr = mlx_new_window(mlx_ptr, 900, 500, "Hello World!");
    char *str = "Hello World!\nteste2";
	char **splitted = ft_split(str, '\n');
    int i = 0;
    while (splitted[i])
    {
        mlx_string_put(mlx_ptr, win_ptr, 3, 10 + (i * 15), 0x00FFFFFF, splitted[i]);
        i++;
    }

    free_split(splitted);

    mlx_loop(mlx_ptr);
	mlx_destroy_window(mlx_ptr, win_ptr);
}
