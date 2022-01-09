# Copyright @bigpel66

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

CC          = clang++
CFLAGS      = -Wall -Werror -Wextra
CDEBUG      = -fsanitize=address -g -std=c++98
RM          = rm -f

# =============================================================================
# File Variables
# =============================================================================

NAME         = a.out
HEADER       = ./
FOLDER       = ./
SRC_LIST     = main.cpp          \
               mutantstack.cpp
SRC          = $(addprefix $(FOLDER), $(SRC_LIST))
OBJ          = $(SRC:.cpp=.o)

# =============================================================================
# Target Generating
# =============================================================================

%.o         : %.cpp
	@echo $(YELLOW) "Compiling...\t" $< $(EOC) $(LINE_CLEAR)
	@$(CC) $(CFLAGS) -I $(HEADER) -o $@ -c $<

$(NAME)     : $(OBJ)
	@echo $(GREEN) "Source files are compiled!\n\n" $(EOC)
	@echo $(YELLOW) "Building executable $(NAME)" $(EOC)
	@$(CC) $(CFALGS) -I $(HEADER) -o $(NAME) $(OBJ)
	@echo $(GREEN) "$(NAME) is created!\n" $(EOC)

# =============================================================================
# Rules
# =============================================================================

.PHONY      : all
all         : $(NAME)

.PHONY      : clean
clean       :
	@echo $(YELLOW) "Cleaning object files..." $(EOC)
	@$(RM) $(OBJ)
	@echo $(RED) "Object files are cleaned!\n" $(EOC)

.PHONY      : fclean
fclean      : clean
	@echo $(YELLOW) "Removing $(NAME)..." $(EOC)
	@$(RM) $(NAME)
	@echo $(RED) "$(NAME) is removed!\n\n" $(EOC)

.PHONY      : re
re          : fclean all
