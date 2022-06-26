# Copyright @nesvoboda
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
# Rules
# =============================================================================

.PHONY      : all
all         :
	@./compile.sh
	@./run.sh
	@make fclean

.PHONY      : clean
clean       :

.PHONY      : fclean
fclean      : clean
	@$(RM) ft_*
	@$(RM) input_*
	@$(RM) std_output_*
	@$(RM) test_output_*

.PHONY      : re
re          : fclean all
