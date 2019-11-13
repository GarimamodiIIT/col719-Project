#include "baseline.h"



int main()
{
	
	int input[C][H][W];
	int kernel[M][K][K][C];
	int output[M][H][W];
	FILE *fptr;
	int i, j, k, l;
	printf("%d, %d, %d, %d, %d", C, H, W, K, M);
	fptr=fopen("image.dat", "r");
	
	for(i=0;i<C;i++)
		for(j=0;j<H;j++)
			for(k=0;k<W;k++)
			{
				fscanf(fptr, "%d", &input[i][j][k]);
				
			}
			
	
	fclose(fptr);
	
	fptr=fopen("kernel.dat", "r");
	
	for(i=0;i<M;i++)
	{
		for(j=0;j<K;j++)
		{
			for(k=0;k<K;k++)
			{
				for (l=0;l<C;l++)
				{
					fscanf(fptr, "%d", &kernel[i][j][k][l]);
					
				}
			}
		}
	}
	fclose(fptr);

	baseline(input, kernel, output);
	fptr=fopen("output.dat", "w");
	for(i=0;i<M;i++)
		for(j=0;j<H-K+1;j++)
			for(k=0;k<W-K+1;k++)
				fprintf(fptr, "%d ", output[i][j][k]);
	fclose(fptr);
	
	printf("Comparing against data\n");
	if (system("diff -w output.dat output_expected.dat")) {

	fprintf(stdout, "*******************************************\n");
	fprintf(stdout, "FAIL: Output DOES NOT match the expected output\n");
	fprintf(stdout, "*******************************************\n");
     return 0;
  } else {
	fprintf(stdout, "*******************************************\n");
	fprintf(stdout, "PASS: The output matches the expected output!\n");
	fprintf(stdout, "*******************************************\n");
     return 0;
  }
	return 0;
}
