#include <stdio.h>
#include <stdlib.h>
#include <ncurses.h>
#include <time.h>
#define TICKS 100  // 1 millisecond = 1,000,000 Nanoseconds
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
	char sprite;
}block;
typedef struct
{
	int block_count;
	int row_size;
	int row_count;
	block** blocks;
}level_t;

level_t gen_level(int level)
{
	level_t l;
	block b[l.row_size][l.row_count];
	l.blocks = b;
	l.row_size = MAXIMUM_RIGHT-1;
	l.row_count = 12+level;
	l.block_count = l.row_size * l.row_count;
	printw("niggers\n");
	refresh();
	for(int i = 0; i < l.row_size; i++)
	{
		for(int j = 0;j< l.row_count;j++)
		{
		
			l.blocks[i][j].x = 2+i;
			l.blocks[i][j].y = 2+j;
			printw("fuckin\n");
			refresh();
			switch(rand()%2)
			{
				case 0:
					l.blocks[i][j].value = 20;
					l.blocks[i][j].sprite = '$';
					break;
				case 1:
					l.blocks[i][j].value =10;
					l.blocks[i][j].sprite ='0';
					break;
			}
		}
	}
	printf("I reached till here without segfaulting");

}
int main()
{
	// ALL OUR ESSENTIAL INITS GO HERE
	initscr();
	noecho();
	raw();
	keypad(stdscr, true);
	curs_set(false);
	nodelay(stdscr,true);
	timeout(TICKS);
	srand(time(NULL));

	// ALL OUR VARIABLES MUST BE STARTED TOO
	ball b;
	paddle p;
	p.sprite = "========";
	p.x = 18;
	b.x = 4;
	b.y = (rand()%6)+2;
	b.vel_x = 1;  
	b.vel_y = 1;
	int lives = 3;
	int points = 0;	
	int c;		
	int exit = 0;
	char move = ' ';

	int level = 0;
	
	level_t current_level = gen_level(level);	
	int remaining_blocks = current_level.block_count;
	//MAIN GAME LOOP
	
	// gotta render first frame tho
	mvprintw(b.y,b.x,"o");
	draw_frame(25);	
	refresh();
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
		    }
		}
		switch(move)
		{
			case 'l':
				if((p.x) > 1) p.x--;
				break;
			case 'r':
			 	if((p.x+8) <= MAXIMUM_RIGHT) p.x++;
				break;
		}
		
		// COLLISION DETECTION & CHECKING FOR LIVES
		if(b.y >= MAXIMUM_DOWN)
		{
			lives--;
			b.y = (rand()%6)+2;
		}
		if(b.x >= MAXIMUM_RIGHT || b.x <= 1) 
			b.vel_x *= -1;
		b.x+=b.vel_x;

		if(b.y <= 1|| (b.y ==(MAXIMUM_DOWN-1) && (b.x >= p.x && b.x < (p.x+8))))
			b.vel_y *= -1;
		b.y += b.vel_y;


		/**	RENDERING	**/
		clear();
		draw_frame(0);
		mvprintw(MAXIMUM_DOWN-1,p.x,p.sprite);
		mvprintw(b.y,b.x,"o");
		mvprintw(MAXIMUM_DOWN+2,0,"LIVES: ");
		for(int i =-1; i < lives-1;i++)
			mvprintw(MAXIMUM_DOWN+2,8+i,"o ");
		mvprintw(MAXIMUM_DOWN+3,0,"POINTS: %d",points);
		refresh;
	}


	endwin();
}

void draw_frame(int mills)
{
	mvprintw(0,0,"++++++++++++++++++++++++++++++++++++++++++++");
	for(int i = 1; i< MAXIMUM_DOWN+1;i++)
	{
		mvprintw(i,0,"+                                          +");
	}
	mvprintw(MAXIMUM_DOWN+1,0,"++++++++++++++++++++++++++++++++++++++++++++");
}


