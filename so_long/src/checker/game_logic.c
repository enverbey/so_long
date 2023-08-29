/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_logic.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: envyilma <envyilma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/27 15:58:42 by envyilma          #+#    #+#             */
/*   Updated: 2023/08/29 16:50:08 by envyilma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/so_long.h"

void
	test_logic(char **map, int x, int y)
{
	map[x][y] = '.';
	if (map[x + 1][y] == 'E')
		map[x + 1][y] = '.';
	else if (map[x - 1][y] == 'E')
		map[x - 1][y] = '.';
	else if (map[x][y + 1] == 'E')
		map[x][y + 1] = '.';
	else if (map[x][y - 1] == 'E')
		map[x][y - 1] = '.';
	if (map[x + 1][y] == '0' || map[x + 1][y] == 'C')
		test_logic(map, x + 1, y);
	if (map[x - 1][y] == '0' || map[x - 1][y] == 'C')
		test_logic(map, x - 1, y);
	if (map[x][y + 1] == '0' || map[x][y + 1] == 'C')
		test_logic(map, x, y + 1);
	if (map[x][y - 1] == '0' || map[x][y - 1] == 'C')
		test_logic(map, x, y - 1);
}

void
	find_player(char **map, int *x, int *y)
{
	int	i;
	int	j;

	i = 0;
	while (map[i])
	{
		j = 0;
		while (map[i][j])
		{
			if (map[i][j] == 'P')
			{
				*x = i;
				*y = j;
				return ;
			}
			j++;
		}
		i++;
	}
}

int	is_logic(char **map)
{
	int	i;
	int	j;

	i = 0;
	while (map[i])
	{
		j = -1;
		while (++j, map[i][j])
		{
			if (map[i][j] == 'C' || map[i][j] == 'E')
				return (0);
		}
		i++;
	}
	return (1);
}

int	check_game_logic(char **map)
{
	int	x;
	int	y;
	int	result;

	find_player(map, &x, &y);
	test_logic(map, x, y);
	result = is_logic(map);
	free_map(map);
	return (result);
}
