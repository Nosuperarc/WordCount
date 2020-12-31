#include<stdio.h>
#include<string.h>
int  main(int argc,char *argv[])
{
	char value;
	char character[100];
	char *charact;
	int state;
	int flagcnt[100];
	int word = 0;
	FILE *fp;
	int count = 0;

	fp = fopen(argv[2],"r");
	charact = character;

	if((strcmp(argv[1],"-c") == 0) || (strcmp(argv[1],"-C") == 0))
	{
		count = -1;

	while(!feof(fp))
	{
		value = fgetc(fp);
		count++;
	}
		printf("×Ö·ûÊý£º %d\n",count);
		
	}
	else if((strcmp(argv[1],"-w") == 0) || (strcmp(argv[1],"-W") == 0))
	{
		while(!feof(fp))
		{
			value = fgetc(fp);
			*charact = value;
			charact++;
			count++;
		}
		for(int i=0;i<count;i++)
		{
			if(character[i]>='a' && character[i]<='z')
				{
					state= 1;
					flagcnt[i] = state;
				}
			else if (character[i] >= 'A' && character[i] <= 'Z')
				{
					state = 1;
					flagcnt[i] = state;
				}
			else
				{	
					state= 0;
					flagcnt[i] = state;
				}
		}

		for(int i=0;i<count;i++)
		{
			int high = flagcnt[i];
			int last = flagcnt[i+1];

			if(high != last)
			{
				word++;
			}
		}

		printf("µ¥´ÊÊý£º %d\n",word/2);
	}
	
}

