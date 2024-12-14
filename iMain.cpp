# include "iGraphics.h"
#include<math.h>
#include<bits/stdc++.h>
#include<windows.h>
#include<MMSystem.h>
#define pi acos(-1)




					/*
						Name:MD Sadik Hossain Shanto
						1905101_CSE
					*/



						//INITIALIZATION
int screen_height=800,screen_width=1200;
int divider=30;
int balls[21][19];


						//gamescreen
int mainscreen=0,homescreen=1,help=0,rules=0,setup=0,gameover=0,soundon=1,halloffame=0,win=0;








							//Scores

int score=0;
int cnt;
char EnterName[40]="Unknown";
int indexNumber=strlen(EnterName);
typedef struct PlayerInfo
{
	char GameName[40];
	int GameScore;
}P;

P SortingArray[11];

void ShowHighScores()
{
	FILE *filepointer = fopen("HighScores.txt" , "rb");
	fread(SortingArray, sizeof(P) , 10 , filepointer);
	fclose(filepointer);
}

void UpdateHighScores()
{
	FILE *filepointer = fopen ("HighScores.txt" , "rb");

	fread(SortingArray , sizeof(P) ,10 , filepointer);
	fclose(filepointer);
	SortingArray[10].GameScore = score;

	strcpy(SortingArray[10].GameName,EnterName);
	for(int i = 10;i>0;i--){
		int k = 0;
		for(int j = 0;j <= i;j++){
			if(SortingArray[j].GameScore < SortingArray[k].GameScore)
			{
				k = j;
			}
		}
	int t = SortingArray[i].GameScore;
	SortingArray[i].GameScore = SortingArray[k].GameScore;
	SortingArray[k].GameScore = t;
	char Name1[40],Name2[40];

	strcpy(Name1 , SortingArray[i].GameName);
	strcpy(Name2 , SortingArray[k].GameName);
	strcpy(SortingArray[k].GameName , Name1);
	strcpy(SortingArray[i].GameName , Name2);
}
filepointer = fopen("HighScores.txt" , "wb");
fwrite(SortingArray , sizeof(P) , 10 , filepointer);
fclose(filepointer);
}





						//Maze

int ara[21][19]={
                                1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1,
                                1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1,
                                1, 0, 1, 1, 1, 1, 1, 1, 0, 1, 0, 1, 1, 1, 1, 1, 1, 0, 1,
                                1, 3, 0, 0, 5, 1, 0, 0, 0, 1, 0, 0, 0, 1, 0, 0, 0, 3, 1,
                                1, 1, 0, 1, 0, 1, 0, 1, 1, 1, 1, 1, 0, 1, 0, 1, 0, 1, 1,
                                1, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 6, 1,
                                1, 0, 1, 1, 0, 1, 1, 1, 0, 1, 0, 1, 1, 1, 0, 1, 1, 0, 1,
                                1, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 1,
                                1, 1, 1, 1, 0, 1, 0, 1, 1, 1, 1, 1, 0, 1, 0, 1, 1, 1, 1,
                                2, 2, 2, 1, 0, 1, 0, 0, 0, 0, 0, 0, 0, 1, 0, 1, 2, 2, 2,
                                1, 1, 1, 1, 0, 1, 0, 1, 0, 0, 0, 1, 0, 1, 0, 1, 1, 1, 1,
                                2, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 2,
                                1, 1, 1, 1, 0, 1, 0, 1, 1, 1, 1, 1, 0, 1, 0, 1, 1, 1, 1,
                                2, 2, 2, 1, 0, 1, 0, 0, 0, 0, 4, 0, 0, 1, 0, 1, 2, 2, 2,
                                1, 1, 1, 1, 0, 1, 1, 1, 0, 1, 0, 1, 1, 1, 0, 1, 1, 1, 1,
                                1, 3, 0, 0, 0, 1, 0, 0, 0, 1, 0, 0, 0, 1, 0, 0, 0, 3, 1,
                                1, 0, 1, 1, 0, 1, 0, 1, 1, 1, 1, 1, 0, 1, 0, 1, 1, 0, 1,
                                1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1,
                                1, 0, 1, 1, 0, 1, 1, 1, 0, 1, 0, 1, 1, 1, 0, 1, 1, 0, 1,
                                1, 2, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 1,
                                1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1,


                };

int maze[21][19];






typedef struct  player{
	int x;
	int y;
	int dx;
	int dy;
	int eat;
	int dir;
	int tx;
	int ty;
	int fr;
	int idxc;
	int cur;
	int ini;
	int ddx[5]={};


}player;




			//functions






						//Global Variables
player pacman;
player blinky;
player inky;
player pinky;
player clyde;
int state;
int life=3;
int rx,ry,rt;
int Gamemode=1;
int fright_counter=1;
int Ghostmode=0;
int ini=0;
int tiime=1;
char str[7];
int highscore=SortingArray[0].GameScore;
int ddx[4]={1,0,-1,0};
int ddy[4]={0,1,0,-1};





						//Functions Declaration
void Draw_maze();
void ChasePoint();
void ScatterPoint();
void FrightenPoint();
void EatenPoint();
void Launch_blinky();
void Launch_clyde();
void Launch_inky();
void Launch_pinky();
double distance (int x1,int y1,int x2,int y2);








					//SaveGame

typedef struct _save{
	int life;
	int pacmandx;
	int pacmandy;
	int pinkydx;
	int pinkydy;
	int inkydx;
	int inkydy;
	int blinkydx;
	int blinkydy;
	int clydedx;
	int clydedy;
	int time;
	int pacmaneat;
	int blinkyeat;
	int pinkyeat;
	int inkyeat;
	int clydeeat;
	int Ghostmode;
	int blinkyini;
	int pinkyini;
	int inlyini;
	int clydeini;
	int pacmanini;
	int Pacmaneat;
	int score;
	int pinkydir;
	int inkydir;
	int blinkydir;
	int clydedir;
	int pacmancur;
	int maze[21][19];
}Save;
Save save;

void ShowSave()
{
	FILE *filepointer = fopen("save.txt" , "rb");
	fread(&save, sizeof(Save) , 1, filepointer);
	fclose(filepointer);
}

void UpdateSave()
{
	FILE *filepointer = fopen("save.txt" , "wb");
	fwrite(&save , sizeof(Save) , 1, filepointer);
	fclose(filepointer);
}









		//pacman
