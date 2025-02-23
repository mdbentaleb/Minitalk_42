/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moben-ta <moben-ta@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/31 18:15:15 by moben-ta          #+#    #+#             */
/*   Updated: 2025/02/12 18:14:51 by moben-ta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./minitalk_bonus.h"

void	ft_init_data(t_data *data)
{
	data->bit_index = 0;
	data->curr_char = 0;
	data->message = NULL;
	data->message_len = 0;
	data->index = 0;
	data->len_or_char = 1;
}

static void	handle_length(t_data *v, int bit)
{
	v->message_len = (v->message_len << 1) | bit;
	v->bit_index++;
	if (v->bit_index == 32)
	{
		v->message = (char *)malloc(v->message_len + 1);
		if (!v->message)
			exit(1);
		v->message[v->message_len] = '\0';
		v->bit_index = 0;
		v->len_or_char = 0;
	}
}

static void	handle_message(t_data *data, int bit)
{
	if (bit == 1)
		data->curr_char = data->curr_char << 1 | 1;
	else
		data->curr_char = data->curr_char << 1 | 0;
	data->bit_index++;
	if (data->bit_index == 8)
	{
		data->message[data->index++] = data->curr_char;
		if (data->index == data->message_len)
		{
			ft_printf("%s\n", data->message);
			kill(data->client_pid, SIGUSR1);
			free(data->message);
			ft_init_data(data);
		}
		data->bit_index = 0;
		data->curr_char = 0;
	}
}

static void	handle_signal(int signum, siginfo_t *info, void *context)
{
	static t_data	v;
	int				bit;

	(void)context;
	if (signum == SIGUSR1)
		bit = 1;
	else
		bit = 0;
	if (v.client_pid != info->si_pid)
	{
		v.client_pid = info->si_pid;
		free(v.message);
		ft_init_data(&v);
	}
	if (v.len_or_char == 1)
		handle_length(&v, bit);
	else
		handle_message(&v, bit);
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
