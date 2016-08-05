//HEADER FILES

/*

Authours:  Sai Praneeth (1031310381)
           Satyam Verma (1031310411)

*/

#include <iostream.h>
#include <string.h>
#include <conio.h>
#include <math.h>
#include <graphics.h>
#include <dos.h>
#include <ctype.h>
#include <stdlib.h>
#include <time.h>
#include <iomanip.h>
#include <fstream.h>



int hangman(int count,int end){
		int gd=DETECT,gm,gameover=0;
		initgraph(&gd,&gm,"C:\\TC\\BGI");
		settextstyle(DEFAULT_FONT,HORIZ_DIR,3);      //default font
		outtextxy(25,30,"HANGMAN!");
		line(0,55,700,55);   //underline
		settextstyle(DEFAULT_FONT,HORIZ_DIR,2);
		if(count>=1){
			line(200,400,500,400);  	    //base
			line(400,400,400,100);      	//stand
			line(275,100,400,100);			//top
			line(275,100,275,150);			//drop-down
			if(count==1)	outtextxy(25,430,"6 Chances left!");
		}

		if(count>=2){
			circle(275,175,25);				//head
			if(count==2)	outtextxy(25,430,"5 Chances left!");
		}

		if(count>=3){
			line(275,200,275,290);			//body
			if(count==3)	outtextxy(25,430,"4 Chances left!");
		}

		if(count>=4){
			line(275,240,225,240);			//left arm
			if(count==4)	outtextxy(25,430,"3 Chances left!");
		}

		if(count>=5){
			line(275,240,325,240);			//right arm
			if(count==5)	outtextxy(25,430,"2 Chances left!");
		}

		if(count>=6){
			line(275,290,239,326);			//left leg
			if(count==6)	outtextxy(25,430,"1 Chances left!");
		}

		if(count>=7){
			line(275,290,311,326);			//right leg
			if(count==7 && end!=0)	outtextxy(25,430,"OOPS!");
			outtextxy(25,460,"Press any KEY to continue..");
			getch();
			if(end!=0){
				cleardevice();
				settextstyle(DEFAULT_FONT,HORIZ_DIR,6);
				outtextxy(100,250,"GAME OVER!");
				gameover=1;
			}
		}
		
	//	settextstyle(DEFAULT_FONT,HORIZ_DIR,1);
	//	outtextxy(25,460,"Press any KEY to continue..");
		getch();
		cleardevice();
		closegraph();
		return gameover;
}

int start(int trial){
	int choice;
	hangman(7,trial);
//	rules();
	cout<<"Welcome to HANGMAN!\n\n\n";
	cout<<"Select Category:\n1.Countries\n2.Cities\n3.Animals\n4.Movies\nChoice: ";
	cin>>choice;
	return choice;
}

void wordSet(int cat,char word[]){

	ifstream indata;
	ofstream outdata;
	indata.open("Hangman\\Database.csv");

	srand (time(NULL));
	int j,i = rand() % 7;
	if(cat==1) 			i += 1;
	else if(cat==2)		i += 8;
	else if(cat==3) 	i += 15;
	else if(cat==4)		i += 22;
	else				{	cout<<"Invalid Category\n"; cat = start(0); wordSet(cat,word); }
	for(j = 0;j<i;j++)	indata>> word;
//	cout<<i;
}

int main(){
	int gameover=0;
	while(1 && (gameover==0)){
		clrscr();
		int cat,trial=0,wordlen,wrongans=0,correct = 0,blanks[100]={0},i,check,temp=0;
		char again,word[100],alpha[26],letter;

		for(i=0;i<26;i++)	alpha[i] = 65+i;				//Available alphabets

		cat = start(trial);
		wordSet(cat,word);
		wordlen = strlen(word);
		while(wrongans<7 && correct != wordlen){
			clrscr();
			check = 0;
			if(cat == 1)	cout<<"Guess the country: \n\n";
			else if(cat == 2)	cout<<"Guess the city: \n\n";
			else if(cat == 3)	cout<<"Guess the animal: \n\n";
			else if(cat == 4)	cout<<"Guess the movie: \n\n";
			
			for(i=0;i<wordlen;i++){
				if(blanks[i]==0 && (word[i]>=65 && word[i]<91))	cout<<"_ ";
				else if (word[i]=='*'){
					if(temp==0)	correct++;
					cout<<"   ";
				}
				else{
					if(temp==0)	correct++;
					cout<<word[i]<<" ";
				}
			}
			
	//		cout<<endl<<endl<<correct<<endl<<endl;                                //for testing

			cout<<"\n\nAvailable Letters:   ";
			for(i=0;i<26;i++)	cout<<alpha[i];
			
			cout<<"\nEnter choice: ";
			cin>>letter;
			letter = toupper(letter);
			if(letter == '*') break;                         //for testing purposes
			
			
			//To avaoid repetition
			else{
				for(i=0;i<26;i++){
					if(alpha[i]==letter){
						check++;
						break;
					}
				}
				if(check==0){
					cout<<"\nThis letter has already been entered.Choose letter from the available options.\nPress ANY key to continue..";
					getch();
					continue;
				}
			}

			check = 0;										//reset
			temp = (letter-'A');
			alpha[temp] = ' ';
			trial++;
			
			for(i=0;i<wordlen;i++){
				if(word[i] == letter){
					blanks[i] = 1;
					correct++;
					check++;
				}
			}
			if(check == 0){
				cout<<"OOPS!\nLetter not present in the word.";
				wrongans++;
				gameover = hangman(wrongans,1);							//to set end not to 0
			}

			temp=1;
		}
		if(correct == wordlen)	cout<<"\n\n\nYAY!! YOU WIN!!\n";
			
		cout<<"\nRight answer : ";
		for(i=0;i<wordlen;i++){
			if(word[i] == '*')	cout<<" ";
			else 	cout<<word[i];
		}

		cout<<"\n\nDo you want to play again? (Y/N) ";
		cin>>again;
		if(again == 'n' || again == 'N') break;
		gameover = 0;
	}
	
	cout<<"Press any KEY to exit..";
	getch();
	return 0;
}
