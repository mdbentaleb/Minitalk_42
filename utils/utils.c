/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moben-ta <moben-ta@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/04 10:13:25 by moben-ta          #+#    #+#             */
/*   Updated: 2025/02/12 18:15:18 by moben-ta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../mandatory/minitalk.h"

int	ft_atoi(const char *str)
{
	int			i;
	int			sign;
	long long	res;

	sign = 1;
	i = 0;
	while (str[i] == ' ' || (str[i] >= 9 && str[i] <= 13))
		i++;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			sign = -1;
		i++;
	}
	res = 0;
	while (str[i] >= '0' && str[i] <= '9')
	{
		res = (res * 10) + (str[i] - '0');
		if (res > 9223372036854775807 && sign == -1)
			return (0);
		else if (res > 9223372036854775807 && sign == 1)
			return (-1);
		i++;
	}
	return (res * sign);
}

int	ft_strlen(const char *s)
{
	int	i;

	i = 0;
	while (s[i] != '\0')
		i++;
	return (i);
}

int	check_args_error(char *arv[])
{
	int	pid;

	pid = ft_atoi(arv[1]);
	if ((pid <= 0) || kill(pid, 0) == -1)
	{
		ft_printf("❌ %s%sError Invalid PID%s%s\n", RED, BOLD, RESET, RESET);
		exit(1);
	}
	if (ft_strlen(arv[2]) == 0)
	{
		ft_printf("❌ %s%sError Empty message%s%s\n", RED, BOLD, RESET, RESET);
		exit(1);
	}
	return (pid);
}

void	ft_print_banner(int pid)
{
	ft_printf("%s%s+ ======================================", CYAN, BOLD);
	ft_printf("====================================== +%s%s\n", RESET, RESET);
	ft_printf("%s%s|                                   MINITALK", CYAN, BOLD);
	ft_printf("                                   |%s%s\n", RESET, RESET);
	ft_printf("%s%s+ ========================================", CYAN, BOLD);
	ft_printf("==================================== +%s%s\n", RESET, RESET);
	ft_printf("Server PID: %s%d%s\n", GREEN, getpid(), RESET);
}