void InitializePacman()
{
		pacman.x=100+(1*30);
		pacman.y= 100+(1*30);
		pacman.dx=1;
		pacman.dir=-1;
		pacman.cur=-1;
		pacman.eat=0;
}

		//blinky
void InitializeBlinky()
{
		blinky.x=100+(8*30);
		blinky.y= 100+(11*30);
		blinky.dx=1;;
		blinky.dir=1;
		blinky.cur=0;
		blinky.eat=0;

}

void InitializePinky()
{
		pinky.x=100+(9*30);
		pinky.y= 100+(9*30);
		pinky.dx=1;;
		pinky.dir=1;
		pinky.cur=0;
		pinky.eat=0;
}

void InitializeInky()
{
		inky.x=100+(8*30);
		inky.y= 100+(9*30);
		inky.dx=1;
		inky.dir=1;
		inky.cur=0;
		inky.eat=0;
}
void InitializeClyde()
{
		clyde.x=100+(10*30);
		clyde.y= 100+(9*30);
		clyde.dx=1;;
		clyde.dir=1;
		clyde.cur=0;
		clyde.eat=0;
}




		//Bool
int up,down,left,right,frc,eatc;
int alive=1;
int gmode;
int inipac=0;




void FrightIncrease()
{
	if(Gamemode==2){
	fright_counter+=1;

	}
}


void ModeChange()
{
	if(Gamemode!=2){
	Ghostmode+=1;
	if((Ghostmode>=1&&Ghostmode<=7)||(Ghostmode>=28&&Ghostmode<=34)||(Ghostmode>=55&&Ghostmode<=62)||(Ghostmode>=83&&Ghostmode<=90)||(Ghostmode>=101&&Ghostmode<=110))
		Gamemode= -1;
	else
		Gamemode=1;

	}

}

double distance (int x1,int y1,int x2,int y2)
{
	double ans=sqrt((x1-x2)*(x1-x2)+(y1-y2)*(y1-y2));
	return ans;
}



void launch_pacman()
{
	int checkx=((pacman.y-100)/30),checky=((pacman.x-100)/30);
	if(((pacman.y-100)%30)==0&&((pacman.x-100)%30)==0&&maze[20-checkx][checky]==0){score+=10,maze[20-checkx][checky]=2;}
	if(((pacman.y-100)%30)==0&&((pacman.x-100)%30)==0&&maze[20-checkx][checky]==3){score+=30,maze[20-checkx][checky]=2,Gamemode=2,fright_counter=1;if(soundon==1)PlaySound("music\\pacman_chomp.wav",NULL,SND_ASYNC);}
	if(((pacman.y-100)%30)==0&&((pacman.x-100)%30)==0&&maze[20-checkx][checky]==4){score+=50,maze[20-checkx][checky]=2;if(soundon==1)PlaySound("music\\pacman_eatfruit.wav",NULL,SND_ASYNC);}
	if(((pacman.y-100)%30)==0&&((pacman.x-100)%30)==0&&maze[20-checkx][checky]==5){score+=100,maze[20-checkx][checky]=2;if(soundon==1)PlaySound("music\\pacman_eatfruit.wav",NULL,SND_ASYNC);}
	if(((pacman.y-100)%30)==0&&((pacman.x-100)%30)==0&&maze[20-checkx][checky]==6){score+=70,maze[20-checkx][checky]=2;;if(soundon==1)PlaySound("music\\pacman_eatfruit.wav",NULL,SND_ASYNC);}

	if(pacman.ini==0){
		InitializePacman();
		pacman.ini=1;
	}


	if(((pacman.y-100)%30)==0&&((pacman.x-100)%30)==0&&(checky==18)&&checkx==9&&(pacman.dir==0||pacman.cur==0)){
		pacman.x=100+2;

		iShowBMP2(pacman.x,pacman.y,"images\\Pac_rgt.bmp",0);

	}
	else if(((pacman.y-100)%30)==0&&((pacman.x-100)%30)==0&&(checky==0)&&checkx==9&&(pacman.dir==2||pacman.cur==2)){
		pacman.x=100+(18*30)-2;iShowBMP2(pacman.x,pacman.y,"images\\Pac_rgt.bmp",0);
	}

	else{
	checkx=((pacman.y-100)/30),checky=((pacman.x-100)/30);
	if(((pacman.y-100)%30)==0&&((pacman.x-100)%30)==0){
		if(pacman.dir==0){
			if(maze[20-checkx][checky+1]!=1)
				pacman.cur=pacman.dir;
		}
		else if(pacman.dir==2){
			if(maze[20-checkx][checky-1]!=1)
				pacman.cur=pacman.dir;
		}
		else if(pacman.dir==1){
			if(maze[20-checkx-1][checky]!=1)
				pacman.cur=pacman.dir;
		}
		else if(pacman.dir==3){
			if(maze[20-checkx+1][checky]!=1)
				pacman.cur=pacman.dir;
		}
	}


		if(pacman.cur==0){
			if(((pacman.y-100)%30)==0&&((pacman.x-100)%30)==0){
				if(maze[20-checkx][checky+1]!=1)
					if(pacman.eat==0)pacman.x+=pacman.dx;
			}
			else{
					if(pacman.eat==0)pacman.x+=pacman.dx;
			}
		}
		else if(pacman.cur==2){
			if(((pacman.y-100)%30)==0&&((pacman.x-100)%30)==0){
			if(maze[20-checkx][checky-1]!=1)
				if(pacman.eat==0)
				pacman.x-=pacman.dx;
			}
			else{
					if(pacman.eat==0)
					pacman.x-=pacman.dx;
			}
		}
		else if(pacman.cur==1){
			if(((pacman.y-100)%30)==0&&((pacman.x-100)%30)==0){
			if(maze[20-checkx-1][checky]!=1)
				if(pacman.eat==0)pacman.y+=pacman.dx;
			}
			else{
					if(pacman.eat==0)pacman.y+=pacman.dx;
			}
		}
		else if(pacman.cur==3){
			if(((pacman.y-100)%30)==0&&((pacman.x-100)%30)==0){
			if(maze[20-checkx+1][checky]!=1)
				if(pacman.eat==0)pacman.y-=pacman.dx;
			}
			else{
					if(pacman.eat==0)pacman.y-=pacman.dx;
			}
		}


	iShowBMP2(pacman.x,pacman.y,"images\\Pac_rgt.bmp",0);
	}


}


