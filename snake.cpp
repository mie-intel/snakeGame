// ==============> Snake game code <============== //

#include<bits/stdc++.h>
#include<iostream>
#include<cstdlib>
#include<conio.h>
#include<Windows.h>
#include<MMSystem.h>

unsigned int sleep (unsigned int seconds);

using namespace std;

bool gameOver, ok = true, hardMode = false, prevhard = false;;
const int width = 20;
const int height = 20;
int x, y, fruitx, fruity, score;
int tailx[100],taily[100];
char hado[100];
int ntail;

enum eDirection {STOP = 0, LEFT, RIGHT, UP, DOWN};
eDirection dir;
char head = '^';

//============================================
void help(){
	string helsp;
	bool sin = true;
	
		system("cls");

		
		for(int i = 0; i < width + 2; i++){
			cout << "#";
		}cout << endl;

	for (int i = 0; i < height;i++){
		for (int j = 0; j < width;j++){
			if (j == 0)cout << "#";
			if (i == y && j == x){
				cout << head;
			}else if (i == fruity && j == fruitx){
				cout << "O";
			}
			else {
				bool print = false;
				for(int k = 0; k < ntail;k++){
					
					if (tailx[k] == j && taily[k] == i){
						cout << hado[k];
						print = true;
					}
				}if(!print)	cout <<" ";
			
			}
			if (j == width - 1) cout << "#";
		}cout << endl;
	}


	for(int i = 0; i < width + 2; i++){
		cout << "#";
	}



		cout << endl << endl;
		cout << "         Help" << endl;
		cout << "======================" << endl << endl;
		cout << "Move =================" << endl;
		cout << "Press: w to go up" << endl;
		cout << "       a to go left" << endl;
		cout << "       d to go right" << endl;
		cout << "       s to go down" << endl << endl;
		cout << "Another ==============" << endl;
		cout << "Press: p to pause game" << endl;
		cout << "       m to set game mode" << endl;
		cout << "       o to exit" << endl<<endl;
		cout << "Press any key to continue" << endl;
		cout << "Command: ";
		
		
		cin >> helsp;
		
	system("cls");
	

}
//============================================
void setMode(){
	system("cls");

	bool sin = true;
		
		for(int i = 0; i < width + 2; i++){
			cout << "#";
		}cout << endl;

	for (int i = 0; i < height;i++){
		for (int j = 0; j < width;j++){
			if (j == 0)cout << "#";
			if (i == y && j == x){
				cout << head;
			}else if (i == fruity && j == fruitx){
				cout << "O";
			}
			else {
				bool print = false;
				for(int k = 0; k < ntail;k++){
					
					if (tailx[k] == j && taily[k] == i){
						cout << hado[k];
						print = true;
					}
				}if(!print)	cout <<" ";
			
			}
			if (j == width - 1) cout << "#";
		}cout << endl;
	}


	for(int i = 0; i < width + 2; i++){
		cout << "#";
	}
	
	cout << endl << endl;
	cout << "     Settings Mode" << endl; 
	cout << "======================" << endl;
	cout << "Command \"true\" to activated Hard Mode" << endl;
	cout << "Command \"false\" to enter Easy Mode" << endl;
	cout << "Command: ";
	string hard;
	bool ten = true;

	while(ten){
		cin >> hard;
		if(hard == "true"){
			if(prevhard == false){
					system("cls");
							// rest ------------------------------------------------
									ntail = 0;
									gameOver = false;
									dir = STOP;
									x = width / 2;
									y = height / 2;
									score = 0;
									head = '^';

									int padma = 50;
									while(padma--){
										int go = rand() % 35;
										cout << endl << "  Restarting Game" << endl;
										for(int bakso = 0; bakso < go; bakso++){
											cout << "-";
										}system("cls");
									}
							// rest ------------------------------------------------
				}
			hardMode = true;
			prevhard = true;
			ten = false;
			system("cls");
		}
		else if (hard == "false"){
			
				if(prevhard == true){
					system("cls");
							// rest ------------------------------------------------
									ntail = 0;
									gameOver = false;
									dir = STOP;
									x = width / 2;
									y = height / 2;
									score = 0;
									head = '^';

									int padma = 50;
									while(padma--){
										int go = rand() % 35;
										cout << endl << "  Restarting Game" << endl;
										for(int bakso = 0; bakso < go; bakso++){
											cout << "-";
										}system("cls");
									}
							// rest ------------------------------------------------
				}
			prevhard = false;
			hardMode = false;
			ten = false;
			system("cls");
		}
		else {
			
			system("cls");
			for(int i = 0; i < width + 2; i++){
				cout << "#";
			}cout << endl;

			for (int i = 0; i < height;i++){
				for (int j = 0; j < width;j++){
					if (j == 0)cout << "#";
					if (i == y && j == x){
						cout << head;
					}else if (i == fruity && j == fruitx){
				cout << "O";
			}
			else {
				bool print = false;
				for(int k = 0; k < ntail;k++){
					
					if (tailx[k] == j && taily[k] == i){
						cout << hado[k];
						print = true;
					}
				}if(!print)	cout <<" ";
			
					}
				if (j == width - 1) cout << "#";
				}cout << endl;
			}


			for(int i = 0; i < width + 2; i++){
				cout << "#";
			}
			cout << endl << endl << "Wrong input";
		
			cout << endl << "Your input was: \"" << hard << "\"" << endl;
			cout << "Command \"true\" to activated Hard Mode" << endl;
			cout << "Command \"false\" to enter Easy Mode";
			cout << endl << "Command: ";
		}
	}
}
//============================================
void gameMode(bool mode){
	if(mode){
		if(x > width || x < 0 || y > height || y < 0){
			gameOver = true;
			ok = false;
		}
	}else{
		if (x >= width)x = 0; else if (x < 0)x = width - 1;
		if (y >= height)y = 0; else if (y < 0)y = height - 1;
	}
}
//============================================
void board(){
	cout << endl << endl;
		cout << "Score: " << score << endl;
	
		cout << "Press p to pause" << endl;
		cout << "Press m to change mode" << endl;
		cout << "Press h to go to help" << endl;
		cout << "Press o to exit" << endl;
		cout << "Snake Arya" << endl;
			if(hardMode == true)cout << "Hard" << endl;
			else if(hardMode == false)cout << "Easy" << endl;
}

