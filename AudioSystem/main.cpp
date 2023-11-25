#include "AplikacijaGUI.h"
#include "muzikaTest.h"

int main()
{
    AplikacijaGUI AudioSystemGUI;

    while (AudioSystemGUI.getWindowIsOpen()) //petlja u kojoj se odvijaju akcije aplikacije dok je prozor otvoren
    {
        //update
        AudioSystemGUI.UpdateGUI();

        //render
        AudioSystemGUI.RenderGUI();
    }


    //AudioPlayer player;
    //player.Pokreni();
    
    return 0;
}