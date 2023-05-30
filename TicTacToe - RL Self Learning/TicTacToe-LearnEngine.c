#include<suriv.h>
long int iter=0,mn=370000,nofmv=0,tofmv=0;
char b[370000][10];
long int combo(long int cn)
{
	long int ca[cn+1],cm=0,cs=1,ci=0,cj,cb[cn+1],cbj,cx[cn+1];
	cn+=1;	
long int call()
{
	if(cs<cn)
	{
		for(cb[ci]=1;cb[ci]<cn;cb[ci]++)
		{
			int mi=0;
			ca[cm]=cb[ci];
			cx[ca[cm]]++;
			if(cx[ca[cm]]>1)
			{
				mi=1;
			}
			++cm;
			++cs;
			ci++;
			/*for(cbj=0;cbj<cm;cbj++){
		printf("%li",ca[cbj]);}
		printf("\n");*/
			if(mi!=1)
			call();
			
			cx[ca[cm-1]]--;
			--ci;
			--cm;
			--cs;
		}
	}
	else
	{
	for(cbj=0;cbj<cm;cbj++)
	{
		b[nofmv][cbj]=ca[cbj]+48;
	}
	++nofmv;
	}
}
for(cbj=0;cbj<cn;cbj++)
{
	cx[cbj]=0;
}
	call();
	printf("%li Possible combinations",nofmv);
}
main()
{
	FILE *odldata,*xdldata,*ddldata;
	odldata=fopen("D:\\XOdata\\DeepLearneddata-O.txt","a");
    xdldata=fopen("D:\\XOdata\\DeepLearneddata-X.txt","a");
	ddldata=fopen("D:\\XOdata\\DeepLearneddata-D.txt","a");
	combo(9);
	do{ 
   int i=0,j,m=1,k,n=1,p=0,result=0,e=1;
  	 char a[3][3];
  	 srand(time(NULL));
    for(i=0;i<=3;i++)
    {
        for(j=0;j<=3;j++)
        {
            a[i][j]=' ';
        }
    }
    system("color 4f");/*
    printf("::::X O Game...::::\n::::An SKS Creation...::::\n\n\n ");

    printf("Lets play.....\n\n\n");
    matrix(3,a);*/
while(p<9)
{ 
    m=1;
    e=1;
    
    if(p%2==0)
  {
      n=1;
  }  
  else
  {
      n=2;
  }
  k=b[iter][p]-48;
  
  /*
if(n==1)
{
   printf("\nPlayer %d chance:",n);
   k=getch();
   k-=48;
b[p]=k;
}
else if(n==2)
{
 while(e==1)
{ 
k=rand()%10;
for(i=0;i<p;i++)
{
if(b[i]==k)
{break;}
else
{
if(i==(p-1))
{
e=0;
b[p]=k;
}
}
}
}
}*/
   if(k<=9)
   {
   for(i=0;i<3;i++)
   {
       for(j=0;j<3;j++)
       {
           if(k==m)
           {
               if((n==1)&&(a[i][j]==' '))
               {
                   a[i][j]='X';
                   p++;
               }
               else if((n==2)&&(a[i][j]==' '))
               {
                   a[i][j]='O';
                   p++;
               }
               else
               {
                   printf("\nAlready there..\n");
               }i+=3;
               break;     
           }
           m++;
       } 
   }

   /*system("cls");*/
   for(i=0;i<3;i++)
{
    for(j=0;j<3;j++)
    {
        if(a[i][j]!=a[i][j+1])
        {
            break;
            
        }
        else
        {
            if((j==1)&&a[i][j]!=' ')
            {
                /*printf("        GAME OVER!!!\n        %c WIns!!",a[i][j]);*/
                int xo;
                if(a[i][j]=='O')
                {
				fputs(b[iter],odldata);
				fputs("\n",odldata);
				}
				else if(a[i][j]=='X')
				{
				fputs(b[iter],xdldata);
				fputs("\n",xdldata);
				}
                result=1;
                goto san;
                break;
            }
        }
    }   
}

for(i=0;i<3;i++)
{
    for(j=0;j<3;j++)
    {
        if(a[j][i]!=a[j+1][i])
        {
        
            break;
        }
        else
        {
            if((j==1)&&a[j][i]!=' ')
            {
                /*printf("        GAME OVER!!!\n        %c WIns!!",a[j][i]);*/
                int xo;
                if(a[j][i]=='O')
                {
                fputs(b[iter],odldata);
				fputs("\n",odldata);
				}
				else if(a[j][i]=='X')
				{
				fputs(b[iter],xdldata);
				fputs("\n",xdldata);
				}
				result=1;
                goto san;
                break;
            }
        }
    }   
}
for(i=0;i<3;i++)
{
    if(a[i][i]!=a[i+1][i+1])
        {
    
            break;
        }
        else
        {
            if((i==1)&&a[i][i]!=' ')
            {
                /*printf("        GAME OVER!!!\n        %c WIns!!",a[i][i]);*/
                int xo;
                if(a[i][i]=='O')
                {
                fputs(b[iter],odldata);
				fputs("\n",odldata);
				}
				else if(a[i][i]=='X')
				{
				fputs(b[iter],xdldata);
				fputs("\n",xdldata);
				}
				result=1;
                goto san;
                break;
            }
        }
}

for(i=0,j=2;i<3&&j>=0;i++,j--)
{
    
      if(a[i][j]!=a[i+1][j-1])
        {
            break;
            
        }
        else
        {
            if((i==1)&&a[i][j]!=' ')
            {
                /*printf("        GAME OVER!!!\n        %c WIns!!",a[i][j]);*/
                int xo;
                if(a[i][j]=='O')
                {
                fputs(b[iter],odldata);
				fputs("\n",odldata);
				}
				else if(a[i][j]=='X')
				{
				fputs(b[iter],xdldata);
				fputs("\n",xdldata);
				}
				result=1;
                goto san;
                break;
            }
        
        }
    
}
san:
{ 
if(result==1)
    {
	break;
    }
}
if(p==9)
    {
        /*printf("GAME OVER!!!!                 Its a draw match....");*/
				fputs(b[iter],ddldata);
				fputs("\n",ddldata);
				
        break;
    }
    /*
   printf("Lets play.....\n\n\n");
	matrix(3,a);*/
}
   else
   {
       printf("\nInvalid Choice\n");
       getch();
   }
}iter++;
}while(iter<nofmv);
printf("\n\nCompleted");
scanf("%d",&iter);
getch();
    }
