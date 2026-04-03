#include<stdio.h>
#include<time.h>
#include <stdlib.h>
int oldGrid[4][4];
int grid[4][4];
 int score =0;
int checkWin()
{
	for(int i=0;i<4;i++)
	{	
		for(int j=0;j<4;j++)
		{
			if(grid[i][j]==2048)
			return 1;
		}
	}
return 0;
}
int checkGameOver(){
	for(int i=0;i<4;i++)
	{
		for(int j=0;j<4;j++)
		{
			if(grid[i][j]==0)
			return 0;
		}
	}
	for(int i=0;i<4;i++)
	{
		for(int j=0;j<3;j++)
		{
			if(grid[i][j]==grid[i][j+1])
			return 0;
		}
	}
 	for(int j=0;j<4;j++) {
        for(int i=0;i<3;i++) {
            if(grid[i][j] == grid[i+1][j])
                return 0;
        }
    }
return 1;
}

void initgrid() {
    for(int i=0;i<4;i++) {
        for(int j=0;j<4;j++) {
            grid[i][j] = 0;
        }
    }
}
void addrandomtile(int grid[4][4])
{
	int empty[16][2];
	int cnt=0;
	for(int i=0;i<4;i++)
	{
		for(int j=0;j<4;j++)
		{
			if(grid[i][j]==0)
			{
				empty[cnt][0]=i;
				empty[cnt][1]=j;
				cnt++;
			}
		}
	}
	if(cnt==0) return ;
	int r=rand()%cnt;
	int value =(rand()%10<9)?2:4;
	
	int row=empty[r][0];
	int col = empty[r][1];
        grid[row][col] = value;
	
}
void compress(int row){
	int temp[4]={0,0,0,0};
	int index=0;
	for(int i=0;i<4;i++)
	{
		if(grid[row][i]!=0)
		{
			temp[index]=grid[row][i];
			index++;
		}
	}
	for(int i=0;i<4;i++)
	{
		grid[row][i]=temp[i];
	}
}
void merge(int row){
   
	for(int i=0;i<3;i++)
	{
		if(grid[row][i]==grid[row][i+1]&&grid[row][i]!=0)
		{
			grid[row][i]=grid[row][i]*2;
			 score += grid[row][i];
			grid[row][i+1]=0;
			i++;
		}
	}
}
void reverserows(){
	for(int i=0;i<4;i++)
	{
		for(int j=0;j<2;j++)
		{
			int temp=grid[i][j];
			grid[i][j]=grid[i][3-j];
			grid[i][3-j]=temp;
		}
	}
}
void transposegrid()
{
	for(int i=0;i<4;i++)
	{
		for(int j=i+1;j<4;j++)
		{
			int temp=grid[i][j];
			grid[i][j]=grid[j][i];
			grid[j][i]=temp;
		}
	}
}
			
void moveleft(){
	for(int i=0;i<4;i++)
	{
		compress(i);
		merge(i);
		compress(i);
	}
}
void moveright(){
	
		reverserows();	
		moveleft();
		reverserows();
	}
void moveup()
{
    for(int col=0; col<4; col++)
    {
        int temp[4] = {0};
        int index = 0;

        // compress
        for(int row=0; row<4; row++)
        {
            if(grid[row][col] != 0)
                temp[index++] = grid[row][col];
        }

        // merge
        for(int i=0; i<3; i++)
        {
            if(temp[i] == temp[i+1] && temp[i] != 0)
            {
                temp[i] *= 2;
                score += temp[i];
                temp[i+1] = 0;
                i++;
            }
        }

        // compress again
        int final[4] = {0};
        index = 0;
        for(int i=0;i<4;i++)
        {
            if(temp[i] != 0)
                final[index++] = temp[i];
        }

        // write back
        for(int row=0; row<4; row++)
            grid[row][col] = final[row];
    }
}
void movedown()
{
    for(int col=0; col<4; col++)
    {
        int temp[4] = {0};
        int index = 3;

        // compress (bottom)
        for(int row=3; row>=0; row--)
        {
            if(grid[row][col] != 0)
                temp[index--] = grid[row][col];
        }

        // merge
        for(int i=3; i>0; i--)
        {
            if(temp[i] == temp[i-1] && temp[i] != 0)
            {
                temp[i] *= 2;
                score += temp[i];
                temp[i-1] = 0;
                i--;
            }
        }

        // compress again
        int final[4] = {0};
        index = 3;
        for(int i=3;i>=0;i--)
        {
            if(temp[i] != 0)
                final[index--] = temp[i];
        }

        // write back
        for(int row=0; row<4; row++)
            grid[row][col] = final[row];
    }
}void printgrid() {
     printf("\nSCORE: %d\n", score);
    printf("\n-----------------------------\n");
    for(int i=0;i<4;i++) {
        for(int j=0;j<4;j++) {
            if(grid[i][j]==0)
                printf("|    ");
            else
                printf("|%4d", grid[i][j]);
        }
        printf("|\n-----------------------------\n");
    }
}	
int main()
{
	
	srand(time(0));
	initgrid();
	addrandomtile(grid);
	addrandomtile(grid);
	while(1){
		printgrid();
		for(int i=0;i<4;i++)
		{
			for(int j=0;j<4;j++)
			{
				oldGrid[i][j]=grid[i][j];
			}
		}
		char move;
		printf("Enter Move : (W/A/S/D)\n");
		scanf(" %c",&move);
		if(move=='A')
		{
			moveleft();
		}
		else if(move=='D')
		{
			moveright();
		}
		else if(move=='W')
		{
			moveup();
		}
		else if(move=='S')
		{
		

	movedown();
		}
		int changed =0;
		for(int i=0;i<4;i++)
		{
			for(int j=0;j<4;j++)
			{
				if(oldGrid[i][j]!=grid[i][j])
				
					changed=1;
			}
		}
		if(changed)
		{
			addrandomtile(grid);
		}		
		if(checkWin())
		{
			printf("You Won\n");
			break;
		}
		if(checkGameOver())
		{
			printf("Game Over\n");
			break;
		}
	}
}
		