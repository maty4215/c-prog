#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int shuff(int cards[])
{
	
	int t;
	int i;
	int desk[52];	
	for (i=0;i<52;i++)
		desk[i] = (i/13+3)*100 + i%13 + 1;

	srand(time(NULL));
	for (i = 0; i < 52; i++)
	{
		do
		{
			t = rand() % 52;
		} while (desk[t] == 0);
		cards[i] = desk[t];
		desk[t] = 0;
	}
	
	return 0;
}

int convert_jkq(int a)
{
	if ((a%100==11) ||(a%100==12) ||(a%100==13)) return (a/100)*100+10;
	else return a;
}

void pic(int num)
{
	char fl;
	int po_num;
	
	fl = num / 100;
	po_num = num % 100;
	switch (po_num)
	{
		case 1: 
		{
			printf("%c\n", fl);
			printf(" A\n");
			break;
		}
		case 2:
		case 3:
		case 4:
		case 5:
		case 6:
		case 7:
		case 8:
		case 9:
		case 10:
		{
			printf(" %c\n", fl);
			printf("%2d\n", po_num);
			break;
		}
		case 11:
		{
			printf("%c\n", fl);
			printf(" J\n");
			break;
		}
		case 12:
		{
			printf("%c\n", fl);
			printf(" Q\n");
			break;
		}
		case 13:
		{
			printf("%c\n", fl);
			printf(" K\n");
			break;
		}

	}
}