void IncreaseTime()
{
	tiime+=1;
}

void PauseTimer()
{

	if(tiime%3==0){
		pacman.eat=0;
		tiime=1;
		pacman.ini=0;
		pinky.ini=0;
		inky.ini=0;
		blinky.ini=0;
		clyde.ini=0;
		life-=1;

	}
}



void GhostEatCheck()
{
	if(Gamemode==2){
		if(pacman.x>=pinky.x&&pacman.x<=(pinky.x+30)&&pacman.y>=pinky.y&&pacman.y<=(pinky.y+30)&&pinky.eat==0){
				pinky.eat=1,pinky.dx=1;
				score+=200;
				if(soundon==1)PlaySound("music\\pacman_eatghost.wav",NULL,SND_ASYNC);
		}
		if(pacman.x>=inky.x&&pacman.x<=(inky.x+30)&&pacman.y>=inky.y&&pacman.y<=(inky.y+30)&&inky.eat==0){
				inky.eat=1,inky.dx=1;
				score+=200;
				if(soundon==1)PlaySound("music\\pacman_eatghost.wav",NULL,SND_ASYNC);
		}
		if(pacman.x>=blinky.x&&pacman.x<=(blinky.x+30)&&pacman.y>=blinky.y&&pacman.y<=(blinky.y+30)&&blinky.eat==0){
				blinky.eat=1,blinky.dx=1;
				score+=200;
				if(soundon==1)PlaySound("music\\pacman_eatghost.wav",NULL,SND_ASYNC);
		}
		if(pacman.x>=clyde.x&&pacman.x<=(clyde.x+30)&&pacman.y>=clyde.y&&pacman.y<=(clyde.y+30)&&clyde.eat==0){
				clyde.eat=1,clyde.dx=1;
				score+=200;
				if(soundon==1)PlaySound("music\\pacman_eatghost.wav",NULL,SND_ASYNC);
		}
	}
}



void PacmanEatCheck()
{
	if(mainscreen==1){
	if((pacman.x>=pinky.x&&pacman.x<=pinky.x+30&&pacman.y>=pinky.y&&pacman.y<=pinky.y+30&&pacman.eat==0)&&pinky.eat==0&&Gamemode!=2){pacman.eat=1;if(soundon==1)PlaySound("music\\pacman_death.wav",NULL,SND_ASYNC);}
	if((pacman.x>=inky.x&&pacman.x<=inky.x+30&&pacman.y>=inky.y&&pacman.y<=inky.y+30)&&inky.eat==0&&Gamemode!=2&&pacman.eat==0){pacman.eat=1;if(soundon==1)PlaySound("music\\pacman_death.wav",NULL,SND_ASYNC);;}
	if((pacman.x>=blinky.x&&pacman.x<=blinky.x+30&&pacman.y>=blinky.y&&pacman.y<=blinky.y+30)&&blinky.eat==0&&Gamemode!=2&&pacman.eat==0){pacman.eat=1;if(soundon==1)PlaySound("music\\pacman_death.wav",NULL,SND_ASYNC);;}
	if((pacman.x>=clyde.x&&pacman.x<=clyde.x+30&&pacman.y>=clyde.y&&pacman.y<=clyde.y+30)&&clyde.eat==0&&Gamemode!=2&&pacman.eat==0){pacman.eat=1;if(soundon==1)PlaySound("music\\pacman_death.wav",NULL,SND_ASYNC);;}
	}
}
void GhostRestore()
{

	if(blinky.eat==1&&blinky.x==(100+(10*30))&&blinky.y==(100+(9*30)))blinky.eat=0,blinky.dx=1;
	if(pinky.eat==1&&pinky.x==(100+(10*30))&&pinky.y==(100+(9*30)))pinky.eat=0,pinky.dx=1;
	if(inky.eat==1&&inky.x==(100+(10*30))&&inky.y==(100+(9*30)))inky.eat=0,inky.dx=1;
	if(clyde.eat==1&&clyde.x==(100+(10*30))&&clyde.y==(100+(9*30)))clyde.eat=0,clyde.dx=1;
}

void Gamescreen()
{
	Draw_maze();
	iShowBMP2(700,100,"images\\homeimage.bmp",0);

	PacmanEatCheck();

	launch_pacman();

	if(Gamemode==2){

		if(fright_counter%9==0){
			Gamemode=1;
			fright_counter=1;
		}
	}

	if(Gamemode==1)
	ChasePoint();
	else if(Gamemode==-1)
	ScatterPoint();
	else if(Gamemode==2){
	FrightenPoint();
	}

	EatenPoint();
	Launch_clyde();
	Launch_inky();
	Launch_pinky();
	Launch_blinky();


	if(blinky.eat==1&&blinky.x==(100+(10*30))&&blinky.y==(100+(9*30)))blinky.eat=0,blinky.dx=1;
	if(pinky.eat==1&&pinky.x==(100+(10*30))&&pinky.y==(100+(9*30)))pinky.eat=0,pinky.dx=1;
	if(inky.eat==1&&inky.x==(100+(10*30))&&inky.y==(100+(9*30)))inky.eat=0,inky.dx=1;
	if(clyde.eat==1&&clyde.x==(100+(10*30))&&clyde.y==(100+(9*30)))clyde.eat=0,clyde.dx=1;




	if(pacman.eat==0)tiime=1;
	if(pacman.eat==1){
		iShowBMP2(260,300,"images\\oops.bmp",0);
		PauseTimer();
	}

	for(int i=1;i<=life;i++){
		iShowBMP2(800+(i*40),200,"images\\life.bmp",0);
	}
	iSetColor(0,255,0);
	iText(840,150,"SCORE: ",GLUT_BITMAP_TIMES_ROMAN_24);
	str[0]='\0';
	sprintf(str,"%d",score);
	iText(940,150,str,GLUT_BITMAP_TIMES_ROMAN_24);

	if(score>highscore){
		highscore=score;
	}

	str[0]='\0';
	sprintf(str,"%d",highscore);
	iText(830,690,"HIGHSCORE",GLUT_BITMAP_TIMES_ROMAN_24);
	iText(890,650,str,GLUT_BITMAP_TIMES_ROMAN_24);

	iShowBMP2(1080,50,"images\\home.bmp",0);


}



