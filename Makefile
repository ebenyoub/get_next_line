10:
	gcc -Wall -Werror -Wextra -g -D BUFFER_SIZE=10 *.c
	./a.out

1:
	gcc -Wall -Werror -Wextra -g -D BUFFER_SIZE=10 *.c
	./a.out
	
9:
	gcc -Wall -Werror -Wextra -g -D BUFFER_SIZE=10 *.c
	./a.out

1000:
	gcc -Wall -Werror -Wextra -g -D BUFFER_SIZE=1000 *.c
	./a.out

100:
	gcc -Wall -Werror -Wextra -g -D BUFFER_SIZE=100 *.c
	./a.out

10000:
	gcc -Wall -Werror -Wextra -g -D BUFFER_SIZE=10000 *.c
	./a.out
	
100000:
	gcc -Wall -Werror -Wextra -g -D BUFFER_SIZE=10000 *.c
	./a.out

1000000:
	gcc -Wall -Werror -Wextra -g -D BUFFER_SIZE=10000 *.c
	./a.out

val:
	valgrind --leak-check=full ./a.out