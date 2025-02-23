# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: moben-ta <moben-ta@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/02/12 18:15:22 by moben-ta          #+#    #+#              #
#    Updated: 2025/02/12 18:15:23 by moben-ta         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

MANDATORY_DIR = mandatory
BONUS_DIR = bonus

MANDATORY_DIR = mandatory
BONUS_DIR = bonus


all:
	@rm -rf server server_b client client_b
	@$(MAKE) -C $(MANDATORY_DIR) OUT_DIR=..
	@echo "✔ Compilation completed successfully."


bonus:
	@rm -rf server server_b client client_b
	@$(MAKE) -C $(BONUS_DIR) OUT_DIR=..
	@echo "✔ Bonus compiled successfully."


clean:
	@$(MAKE) -C $(MANDATORY_DIR) clean
	@$(MAKE) -C $(BONUS_DIR) clean
	@echo "✔ Cleaning all object files."


fclean: clean
	@rm -rf server server_b client client_b
	@rm -rf server server_b client client_b
	@$(MAKE) -C $(MANDATORY_DIR) fclean
	@$(MAKE) -C $(BONUS_DIR) fclean
	@echo "✔ Full Cleaning."

re: fclean all

.PHONY: all bonus clean
