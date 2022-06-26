# Copyright @pruiz-ca
# Modified by @bigpel66

# =============================================================================
# Color Variables
# =============================================================================

BLACK       = "\033[0;30m"
GRAY        = "\033[1;30m"
RED         = "\033[0;31m"
GREEN       = "\033[0;32m"
YELLOW      = "\033[1;33m"
PURPLE      = "\033[0;35m"
CYAN        = "\033[0;36m"
WHITE       = "\033[1;37m"
EOC         = "\033[0;0m"
LINE_CLEAR  = "\x1b[1A\x1b[M"

# =============================================================================
# Command Variables
# =============================================================================

CXX         = c++
CXXFLAGS    = -Wall -Werror -Wextra -std=c++98
CXXDEBUG    = -fsanitize=address -g
RM          = rm -f

# =============================================================================
# File Variables
# =============================================================================

NAME         = ft_container
HEADER       = ./
FOLDER       = ./
SRC_LIST     = main.cpp             \
							 benchmark.cpp
SRC          = $(addprefix $(FOLDER), $(SRC_LIST))
OBJ          = $(SRC:.cpp=.o)

# =============================================================================
# Target Generating
# =============================================================================

%.o         : %.cpp
	@$(CXX) $(CXXFLAGS) -I $(HEADER) -o $@ -c $<

$(NAME)     : $(OBJ)
	@$(CXX) $(CXXFLAGS) -I $(HEADER) -o $(NAME) $(OBJ)
	@./$(NAME)
	@make fclean

# =============================================================================
# Rules
# =============================================================================

.PHONY      : all
all         : $(NAME)

.PHONY      : clean
clean       :
	@$(RM) $(OBJ)

.PHONY      : fclean
fclean      : clean
	@$(RM) $(NAME)

.PHONY      : re
re          : fclean all
