/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minitalk_bonus.h                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moben-ta <moben-ta@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/01 11:30:39 by moben-ta          #+#    #+#             */
/*   Updated: 2025/02/12 18:14:47 by moben-ta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINITALK_BONUS_H
# define MINITALK_BONUS_H

# include <signal.h>
# include <unistd.h>
# include <stdlib.h>
# include "../ft_printf/ft_printf.h"

# define RED		"\033[31m"
# define GREEN		"\033[32m"
# define YELLOW		"\033[33m"
# define BOLD		"\033[1m"
# define RESET		"\033[0m"
# define GRAY		"\e[90m"
# define CYAN		"\033[0;36m"

typedef struct s_data
{
	int		bit_index;
	char	curr_char;
	int		client_pid;
	char	*message;
	int		message_len;
	int		index;
	int		len_or_char;
}	t_data;

int		ft_atoi(const char *str);
int		ft_strlen(const char *s);
void	ft_print_banner(int pid);
int		check_args_error(char *arv[]);

#endif