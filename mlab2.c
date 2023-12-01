#include <stdio.h>
#include "lab2.h"

int main(){
	int keykey;
	printf("1 - write, 2 - read, 3 - search\n");
	scanf("%d", &keykey);
	switch(keykey){
		case 1:
			write();
			break;
		case 2:
			read();
			break;
		case 3:
			search();
			break;
		default:
			printf("error\n");
	}
	return 0;
}
