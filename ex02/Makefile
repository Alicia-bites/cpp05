# project settings
NAME 			:=	Bureaucrat
NAME_AR			:=	Bureaucrat.a
C++				:=	c++
CXXFLAGS		:=	-MMD -Wall -Wextra -Werror -std=c++98
# CXXFLAGSADD		:=	-g3

VALGRIND		:=	valgrind -s --leak-check=full --show-leak-kinds=all --track-origins=yes #--track-fds=yes

IPATH			:=	includes
OPATH			:=	obj

SRCS_PATH		:=	srcs

RM				:=	rm -rf

SRCS			:=	main.cpp \
					Bureaucrat.cpp \
					Form.cpp

OBJS			:=	$(addprefix $(OPATH)/, $(SRCS:.cpp=.o))
DEPS			:=	$(OBJS:.o=.d)

vpath %.hpp $(IPATH)
vpath %.cpp $(SRCS_PATH)\

vpath %.o $(OPATH)

all:	$(NAME)

$(OPATH)/%.o:	%.cpp
			$(C++) $(CXXFLAGS) $(CXXFLAGSADD) -I $(IPATH) -c $< -o $@

$(NAME):	$(OBJS)
			$(C++) $(CXXFLAGS) $(CXXFLAGSADD) $(OBJS) -I $(IPATH) -o $(NAME)

$(OBJS):	| $(OPATH)

$(OPATH):
			mkdir -p $(OPATH)

clean:
			$(RM) $(OPATH)

fclean:
			make clean
			$(RM) $(NAME)
  
re:
			make fclean
			make all

valgrind:
			make
			$(VALGRIND) ./$(NAME)

-include $(DEPS)

.PHONY: all clean fclean re norme sym comp comp_vgdb comp_envi archive test_ok test_ko test_man