#include <stdio.h>
#include <windows.h>
#include <malloc.h>
long int it, ostarr = 0, oenarr = 104999, place = 1, dstarr = 0, denarr = 24020, enar, *nomve;
char **Xmovesdata, **Omovesdata, **Dmovesdata;
int matrix(int n, char chr[n][n])
{
	int im = 0, t = n;
	xy(5, 5);
	printf("\t%c", 218);
	for (im = 0; im < n; im++)
	{
		printf("%c%c%c", 196, 196, 196);
		if (im < n - 1)
			printf("%c", 450);
	}
	printf("%c", 191);
	while (t > 0)
	{
		printf("\n\t%c", 179);
		t--;
		for (im = 0; im < n; im++)
		{
			printf(" %c %c", chr[t][im], 179);
		}
		if (t != 0)
		{
			printf("\n\t%c", 195);
			for (im = 0; im < n; im++)
			{
				printf("%c%c%c", 196, 196, 196);
				if (im < n - 1)
					printf("%c", 197);
			}
			printf("%c", 180);
		}
	}
	printf("\n\t%c", 192);
	for (im = 0; im < n; im++)
	{
		printf("%c%c%c", 196, 196, 196);
		if (im < n - 1)
			printf("%c", 193);
	}
	printf("%c", 217);
}

int xy(int x, int y)
{
	COORD san = {x, y};
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), san);
}

main()
{
	int i = 0, j, m = 1, k, n = 1, p = 0, result = 0, b[9], e = 1;
	char a[3][3];
	srand(time(NULL));
	nomve = (int *)malloc(50000 * sizeof(int *));
	for (i = 0; i < 3; i++)
	{
		for (j = 0; j < 3; j++)
		{
			a[i][j] = ' ';
		}
	}
	dataget();
	system("color 4f");
	printf("::::...X O Game...::::\n::::...An SKS Creation...::::\n\n\n ");
	printf("Lets play.....\n\n\n");
	matrix(3, a);
	while (p < 9)
	{
		m = 1;
		e = 1;
		n = (p % 2 == 0) ? 1 : 2;

		if (n == 1)
		{
			printf("Your Chance:");
			k = getch();
			k -= 48;
			b[p] = k;
		}
		else if (n == 2)
		{
			k = datapar(b[p - 1], 0);
			datapar(k, 1);
		}
		if (k <= 9)
		{
			if ((n == 1) && (a[(k - 1) / 3][(k - 1) % 3] == ' '))
			{
				a[(k - 1) / 3][(k - 1) % 3] = 'X';
				p++;
			}
			else if ((n == 2) && (a[(k - 1) / 3][(k - 1) % 3] == ' '))
			{
				a[(k - 1) / 3][(k - 1) % 3] = 'O';
				p++;
			}
			else
			{
				printf("\nAlready there..\n");
				getch();
			}
			system("cls");
			for (i = 0; i < 3; i++)
			{
				for (j = 0; j < 3; j++)
				{
					if (a[i][j] != a[i][j + 1])
					{
						break;
					}
					else
					{
						if ((j == 1) && a[i][j] != ' ')
						{
							printf("        GAME OVER!!!\n        %c WIns!!", a[i][j]);
							result = 1;
							goto san;
							break;
						}
					}
				}
			}
			for (i = 0; i < 3; i++)
			{
				for (j = 0; j < 3; j++)
				{
					if (a[j][i] != a[j + 1][i])
					{
						break;
					}
					else
					{
						if ((j == 1) && a[j][i] != ' ')
						{
							printf("        GAME OVER!!!\n        %c WIns!!", a[j][i]);
							result = 1;
							goto san;
							break;
						}
					}
				}
			}
			for (i = 0; i < 3; i++)
			{
				if (a[i][i] != a[i + 1][i + 1])
				{
					break;
				}
				else
				{
					if ((i == 1) && a[i][i] != ' ')
					{
						printf("        GAME OVER!!!\n        %c WIns!!", a[i][i]);
						result = 1;
						goto san;
						break;
					}
				}
			}
			for (i = 0, j = 2; i < 3 && j >= 0; i++, j--)
			{
				if (a[i][j] != a[i + 1][j - 1])
				{
					break;
				}
				else
				{
					if ((i == 1) && a[i][j] != ' ')
					{
						printf("        GAME OVER!!!\n        %c WIns!!", a[i][j]);
						result = 1;
						goto san;
						break;
					}
				}
			}
		san:
		{
			if (result == 1)
			{
				matrix(3, a);
				break;
			}
		}
			if (p == 9)
			{
				printf("GAME OVER!!!!                 Its a draw match....");
				break;
			}
			printf("Lets play.....\n\n\n");
			matrix(3, a);
		}
		else
		{
			printf("\nInvalid Choice\n");
			getch();
		}
	}
	getch();
}

dataget()
{
	FILE *dldata;
	long int diteration = 0, k = 0, i;
	Xmovesdata = (char **)malloc(212256 * sizeof(char *));
	for (i = 0; i < 212256; i++)
		Xmovesdata[i] = (char *)malloc(10 * sizeof(char));

	dldata = fopen("DeepLearneddata-X.txt", "r+");
	while (fgets(Xmovesdata[diteration], 10, dldata) != NULL)
	{
		if (Xmovesdata[diteration][0] != '\n')
			diteration++;
	}
	fclose(dldata);

	diteration = 0;
	Omovesdata = (char **)malloc(105000 * sizeof(char *));
	for (i = 0; i < 105000; i++)
		Omovesdata[i] = (char *)malloc(10 * sizeof(char));

	dldata = fopen("DeepLearneddata-O.txt", "r+");
	while (fgets(Omovesdata[diteration], 10, dldata) != NULL)
	{
		if (Omovesdata[diteration][0] != '\n')
		{
			if (strlen(Omovesdata[diteration]) < 3)
			{
				nomve[diteration - 1] = Omovesdata[diteration][0] - 48;
			}
			else
				diteration++;
		}
	}
	fclose(dldata);

	diteration = 0;
	Dmovesdata = (char **)malloc(50000 * sizeof(char *));
	for (i = 0; i < 50000; i++)
		Dmovesdata[i] = (char *)malloc(10 * sizeof(char));

	dldata = fopen("DeepLearneddata-D.txt", "r+");
	while (fgets(Dmovesdata[diteration], 10, dldata) != NULL)
	{
		if (Dmovesdata[diteration][0] != '\n')
			diteration++;
	}
	fclose(dldata);
}

datapar(long int k, int dec)
{
	int epar = 0, nofnd = 0, che = 10;
	for (it = ostarr; it <= oenarr; it++)
	{
		if ((Omovesdata[it][place - 1] - 48) == k)
		{
			if (nomve[it] < che)
			{
				ostarr = it;
				che = nomve[it];
			}
			enar = it;
			nofnd = 1;
		}
	}
	oenarr = enar;
	for (it = dstarr; it <= denarr; it++)
	{
		if ((Dmovesdata[it][place - 1] - 48) == k)
		{
			if (epar == 0)
			{
				dstarr = it;
				epar = 1;
			}
			enar = it;
		}
	}
	denarr = enar;
	place++;
	if (nofnd == 1 && dec != 1)
	{
		return (Omovesdata[ostarr][place - 1] - 48);
	}
	else if (nofnd == 0 && dec != 1)
	{
		return (Dmovesdata[dstarr][place - 1] - 48);
	}
}
