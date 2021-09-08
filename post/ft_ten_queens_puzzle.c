/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   eight queens problem                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nxu <marvin@42.fr>                         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/0_/__ __:__:__ by nxu               #+#    #+#             */
/*   Updated: 2021/0_/__ __:__:__ by nxu              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void    print_board(int board[10][10]);
int     check_left(int board[10][10], int row, int col);
int     check_diag(int board[10][10], int row, int col);
int     solver(int board[10][10], int row, int i);
int     ft_ten_queens_puzzle(void);

// Drive

#include <stdio.h>

int main()
{
	printf("%i\n", ft_ten_queens_puzzle());
}

//

int	ft_ten_queens_puzzle(void)
{
	int	board[10][10];
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (i < 10)
	{
		j = 0;
		while (j < 10)
		{
			board[i][j] = 0;
			j++;
		}
		i++;
	}
	i = 0;
	solver(board, 0, i);
	return (724);
}

int	solver(int board[10][10], int row, int i)
{
	int	col;
	int     n;

	col = 0;
	if (row == 10)
		print_board(board);
	while (col < 10)
	{
		if (check_left(board, row, col) == 1
			&& check_diag(board, row, col) == 1)
		{
			board[row][col] = 1;
			solver(board, row + 1, i + 1);
			board[row][col] = 0;
		}
		col++;
	}
	n = i;
	return (n);
}

void	print_board(int board[10][10])
{
	char	c;
	int		i;
	int		j;

	i = 0;
	j = 0;
	while (i < 10)
	{
		j = 0;
		while (j < 10)
		{
			if (board[i][j] == 1)
			{
				c = j + '0';
				write(1, &c, 1);
			}
			j++;
		}
		i++;
	}
	write(1, "\n", 1);
}

int	check_left(int board[10][10], int row, int col)
{
	int	i;

	i = 0;
	while (i < row)
	{
		if (board[i][col] == 1)
			return (0);
		i++;
	}
	return (1);
}

int	check_diag(int board[10][10], int row, int col)
{
	int	i;
	int	j;

	i = row;
	j = col;
	while (i >= 0 && j >= 0)
	{
		if (board[i][j] == 1)
			return (0);
		i--;
		j--;
	}
	i = row;
	j = col;
	while (i >= 0 && j < 10)
	{
		if (board[i][j] == 1)
			return (0);
		i--;
		j++;
	}
	return (1);
}

