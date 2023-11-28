#include <stdio.h>
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
	while(fscanf(f, "%s %d %s %d", mn.drinks, &mn.dprice, mn.food, &mn.fprice) == 4)
		printf("%s %d %s %d\n", mn.drinks, mn.dprice, mn.food, mn.fprice);
	fclose(f);
}

/*int binsearch(int *num, int n, int key){
	int left = 0;
	int right = n - 1;
	int index = -1;
	while(left <= right){
		int mid = (left + right)/2;
		if(key == num[mid]){
			index = mid;
			break;
		}
		if(key < num[mid])
			right = mid - 1;
		else
			left = mid + 1;
	}
	return index;
}

void search(){
	FILE*f = fopen("file.txt", "r");
	if(f == NULL){
		printf("error");
		return;
	}
	int a[sizeof(menu)];
        menu mn;
        while(fscanf(f, "%s %d %s %d", mn.drinks, &mn.dprice, mn.food, &mn.fprice) == 4){
		for(int i = 0; i < sizeof(menu); i++)
			fscanf(f, "%d", &a[i]);
	}
	int key;
	scanf("%d", &key);
	int index = binsearch(a, sizeof(menu), key);
	if(index >= 0)
		printf("find %d in %d\n", a[index], index);
	else
		printf("not found\n");
	fclose(f);
}*/

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
		else
			printf("error\n");
	}
	fclose(f);
}
