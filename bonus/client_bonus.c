/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moben-ta <moben-ta@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/31 18:15:22 by moben-ta          #+#    #+#             */
/*   Updated: 2025/02/12 18:14:38 by moben-ta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./minitalk_bonus.h"

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
		usleep(200);
	}
}

static void	ft_send_message_len(int len, int pid)
{
	int	i;

	i = 31;
	while (i >= 0)
	{
		if (len >> i & 1)
			kill(pid, SIGUSR1);
		else
			kill(pid, SIGUSR2);
		i--;
		usleep(200);
	}
}

static void	ft_send_message(char *str, int pid)
{
	int	i;
	int	len;

	len = ft_strlen(str);
	ft_send_message_len(len, pid);
	i = 0;
	while (str[i] != '\0')
	{
		ft_send_char_bit(str[i], pid);
		i++;
	}
}

static void	handler(int signum)
{
	if (signum == SIGUSR1)
		ft_printf("✔ %s%sMessage successfully received by the server.%s%s\n",
			GREEN, BOLD, RESET, RESET);
}

int	main(int arc, char **arv)
{
	struct sigaction	sa;
	int					pid;

	if (arc == 3)
	{
		sa.sa_handler = handler;
		sa.sa_flags = 0;
		sigemptyset(&sa.sa_mask);
		sigaction(SIGUSR1, &sa, NULL); 
		pid = check_args_error(arv);
		ft_printf("    %sSending your message to server... \n%s", GRAY, RESET);
		ft_send_message(arv[2], pid);
	}
	else
		ft_printf("⚠️  %sUsage%s: %s <PID> <message>\n", YELLOW, RESET, arv[0]);
	return (0);
}
