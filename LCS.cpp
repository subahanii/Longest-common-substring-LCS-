#include <iostream>
#include<string.h>
using namespace std;
int LCS[100][100],arrow[100][100];
	char str1[]="taggtcac";//Give first string here.
	char str2[]="acgatagc";//Second string here.
	char str[100];// This is for storing matching string only.
void printLCS(int m ,int n)
{
	static int a=0;
	if(arrow[m][n]==3)
	{
		
		str[a++]=str1[n-1];
		//cout<<" "<<str1[n-1];
		printLCS(m-1,n-1);		
	}
	else if(arrow[m][n]==2)
	    printLCS(m-1,n);
	else if(arrow[m][n]==1)
        printLCS(m,n-1);

			
	
}
void LCSfind(int m, int n)
{
	int i,j;
	for(i=0;i<=n;i++)
	LCS[0][i]=0;
	
    for(i=0;i<=m;i++)
	LCS[i][0]=0;
	
	for(i=1;i<=m;i++)
	{
		for(j=1;j<=n;j++)
		{
			if(str2[i-1]==str1[j-1])
			{
				LCS[i][j]=LCS[i-1][j-1]+1;
				arrow[i][j]=3;//   3 for diagonal arrow
			}
			else
			{
				//LCS[i][j]=max(LCS[i-1],[j], LCS[i][j-1])
				if(LCS[i-1][j]>=LCS[i][j-1])
				{
					arrow[i][j]=2;//    2 for upper arrow
					LCS[i][j]=LCS[i-1][j];
				}
				else
				{
					arrow[i][j]=1;//   1 for left arrow
					LCS[i][j]=LCS[i][j-1];
				}
			}
			
			
		}
	}

}
int main() 
{
	int i,j;
	cout<<"Hello man! Welcome Here."
	LCSfind(strlen(str1), strlen(str2));
	printLCS(strlen(str1),strlen(str2));
	cout<<"\nLCS length is: "<<strlen(str)<<"\nLCS is: ";
	for(i=strlen(str);i>=0;i--)
    cout<<str[i];
    return 0;
}
