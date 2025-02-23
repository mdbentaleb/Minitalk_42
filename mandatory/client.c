/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moben-ta <moben-ta@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/31 18:15:22 by moben-ta          #+#    #+#             */
/*   Updated: 2025/02/12 18:14:57 by moben-ta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./minitalk.h"

static void	ft_send_char_bit(char c, int pid)
{
	int	i;

	i = 7;
	while (i >= 0)
	{
		if (c >> i & 1)
			kill(pid, SIGUSR1);
		else
			kill(pid, SIGUSR2);
		i--;
		usleep(500);
	}
}

static void	ft_send_message(char *str, int pid)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
	{
		ft_send_char_bit(str[i], pid);
		i++;
	}
	ft_send_char_bit('\0', pid);
}

int	main(int arc, char **arv)
{
	int	pid;

	if (arc == 3)
	{
		pid = check_args_error(arv);
		ft_send_message(arv[2], pid);
	}
	else
		ft_printf("⚠️  %sUsage%s: %s <PID> <message>\n", YELLOW, RESET, arv[0]);
	return (0);
}
