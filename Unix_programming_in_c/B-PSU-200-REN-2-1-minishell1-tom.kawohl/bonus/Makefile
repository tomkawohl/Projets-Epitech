##
## EPITECH PROJECT, 2022
## setup
## File description:
## Makefile
##
all:
	@$(MAKE) -sC ../

clean:
	@rm -f mysh
	@rm -f tester.sh
	@rm -f tests
	@$(MAKE) fclean -sC ../

test:	all
		@cp test_folder/tester.sh .
		@cp test_folder/tests .
		@cp ../mysh .
		./tester.sh
		@$(MAKE) -s clean

.PHONY: all test clean
