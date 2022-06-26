# Copyright @mfunyu
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

NAME        = ft_container
INCLUDES    = -Isrcs/includes -I../../includes
CXX         = c++
CXXFLAGS    = -Wall -Werror -Wextra -std=c++98 -pedantic-errors $(INCLUDES) -MMD -MP
CXXDEBUG    = -fsanitize=address -g
DEFINES     = -D_MAP -D_SET -D_STACK -D_VECTOR
RM          = rm -f

# =============================================================================
#
# File Variables
# =============================================================================

SRCS_       = main.cpp                                \
              Log.cpp                                 \
              UnitTester.cpp
SRCS_MAP    = MapTest.cpp                             \
              MapTest_Basic.cpp                       \
              MapTest_ElementAccess.cpp               \
              MapTest_Iterators.cpp                   \
              MapTest_Capacity.cpp                    \
              MapTest_Lookup.cpp                      \
              MapTest_Observers.cpp                   \
              MapTest_NonMemberFunctions.cpp          \
              MapTest_Modifiers.cpp
SRCS_SET    = SetTest.cpp                             \
              SetTest_Basic.cpp                       \
              SetTest_Iterators.cpp                   \
              SetTest_Capacity.cpp                    \
              SetTest_Lookup.cpp                      \
              SetTest_Observers.cpp                   \
              SetTest_NonMemberFunctions.cpp          \
              SetTest_Modifiers.cpp
SRCS_STACK  = StackTest.cpp                           \
              StackTest_Basic.cpp                     \
              StackTest_Else.cpp                      \
              StackTest_Template.cpp                  \
              StackTest_NonMemberFunctions.cpp
SRCS_VECTOR = VectorTest.cpp                          \
              VectorTest_Basic.cpp                    \
              VectorTest_ElementAccess.cpp            \
              VectorTest_Iterators.cpp                \
              VectorTest_Capacity.cpp                 \
              VectorTest_NonMemberFunctions.cpp       \
              VectorTest_Modifiers.cpp
SRCS        = $(SRCS_)                                \
              $(SRCS_MAP)                             \
              $(SRCS_SET)                             \
              $(SRCS_STACK)                           \
              $(SRCS_VECTOR)

# =============================================================================
# Rules
# =============================================================================

ifdef BENCH
DEFINES      += -DBENCH
NAME         = benchmark
SRCS         = $(SRCS_)                                \
               UnitTesterBench.cpp                     \
               MapTest.cpp                             \
               MapTest_Bench.cpp                       \
               SetTest.cpp                             \
               SetTest_Bench.cpp                       \
               StackTest.cpp                           \
               StackTest_Bench.cpp                     \
               VectorTest.cpp                          \
               VectorTest_Bench.cpp                    
endif

CXXFLAGS     += $(DEFINES)
OBJS_DIR     = objs/
OBJS         = $(addprefix $(OBJS_DIR), $(SRCS:.cpp=.o))
SRCS_DIR     = srcs
VPATH        = $(SRCS_DIR)                            \
               $(SRCS_DIR)/map                        \
               $(SRCS_DIR)/set                        \
               $(SRCS_DIR)/stack                      \
               $(SRCS_DIR)/vector                     
DEPS         = $(OBJS:.o=.d)

.PHONY           : all
all              : $(NAME)

-include       $(DEPS)

$(NAME)          : $(OBJS_DIR) $(OBJS)
	@$(CXX) $(CXXFLAGS) -o $@ $(OBJS)

$(OBJS_DIR)%.o   : %.cpp
	@$(CXX) $(CXXFLAGS) -o $@ -c $<

$(OBJS_DIR)      :
	@-mkdir $@

.PHONY           : clean
clean            :
	@$(RM) -R $(OBJS_DIR)

.PHONY           : fclean
fclean           : clean
	@$(RM) result.log benchmark

.PHONY           : re
re               : fclean all

.PHONY           : bench
bench            : 
	@make re BENCH=1
	@./benchmark
	@make fclean
