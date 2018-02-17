all:
	gcc os_hw1.c -o os_hw1
	gcc cat.c -o cat
	gcc mkdir.c -o mkdir
	gcc rm.c -o rm
	gcc ls.c -o ls
	gcc date.c -o date
clean:
	rm os_hw1
	rm cat
	rm mkdir
	rm date
	rm rm
	rm ls