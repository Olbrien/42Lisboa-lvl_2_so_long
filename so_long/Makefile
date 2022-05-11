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
	CFLAGS = -Wall -Wextra -Werror -I $(MAC) $(FLAGS_INC) -D "LINUX=0" -g
	SFLAGS = -Wall -Wextra -Werror -I $(MAC) -fsanitize=address $(FLAGS_INC) -D "LINUX=0" -g
	LFLAGS = -Wall -Wextra -Werror -I $(MAC) -fsanitize=leak $(FLAGS_INC) -D "LINUX=0" -g
else
	CFLAGS = -Wall -Wextra -Werror -I $(LINUX) $(FLAGS_INC) -D "LINUX=1" -g
	SFLAGS = -Wall -Wextra -Werror -I $(LINUX) -fsanitize=address $(FLAGS_INC) -D "LINUX=1" -g
	LFLAGS = -Wall -Wextra -Werror -I $(LINUX) -fsanitize=leak $(FLAGS_INC) -D "LINUX=1" -g
endif

#### ######## #### #### ######## #### #### ######## #### #### ######## #### #### ######## ####

SRCS_MAIN     = main
SRCS_IMAGES   = treatment treatment2
SRCS_MAP      = treatment validation tilemap
SRCS_MLX      = game hooks hooks2 render
SRCS_UTILITY  = utils ft_split ft_strdup ft_strjoin ft_strlen ft_strchr ft_putchar_fd \
				ft_putnbr_fd

SRC = $(addsuffix .c, $(addprefix sources/, $(SRCS_MAIN))) \
      $(addsuffix .c, $(addprefix sources/images/, $(SRCS_IMAGES))) \
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
	@rm -f $(BONUS_OBJS)
	@echo "\033[0m"

fclean: message
	@echo "\nDeleting objects..."
	@rm -f $(OBJS)
	@rm -f $(BONUS_OBJS)
	@echo "Deleting executables..."
	@rm -f $(BIN_DIR)/$(PROGRAM)
	@rm -f $(BIN_DIR)/$(BONUS_PROGRAM)
	@rm -r $(OBJ_DIR) || true
	@rm -r $(BONUS_OBJ_DIR) || true
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

#### ######## #### #### ######## #### #### ######## #### #### ######## #### #### ######## ####

BONUS_PROGRAM     = so_long_bonus

BONUS_OBJ_DIR     = objects_bonus

BONUS_SRC_DIR     = sources_bonus

#### ######## #### #### ######## #### #### ######## #### #### ######## #### #### ######## ####

BONUS_SRCS_MAIN     = main_bonus
BONUS_SRCS_IMAGES   = treatment_bonus treatment2_bonus
BONUS_SRCS_MAP      = treatment_bonus validation_bonus tilemap_bonus
BONUS_SRCS_MLX      = game_bonus hooks_bonus hooks2_bonus render_bonus
BONUS_SRCS_UTILITY  = utils_bonus ft_split ft_strdup ft_strjoin ft_strlen ft_strchr ft_putchar_fd \
					ft_putnbr_fd

BONUS_SRC = $(addsuffix .c, $(addprefix sources_bonus/, $(BONUS_SRCS_MAIN))) \
            $(addsuffix .c, $(addprefix sources_bonus/images/, $(BONUS_SRCS_IMAGES))) \
            $(addsuffix .c, $(addprefix sources_bonus/map/, $(BONUS_SRCS_MAP))) \
            $(addsuffix .c, $(addprefix sources_bonus/mlx/, $(BONUS_SRCS_MLX))) \
            $(addsuffix .c, $(addprefix sources_bonus/utility/, $(BONUS_SRCS_UTILITY)))

#### ######## #### #### ######## #### #### ######## #### #### ######## #### #### ######## ####

bonus: message $(BONUS_PROGRAM)                               # Default                         #
bonus_sanitize: clear fclean message bonus_debug_s clean      # Compiles with fsanitize=address #
bonus_leaks: clear fclean message bonus_debug_l clean         # Compiles with fsanitize=leaks   #

#### ######## #### #### ######## #### #### ######## #### #### ######## #### #### ######## ####

BONUS_OBJS = $(BONUS_SRC:$(BONUS_SRC_DIR)/%.c=$(BONUS_OBJ_DIR)/%.o)

#### ######## #### #### ######## #### #### ######## #### #### ######## #### #### ######## ####

$(BONUS_OBJ_DIR)/%.o: $(BONUS_SRC_DIR)/%.c
	@printf "\033[0;33mGenerating ${BONUS_PROGRAM} objects... %s\n" $@
	@mkdir -p $(dir $@)
	@${CC} ${FLAGS_INC} ${CFLAGS} -c $< -o $@

#### ######## #### #### ######## #### #### ######## #### #### ######## #### #### ######## ####

$(BONUS_PROGRAM): $(BONUS_OBJS)
	@echo "\n\033[0;32mCompiling ${BONUS_PROGRAM}..."
	@$(CC) $(BONUS_OBJS) $(CFLAGS) -o $(BONUS_PROGRAM)
	@mkdir -p $(BIN_DIR)
	@mv $(BONUS_PROGRAM) $(BIN_DIR)

#### ######## #### #### ######## #### #### ######## #### #### ######## #### #### ######## ####

bonus_debug_s: $(BONUS_OBJS)
	@echo "\n\033[0;32mCompiling ${BONUS_PROGRAM}..."
	@$(CC) $(BONUS_OBJS) $(SFLAGS) -o $(BONUS_PROGRAM)
	@mkdir -p $(BIN_DIR)
	@mv $(BONUS_PROGRAM) $(BIN_DIR)

bonus_debug_l: $(BONUS_OBJS)
	@echo "\n\033[0;32mCompiling ${BONUS_PROGRAM}..."
	@$(CC) $(BONUS_OBJS) $(LFLAGS) -o $(BONUS_PROGRAM)
	@mkdir -p $(BIN_DIR)
	@mv $(BONUS_PROGRAM) $(BIN_DIR)

#### ######## #### #### ######## #### #### ######## #### #### ######## #### #### ######## ####
