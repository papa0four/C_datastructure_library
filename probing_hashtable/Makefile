test: 
	gcc -Wall include/hashtable.h src/hashtable.c tests/main_tests.c tests/hashtable_tests.c -lcunit -Wno-unused-function -Wno-int-to-pointer-cast -Wno-pointer-to-int-cast -o hashtable_tests
	./hashtable_tests
	rm hashtable_tests*