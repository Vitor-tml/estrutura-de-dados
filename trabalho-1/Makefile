all:
	@make sequencial -s
	@echo -e "\033[33mSequencial - OK\033[0m"
	@sleep 1
	@make encadeada -s
	@echo -e "\033[33mEncadeada  - OK\033[0m"
	@sleep 1
	@make funcoes -s
	@echo -e "\033[33mFuncoes    - OK\033[0m"
	@sleep 1
	@make main -s
	@echo -e "\033[33mMain       - OK\033[0m"
	@sleep 1
	@echo -e "\033[32mExecutando...\n---------------------\033[0m"
	@sleep 1
	@make exe -s

sequencial:
	gcc -c ./src/sequencial.c -I ./include -o ./obj/sequencial.o 

encadeada:
	gcc -c ./src/encadeada.c -I ./include -o ./obj/encadeada.o 

funcoes:
	gcc -c ./src/funcoes.c -I ./include -o ./obj/funcoes.o 

main:
	gcc ./main.c ./obj/funcoes.o ./obj/encadeada.o ./obj/sequencial.o -I ./include -o ./output/main.exe 

exe:
	./output/main.exe

repositorio:
	mkdir ./output
	mkdir ./obj
	
clear:
	rm ./output/main.exe
	rm ./obj/encadeada.o
	rm ./obj/sequencial.o
	rm ./obj/funcoes.o 


seq:
	make sequencial
	gcc ./main.c ./obj/sequencial.o -I ./include -o ./output/main.exe 

enc:
	make encadeada
	gcc ./main.c ./obj/encadeada.o -I ./include -o ./output/main.exe 

func:
	make funcoes
	gcc ./main.c ./obj/funcoes.o -I ./include -o ./output/main.exe