#include <stdio.h>
#include <math.h>

//helper function
float getLength(float xa, float ya, float xb, float yb){
  return (float)sqrt((xa-xb)*(xa-xb)+(ya-yb)*(ya-yb));
}

float getArea(float ab, float bc, float ac){
	float s = (ab+bc+ac)/2.0;
	return (float)sqrt(s*(s-ab)*(s-bc)*(s-ac));
}

int main(void){
	float a_x, a_y, b_x, b_y, c_x, c_y;
	float ab, bc, ac;
	printf("Enter the x- and y-coordinates of point A: \n");
	scanf("%f %f", &a_x, &a_y);
	printf("Enter the x- and y-coordinates of point B: \n");
	scanf("%f %f", &b_x, &b_y);
	printf("Enter the x- and y-coordinates of point C: \n");
	scanf("%f %f", &c_x, &c_y);
	
	ab = getLength(a_x, a_y, b_x, b_y);
	bc = getLength(c_x, c_y, b_x, b_y);
	ac = getLength(a_x, a_y, c_x, c_y);
	
	printf("Length of AB is %.3f\n", ab);
	printf("Length of BC is %.3f\n", bc);
	printf("Length of AC is %.3f\n", ac);
	printf("Circumference is %.3f\n\n", ab+bc+ac);
	
	printf("Area is %.3f\n", getArea(ab, bc, ac));
	return 0;
}
