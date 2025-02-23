/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moben-ta <moben-ta@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/31 18:15:15 by moben-ta          #+#    #+#             */
/*   Updated: 2025/02/12 18:15:12 by moben-ta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./minitalk.h"

static void	ft_print_char(char c)
{
	if (c == '\0')
		ft_printf("\n");
	else
		ft_printf("%c", c);
}

static void	ft_set_to_z(int *bit_index, char *curr_char)
{
	*bit_index = 0;
	*curr_char = 0;
}

static void	handle_signal(int signum, siginfo_t *info, void *context)
{
	static int	bit_index;
	static char	curr_char;
	static int	client_pid;

	(void)context;
	if (client_pid == 0)
		client_pid = info->si_pid;
	else if (client_pid != info->si_pid)
	{
		client_pid = info->si_pid;
		ft_set_to_z(&bit_index, &curr_char);
	}
	if (signum == SIGUSR1)
		curr_char = curr_char << 1 | 1;
	else if (signum == SIGUSR2)
		curr_char = curr_char << 1 | 0;
	bit_index++;
	if (bit_index == 8)
	{
		ft_print_char(curr_char);
		client_pid = 0;
		bit_index = 0;
	}
}

int	main(void)
{
	struct sigaction	sa;

	sa.sa_sigaction = handle_signal;
	sa.sa_flags = SA_SIGINFO;
	sigaction(SIGUSR1, &sa, NULL);
	sigaction(SIGUSR2, &sa, NULL);
	ft_print_banner(getpid());
	while (1)
		pause();
	return (0);
}
