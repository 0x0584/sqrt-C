#include <stdio.h>
#include <stdlib.h>
 #define KRED  "\x1B[31m"
 #define RESET "\033[0m"
 #define KYEL  "\x1B[33m"
 #define KBLU  "\x1B[34m" 
int main (int argc, char *argv[]) {
	double val, min, max; 
	double sqrt;
	double S, _sqrt;
	int cnt = 0;
	
	// enter an argument,
	
	if (argc < 2) {
		printf ("Usage: sqrt <number>\n");
		return 1;
	}
	    val = fabs (atof (argv[1]));// <force to non-negative.>
	if ( val < 1.0 )
		{
		min = val;        
		max = sqrt = 1.0; // if val < 1.0 result is greater than val but less than 1.0
		}
	 else
	{
		min = 0;          //minimum 
	        max = sqrt = val; //maximum
	} 
		//1e-8 = 10^(-8) = 0.00000001
		do
		{
		_sqrt = sqrt;//keep the old sqrt
	        sqrt = (max + min) / 2;
		S = sqrt * sqrt;
			printf("test n(%d)\tsqrt(%f) = %.6f\t",++cnt,val, sqrt);
			if (S > val) {
				puts("too high");
				printf(KYEL);//switching the console to yellow
				printf("\t\t=%s %f\n","the old max",max);
				printf("\t\t=%s %f\n","the old min",min);
				max = sqrt;//setting max to the current mid
				printf("\t\t>%4s %f","the new max",max);
				printf(RESET);//restet the console color
			} else {
				puts("too low");
				printf(KBLU);
				printf("\t\t-%s %f\n","the old max",max);
				printf("\t\t-%s %f\n","the old min",min);
				min = sqrt;//setting min to the current mid
				printf("\t\t>%4s %f","the new min",min);
				printf(RESET);
			}//end else
			puts("");
		}while (fabs(_sqrt - sqrt) >= 1e-8);
		puts("");
		printf(KRED);
		puts("\t====================================================");
		printf ("\tfinal value.\tsqrt(%f) = %.6f\n", val, sqrt);
		puts("\t====================================================");
		printf(RESET);
	return 0;
}//end main()
