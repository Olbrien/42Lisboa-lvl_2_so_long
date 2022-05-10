#### ######## #### #### ######## #### #### ######## #### #### ######## #### #### ######## ####

PROGRAM           = so_long

INC_DIR           = includes
BIN_DIR           = binaries
OBJ_DIR           = objects
SRC_DIR           = sources

FLAGS_INC   = -I $(INC_DIR)

CC = gcc

LINUX = -lbsd -lmlx -lXext -lX11 -lm
MAC   = -lmlx -framework OpenGL -framework AppKit -lm

ifeq ($(UNAME), Darwin)
	CFLAGS = -Wall -Wextra -Werror -I $(MAC) $(FLAGS_INC) -g
	SFLAGS = -Wall -Wextra -Werror -I $(MAC) -fsanitize=address $(FLAGS_INC) -g
	LFLAGS = -Wall -Wextra -Werror -I $(MAC) -fsanitize=leak $(FLAGS_INC) -g
else
	CFLAGS = -Wall -Wextra -Werror -I $(LINUX) $(FLAGS_INC) -g
	SFLAGS = -Wall -Wextra -Werror -I $(LINUX) -fsanitize=address $(FLAGS_INC) -g
	LFLAGS = -Wall -Wextra -Werror -I $(LINUX) -fsanitize=leak $(FLAGS_INC) -g
endif



#### ######## #### #### ######## #### #### ######## #### #### ######## #### #### ######## ####

SRCS_MAIN     = main
SRCS_MAP      = treatment validation tilemap
SRCS_MLX      = game panel hooks
SRCS_UTILITY  = utils ft_split ft_strdup ft_strjoin ft_strlen ft_strchr ft_putchar_fd \
				ft_putnbr_fd

SRC = $(addsuffix .c, $(addprefix sources/, $(SRCS_MAIN))) \
      $(addsuffix .c, $(addprefix sources/map/, $(SRCS_MAP))) \
      $(addsuffix .c, $(addprefix sources/mlx/, $(SRCS_MLX))) \
      $(addsuffix .c, $(addprefix sources/utility/, $(SRCS_UTILITY)))

#### ######## #### #### ######## #### #### ######## #### #### ######## #### #### ######## ####

OBJS = $(SRC:$(SRC_DIR)/%.c=$(OBJ_DIR)/%.o)

#### ######## #### #### ######## #### #### ######## #### #### ######## #### #### ######## ####

all: message $(PROGRAM)                                 # Default                         #
c: clear fclean message $(PROGRAM) clean                # Compiles and clears the screen  #
sanitize: clear fclean message debug_s clean            # Compiles with fsanitize=address #
leaks: clear fclean message debug_l clean               # Compiles with fsanitize=leaks   #

#### ######## #### #### ######## #### #### ######## #### #### ######## #### #### ######## ####

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c
	@printf "\033[0;33mGenerating ${PROGRAM} objects... %s\n" $@
	@mkdir -p $(dir $@)
	@${CC} ${FLAGS_INC} ${CFLAGS} -c $< -o $@

#### ######## #### #### ######## #### #### ######## #### #### ######## #### #### ######## ####

$(PROGRAM): $(OBJS)
	@echo "\n\033[0;32mCompiling ${PROGRAM}..."
	@$(CC) $(OBJS) $(CFLAGS) -o $(PROGRAM)
	@mkdir -p $(BIN_DIR)
	@mv $(PROGRAM) $(BIN_DIR)

#### ######## #### #### ######## #### #### ######## #### #### ######## #### #### ######## ####

debug_s: $(OBJS)
	@echo "\n\033[0;32mCompiling ${PROGRAM}..."
	@$(CC) $(OBJS) $(SFLAGS) -o $(PROGRAM)
	@mkdir -p $(BIN_DIR)
	@mv $(PROGRAM) $(BIN_DIR)

debug_l: $(OBJS)
	@echo "\n\033[0;32mCompiling ${PROGRAM}..."
	@$(CC) $(OBJS) $(LFLAGS) -o $(PROGRAM)
	@mkdir -p $(BIN_DIR)
	@mv $(PROGRAM) $(BIN_DIR)

#### ######## #### #### ######## #### #### ######## #### #### ######## #### #### ######## ####

clean: message
	@echo "\nRemoving binaries..."
	@rm -f $(OBJS)
	@echo "\033[0m"

fclean: message
	@echo "\nDeleting objects..."
	@rm -f $(OBJS)
	@echo "Deleting executables..."
	@rm -f $(BIN_DIR)/$(PROGRAM)
	@rm -r $(OBJ_DIR) || true
	@rmdir $(BIN_DIR) || true
	@echo "\033[0m"

re: clear fclean all

#### ######## #### #### ######## #### #### ######## #### #### ######## #### #### ######## ####

message:
	@printf "\n"
	@printf "\033[1;36m	!! Makefile by tisantos @42Lisboa !! \e[0m \n"
	@printf "\033[1;35m		!! Makefile by tisantos @42Lisboa !! \e[0m \n"
	@printf "\033[1;31m			!! Makefile by tisantos @42Lisboa !! \e[0m \n"
	@printf "\033[1;38m				!! Makefile by tisantos @42Lisboa !! \e[0m \n"
	@printf "\n"

clear:
	@clear

#### ######## #### #### ######## #### #### ######## #### #### ######## #### #### ######## ####
