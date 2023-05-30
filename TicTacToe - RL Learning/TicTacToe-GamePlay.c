#include <stdio.h>
int matrix(char chr[3][3])
{
    printf("%c%c%c%c%c%c%c%c%c%c%c%c%c", 218, 196, 196, 196, 450, 196, 196, 196, 450, 196, 196, 196, 191);
    printf("\n%c %c %c %c %c %c %c", 179, chr[2][0], 179, chr[2][1], 179, chr[2][2], 179);
    printf("\n%c%c%c%c%c%c%c%c%c%c%c%c%c", 195, 196, 196, 196, 197, 196, 196, 196, 197, 196, 196, 196, 180);
    printf("\n%c %c %c %c %c %c %c", 179, chr[1][0], 179, chr[1][1], 179, chr[1][2], 179);
    printf("\n%c%c%c%c%c%c%c%c%c%c%c%c%c", 195, 196, 196, 196, 197, 196, 196, 196, 197, 196, 196, 196, 180);
    printf("\n%c %c %c %c %c %c %c", 179, chr[0][0], 179, chr[0][1], 179, chr[0][2], 179);
    printf("\n%c%c%c%c%c%c%c%c%c%c%c%c%c", 192, 196, 196, 196, 193, 196, 196, 196, 193, 196, 196, 196, 217);
}
main()
{
    FILE *mcdata;
    int i = 0, j, m = 1, n = 1, p = 0, result = 0, b[9], e = 1, diteration = 0, playerchance = 0, datalength[100], datal, datac, datalrem = 0, datacrem = 0;
    char a[3][3], moves[10], k, movesdata[100][20];
    srand(time(NULL));
    mcdata = fopen("winsdata.txt", "r+");
    while (fgets(movesdata[diteration], 20, mcdata) != NULL)
    {
        diteration++;
    }
    for (i = 0; i < diteration; i++)
    {
        datalength[i] = strlen(movesdata[i]) - 1;
    }
    fclose(mcdata);
    for (i = 0; i <= 3; i++)
    {
        for (j = 0; j <= 3; j++)
        {
            a[i][j] = ' ';
        }
    }
    system("color 4f");
    mcdata = fopen("winsdata.txt", "a");
    printf("::::X O Game...::::\n::::An SKS Creation...::::\n\n\n ");
    printf("Lets play.....\n\n\n");
    matrix(a);
    while (p < 9)
    {
        m = 1;
        e = 1;
        int decider = 0;
        if (p % 2 == 0)
        {
            n = 1;
        }
        else
        {
            n = 2;
        }
        if (n == 1)
        {
            printf("\nPlayer %d chance:", n);
            k = getch();
            k -= 48;
            b[p] = k;
        }
        else if (n == 2)
        {
            if (diteration == 0)
            {
                decider = 1;
            }
            for (datac = datacrem; datac < diteration && decider == 0; datac++)
            {
                for (datal = datalrem; datal < datalength[datac]; datal++)
                {
                    int placeiter = 1;
                    for (i = 0; i < 3; i++)
                    {
                        for (j = 0; j < 3; j++)
                        {
                            if (movesdata[datac][datal] - 64 == placeiter)
                            {
                                if (a[i][j] == ' ' || a[i][j] == 'O')
                                {
                                    if (datal == datalength[datac] - 1)
                                    {
                                        datal = datalrem;
                                        k = movesdata[datac][datal] - 64;
                                        b[p] = k;
                                        datalrem = datal + 1;
                                        datacrem = datac;
                                        j = 10;
                                        i = 10;
                                        datal = -1;
                                        datac = -2;
                                    }
                                }
                                else
                                {
                                    j = 10;
                                    i = 10;
                                    datal = -1;
                                    if (datalrem != 0)
                                    {
                                        datac = -1;
                                    }
                                    datalrem = 0;
                                    datacrem = 0;
                                    if (datac == diteration - 1)
                                    {
                                        decider = 1;
                                    }
                                }
                            }
                            placeiter++;
                        }
                    }
                    if (datal == -1)
                    {
                        break;
                    }
                }
                if (datac == -2)
                {
                    break;
                }
            }
            if (decider == 1)
            {
                while (e == 1)
                {
                    k = rand() % 10;
                    for (i = 0; i < p; i++)
                    {
                        if (b[i] == k)
                        {
                            break;
                        }
                        else
                        {
                            if (i == (p - 1))
                            {
                                e = 0;
                                b[p] = k;
                            }
                        }
                    }
                }
            }
        }
        if (k <= 9)
        {
            for (i = 0; i < 3; i++)
            {
                for (j = 0; j < 3; j++)
                {
                    if (k == m)
                    {
                        if ((n == 1) && (a[i][j] == ' '))
                        {
                            a[i][j] = 'X';
                            moves[playerchance] = k + 64;
                            playerchance++;
                            moves[playerchance] = '\0';
                            p++;
                        }
                        else if ((n == 2) && (a[i][j] == ' '))
                        {
                            a[i][j] = 'O';
                            p++;
                        }
                        else
                        {
                            if (n == 1)
                            {
                                printf("\nAlready there..");
                                getch();
                            }
                        }
                        i += 3;
                        break;
                    }
                    m++;
                }
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
                            if (a[i][j] == 'X')
                            {
                                fputs(moves, mcdata);
                                fputs("\n", mcdata);
                            }
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
                            if (a[i][j] == 'X')
                            {
                                fputs(moves, mcdata);
                                fputs("\n", mcdata);
                            }
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
                        if (a[i][j] == 'X')
                        {
                            fputs(moves, mcdata);
                            fputs("\n", mcdata);
                        }
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
                        if (a[i][j] == 'X')
                        {
                            fputs(moves, mcdata);
                            fputs("\n", mcdata);
                        }
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
                break;
            }
        }
            if (p == 9)
            {
                printf("GAME OVER!!!!                 Its a draw match....");
                break;
            }
            printf("Lets play.....\n\n\n");
            matrix(a);
        }
        else
        {
            printf("\nInvalid Choice");
            getch();
        }
    }
    getch();
}
