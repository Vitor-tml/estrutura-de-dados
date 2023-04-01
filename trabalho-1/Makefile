all:
	@make sequencial -s
	@echo -e "\033[33mSequencial - OK\033[0m"
	@make encadeada -s
	@echo -e "\033[33mEncadeada  - OK\033[0m"
	@make arquivos -s
	@echo -e "\033[33marquivos    - OK\033[0m"
	@make main -s
	@echo -e "\033[33mMain       - OK\033[0m"
	@echo -e "\033[32mExecutando...\n---------------------\033[0m"
	@make exe -s

sequencial:
	gcc -c ./src/sequencial.c -I ./include -o ./obj/sequencial.o 

encadeada:
	gcc -c ./src/encadeada.c -I ./include -o ./obj/encadeada.o 

arquivos:
	gcc -c ./src/arquivos.c -I ./include -o ./obj/arquivos.o 

main:
	gcc ./main.c ./obj/arquivos.o ./obj/encadeada.o ./obj/sequencial.o -I ./include -o ./output/main.exe 

exe:
	./output/main.exe

repositorio:
	mkdir ./output
	mkdir ./obj
	
clear:
	rm ./output/main.exe
	rm ./obj/encadeada.o
	rm ./obj/sequencial.o
	rm ./obj/arquivos.o 


seq:
	make sequencial
	gcc ./main.c ./obj/sequencial.o -I ./include -o ./output/main.exe 

enc:
	make encadeada
	gcc ./main.c ./obj/encadeada.o -I ./include -o ./output/main.exe 

arq:
	make arquivos
	gcc ./main.c ./obj/arquivos.o -I ./include -o ./output/main.exe