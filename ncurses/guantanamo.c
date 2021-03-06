#include <stdio.h>
#include <stdlib.h>
#include <curses.h>
#include <time.h>
#define TICKS 80  // 1 millisecond = 1,000,000 Nanoseconds
#define MAXIMUM_RIGHT 42 
#define MAXIMUM_DOWN 24//14

void draw_frame();
typedef struct
{
	int x;
	int y;
	int vel_x;
	int vel_y;
}ball;
typedef struct
{
	int x;//leftmost position of paddle
	char* sprite;// 
}paddle;
typedef struct
{
	int x;
	int y;
	int value;
	int is_ded;
	char* sprite;
}block;
typedef struct
{
	int block_count;
	int row_size;
	int row_count;
	block blocks[64][64];
}level_t;
typedef struct
{
	char* name;
	int score;
	int ranking;
} player_score;

level_t gen_level(int level)
{
	level_t l;
	l.block_count = 0;
	l.row_size = MAXIMUM_RIGHT-2;
	l.row_count = 6+level;
	for(int i = 0; i < l.row_size; i++)
	{
		for(int j = 0;j< l.row_count;j++)
		{
		
			if(i % 4 ==0 ) 
			{
				l.blocks[i][j].x = 2+i;
				l.blocks[i][j].y = 4+j;
				l.blocks[i][j].is_ded = 0;
				switch(rand()%24)
				{
					case 0:
					case 1:
						l.blocks[i][j].value = 20;
						l.blocks[i][j].sprite = "$$$$";
						break;
					case 2:
					case 3:
					case 4:
						l.blocks[i][j].value =10;
						l.blocks[i][j].sprite ="####";
						break;
					case 23:
						l.blocks[i][j].value =50;
						l.blocks[i][j].sprite ="[EL]";
						break;
					default:
						l.blocks[i][j].value =10;
						l.blocks[i][j].sprite ="####";
						break;
				}
				l.block_count++;

			}
		}

	}
	return l;

}
void clear_scores()
{
	FILE* f= fopen("iwillnever.score","w");
       	if(f == NULL) 
	{
		mvprintw(64,0,"error fugg");
		return;
	}
	char* names[9] = { "HTL","JSG","MSL","HMM","GOE","SPR","HSS","FGL","ROM"};
	for(int i = 1;i <=9;i++)
	{
		fprintf(f,"%s\t6000000\n",names[i-1]); 
	}	
	fclose(f);
}
void check_score(int newscore)
{
	FILE* f= fopen("iwillnever.score","r+");
       	if(f == NULL) 
	{
		mvprintw(64,0,"error fugg");
		return;
	}	
	
	fseek(f,0,SEEK_END);
	long f_size = ftell(f);
	fseek(f,0,SEEK_SET);
	char buffer[f_size];
	fread(buffer,f_size,1,f);
	fclose(f);
	
	player_score scores[9];
	for(int i=0;i<9;i++)
	{
		scores[i].ranking = i+1;
		sscanf(buffer,"%s\t%d",scores[i].name,scores[i].score);
	}
}

