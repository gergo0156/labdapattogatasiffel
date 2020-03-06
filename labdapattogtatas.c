#include <stdio.h>
#include <curses.h>
#include <unistd.h>

int
main ( void )
{
    WINDOW *ablak;
    ablak = initscr ();

    int x = 0;
    int y = 0;

    int xlepes = 1;
    int ylepes = 1;

    int mx;
    int my;

    for ( ;; ) {

        getmaxyx ( ablak, my , mx );

        mvprintw ( y, x, "O" );

        refresh ();
        usleep ( 100000 );

        x = x + xlepes;
        y = y + ylepes;

        if ( x>=mx-1 ) { // elerte-e a jobb oldalt?
            xlepes = xlepes * -1;
        }
        if ( x<=0 ) { // elerte-e a bal oldalt?
            xlepes = xlepes * -1;
        }
        if ( y<=0 ) { // elerte-e a tetejet?
            ylepes = ylepes * -1;
        }
        if ( y>=my-1 ) { // elerte-e a aljat?
            ylepes = ylepes * -1
        }

    }

    return 0;
}
