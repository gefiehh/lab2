#include <stdio.h>
#include <stdlib.h>
#include "lab2.h"

void write(){
	FILE*f = fopen("file.txt", "w");
	if(f == NULL){
		printf("error\n");
		return;
	}
	int n;
	printf("n = ");
	scanf("%d", &n);
	menu mn;
	for(int i = 0; i < n; i++){
		printf("drink - ");
		scanf("%s", mn.drinks);
		printf("price of drink - ");
		scanf("%d", &mn.dprice);
		printf("food - ");
                scanf("%s", mn.food);
                printf("price of food - ");
                scanf("%d", &mn.fprice);
		fprintf(f, "%s %d %s %d\n", mn.drinks, mn.dprice, mn.food, mn.fprice);
	}
	fclose(f);
}

void read(){
	FILE*f = fopen("file.txt", "r");
	if(f == NULL){
		printf("error\n");
		return;
	}
	menu mn;
	int count = 0;
	char arr[100];
	while(fscanf(f, "%s %d %s %d", mn.drinks, &mn.dprice, mn.food, &mn.fprice) == 4)
		count++;
	rewind(f);
	menu*arr = (menu*)calloc(count, sizeof(menu));
	for(int i = 0; i < count; i++){
		fscanf(f, "%s %d %s %d", arr[i].drinks, &arr[i].dprice, arr[i].food, &arr[i].fprice);
		printf("%s %d %s %d\n", arr[i].drinks, &arr[i].dprice, arr[i].food, &arr[i].fprice);
	}
	free(arr);
	fclose(f);
}

void search(){
	FILE*f = fopen("file.txt", "r");
        if(f == NULL){
                printf("error\n");
                return;
        }
	int key;
	scanf("%d", &key);
	menu mn;
	while(fscanf(f, "%s %d %s %d", mn.drinks, &mn.dprice, mn.food, &mn.fprice) == 4){
		if(mn.dprice == key)
			printf("%d is price of %s\n", mn.dprice, mn.drinks);
		if(mn.fprice == key)
			printf("%d is price of %s\n", mn.fprice, mn.food);
		if(mn.dprice != key and mn.frice != key)
			printf("error\n");
	}
	fclose(f);
}