void ChasePoint()
{

	if(pinky.eat==0){
		if(pacman.cur==0)pinky.tx= pacman.x + 4*30,pinky.ty=pacman.y;
		else if(pacman.cur==1)pinky.tx= pacman.x - 4*30,pinky.ty=pacman.y+4*30;
		else if(pacman.cur==2)pinky.tx= pacman.x - 4*30,pinky.ty=pacman.y;
		else if(pacman.cur==3)pinky.tx= pacman.x ,pinky.ty=pacman.y-4*30;
	}

	if(inky.eat==0){
		inky.tx=(2*pacman.x)-blinky.x;
		inky.ty=(2*pacman.y)-blinky.y;
	}

	if(clyde.eat==0){
		if(distance(pacman.x,pacman.y,clyde.x,clyde.y)<=7*30)
		{
		clyde.tx=200+(2*30);
		clyde.ty=200+(2*30);
		}
		else
		{
		clyde.tx=pacman.x+30;
		clyde.ty=pacman.y+30;
		}
	}

	if(blinky.eat==0){
		blinky.tx=pacman.x;
		blinky.ty=pacman.y;
	}


}


void ScatterPoint()
{
	if(blinky.eat==0){
		blinky.tx=200+(13*30);
		blinky.ty=200+(18*30);
	}
	if(inky.eat==0){
		inky.tx=200+(12*30);
		inky.ty=200+(4*30);
	}
	if(pinky.eat==0){
		pinky.tx=200+(3*30);
		pinky.ty=200+(18*30);
	}
	if(clyde.eat==0){
		clyde.tx=200+(5*30);
		clyde.ty=200+(4*30);
	}
}


void EatenPoint()
{
	if(blinky.eat==1){
		blinky.tx=100+(10*30);
		blinky.ty=100+(9*30);
	}
	if(inky.eat==1){
		inky.tx=100+(10*30);
		inky.ty=100+(9*30);
	}
	if(pinky.eat==1){
		pinky.tx=100+(10*30);
		pinky.ty=100+(9*30);
	}
	if(clyde.eat==1){
		clyde.tx=100+(10*30);
		clyde.ty= 100+(9*30);
	}
}

void FrightenPoint()
{

	if(pacman.y>=470){
		if(blinky.eat==0){
			blinky.tx=pacman.y;
			blinky.ty=150;
		}
		if(inky.eat==0){
			inky.tx=pacman.y+60;
			inky.ty=160;
		}
		if(pinky.eat==0){
			pinky.tx=pacman.y-60;
			pinky.ty=130;
		}
		if(clyde.eat==0){
			clyde.tx=pacman.y+120;
			clyde.ty=140;
		}
	}
	else{
		if(blinky.eat==0){
			blinky.tx=pacman.y;
			blinky.ty=760;
		}
		if(inky.eat==0){
			inky.tx=pacman.y+60;
			inky.ty=790;
		}
		if(pinky.eat==0){
			pinky.tx=pacman.y-60;
			pinky.ty=780;
		}
		if(clyde.eat==0){
			clyde.tx=pacman.y+120;
			clyde.ty=770;
		}
	}
}


void Launch_blinky()
{
	if(blinky.ini==0){
		InitializeBlinky();
		blinky.ini=1;
	}



	int checkx=((blinky.y-100)/30),checky=((blinky.x-100)/30);
	if(((blinky.y-100)%30)==0&&((blinky.x-100)%30)==0&&(checky==18)&&checkx==9&&(blinky.dir==0||blinky.cur==0)){
		blinky.x=100+2,blinky.dir=0;
		if(blinky.eat==1)iShowBMP2(blinky.x,blinky.y,"images\\eaten.bmp",0);
		else if(Gamemode==1||Gamemode==-1)iShowBMP2(blinky.x,blinky.y,"images\\blinky.bmp",0);
		else if(Gamemode==2)iShowBMP2(blinky.x,blinky.y,"images\\frighten.bmp",0);
	}
	else if(((blinky.y-100)%30)==0&&((blinky.x-100)%30)==0&&(checky==0)&&checkx==9&&(blinky.dir==2||blinky.cur==2)){
		blinky.x=100+(18*30)-2,blinky.dir=2;
		if(blinky.eat==1)iShowBMP2(blinky.x,blinky.y,"images\\eaten.bmp",0);
		else if(Gamemode==1||Gamemode==-1)iShowBMP2(blinky.x,blinky.y,"images\\blinky.bmp",0);
		else if(Gamemode==2)iShowBMP2(blinky.x,blinky.y,"images\\frighten.bmp",0);
	}
	else{
		checkx=((blinky.y-100)/30),checky=((blinky.x-100)/30);
		if(((blinky.y-100)%30)==0&&((blinky.x-100)%30)==0){
			double s,lowest=99999999;
			int i ,best;
			for(i=0;i<4;i++){


				if( (i+2)%4 != blinky.dir){

						int nx=checky;
						int ny=checkx;
						nx+=ddx[i];
						ny+=ddy[i];

						if(maze[20-ny][nx]==1)  continue;

						s=distance((nx*30)+100, (ny*30)+100, blinky.tx, blinky.ty);

						if(s<lowest){
								lowest=s;
								best=i;
						}
				}
			}
			    if(best==0)blinky.dir=0;
			    else if(best==1)blinky.dir=1;
			    else if(best==2)blinky.dir=2;
			    else if(best==3)blinky.dir=3;

		}


		if(blinky.dir==0){
			if(pacman.eat==0)blinky.x+=blinky.dx;
		}
		else if(blinky.dir==1){
			if(pacman.eat==0)blinky.y+=blinky.dx;
		}
		else if(blinky.dir==2){
			if(pacman.eat==0)blinky.x-=blinky.dx;
		}
		else if(blinky.dir==3){
			if(pacman.eat==0)blinky.y-=blinky.dx;
		}
		if(blinky.eat==1)iShowBMP2(blinky.x,blinky.y,"images\\eaten.bmp",0);
		else if(Gamemode==1||Gamemode==-1)iShowBMP2(blinky.x,blinky.y,"images\\blinky.bmp",0);
		else if(Gamemode==2)iShowBMP2(blinky.x,blinky.y,"images\\frighten.bmp",0);
	}


}