//============================================
void draw(){
	system("cls");
	for(int i = 0; i < width + 2; i++){
		cout << "#";
	}cout << endl;

	for (int i = 0; i < height;i++){
		for (int j = 0; j < width;j++){
			if (j == 0)cout << "#";
			if (i == y && j == x){
				cout << head;
			}else if (i == fruity && j == fruitx){
				cout << "O";
			}
			else {
				bool print = false;
				for(int k = 0; k < ntail;k++){
					
					if (tailx[k] == j && taily[k] == i){
						cout << hado[k];
						print = true;
					}
				}if(!print)	cout <<" ";
			
			}
			if (j == width - 1) cout << "#";
		}cout << endl;
	}


	for(int i = 0; i < width + 2; i++){
		cout << "#";
	}
}

//============================================
void rest(){
	ntail = 0;
	gameOver = false;
	dir = STOP;
	x = width / 2;
	y = height / 2;
	fruitx = rand() % (width - 2) + 1;
	fruity = rand() % (height - 2) + 1;
	score = 0;
	head = '^';
}

//============================================
void pauseGame(){
	system("cls");
	
	draw();
	string ko;
	
	while(true){
		cout << endl << endl;
		cout << "     Game Paused" << endl; 
		cout << "======================" << endl;
		cout << "Press m to set Mode " << endl << "Press s to continue" << endl ;
		cout << "Press r to restart" << endl<< "Press h to go to help" <<  endl <<"Type \"exit\" to exit" << endl;
		cout << "Command: ";
		cin >> ko;
		if (ko == "m"){
			setMode();
			system("cls");
			draw();
		}else if (ko == "r"){
			system("cls");
			rest();
			int padma = 50;
			while(padma--){
				int go = rand() % 35;
				cout << endl << "  Restarting Game" << endl;
				for(int bakso = 0; bakso < go; bakso++){
					cout << "-";
				}system("cls");
			}draw();
			
		}
		else if (ko == "s"){
			gameOver = false;
			break;
		}else if (ko == "exit"){
			system("cls");
			ok = false;
			gameOver = true;
			break;
		}else if (ko == "h"){
			system("cls");
			help();
			draw();
		}
		else {
			system("cls");
			cout << "Wrong input" << endl;
			Sleep(2);
			draw();

		}
	}
}

//============================================
void setup(){
	hardMode = false;
	gameOver = false;
	dir = STOP;
	x = width / 2;
	y = height / 2;
	fruitx = rand() % (width - 2) + 1;
	fruity = rand() % (height - 2) + 1;
	score = 0;
}

