OBJS=fonctions.o direction.o lancer_jeu.o
CC=gcc
PROG=puiss
OPTS=-Wall -g



puiss : main.c ${OBJS}
		${CC} -o ${PROG} ${OBJS} main.c ${OPTS}

fonctions.o: fonctions.c
	${CC} -c fonctions.c ${OPTS} 

main.o: main.c 
	${CC} -c main.c ${OPTS}

direction.o: direction.c
	${CC} -c direction.c ${OPTS}  

lancer_jeu.o: lancer_jeu.c
	${CC} -c lancer_jeu.c ${OPTS}   

clean : 
	rm -f  *.o ${PROG}