void Launch_pinky()
{
	if(pinky.ini==0){
		InitializePinky();
		pinky.ini=1;
	}

	int checkx=((pinky.y-100)/30),checky=((pinky.x-100)/30);
	if(((pinky.y-100)%30)==0&&((pinky.x-100)%30)==0&&(checky==18)&&checkx==9&&(pinky.dir==0||pinky.cur==0)){
		pinky.x=100+2,pinky.dir=0;
		if(pinky.eat==1)iShowBMP2(pinky.x,pinky.y,"images\\eaten.bmp",0);
		else if(Gamemode==1||Gamemode==-1)iShowBMP2(pinky.x,pinky.y,"images\\pinky.bmp",0);
		else if(Gamemode==2)iShowBMP2(pinky.x,pinky.y,"images\\frighten.bmp",0);
	}

	else if(((pinky.y-100)%30)==0&&((pinky.x-100)%30)==0&&(checky==0)&&checkx==9&&(pinky.dir==2||pinky.cur==2)){
		pinky.x=100+(18*30)-2,pinky.dir=2;
		if(pinky.eat==1)iShowBMP2(pinky.x,pinky.y,"images\\eaten.bmp",0);
		else if(Gamemode==1||Gamemode==-1)iShowBMP2(pinky.x,pinky.y,"images\\pinky.bmp",0);
		else if(Gamemode==2)iShowBMP2(pinky.x,pinky.y,"images\\frighten.bmp",0);
	}
	else{
		checkx=((pinky.y-100)/30),checky=((pinky.x-100)/30);
		if(((pinky.y-100)%30)==0&&((pinky.x-100)%30)==0){
			double s,lowest=99999999;
			int i ,best;
			for(i=0;i<4;i++){
				if( (i+2)%4 != pinky.dir){

						int nx=checky;
						int ny=checkx;
						nx+=ddx[i];
						ny+=ddy[i];

						if(maze[20-ny][nx]==1)  continue;

						s=distance((nx*30)+100, (ny*30)+100, pinky.tx,pinky.ty);

						if(s<lowest){
								lowest=s;
								best=i;
						}
				}
			}
			    if(best==0)pinky.dir=0;
			    else if(best==1)pinky.dir=1;
			    else if(best==2)pinky.dir=2;
			    else if(best==3)pinky.dir=3;

		}


		if(pinky.dir==0){
			if(pacman.eat==0)pinky.x+=pinky.dx;
		}
		else if(pinky.dir==1){
			if(pacman.eat==0)pinky.y+=pinky.dx;
		}
		else if(pinky.dir==2){
			if(pacman.eat==0)pinky.x-=pinky.dx;
		}
		else if(pinky.dir==3){
			if(pacman.eat==0)pinky.y-=pinky.dx;
		}
		if(pinky.eat==1)iShowBMP2(pinky.x,pinky.y,"images\\eaten.bmp",0);
		else if(Gamemode==1||Gamemode==-1)iShowBMP2(pinky.x,pinky.y,"images\\pinky.bmp",0);
		else if(Gamemode==2)iShowBMP2(pinky.x,pinky.y,"images\\frighten.bmp",0);
	}



}



void Launch_inky()
{
	if(inky.ini==0){
		InitializeInky();
		inky.ini=1;
	}

	int checkx=((inky.y-100)/30),checky=((inky.x-100)/30);
	if(((inky.y-100)%30)==0&&((inky.x-100)%30)==0&&(checky==18)&&checkx==9&&(inky.dir==0||inky.cur==0)){
		inky.x=100+2,inky.dir=0;
		if(inky.eat==1)iShowBMP2(inky.x,inky.y,"images\\eaten.bmp",0);
		else if(Gamemode==1||Gamemode==-1)iShowBMP2(inky.x,inky.y,"images\\inky.bmp",0);
		else if(Gamemode==2)iShowBMP2(inky.x,inky.y,"images\\frighten.bmp",0);
	}

	else if(((inky.y-100)%30)==0&&((inky.x-100)%30)==0&&(checky==0)&&checkx==9&&(inky.dir==2|inky.cur==2)){
		inky.x=100+(18*30)-2,inky.dir=2;
		if(inky.eat==1)iShowBMP2(inky.x,inky.y,"images\\eaten.bmp",0);
		else if(Gamemode==1||Gamemode==-1)iShowBMP2(inky.x,inky.y,"images\\inky.bmp",0);
		else if(Gamemode==2)iShowBMP2(inky.x,inky.y,"images\\frighten.bmp",0);
	}
	else{
		checkx=((inky.y-100)/30),checky=((inky.x-100)/30);
		if(((inky.y-100)%30)==0&&((inky.x-100)%30)==0){
			double s,lowest=99999999;
			int i ,best;
			for(i=0;i<4;i++){
				if( (i+2)%4 != inky.dir){

						int nx=checky;
						int ny=checkx;
						nx+=ddx[i];
						ny+=ddy[i];

						if(maze[20-ny][nx]==1)  continue;

						s=distance((nx*30)+100, (ny*30)+100, inky.tx,inky.ty);

						if(s<lowest){
								lowest=s;
								best=i;
						}
				}
			}
			    if(best==0)inky.dir=0;
			    else if(best==1)inky.dir=1;
			    else if(best==2)inky.dir=2;
			    else if(best==3)inky.dir=3;

		}


		if(inky.dir==0){
			if(pacman.eat==0)inky.x+=inky.dx;
		}
		else if(inky.dir==1){
			if(pacman.eat==0)inky.y+=inky.dx;
		}
		else if(inky.dir==2){
			if(pacman.eat==0)inky.x-=inky.dx;
		}
		else if(inky.dir==3){
			if(pacman.eat==0)inky.y-=inky.dx;
		}
		if(inky.eat==1)iShowBMP2(inky.x,inky.y,"images\\eaten.bmp",0);
		else if(Gamemode==1||Gamemode==-1)iShowBMP2(inky.x,inky.y,"images\\inky.bmp",0);
		else if(Gamemode==2)iShowBMP2(inky.x,inky.y,"images\\frighten.bmp",0);
	}



}