//============================================
void input(){
	if(_kbhit() && dir == STOP){
		switch(getch()){
			case 'd':
				dir = RIGHT;
				break;
			case 'a':
				dir = LEFT;
				break;
			case 'w':
				dir = UP;
				break;
			
			case 's':
				dir = DOWN;
				break;
			case 'p':
				gameOver = true;
				pauseGame();
				break;
			case 'o':
				ok = false;
				gameOver = true;
				break;
			case 'm':
				setMode();
				break;
			case 'h':
				help();
				break; 
		}
	}
	if(_kbhit() && dir == LEFT){
		switch(getch()){
			case 'a':
				dir = LEFT;
				break;
			case 'w':
				dir = UP;
				break;
			
			case 's':
				dir = DOWN;
				break;
			case 'p':
				gameOver = true;
				pauseGame();
				break;
			case 'o':
				ok = false;
				gameOver = true;
				break;
			case 'm':
				setMode();
				break;
			case 'h':
				help();
				break; 
		}
	}else if(_kbhit()&& dir == RIGHT){
		switch(getch()){
			
			case 'w':
				dir = UP;
				break;
			case 'd':
				dir = RIGHT;
				break;
			case 's':
				dir = DOWN;
				break;
			case 'p':
				gameOver = true;
				pauseGame();
				break;
			case 'o':
				ok = false;
				gameOver = true;
				break;
			case 'm':
				setMode();
				break;
			case 'h':
				help();
				break; 
		}
	}else if(_kbhit() && dir == UP){
		switch(getch()){
			case 'a':
				dir = LEFT;
				break;
			case 'w':
				dir = UP;
				break;
			case 'd':
				dir = RIGHT;
				break;
			
			case 'p':
				gameOver = true;
				pauseGame();
				break;
			case 'o':
				ok = false;
				gameOver = true;
				break;
			case 'm':
				setMode();
				break;
			case 'h':
				help();
				break; 
		}
	}else if(_kbhit() && dir == DOWN){
		switch(getch()){
			case 'a':
				dir = LEFT;
				break;
			
			case 'd':
				dir = RIGHT;
				break;
			case 's':
				dir = DOWN;
				break;
			case 'p':
				gameOver = true;
				pauseGame();
				break;
			case 'o':
				ok = false;
				gameOver = true;
				break;
			case 'm':
				setMode();
				break;
			case 'h':
				help();
				break; 
		}
	}
			
}

//============================================
void logic(){
	int prevx = tailx[0];
	int prevy = taily[0];
	char prevh = hado[0];
	int prev2x, prev2y;
	char prev2h;
	tailx[0] = x;
	taily[0] = y;
	hado[0] = head;

	for(int i = 1; i < ntail; i++){
		prev2x = tailx[i];
		prev2h = hado[i];
		prev2y = taily[i];
		tailx[i] = prevx;
		hado[i] = prevh;
		taily[i] = prevy;
		prevx = prev2x;
		prevy = prev2y;
		prevh = prev2h;
	}

	switch (dir){
		case LEFT:
			head = '<';
			x--;
			break;
		case RIGHT:
			head = '>';
			x++;
			break;
		case UP:
			head = '^';
			y--;
			break;
		case DOWN:
			head = 'v';
			y++;
			break;
		default:
			break;
	}
	//========================================
	gameMode(hardMode);
	for(int i = 0; i < ntail; i++){
		if (tailx[i] == x && taily[i] == y){
			gameOver = true;
			ok = false;
		}
	}
	//========================================
	if (x == fruitx && y == fruity){
		score += 10;
		fruitx = rand() % (width - 2) + 1;
		fruity = rand() % (height - 2) + 1;
		ntail++;
		Beep(435 * 5,500);
	}
}

//============================================
void game(){
	system("cls");
	int padma = 50;
	while(padma--){
		int go = rand() % 35;
		cout << endl << "           Loading" << endl;
		for(int bakso = 0; bakso < go; bakso++){
			cout << "-";
		}system("cls");
	}
		gameOver = false;
		draw();
			Beep(43*50, 2000);
			
			while(!gameOver){
				
				draw();
				board();
				input();
				logic();

				Sleep(0.9);
				if (ok == false)break;
			}
			if (ok == true && gameOver == true)
				pauseGame();
}

//============================================
int main(){
	string in;

	setup();
	cout << "Press s to start / continue: ";
		cin >> in;

		if (in == "s"){
			while(ok){
				game();
			}
			
			
		}else {
			cout << endl;
			cout << "                   <===== Wrong input =====>"<< endl;
			cout << "Command \"exit\" if you want to exit or type another to start again";
			cout << endl << "Command: ";
			cin >> in;
			if (in.compare("exit") != 0) game();
	}
	system("cls");
	draw();
	input();
	logic();
	cout << endl;
	cout << endl;
	cout << "        Result" << endl;
	cout << "======================" << endl;
	cout << "Final score = " << score << endl;
	if(hardMode)cout << "dif: Hard";
	else cout << "dif: Easy";
	cout << endl;
				if (score <= 40)cout << "> NOOB";
				else if (score <= 100)cout << "> Mayan";
				else if (score <= 200) cout << "> Sithik malih";
				else cout << "> BEJO";
				cout << endl;

				Beep(43 * 50,1000);
				Beep(40 * 50,1500);
				Beep(38 * 50,3000);
	return 0;
}

//============================================