void get_highscores()
{
	FILE* f= fopen("iwillnever.score","r+");
       	if(f == NULL) 
	{
		mvprintw(64,0,"error fugg");
		return;
	}	
	char* name;
	int score;
	int ranking;
	
	char buf[20];
	int i = 0;
	while (fgets(buf, sizeof buf, f) != NULL) 
	{
		//fscanf(buf,"%d\t%12s\t%d\n",&ranking,name,&score);
		//mvprintw(5+(i++),8,"%30%d\t%s\t%d\n",ranking,name,score);
		mvprintw(5+(i++),0,"%d\t%s",i,buf);
	}
	mvprintw(5+i,0,"\n\nESC ESCAPES, SPACEBAR PLAYS, R RESETS (SCORES)");
	fclose(f);
	
}
void game();
int main(void)
{
	// ALL OUR ESSENTIAL INITS GO HERE
	initscr();
	noecho();
	//raw();
	keypad(stdscr, true);
	curs_set(false);
	nodelay(stdscr,true);
	timeout(TICKS);
	srand(time(NULL));


	int c;
	while((c = getch()) != 27) 
	{
		//draw_frame(0);
		mvprintw(2,0,"\tGUANTANAMO");
		refresh();
		get_highscores();
		refresh();
		if(c != ERR) 
		{
			switch(c)
			{
				case ' ':
					game();
					clear();
					break;
				case'r':
					clear_scores();
					break;
			}
		}
	}
	endwin();
}
void game()
{
	// ALL OUR VARIABLES MUST BE STARTED TOO
	int level = 0;
	paddle p;
	ball b;
	p.sprite = "========";
	p.x = 16;
	b.x = p.x+3;
	b.y = MAXIMUM_DOWN -2;
	b.vel_x = 0;  
	b.vel_y = 0;
	int lives = 3;
	int points = 0;	
	int c;		
	int exit = 0;

	char move = ' ';
	int launch = 0;

	
	level_t current_level = gen_level(level);	
	int remaining_blocks = current_level.block_count;
	//MAIN GAME LOOP
	
	// gotta render first frame tho
	while((c = getch()) != 27 && lives > 0) 
	{
		// GET KEYBOARD POOP
		if(c != ERR) 
		{
		    switch(c)
		    {
		    
		    	case KEY_LEFT:
				if(move == ' ') move = 'l';
				else move = ' ';

			 	break;
		    	case KEY_RIGHT:
				if(move == ' ') move = 'r';
				else move = ' ';
			 	break;
			case ' ':
				move = ' ';
				if(launch == 0)launch = 1;

		    }
		}
		switch(move)
		{
			case 'l':
				if((p.x) > 1) p.x-=3;
				break;
			case 'r':
			 	if((p.x+8) <= MAXIMUM_RIGHT-1) p.x+=3;
				break;
		}
		if(p.x <= 1) 
		{
			p.x = 1;
			move = ' ';
		}
		if(p.x+8 > MAXIMUM_RIGHT-1) 
		{
			p.x = MAXIMUM_RIGHT-7;
			move = ' ';
		}
		if(launch == 0) b.x = p.x+3;
		else if(launch == 1)
		{
			launch = -1;
			b.vel_y = -1;
			b.y--;
			switch(rand()%2)
			{
				case 0:
					b.vel_x = -1;
					break;
				case 1:
					b.vel_x = 1;
				break;
			}
		}
				
		// COLLISION DETECTION & CHECKING FOR LIVES
		for(int i =0;i<current_level.row_size;i++)
		{
			for(int j =0;j<current_level.row_count;j++)
			{
				if((current_level.blocks[i][j].x == b.x||current_level.blocks[i][j].x+1 ==b.x || current_level.blocks[i][j].x+2 ==b.x || current_level.blocks[i][j].x+3 ==b.x )&& current_level.blocks[i][j].y == b.y && current_level.blocks[i][j].is_ded == 0) 
				{
					current_level.blocks[i][j].is_ded = 1;
					points += current_level.blocks[i][j].value;
					remaining_blocks--;
					if(remaining_blocks < 1)
					{
						current_level = gen_level(level++);
						launch = 0;	
						b.x = p.x+3;
						b.y = MAXIMUM_DOWN-2;
						b.vel_x = 0, b.vel_y = 0;
						remaining_blocks = 0;
						remaining_blocks = current_level.block_count;
					}
					b.vel_y *= -1;
					//if((rand()%4) > 1) b.vel_x *= -1;
					if(current_level.blocks[i][j].value == 50) lives++;
				}
			}
		}
		if(b.x >= MAXIMUM_RIGHT-1 || b.x <= 1) 
		{	
			b.vel_x *= -1;
		}
		b.x+=b.vel_x;

		if(b.y <= 1|| (b.y ==(MAXIMUM_DOWN-2) && (b.x >= p.x && b.x <= (p.x+8))))
		{
			b.vel_y *= -1;	
			if(b.vel_x < 0 && move == 'l' && b.vel_x > -2) b.vel_x--;
			else if (b.vel_x > 0 && move == 'r'&& b.vel_x < 2) b.vel_x++;

			if(b.vel_x < 0 && move == 'r') b.vel_x=1;
			else if(b.vel_x > 0 && move == 'l') b.vel_x=-1;

			if(b.vel_x < -1) b.vel_x = -1;
			if(b.vel_x > 1) b.vel_x = 1;
		}
		b.y += b.vel_y;
		if(b.x >MAXIMUM_RIGHT-1) b.x = MAXIMUM_RIGHT-1; 
		if(b.x < 1) b.x = 1; 

		if(b.y >= MAXIMUM_DOWN+2)
		{
			lives--;
			b.y = 10+level;
			b.vel_x = 0;
			switch(rand()%2)
			{
				case 0:
					b.vel_x = -1;
					break;
				case 1:
					b.vel_x = 1;
			}
			b.x = (rand()%(MAXIMUM_RIGHT-5))+6;
		}

		/**	RENDERING	**/
		clear();
		draw_frame(0);
		mvprintw(MAXIMUM_DOWN-1,p.x,p.sprite);
		mvprintw(b.y,b.x,"o");
		mvprintw(MAXIMUM_DOWN+2,0,"LIVES: ");
		for(int i =-1; i < lives-1;i++)
			mvprintw(MAXIMUM_DOWN+2,8+i,"o ");
		mvprintw(MAXIMUM_DOWN+3,0,"POINTS: %d",points);
		mvprintw(MAXIMUM_DOWN+4,0,"LEVEL %d",level+1);
		mvprintw(MAXIMUM_DOWN+5,0,"REMAINING BLOCKS: %d",remaining_blocks);
		for(int i =0;i<current_level.row_size;i++)
		{
			for(int j =0;j<current_level.row_count;j++)
			{
				if(current_level.blocks[i][j].is_ded != 1 && i % 4 == 0 ) 
					mvprintw(current_level.blocks[i][j].y,current_level.blocks[i][j].x,"%s",current_level.blocks[i][j].sprite);
			}
		}
		refresh;
	}	
	check_score(points);
}

void draw_frame(int mills)
{
	mvprintw(0,0,"++++++++++++++++++++++++++++++++++++++++++++");
	for(int i = 1; i< MAXIMUM_DOWN+1;i++)
	{
		mvprintw(i,0,"+                                          +");
	}//	mvprintw(2,0,"                 GUANTANAMO                  ");
	mvprintw(MAXIMUM_DOWN+1,0,"++++++++++++++++++++++++++++++++++++++++++++");
}



