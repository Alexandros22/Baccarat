#include <stdio.h>
#include <time.h>
#include <stdlib.h>

void main()
{
	int rand();
	char ans, ans2, ans3, ans4;
	int starting_money, i, j, y,  z,  m, h, bet, mp;
	int A[53];
	srand(time(NULL));
	do
	{
	    printf("Please put your starting money:"); // scan of starting money //
		fflush(stdin);
		scanf("%d", &starting_money);
		if (starting_money<0 || starting_money>500)
			printf("Wrong input! Your money must be between 0 and 500!\n");
	}while (starting_money<0 || starting_money>500);	// check of starting money //
	y=0;
	for (i=1;i<=4;i++)
	{
		for (j=1;j<=13;j++)
		{
			y=y+1;
			if (j>=10)		// create the cards //
				A[y]=0;
			else
				A[y]=j;
		}
	}
	do
	{
		for (i=52;i>=2;i=i-1)
		{
			A[0]=A[i];
			z=1+rand()%(i-1);	// stirring of cards //
			A[i]=A[z];
			A[z]=A[0];
		}
		i=52;
		do
		{
			m=(A[i]+A[i-1])%10;			// sum of player // 
			printf("\nYour cards' sum is:%d\n %d + %d\n", m, A[i], A[i-1]);
			do
			{
				printf("\nPut your bet:");	// scan of bet //
				fflush(stdin);
				scanf("%d", &bet);
				if (bet>starting_money || bet<=0)
					printf("Please careful with your money!!\n");
			}while (bet>starting_money || bet<=0);		// check the bet // 
			starting_money=starting_money-bet;				// money - bet //
			h=(A[i-2]+A[i-3])%10;		// sum of computer //
			do
			{
			    printf("\nDo you want other card? (Put Y for yes and N for no):");
				fflush(stdin);
			    scanf("%c", &ans);
				if (ans=='Y')
				{
					mp=m;
					m=(m+A[i-4])%10;	// an ans=Y then adds another card //
					printf("\nYour cards' sum is:%d\n %d + %d\n", m, mp, A[i-4]);
					i=i-1;
				}
				else if (ans=='N')
					printf("\nYour cards' sum is:%d\n", m); 	// else it continues //
			}while (ans!='Y' && ans!='N');		// check the ans //
			if (h==0)
			{
				printf("\nThe pc takes third card!\n");
				h=(h+A[i-5])%10;
				i=i-1;			// reduces the number of the cards //
			}
			else if (h<=4)
			{
				j=1+rand()%100;
				if (j<=30)
					printf("\nThe pc do not take the third card!\n");
				else
				{
					printf("\nThe pc takes third card!\n");		// possibility to take another card the computer //
					h=(h+A[i-5])%10;
					i=i-1;		// reduces the number of the cards //
				}
			}
			else if (h<=8)
			{
				j=1+rand()%100;
				if (j<=70)
					printf("\nThe pc do not take the third card!\n");
				else
				{
					printf("\nThe pc takes third card!\n");
					h=(h+A[i-5])%10;
					i=i-1;		// reduces the number of the cards //
				}
			}
			if (m>h)			// finds the winner //
			{
				starting_money=starting_money+(2*bet);
				printf("m=%d > h=%d\n", m, h);
				printf("\nYou won this round!! Your money is:%d\n", starting_money);
			}
			else
			{
				printf("m=%d < h=%d\n", m, h);
				printf("\nYou lost this round!! Your money is:%d\n", starting_money);
			}
			i=i-4;				// reduce the cards depending on how many they were pulled//
			printf("\nCards still here:%d\n",i);
			if (starting_money==0)			// if the money are over then the game ends //
				break;
			do
			{
				if (i==0)		// if the cards are over then stirring the cards and exit from this round //
					break;
			    printf("\nDo you want to see the rest of the cards? (Y/N):");
				fflush(stdin);
			    scanf("%c", &ans3);				 
			}while (ans3!='Y' && ans3!='N');	// check the ans3 // 
			if (ans3=='Y')
			{
				for (j=i;j>=1;j=j-1)
					printf("%d, ", A[j]);	// if ans3=Yes then shows the cards //
			}
			if (ans3=='Y')				// stirring the cards and exit from this round //
				ans2='E';
			else
			{
			    do
				{
			        printf("\nPress 'C' to continue or 'E' to ext!");
					fflush(stdin);
			        scanf("%c", &ans2);			
				}while (ans2!='C' && ans2!='E');	// check the ans2 //
			}
			
		}while (i>=6 && ans2=='C' && starting_money!=0);	// repeat the game when we have cards, money, and do not choose stirring of the cards // 
        if (starting_money==0)
		{
			printf("\nYou lose the game!!\n");	// if the money are over then the game ends //
			break;
		}
		do
		{
		    printf("\nPress 'R' to reboot the cards or 'E' to exit!");
			fflush(stdin);
			scanf("%c", &ans4);		
		}while (ans4!='R' && ans4!='E');	// check the ans4 //
	}while (ans4!='E');	// repeat or finish the game through the ans4 //
}
