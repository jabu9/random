// Jabu9
// Banker's Algorithm

#include <stdio.h>

#define MAX_LINES 100
#define MAX_LEN 100

void showData()
{
      
  char data[MAX_LINES][MAX_LEN];

  FILE *file;
  file = fopen("input.txt", "r");
    
  if(file == NULL)
  {
    printf("ERROR...File cannot be opened\n");
      //return 1; // close
  }

  // Line lets us know how many lines in the file
  int line = 0;
  while(!feof(file) && !ferror(file))
      if (fgets(data[line], MAX_LEN, file) != NULL)
        line++;

    fclose(file);

  for (int index = 0; index < line; index++)
    printf("%s", data[index]);
}

void bank_algorithm()
{
  
  int n, m, i, j, k;
	n = 7; // # of processes
	m = 5; // # of resources
  
	int allocation[7][5] = { { 0, 1, 2, 2, 3 }, // P0 // Allocation Matrix
                					 { 1, 0, 0, 0, 0 }, // P1
                					 { 3, 0, 2, 3, 1 }, // P2
                					 { 2, 1, 1, 0, 4 }, // P3
                           { 0, 0, 2, 2, 1 }, // P4
                           { 1, 2, 3, 0, 1 }, // P5
                					 { 6, 6, 4, 4, 0 } }; // P6

	int max[7][5] = { { 0, 1, 2, 2, 3 }, // P0 // MAX Matrix
                		{ 1, 2, 4, 7, 0 }, // P1
                		{ 4, 1, 5, 6, 3 }, // P2
                		{ 3, 3, 6, 7, 5 }, // P3
                    { 2, 0, 4, 3, 4 }, // P4
                    { 4, 3, 6, 3, 2 }, // P5
                		{ 6, 7, 3, 5, 2 } }; // P6

	int available[5] = { 1, 5, 2, 3, 0 }; // Available Resources

	int f[n], ans[n], ind = 0;
	for (k = 0; k < n; k++) {
		f[k] = 0;
	}
	int need[n][m];
	for (i = 0; i < n; i++) {
		for (j = 0; j < m; j++)
			need[i][j] = max[i][j] - allocation[i][j];
	}
	int y = 0;
	for (k = 0; k < 5; k++) {
		for (i = 0; i < n; i++) {
			if (f[i] == 0) {

				int flag = 0;
				for (j = 0; j < m; j++) {
					if (need[i][j] > available[j]){
						flag = 1;
						break;
					}
				}

				if (flag == 0) {
					ans[ind++] = i;
					for (y = 0; y < m; y++)
						available[y] += allocation[i][y];
					f[i] = 1;
				}
			}
		}
	}

	int flag = 1;
	
	for(int i=0;i<n;i++)
	{
	if(f[i]==0)
	{
		flag=0;
		printf("\nThe following system is not safe");
		break;
	}
	}
	
	if(flag==1)
	{
	printf("\n\nSAFE Sequence:\n");
	for (i = 0; i < n - 1; i++)
		printf(" P%d ->", ans[i]);
	printf(" P%d", ans[n - 1]);
	}

}

int main()
{
  
  // Title
  printf("\nBankers Algorithm\n");

  // Show data from input file
  showData();

  // Show solution to algorithm
  bank_algorithm();

	return (0);
}
