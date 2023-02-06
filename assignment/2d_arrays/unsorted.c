#include<stdio.h>

void main()
{
	int i,j,k,arr[3][3]={0,10,3,5,6,16,1,2,7},temp,s;
	for(i=0;i<3;i++)
	{
		for(j=0;j<3;j++)
		{
			for(k=0;k<3;k++)
			{
				for(s=0;s<3;s++)
				{

				if(arr[i][j]>=arr[k][s]);
				
					else
					{
						temp=arr[i][j];
						arr[i][j]=arr[k][s];
						arr[k][s]=temp;
					}
				}

			}
		}
	}
	for(i=0;i<3;i++)
	{
	    for(j=0;j<3;j++)
	    {
		    printf("%3d",arr[i][j]);
	    }
	    printf("\n");
	}
}