void Launch_clyde()
{
	if(clyde.ini==0){
		InitializeClyde();
		clyde.ini=1;
	}


	if(clyde.x==blinky.x&&clyde.y==blinky.y){
		clyde.tx=200+(2*30);
		clyde.ty=200+(2*30);
	}

	int checkx=((clyde.y-100)/30),checky=((clyde.x-100)/30);
	if(((clyde.y-100)%30)==0&&((clyde.x-100)%30)==0&&(checky==18)&&checkx==9&&(clyde.dir==0||clyde.cur==0)){
		clyde.x=100+2;
		if(clyde.eat==1)iShowBMP2(clyde.x,clyde.y,"images\\eaten.bmp",0);
		else if(Gamemode==1||Gamemode==-1)iShowBMP2(clyde.x,clyde.y,"images\\clyde.bmp",0);
		else if(Gamemode==2)iShowBMP2(clyde.x,clyde.y,"images\\frighten.bmp",0);
	}
	else if(((clyde.y-100)%30)==0&&((clyde.x-100)%30)==0&&(checky==0)&&checkx==9&&(clyde.dir==2||clyde.cur==2)){
		clyde.x=100+(18*30)-2;
		if(clyde.eat==1)iShowBMP2(clyde.x,clyde.y,"images\\eaten.bmp",0);
		else if(Gamemode==1||Gamemode==-1)iShowBMP2(clyde.x,clyde.y,"images\\clyde.bmp",0);
		else if(Gamemode==2)iShowBMP2(clyde.x,clyde.y,"images\\frighten.bmp",0);
	}
	else{
		checkx=((clyde.y-100)/30),checky=((clyde.x-100)/30);
		if(((clyde.y-100)%30)==0&&((clyde.x-100)%30)==0){
			double s,lowest=99999999;
			int i ,best;
			for(i=0;i<4;i++){
				if( (i+2)%4 != clyde.dir){

						int nx=checky;
						int ny=checkx;
						nx+=ddx[i];
						ny+=ddy[i];

						if(maze[20-ny][nx]==1)  continue;

						s=distance((nx*30)+100, (ny*30)+100,clyde.tx,clyde.ty);

						if(s<lowest){
								lowest=s;
								best=i;
						}
				}
			}
			    if(best==0)clyde.dir=0;
			    else if(best==1)clyde.dir=1;
			    else if(best==2)clyde.dir=2;
			    else if(best==3)clyde.dir=3;

		}


		if(clyde.dir==0){
			if(pacman.eat==0)clyde.x+=clyde.dx;
		}
		else if(clyde.dir==1){
			if(pacman.eat==0)clyde.y+=clyde.dx;
		}
		else if(clyde.dir==2){
			if(pacman.eat==0)clyde.x-=clyde.dx;
		}
		else if(clyde.dir==3){
			if(pacman.eat==0)clyde.y-=clyde.dx;
		}
		if(clyde.eat==1)iShowBMP2(clyde.x,clyde.y,"images\\eaten.bmp",0);
		else if(Gamemode==1||Gamemode==-1)iShowBMP2(clyde.x,clyde.y,"images\\clyde.bmp",0);
		else if(Gamemode==2)iShowBMP2(clyde.x,clyde.y,"images\\frighten.bmp",0);
	}

}






void Draw_maze()
{
	cnt=0;
	iSetColor(0,0,0);
	for(int i=20;i>=0;i--){
		for(int j=0;j<(19);j++){
			if(maze[i][j]==1){
				iSetColor(38,0,103);
				iFilledRectangle(100+j*divider, 100+(20-i)*divider, divider, divider);
			}
			else if(maze[i][j]==2){
				iSetColor(0,0,0);
				iFilledRectangle(100+j*divider, 100+(20-i)*divider, divider, divider);

			}
			else if(maze[i][j]==3){
				iSetColor(144,5,5);
				iFilledCircle((100+j*divider)+15,(100+(20-i)*divider)+15 , 7);
			}
			else if(maze[i][j]==4){
				iSetColor(0,0,0);
				iShowBMP2(100+j*divider, 100+(20-i)*divider,"images\\food.bmp",0);
			}
			else if(maze[i][j]==5){
				iSetColor(0,0,0);
				iShowBMP2(100+j*divider, 100+(20-i)*divider,"images\\food2.bmp",0);
			}
			else if(maze[i][j]==6){
				iSetColor(0,0,0);
				iShowBMP2(100+j*divider, 100+(20-i)*divider,"images\\food3.bmp",0);
			}
			else{
				iSetColor(144,5,5);
				iFilledCircle((100+j*divider)+15,(100+(20-i)*divider)+15 , 2);
				cnt++;
			}
		}
	}

	if(cnt==0){
		win=1;
		mainscreen=0;
	}
	iSetColor(0,0,0);
}






void HomeScreen()
{
	iShowBMP2(0,0,"images\\homescreen.bmp",0);
	iShowBMP2(500,190,"images\\newgame.bmp",0);
	iShowBMP2(530,145,"images\\help.bmp",0);
	iShowBMP2(510,109,"images\\continue.bmp",0);
	iShowBMP2(510,75,"images\\halloffamebutton.bmp",0);
	iShowBMP2(530,40,"images\\exit.bmp",0);


}


void HelpScreen()
{
	iShowBMP2(0,0,"images\\helpscreen.bmp",0);
	iSetColor(255,0,0);
	iText(100,700,"Right Arrow    :   Move Pacman to the right",GLUT_BITMAP_TIMES_ROMAN_24);
	iText(100,670,"Left Arrow      :    Move Pacman to the left",GLUT_BITMAP_TIMES_ROMAN_24);
	iText(100,640,"Up Arrow        :    Move Pacman to the up",GLUT_BITMAP_TIMES_ROMAN_24);
	iText(100,610,"Down Arrow   :    Move Pacman to the down",GLUT_BITMAP_TIMES_ROMAN_24);
	iText(100,580,"F1                    :    Turn sound effects ON/OFF",GLUT_BITMAP_TIMES_ROMAN_24);

	iShowBMP2(100,530,"images\\food.bmp",0);iText(170,530,"50   Points",GLUT_BITMAP_TIMES_ROMAN_24);
	iShowBMP2(100,490,"images\\food2.bmp",0);iText(170,490,"100   Points",GLUT_BITMAP_TIMES_ROMAN_24);
	iShowBMP2(100,450,"images\\food3.bmp",0);iText(170,450,"70   Points",GLUT_BITMAP_TIMES_ROMAN_24);
	iShowBMP2(100,410,"images\\frighten.bmp",0);iText(170,410,"200   Points",GLUT_BITMAP_TIMES_ROMAN_24);
	iText(100,370,"Eating small dots will give you 10 and eating big ones will give you 30 points",GLUT_BITMAP_TIMES_ROMAN_24);

	iText(100,300,"*Watch out for the ghosts.Eating big dots will make the ghosts frightened.",GLUT_BITMAP_TIMES_ROMAN_24);
	iText(100,260,"*Pacman can eat them while they are afraid.",GLUT_BITMAP_TIMES_ROMAN_24);
	iText(100,220,"Greetings from Blinky,Pinky,Inky,Clyde!!Good Luck...!!!!!!!",GLUT_BITMAP_TIMES_ROMAN_24);



	iShowBMP2(1080,50,"images\\home.bmp",0);
}


