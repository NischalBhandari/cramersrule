#include <stdio.h>


float Determinant(float Matrix[3][3]){
	//this function finds the determinant of the Matrix 3x3 passed into it.
	return (Matrix[0][0]*(Matrix[1][1]* Matrix[2][2]-Matrix[1][2]*Matrix[2][1]) - Matrix[0][1]*(Matrix[1][0]*Matrix[2][2] - Matrix [1][2]*Matrix[2][0]) + Matrix[0][2]*(Matrix[1][0]*Matrix[2][1]-Matrix[1][1]*Matrix[2][0]));
}
void myDisplay(float Matrix[3][3]){
	//this function displays the matrix passed to it [3][3] matrix only.
	for(int i=0; i <3 ; i++){
	for (int j=0; j <3 ; j++){
		printf("%.3f\t",Matrix[i][j]);
	}
	printf("\n");
}
}
// this function divides Dx, Dy and Dz by D which are D[1], D[2], D[3] and D[0] respectively.
//This is the essence of cramers rule for finding the solution .
int result(float Matrix[4]){
	if(Matrix[0] == 0){
		return 2;
	}
	for(int i=1;i <4 ;i++){
		printf("The %d solution is: %.3f\n",i,Matrix[i]/Matrix[0]);
	}
	return 0;
}
int main(){
float TempMatrix[3][3];
float MyMatrix[3][3];
float vectors[3];
float determinant[3];
for(int i = 0; i< 3 ;i++){
	for (int j = 0 ; j <3 ;j++){
		scanf("%f\n",&MyMatrix[i][j]);
	}
}
for(int i=0; i<3 ;i++){
	scanf("%f\n", &vectors[i]);
}
myDisplay(MyMatrix);
printf("The vectors are : ");
for(int i=0 ; i<3; i++){
	printf("%.3f\t",vectors[i]);
}
printf("\n");

//find the determinant of the original matrix D
determinant[0] = Determinant(MyMatrix);
printf("The determinant of the  D is %.3f\n",determinant[0]);

//Now just replace each column with the vectors
for(int z=0;z<3;z++){
	// now here we are just assigning each data to the temporary matrix 
	for (int i=0; i<3;i++){
		for (int j=0; j<3; j++){
			TempMatrix[i][j]= MyMatrix[i][j];
		}
	}
	// now we are assigning each  column z with vectors that is required for cramers.
	for(int k=0; k< 3; k++){
 		TempMatrix[k][z]=vectors[k];
	}
// we are displaying the matrix for the user 
myDisplay(TempMatrix);
// now we find determinant for Dx Dy and Dz(Temporary Matrix) using the Determinant Function 
determinant[z+1] = Determinant(TempMatrix);
//print the determinant for each Dx , Dy and Dz . z+1 is used because D[0] is used 
//for variables quotient matrix or D.
printf("The determinant for x D[%d] is : %.3f\n", z,determinant[z+1]);
}
// now this function is used to divide each Dx, Dy and Dz by D to get the X, Y and Z solution
if(result(determinant))
	printf("Determinant is zero\n");
	printf("\n");




return 0;

}