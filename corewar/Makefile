##
## EPITECH PROJECT, 2022
## B-CPE-201-MPL-2-1-corewar-hippolyte.aubert
## File description:
## Makefile
##

SRC		=		$(wildcard *.c)

OBJ		=		$(SRC:.c=.o)

CFLAGS	=		-W -Wall -Wextra -g3

BIN		=		corewar

LIB 	=		../lib/libmy.a

all: $(BIN)

$(BIN): $(OBJ) $(LIB)
	@$(CC) $(OBJ) -o $(BIN) -L../lib -lmy
	@echo "MAKE Done."

clean:
	@$(RM) $(OBJ)
	@$(RM) *.cor
	@echo "CLEAN Done."

fclean: clean
	@$(RM) $(BIN)
	@echo "FCLEAN Done."

re: fclean all
