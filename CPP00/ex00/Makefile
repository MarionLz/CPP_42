NAME = megaphone

CC = c++
FLAGS = -Wall -Wextra -Werror -std=c++98

SRC_DIR = src/
SRCS = $(SRC_DIR)megaphone.cpp

OBJ_DIR = obj/
OBJS = $(SRCS:$(SRC_DIR)%.cpp=$(OBJ_DIR)%.o)

all: $(NAME)

$(OBJ_DIR)%.o: $(SRC_DIR)/%.cpp
	@mkdir -p $(dir $@)                                                                                                                   
	$(CC) $(FLAGS) -c $< -o $@

$(NAME): $(OBJS)
	$(CC) $(FLAGS) $(OBJS) -o $(NAME)

clean:
	rm -rf $(OBJ_DIR)

fclean: clean
	rm -rf $(NAME)

re: fclean all