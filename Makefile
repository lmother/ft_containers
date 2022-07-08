INC			=	-I.

NAME		=	containers

SRCS		=	*.cpp
OBJS		=	$(SRCS:.cpp=.o)
DEP			=	$(SRCS:.cpp=.d)

%.o:		%.cpp
			$(CC) $(CFLAGS) $(INC) -c $< -o $(NAME)

CC			=	c++

RM			=	rm -rf

CFLAGS		=	-std=c++98 -Wall -Wextra -Werror -MD

.PHONY:	all clean fclean re

all:		$(NAME)

$(NAME):	$(OBJS)
			$(CC) $(CFLAGS) -c $(SRCS)
			$(CC) $(CFLAGS) -o $(NAME) $(OBJS)

clean:
			$(RM) $(OBJS) $(DEP)

fclean:		clean
			$(RM) $(NAME)
			
-include	$(DEP)

re :		fclean all
