#### ######## #### #### ######## #### #### ######## #### #### ######## #### #### ######## ####

PROGRAM           = so_long

INC_DIR           = includes
BIN_DIR           = binaries
OBJ_DIR           = objects
SRC_DIR           = sources

FLAGS_INC   = -I $(INC_DIR)

CC = gcc

CFLAGS = -Wall -Wextra -Werror $(FLAGS_INC) -g
SFLAGS = -Wall -Wextra -Werror -fsanitize=address $(FLAGS_INC) -g
LFLAGS = -Wall -Wextra -Werror -fsanitize=leaks $(FLAGS_INC) -g

#### ######## #### #### ######## #### #### ######## #### #### ######## #### #### ######## ####

SRCS_MAIN = main

SRC = $(addsuffix .c, $(addprefix sources/, $(SRCS_MAIN)))

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
	@$(CC) $(CFLAGS) -o $(PROGRAM) $(OBJS)
	@mkdir -p $(BIN_DIR)
	@mv $(PROGRAM) $(BIN_DIR)

#### ######## #### #### ######## #### #### ######## #### #### ######## #### #### ######## ####

debug_s: $(OBJS)
	@echo "\n\033[0;32mCompiling ${PROGRAM}..."
	@$(CC) $(SFLAGS) -o $(PROGRAM) $(OBJS)
	@mkdir -p $(BIN_DIR)
	@mv $(PROGRAM) $(BIN_DIR)

debug_l: $(OBJS)
	@echo "\n\033[0;32mCompiling ${PROGRAM}..."
	@$(CC) $(LFLAGS) -o $(PROGRAM) $(OBJS)
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
	@rmdir $(OBJ_DIR) || true
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
