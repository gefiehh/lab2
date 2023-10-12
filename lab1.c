#include <stdio.h>
#include <math.h>
#include <stdlib.h>

int main(){
	for(float x = 1; x >= 1 && x <= 2; x += 1){
		for(float z = 1; z >= 1 && z <= 3; z += 2){
			for(float y = 0.1; y >= 0.1 && y <= 0.7; y += 0.7){
				float u = (1 / tan(pow(x, y) + 3 * (pow(z, 2)))) - log(abs((pow(x, 3) - y) / z));
				printf("x = %f , y = %f , z = %f , u(x, y, z) = %f \n", x, y, z, u);
			}
		}
	}
}
