#include <stdio.h>
#include <stdlib.h>

int grade2grade(float grade){
	if( grade >= 90 ){
		return 95;
	}
	else if( grade >= 85 ){
		return 87;
	}
	else if( grade >= 80 ){
		return 82;
	}
	else if( grade >= 77 ){
		return 78;
	}
	else if( grade >= 73 ){
		return 75;
	}
	else if( grade >= 70 ){
		return 70;
	}
	else if( grade >= 67 ){
		return 68;
	}
	else if( grade >= 63 ){
		return 65;
	}
	else if( grade >= 60 ){
		return 60;
	}
	else{
		return 50;
	}
}

float grade2GPA(float grade){			//print the A+ sign and return the rank grade
	if( grade >= 90 ){
		printf("A+ ");
		return 4.3;
	}
	else if( grade >= 85 ){
		printf("A ");
		return 4.0;
	}
	else if( grade >= 80 ){		
		printf("A- ");
		return 3.7;
	}
	else if( grade >= 77 ){
		printf("B+ ");
		return 3.3;
	}
	else if( grade >= 73 ){
		printf("B ");
		return 3.0;
	}
	else if( grade >= 70 ){
		printf("B- ");
		return 2.7;
	}
	else if( grade >= 67 ){
		printf("C+ ");
		return 2.3;
	}
	else if( grade >= 63 ){
		printf("C ");
		return 2.0;
	}
	else if( grade >= 60 ){
		printf("C- ");
		return 1.7;
	}
	else{
		printf("F ");
		return 0;
	}
}

int main(){
	int n = 0;							//number of the students
	float sumGrade = 0, sumGPA = 0, sumRankGrade = 0;
	float grade;
	while( scanf("%f", &grade) != EOF ){
		n++;
		#ifdef HUNDRED
			printf("%.0f ", grade);
			sumGrade += grade;
		#endif
		#ifdef APLUS
			sumGPA += grade2GPA(grade);
			sumRankGrade += grade2grade(grade);
		#endif
	}
	sumGrade /= n;
	sumGPA /= n;
	sumRankGrade /= n;
	#ifdef APLUS
		printf("%.1f %.1f\n", sumGPA, sumRankGrade);
	#endif
	#ifdef HUNDRED
		printf("%.1f\n", sumGrade);
	#endif
}