void GameOverScreen()
{

	iShowBMP2(0,0,"images\\gameover.bmp",0);
	iSetColor(255,255,255);
	iText(400,650,"Press Type Your name and then press ENTER",GLUT_BITMAP_TIMES_ROMAN_24);
	iSetColor(0,0,0);
	iFilledRectangle(500,590,300,40);
	iSetColor(255,255,255);
	iText(500,600,EnterName,GLUT_BITMAP_TIMES_ROMAN_24);

}

void ShowHallOfFame()
{
	ShowHighScores();
	iShowBMP2(0,0,"images\\halloffame.bmp",0);
	iSetColor(255,255,255);
	iText(400,700,"HALL OF FAME",GLUT_BITMAP_TIMES_ROMAN_24);
	str[0]='\0';
	sprintf(str,"%d",SortingArray[0].GameScore);
	iText(100,660,SortingArray[0].GameName,GLUT_BITMAP_TIMES_ROMAN_24);
	iText(500,660,str,GLUT_BITMAP_TIMES_ROMAN_24);
	str[0]='\0';
	sprintf(str,"%d",SortingArray[1].GameScore);
	iText(100,620,SortingArray[1].GameName,GLUT_BITMAP_TIMES_ROMAN_24);
	iText(500,620,str,GLUT_BITMAP_TIMES_ROMAN_24);
	str[0]='\0';
	sprintf(str,"%d",SortingArray[2].GameScore);
	iText(100,580,SortingArray[2].GameName,GLUT_BITMAP_TIMES_ROMAN_24);
	iText(500,580,str,GLUT_BITMAP_TIMES_ROMAN_24);
	str[0]='\0';
	sprintf(str,"%d",SortingArray[3].GameScore);
	iText(100,540,SortingArray[3].GameName,GLUT_BITMAP_TIMES_ROMAN_24);
	iText(500,540,str,GLUT_BITMAP_TIMES_ROMAN_24);
	str[0]='\0';
	sprintf(str,"%d",SortingArray[4].GameScore);
	iText(100,500,SortingArray[4].GameName,GLUT_BITMAP_TIMES_ROMAN_24);
	iText(500,500,str,GLUT_BITMAP_TIMES_ROMAN_24);
	str[0]='\0';
	sprintf(str,"%d",SortingArray[5].GameScore);
	iText(100,460,SortingArray[5].GameName,GLUT_BITMAP_TIMES_ROMAN_24);
	iText(500,460,str,GLUT_BITMAP_TIMES_ROMAN_24);
	str[0]='\0';
	sprintf(str,"%d",SortingArray[6].GameScore);
	iText(100,420,SortingArray[6].GameName,GLUT_BITMAP_TIMES_ROMAN_24);
	iText(500,420,str,GLUT_BITMAP_TIMES_ROMAN_24);
	str[0]='\0';
	sprintf(str,"%d",SortingArray[7].GameScore);
	iText(100,380,SortingArray[7].GameName,GLUT_BITMAP_TIMES_ROMAN_24);
	iText(500,380,str,GLUT_BITMAP_TIMES_ROMAN_24);
	str[0]='\0';
	sprintf(str,"%d",SortingArray[8].GameScore);
	iText(100,340,SortingArray[8].GameName,GLUT_BITMAP_TIMES_ROMAN_24);
	iText(500,340,str,GLUT_BITMAP_TIMES_ROMAN_24);
	str[0]='\0';
	sprintf(str,"%d",SortingArray[9].GameScore);
	iText(100,300,SortingArray[9].GameName,GLUT_BITMAP_TIMES_ROMAN_24);
	iText(500,300,str,GLUT_BITMAP_TIMES_ROMAN_24);


	iShowBMP2(1080,50,"images\\home.bmp",0);

}




void ShowWinScreen()
{

	iShowBMP2(0,0,"images\\halloffame.bmp",0);
	iSetColor(255,255,255);
	iText(400,650,"Press Type Your name and then press ENTER",GLUT_BITMAP_TIMES_ROMAN_24);
	iSetColor(0,0,0);
	iFilledRectangle(500,590,300,40);
	iSetColor(255,255,255);
	iText(500,600,EnterName,GLUT_BITMAP_TIMES_ROMAN_24);
}



void iDraw()
{
	iClear();

	if(life<=0)mainscreen=0,homescreen=0,help=0,rules=0,gameover=1;


	if(homescreen==1)HomeScreen();
	if(gameover==1)GameOverScreen();
	if(help==1)HelpScreen();
	if(halloffame==1)ShowHallOfFame();
	if(win==1)ShowWinScreen();


	if(mainscreen==1)Gamescreen();



}


void iMouseMove(int mx, int my)
{



}


