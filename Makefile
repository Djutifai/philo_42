# Resulting binary name
NAME			= philo

# Resulting bonus binary name
BONUS_NAME		= philo_bonus

# Source files configuration
SRC_DIR 		= philo_dir/src
SRCS			:= $(shell find $(SRC_DIR) -name *.c)
OBJS			= ${patsubst %.c,%.o,${SRCS}}
D_FILES			= ${patsubst %.c,%.d,${SRCS}}
INCLUDES		= philo_dir/includes/

# Bonus source files configuration
BONUS_DIR 		= philo_bonus_dir/src
BONUS_SRCS		:= $(shell find $(BONUS_DIR) -name *.c)
BONUS_OBJS		= ${patsubst %.c,%.o,${BONUS_SRCS}}
BONUS_D_FILES	= ${patsubst %.c,%.d,${BONUS_SRCS}}
INCLUDES_BONUS	= philo_bonus_dir/includes/

# Compilation configuration
THREADS			= -pthread
CFLAGS			= -Wall -Werror -Wextra

# Console output color
GREENBG			= \033[42m
NOBG			= \033[0m
GREENTXT		= \033[1;32m
NOCOLORTXT		= \033[0m

%bonus.o:		%bonus.c Makefile
				${CC} ${CFLAGS} ${THREADS} -c $< -o $@ -I${INCLUDES_BONUS} -MMD

%.o:			%.c Makefile
				${CC} ${CFLAGS} ${THREADS} -c $< -o $@ -I${INCLUDES}  -MMD

all:			${NAME}

bonus:			${BONUS_NAME}

${NAME}:		${OBJS} Makefile
				${CC} ${CFLAGS} ${THREADS} ${OBJS} -o ${basename ${NAME}}
				@echo "${GREENTXT}philo is compiled${NOCOLORTXT}\n"

${BONUS_NAME}:	${BONUS_OBJS} Makefile
				${CC} ${CFLAGS} ${THREADS} ${BONUS_OBJS} -o ${basename ${BONUS_NAME}}
				@echo "${GREENTXT}philo is compiled${NOCOLORTXT}\n"

clean:
				@rm -rf ${OBJS} ${D_FILES}
				@rm -rf ${BONUS_OBJS} ${BONUS_D_FILES}
				@echo "${GREENTXT}Cleaning complete${NOCOLORTXT} \n"

fclean:			clean
				@${RM} ${NAME}
				@${RM} ${BONUS_NAME}
				@echo "${GREENTXT}Full cleaning is complete${NOCOLORTXT} \n"

re:				fclean all

include $(wildcard $(D_FILES)) $(wildcard $(BONUS_D_FILES))

.PHONY:			all clean fclean re bonus
.SILENT:		all clean fclean re bonus $(NAME) $(BONUS_NAME)
