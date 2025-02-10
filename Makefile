# commands 
CC = cc
RM = rm 

# flags 
CCDEBUG = -g -fsanitize=address
CCFLAGS = -Wall -Wextra $(CCDEBUG) 
RMFLAGS = -rf 

# files
SRCS=game.c  rule_p.c  rule_r.c  rule_rr.c  rule_s.c  stack.c 
SRCS_DEBUG = main.c $(SRCS)
SRCS_BEST=  try_all.c $(SRCS)
DEPS = $(wildcard ./*.h)
OBJS_DEBUG = $(SRCS_DEBUG:.c=.o)

NAME_DEBUG= debug 
NAME_BEST= best 

all   : $(NAME_DEBUG)  $(NAME_BEST)

$(NAME_DEBUG) : $(SRCS_DEBUG)
	$(CC) $(CCFLAGS) $^ -o $@ 
$(NAME_BEST) : $(SRCS_BEST)
	$(CC) $(CCFLAGS) $^ -o $@ 

%.o : %.c  
	$(CC) $(CCFLAGS) $^ -o $@ 

clean : 
	$(RM) $(RMFLAGS) $(OBJS_DEBUG) $(OBJS_BEST) 

fclean : clean 
	$(RM) $(RMFLAGS) $(NAME_DEBUG) $(NAME_BEST)

re : fclean all

.PHONY : re clean fclean all 
.SECONDARY: $(OBJS_DEBUG) $(OBJS_BEST)