void iMouse(int button, int state, int mx, int my)
{
	if(button == GLUT_LEFT_BUTTON && state == GLUT_DOWN )
	{
		if(homescreen==1){
			if(mx>=500&&mx<=500+224&&my>=190&&my<=190+36){
				mainscreen=1;
				homescreen=help=rules=0;
				score=0;
				pacman.ini=0;
				blinky.ini=0;
				pinky.ini=0;
				inky.ini=0;
				clyde.ini=0;
				life=3;
				Gamemode=1;
				tiime=1;
				for(int i=0;i<21;i++){
					for(int j=0;j<19;j++){
						maze[i][j]=ara[i][j];
					}
				}
			}
			if(mx>=530&&mx<=530+170&&my>=145&&my<=145+36){
				help=1;
				homescreen=mainscreen=rules=0;
			}


			if(mx>=510&&mx<=510+190&&my>=109&&my<=109+30){
				ShowSave();

				blinky.eat=save.blinkyeat;
				blinky.ini=save.blinkyini=0;


				clyde.eat=save.clydeeat;
				clyde.ini=save.clydeini=0;

				Gamemode=save.Ghostmode;

				inky.eat=save.inkyeat;
				inky.ini=save.inlyini=0;

				life=save.life;

				pacman.eat=save.Pacmaneat;
				pacman.ini=save.pacmanini=0;


				pinky.eat=save.pinkyeat;
				pinky.ini=save.pinkyini=0;


				tiime=save.time;
				score=save.score;

				for(int i=0;i<21;i++){
					for(int j=0;j<19;j++){
						maze[i][j]=save.maze[i][j];
					}
				}


				mainscreen=1;
				homescreen=0;
			}


			if(mx>=510&&mx<=510+200&&my>=75&&my<=75+30){
				halloffame=1;
				homescreen=mainscreen=rules=help=0;
			}
			if(mx>=530&&mx<=530+170&&my>=40&&my<=40+30){
					exit(0);
			}
		}



		if(help==1){
			if(mx>=1080&&mx<=1080+100&&my>=50&&my<=50+100){
				homescreen=1;
				mainscreen=help=rules=0;
			}
		}
		if(halloffame==1){
			if(mx>=1080&&mx<=1080+100&&my>=50&&my<=50+100){
				homescreen=1;
				halloffame=mainscreen=help=rules=0;
			}
		}
		if(mainscreen==1){
			if(mx>=1080&&mx<=1080+100&&my>=50&&my<=50+100){

				save.blinkyeat=blinky.eat;
				save.blinkyini=blinky.ini=0;

				save.clydeeat=clyde.eat;
				save.clydeini=clyde.ini=0;
				save.Ghostmode=Gamemode;

				save.inkyeat=inky.eat;
				save.inlyini=inky.ini=0;
				save.life=life;

				save.Pacmaneat=pacman.eat;
				save.pacmanini=pacman.ini=0;

				save.pinkyeat=pinky.eat;
				save.pinkyini=pinky.ini=0;
				save.time=tiime;
				save.score=score;


				for(int i=0;i<21;i++){
					for(int j=0;j<19;j++){
						save.maze[i][j]=maze[i][j];
					}
				}
				UpdateSave();
				homescreen=1;
				halloffame=mainscreen=help=rules=0;
			}
		}

	}
	if(button == GLUT_RIGHT_BUTTON && state == GLUT_DOWN)
	{


	}
}



void iKeyboard(unsigned char key)
{



		if(key!='\b'&&gameover==1){
			EnterName[indexNumber]=key;
			indexNumber++;
			EnterName[indexNumber]='\0';

		}
		else if(key=='\r'&&gameover==1){
				UpdateHighScores();
				homescreen=1;

		life=3;
		gameover=mainscreen=help=rules=0;

		}
		else if(gameover==1&&key=='\b'){
			if(indexNumber<=0)
					indexNumber=0;
				EnterName[--indexNumber]='\0';
		}


		if(key!='\b'&&win==1){
			EnterName[indexNumber]=key;
			indexNumber++;
			EnterName[indexNumber]='\0';

		}
		else if(key=='\r'&&win==1){
				UpdateHighScores();
				homescreen=1;

		life=3;
		gameover=mainscreen=help=rules=0;

		}
		else if(win==1&&key=='\b'){
			if(indexNumber<=0)
					indexNumber=0;
				EnterName[--indexNumber]='\0';
		}



    if(key=='\r')
    {
    	if(gameover==1){
		homescreen=1;
		UpdateHighScores();
		life=3;
		gameover=mainscreen=help=rules=0;
    	}
    	if(help==1){
		homescreen=1;


		gameover=mainscreen=help=rules=0;
    	}
    	if(win==1){
		homescreen=1;
		UpdateHighScores();
		life=3;
		win=gameover=mainscreen=help=rules=0;
    	}
    }





}



/*
	function iSpecialKeyboard() is called whenver user hits special keys like-
	function keys, home, end, pg up, pg down, arraows etc. you have to use
	appropriate constants to detect them. A list is:
	GLUT_KEY_F1, GLUT_KEY_F2, GLUT_KEY_F3, GLUT_KEY_F4, GLUT_KEY_F5, GLUT_KEY_F6,
	GLUT_KEY_F7, GLUT_KEY_F8, GLUT_KEY_F9, GLUT_KEY_F10, GLUT_KEY_F11, GLUT_KEY_F12,
	GLUT_KEY_LEFT, GLUT_KEY_UP, GLUT_KEY_RIGHT, GLUT_KEY_DOWN, GLUT_KEY_PAGE UP,
	GLUT_KEY_PAGE DOWN, GLUT_KEY_HOME, GLUT_KEY_END, GLUT_KEY_INSERT
*/
void iSpecialKeyboard(unsigned char key)
{


	if(key==GLUT_KEY_F1)
	{
		soundon*=(-1);
	}

     if(key ==GLUT_KEY_DOWN )
    {
        pacman.dir=3;
    }

     if(key ==GLUT_KEY_UP )
    {
        pacman.dir=1;
    }

     if(key ==GLUT_KEY_RIGHT )
    {
        pacman.dir=0;
    }

     if(key ==GLUT_KEY_LEFT )
    {
        pacman.dir=2;
    }



}





int main()
{


	ShowHighScores();
	highscore=SortingArray[0].GameScore;

	iSetTimer(1000,FrightIncrease);
	iSetTimer(1000,ModeChange);
	iSetTimer(1000,IncreaseTime);



	iSetTimer(20,launch_pacman);
	iSetTimer(20,Launch_clyde);
	iSetTimer(20,Launch_inky);
	iSetTimer(20,Launch_pinky);
	iSetTimer(20,Launch_blinky);

	iSetTimer(8,GhostEatCheck);
	iSetTimer(8,PacmanEatCheck);


	//place your own initialization codes here.
	iSetColor(0,0,0);


	iInitialize(screen_width, screen_height, "Demo!");


	return 0;
}
