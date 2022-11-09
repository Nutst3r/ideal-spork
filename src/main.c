#include <genesis.h>

extern bool bstartpressed = 0;
void myJoyHandler( u16 joy, u16 changed, u16 state)

{
    if (joy == JOY_1)
    {
        if (state & BUTTON_START)
        {
            bstartpressed = 1;
            
            //player 1 press start
        }
        else if (changed & BUTTON_START)
        {
            bstartpressed = 0;
            //player 1 released start buttonerio
        }
    }
}

int main(u16 hard)
{
    JOY_init();
    JOY_setEventHandler( &myJoyHandler );


//    while(1)
//    {
//        VDP_waitVSync();
//    }



    int i = 1;
    char vtext[20];
    int vx = 1;

    
    if (bstartpressed == 1){
    while(i <= 10){
        VDP_waitVSync();
        i = i + 1;
        SYS_doVBlankProcess();
        VDP_drawText("Hello Genny World!", vx, 10);
        waitMs(20);
        //VDP_resetScreen();
        VDP_drawText("Hello Genesis World!!", 15, 5);
        waitMs(20);
        //VDP_resetScreen();
        sprintf(vtext, "%i", i);
        VDP_drawText(vtext , 10 , 10);
        waitMs(200);
        //VDP_resetScreen();
        vx = vx +1;
        // read input
        // move sprite
        // update score
        // draw current screen (logo, start screen, settings, game, gameover, credits...)

        // wait for screen refresh
    
    }
    }
    else (bstartpressed == 0);

    return 0;
}