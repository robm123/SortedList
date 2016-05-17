all: sl


linkList.o: linkList.c sorted-list.h
	gcc -c linkList.c
 
main.o: main.c sorted-list.h
	gcc -c main.c
 
libsl.a: linkList.o
	ar rvs libsl.a linkList.o
 
sl: main.o libsl.a
	gcc -o sl main.o libsl.a


clean:
	rm -f sl
	rm -f *.o
	rm -f *.a
