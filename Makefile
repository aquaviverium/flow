NAME = flow
FLAGS = -Wall -Wextra -Werror
INCLUDES = -I includes/ -I ~/.brew/include/SDL2/
SDL_LIB = -L ~/.brew/lib -l SDL2 -l sdl2_image
MORE_MATH_LIB = lib/more_math.a

SRC_DIR = src/
BIN_DIR = bin/

OUT_NAMES = \
	draw_vector \
	input \
	out \
	SDL_initialize \
	utils \

# List of all the source files.
SRC_NAMES = \
	app_api \
	main \
	update \

# List of all the source files, folders are to be added by
# including a $(addprefix, DIR_NAME, $(DIR_FILES))
FILE_NAMES = \
	$(SRC_NAMES) \
	$(addprefix out/, $(OUT_NAMES)) \

SRCS = $(addsuffix .c, $(addprefix $(SRC_DIR), $(FILE_NAMES)))
# Object files will be built to BIN_DIR. They will build the
# structure/ path tree that the SRC_DIR has.
OBJS = $(addprefix $(BIN_DIR), $(SRCS:.c=.o))

all: $(NAME)

$(NAME): $(BIN_DIR) $(OBJS)
	gcc $(FLAGS) $(INCLUDES) -o $(NAME) $(OBJS) $(SDL_LIB) $(MORE_MATH_LIB)

$(BIN_DIR):
	mkdir -p $(BIN_DIR)

# These are the target object file names given by path ($(OBJS)).
# We will create the required directories with mkdir -p.
$(BIN_DIR)%.o: %.c
	mkdir -p $(BIN_DIR)$(dir $<)
	gcc $(FLAGS) $(INCLUDES) -c $< -o $@

clean:
	rm -f $(OBJS)

fclean: clean
	rm -rf $(NAME)

# Ensure that when git add is done the repo is cleaned out.
save: fclean
	git add .
	git commit -m "$(MSG)"
	git push

re: fclean all

run:
	rm -f $(NAME)
	make all
	clear
	@echo "\033[1m\033[32m$(NAME)\033[0m"
	@./$(NAME)

update:
	make -C lib/more_math update
	cp lib/more_math/includes/* ./includes/
	mv lib/more_math/more_math.a ./lib


$(MORE_MATH_LIB):
	make -C lib/more_math
	mv lib/more_math/more_math.a ./lib
