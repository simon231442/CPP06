NAME = ScalarConverter
TEST_NAME = ScalarConverter_test

################################################################################
#                               DIRECTORIES                                    #
################################################################################

OBJ_DIR = obj

################################################################################
#                                SOURCE FILES                                  #
################################################################################

SOURCE = ScalarConverter.cpp main.cpp 
TEST_SOURCE = ScalarConverter.cpp main_tester.cpp

################################################################################
#                             COMPILER OPTIONS                                 #
################################################################################

CCPP = c++
	CPPFLAGS = -Wall -Wextra -Werror -std=c++98 

OBJETS = $(SOURCE:%.cpp=$(OBJ_DIR)/%.o)

################################################################################
#                              TARGETS & RULES                                 #
################################################################################

all : $(NAME)

$(NAME) : $(OBJETS)
	$(CCPP) $(CPPFLAGS) $(OBJETS) -o $(NAME)

$(OBJ_DIR)/%.o : %.cpp | $(OBJ_DIR)
	$(CCPP) $(CPPFLAGS) -c $< -o $@

$(OBJ_DIR) :
	mkdir -p $(OBJ_DIR)

clean :
	rm -rf $(OBJ_DIR)

fclean : clean
	rm -f $(NAME)

re : fclean all

test : $(TEST_NAME)

$(TEST_NAME) : $(TEST_SOURCE)
	$(CCPP) $(CPPFLAGS) $(TEST_SOURCE) -o $(TEST_NAME)

.PHONY : all clean fclean re test

