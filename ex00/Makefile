NAME		= convert
CXX			= c++
CXXFLAGS	= -Wall -Wextra -Werror -std=c++98
GREEN		= \033[0;32m
BLUE		= \033[0;36m
RESET		= \033[0m
SRCS		= main.cpp ScalarConverter.cpp
OBJS		= $(SRCS:.cpp=.o)

all: $(NAME)
$(NAME): $(OBJS)
	$(CXX) $(CXXFLAGS) $(OBJS) -o $(NAME)
	@echo "$(GREEN)$(NAME) created successfully!$(RESET)"
%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@
clean:
	@echo "$(BLUE)Cleaning object$(RESET)"
	rm -f $(OBJS)
	@echo "$(GREEN)Successfully cleaned$(RESET)"
fclean: clean
	@echo "$(BLUE)Cleaning executable$(RESET)"
	rm -f $(NAME)
	@echo "$(GREEN)Successfully cleaned$(RESET)"
re: fclean all

.PHONY: all clean fclean re
