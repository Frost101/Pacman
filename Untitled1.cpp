#include<bits/stdc++.h>
using namespace std;




typedef struct bal{
	char name[40]="Unknown";;
	int score=0;
}player;

player P[10];



int main()
{
	FILE *filepointer = fopen("HighScores.txt","wb");
	for(int i=0;i<10;i++){

		P[i].score=0;
	}
	fwrite(P, sizeof(player) , 10 , filepointer);
	fclose(filepointer);

}