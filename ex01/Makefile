# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: linyao <linyao@student.42barcelona.com>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/01/22 23:15:37 by linyao            #+#    #+#              #
#    Updated: 2025/02/09 22:19:53 by linyao           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = span
CXX = c++
CPPFLAGS = -Wall -Wextra -Werror -std=c++98 -pedantic -Wshadow
RM = rm -rf

INC = Span.hpp
SRC = main.cpp Span.cpp
OBJ = $(SRC:.cpp=.o)

all: $(NAME)

$(NAME): $(OBJ)
	$(CXX) $(CPPFLAGS) $(OBJ) -o $(NAME)
	
%.o: %.cpp $(INC)
	$(CXX) $(CPPFLAGS) -c $< -o $@

clean:
	$(RM) $(OBJ)
	
fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re