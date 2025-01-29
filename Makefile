# commands 
CC = cc
RM = rm 

# flags 
CCDEBUG = -g -fsanitize=address
CCFLAGS = -Wall -Wextra $(CCDEBUG) 
RMFLAGS = -rf 

# files
SRCS = $(wildcard ./*.c)
DEPS = $(wildcard ./*.h)
OBJS = $(SRCS:.c=.o)
NAME = debug 

all : $(NAME) 

$(NAME) : $(SRCS)
	$(CC) $(CCFLAGS) $^ -o $@ 

clean : 
	$(RM) $(RMFLAGS) $(OBJS)

fclean : clean 
	$(RM) $(RMFLAGS) $(NAME)

re : fclean all

.PHONY : re clean fclean all
