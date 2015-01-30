#include <stdio.h>
#include <stdlib.h>
#define ARRAYLEN 100



void main()
{
	int i= 0;
	int j, key, counter;
	int myArray[ARRAYLEN];
	char line[ARRAYLEN]; //array of characters to read in the numbers with fgets because fgets requires an array of characters
	int c;
	int *ip; //This is the "array" pointer that I will assign to point to the memory allocated by malloc()
	int nalloc; //This will be the variable that I will append to, to extend the size of my "array"
	int nitems; //This is the variable that will hold the ACTUAL number of items/integers in the array

	nalloc = 100; //Initializing nalloc to 100 because in the specs it says we should originally start by only allocating 100 free spaces in the array
	ip = malloc(nalloc * sizeof(int)); //Initializing the array size to 100, we must use sizeof function included in the "stdio.h" library to convert the integer value to bytes for the computer language to know how much space to allocate

	if(ip == NULL)
	{
		printf("Out of memory, terminating program. \n");
		exit(1);
	}
	nitems =0; //Initializing nitems to 0 because we have not yet read in any items


	printf("\n------------Unsorted Array-------\n");

	//This is where I will be reading in the values from the "keyboard" aka integers coming in from GenNums and assigning them to my array. I used fgets to that and sscanf to convert the characters read in into integers and actually assigning them to my array.
	while( fgets(line, sizeof(line), stdin) !=0)    
	{
		if(nitems >= nalloc)
		{
			int *newp;
			nalloc +=100;
			newp = (int *)malloc(nalloc * sizeof(int));
			if(newp == NULL)
			{
				printf("Out of memory, terminating program. \n");
				//exit(1);
			}

			for(i=0; i<nitems; i++)
			{
				newp[i] = ip[i];
			}
			free(ip);
			ip = newp;
		}
		sscanf(line, "%d", &c); 
		ip[nitems] = c;
		printf( "'Array' value %d is: %d\n ", nitems, ip[nitems]);
		nitems++;
	}

	counter =nitems; //I am using this counter to keep track of how many numbers come in and get stored in myArray so that I can sort through that array later since the array length right now is 200 and I'm not quite sure how many are actually going to come in from the keyboard.

	// This is the implementation of my lab3 "SortArray" algorithm/function
	for(j=1; j<nitems; j++)
	{
		i=j;

		if(ip[i] == ip[i-1])
			i--;
		while(i>0 && ip[i]<=ip[i-1])
		{
			key = ip[i];
			ip[i] = ip[i-1];
			ip[i-1] = key;
			i--;
		}
	}
	// Printing of the sorted array
	printf("\n\n-----------Sorted Array----------\n");

	for(i=0; i<counter; i++)
	{
		printf(" Array value %d is: %d\n", i, ip[i]);
	}
}

