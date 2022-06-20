##
## EPITECH PROJECT, 2022
## B-CPE-201-MPL-2-1-corewar-hippolyte.aubert
## File description:
## Makefile
##

all:
	make -C lib/my
	make -C asm
	make -C corewar
	make -C bonus

clean:
	make clean -C lib/my
	make clean -C asm
	make clean -C corewar
	make clean -C bonus

fclean:
	make fclean -C lib/my
	make fclean -C asm
	make fclean -C corewar
	make fclean -C bonus

re: fclean all
