NAME		= Serializer

# Files
SRCS		= main.cpp Serializer.cpp
OBJS		:= $(SRCS:.cpp=.o)
DEPS		:= $(OBJS:.o=.d)

# Compilator
CXX			= c++
CXXFLAGS	= -Wall -Wextra -Werror
CXXFLAGS	+= -std=c++98 -MMD -g3

# Rules
all		: $(NAME)

$(NAME)	: $(OBJS)
	$(CXX) $(CXXFLAGS) $(OBJS) -o $(NAME)

leak	: $(NAME)
	valgrind --leak-check=full --track-origins=yes ./$(NAME)

clean	:
	rm -rf $(OBJS_PATH) $(OBJS) $(DEPS)

fclean	: clean
	rm -rf $(NAME)

re		: fclean all

# Rules for .o files
%.o : %.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

.PHONY : all clean fclean re

-include $(DEPS)