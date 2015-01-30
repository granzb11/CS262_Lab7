#include <stdio.h>
#include <stdlib.h>

#define ARRAYLEN 2000

//In this program I do a few different things. I read in a number from the keyboard to set my seed for my random number generator. I then use that seed to generate a random number between 10 to 200 which will determind the SIZE of my array. Then I go ahead an initialize an array, myArray, with random generated integers between 0 and 1000. In here I also show how I would write to a file if I need to later.
int main(int argc, char **argv)
{

        int myArray[ARRAYLEN];
        int i;

        //Declaring the variable for seed
        int seed;
        char myFileName[20];

        //This is where the program takes in the command line. "argv[1] will be the second argument read in from the command line which is going to be a number that will be used as the seed for the random number generator
        sscanf(argv[1], "%d", &seed);

        //This is where I will be using the seed read in from the command line and plugging it into srand to seed the random number generator
        srandom(seed);

        //This is where I will generate a random number between 10 to 200 (there are two ways to do this!!)
        //int r is our random number generated between 10 to 200 to initiliaze my array
        int r = random()%(1900+1)+100;

        //200 is max, 10 is min
        //int r = rand()%(200-10+1)+10;

        //This is where I will initialize myArray with random numbers from 0 to 1000 with size r
        for(i=0; i<r; i++)
        {
                myArray[i] = random()%(5000+1);
                //fprintf(stdout, "%d\n", myArray[i]);
        }

        // Declare pointer to the file
        FILE *ofp;

        //Create my file name that I want data written to
        char outputFilename[] = "myFileName";

        //In order to open a file, use the function fopen(), I am also going to use "w" because I am writing to this file
        ofp= fopen(outputFilename, "w");


        //This is where I will be writing the random generated values of my array into my file 
        for(i=0; i<r; i++)
        {
                int c;
                c = myArray[i];
                fprintf(ofp, "%d\n", myArray[i]);
                printf("%d\n", myArray[i]);
                //putchar(c);
        }




}

