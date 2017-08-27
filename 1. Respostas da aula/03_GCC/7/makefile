ola_num_caracs_1: ola_num_caracs1.o num_caracs.o
	gcc $(CFLAGS) -o ola_num_caracs_1 ola_num_caracs_1.o num_caracs.o
ola_num_caracs_1.o: ola_num_caracs_1.c num_caracs.h
	gcc $(CFLAGS) -c ola_num_caracs_1.c
num_caracs.o: num_caracs.c num_caracs.h
	gcc $(CFLAGS) -c num_caracs.c
clean:
	rm -f *.o ola_num_caracs_1
