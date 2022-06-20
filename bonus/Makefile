##
## EPITECH PROJECT, 2022
## B-CPE-201-MPL-2-1-corewar-hippolyte.aubert
## File description:
## Makefile
##

SRC		=		$(wildcard *.c)

OBJ		=		$(SRC:.c=.o)

LDFLAGS =		-lcsfml-graphics -lcsfml-window -lcsfml-system -lcsfml-audio -lm

CFLAGS	=		-W -Wall -Wextra -lcsfml

BIN		=		corewar

LIB 	=		../lib/libmy.a

all: $(BIN)

$(BIN): $(OBJ) $(LIB)
	@$(CC) $(OBJ) -o $(BIN) $(LDFLAGS) -L../lib -lmy
	@echo "MAKE Done."

clean:
	@$(RM) $(OBJ)
	@echo "CLEAN Done."

fclean: clean
	@$(RM) $(BIN)
	@echo "FCLEAN Done."

re: fclean all