int play(void)
{
	int i;
	int psum=0;
	int bsum=0;
	int pcards[5]={0};
	int bcards[5]={0};
	int cards[52];
	char go_on;
	char d;
	
	printf("Vítej v BLACKJACKOVI\n"
	"Stiskněte ENTER pro start\n");
	do{
		go_on = getchar();
	} while (go_on != '\n');
	printf("\n");
	
	shuff(cards);

	pcards[0]=cards[0];
	pcards[1]=cards[1];
	bcards[0]=cards[2];
	bcards[1]=cards[3];
	
	printf("Jedna ze soupeřových karet:\n");
	pic(bcards[0]);
	printf("\n");
	printf("Vaše karty:\n");
	pic(pcards[0]);
	pic(pcards[1]);
	
	i=0;
	for (i=0; i<2; i++)
	{
		if (pcards[i]%100 == 1)
		{
			printf("Vyberte hodnotu karty %d, Zadejte 'y' pro 11 nebo 'n' pro 1 :\n", i+1);
			do{
				d = getchar();
			} while (d!='y' && d!='n');
			
			if (d == 'y')
			{
				printf("Vybrali jste hodnotu 11 pro kartu A.\n");
				psum = psum + 11;
			}
			else if(d == 'n')
			{
				printf("Vybrali jste hodnotu 1 pro kartu A.\n");
				psum = psum +1;
			}
		}
		else if (convert_jkq(pcards[i]) %100 ==10) psum = psum + 10;
		else psum = psum + pcards[i]%100;
		
		if (psum > 21)
		{
			printf("Balíček vašich karet:%d\n\n",psum);
			printf("Soupeř vyhrál\n");
			return 1;
		}
		else if (psum == 21)
		{
			printf("Balíček vašich karet:%d\n\n",psum);
			printf("Vyhrál jste!\n");
			return 0;
		}
	}
	printf("Balíček vašich karet:%d\n\n",psum);
	
	i=0;
	for (i=0; i<3; i++)
	{
		char j = 'n';
		
		printf("Chcete další karty? Zadejte y nebo n:\n");
		do{
			j = getchar();
		} while (j!='y' &&j!='n');
		
		if (j=='y')
		{
			pcards[i+2]=cards[i+4];
			printf("Vaše %d karta je:\n", i+3);
			pic(pcards[i+2]);
			
			if (pcards[i+2]%100 == 1)
			{
				printf("Vyberte hodnotu karty %d, Zadej 'y' pro 11 nebo 'n' pro 1:\n", i+3);
				do{
					d = getchar();
				} while (d!='y' && d!='n');	
				if (d == 'y')
				{
					printf("Vybrali jste hodnotu 11 pro kartu A.\n");
					psum = psum + 11;
				}
				else if(d == 'n')
				{
					printf("Vybrali jste hodnotu 1 pro kartu A.\n");
					psum = psum +1;
				}
			}
			else if (convert_jkq(pcards[i+2]) %100 ==10) psum = psum + 10;
			else psum = psum + pcards[i+2]%100;
			
			if (psum > 21)
			{
				printf("Balíček vašich karet:%d\n\n",psum);
				printf("Soupeř vyhrál\n");
				return 1;
			}
			else if (psum == 21)
			{
				printf("Balíčekvašich karet:%d\n\n",psum);
				printf("Vyhrál jste!\n");
				return 0;
			}		
			else printf("Balíček vašich karet:%d\n\n",psum);
		}
		else 
		{
			printf("Balíček vašich karet:%d\n\n",psum);
			break;
		}
	}
	if (i == 3)
	{
		printf("Soupeř vyhrál, součet vašich 5 karet není větší než 21\n");
		return 0;
	}
	
	printf("Soupeřovy karty:\n");
	pic(bcards[0]);
	pic(bcards[1]);

	if (bcards[0]%100 + bcards[1]%100 == 2)
	{
		bsum=12;
		printf("Balíček soupeřových karet:%d\n\n", bsum);
	}
	else if ((convert_jkq(bcards[0]))%100 + (convert_jkq(bcards[1]))%100 ==1)
	{
		bsum=21;
		printf("Balíček soupeřových karet:%d\n\n", bsum);
		printf("Soupeř vyhrál\n");
		return 1;
	}
	else if (bcards[0]%100==1 || bcards[1]%100==1)
	{
		bsum=(bcards[0]+bcards[1])%100+(rand()%2)*10;
		printf("Balíček soupeřových karet:%d\n\n", bsum);
	}
	else
	{
		bsum = (convert_jkq(bcards[0]))%100 + (convert_jkq(bcards[1]))%100;
		printf("Balíček soupeřových karet:%d\n\n", bsum);
	}

	for (i=0; i<3 && bsum<17; i++)
	{
		bcards[i+2]=cards[i+7];
		printf("Soupeřova %d karta je:\n", i+3);
		pic(bcards[i+2]);
		
		if (bcards[i+2]%100 == 1)
		{
			if (bsum+11 <= 21)
			{
				printf("Soupeř si vybral hodnotu 11 pro A\n");
				bsum = bsum+11;
				printf("Balíček soupeřových karet:%d\n\n", bsum);
			}
			else
			{
				printf("Soupeř si vybral hodnotu 1 pro A\n");
				bsum = bsum+1;
				printf("Balíček soupeřových karet:%d\n\n", bsum);
			}
		}
		else
		{
			bsum = bsum + convert_jkq(bcards[i+2])%100;
			printf("Balíček soupeřových karet:%d\n\n", bsum);
		}
	}
	if (i == 3)
	{
		printf("Soupeř vyhrál, balíček vašich 5 karet není větší než 21\n");
		return 1;
	}
	
	if (bsum>21 || psum>bsum)
	{
		printf("Soupeř vyhrál\n");
		return 0;
	}
	else if (psum == bsum)
	{
		printf("Máte stejný součet karet\n");
		return 3;
	}
	else if (psum < bsum)
	{
		printf("Soupeř vyhrál\n");
		return 1;
	}
		
	return 3;
}

int main(void)
{
	char znovu;
  
	play();
  
	printf("\nChtěl byste hrát znovu? Zadejte 'y' nebo 'n':\n");
	do{
		znovu = getchar();
	} while (znovu!='y' && znovu!='n');
   
	if (znovu == 'y')
	{
		main();
	}
  
	return 0;
}