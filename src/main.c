#include "../lib/main.h"
#include "../lib/mysdl.h"

int main(int argc, char ** argv)
{
    SDL_Window *w;
    SDL_Renderer *r;
    if(mySDL_Init(SDL_INIT_EVERYTHING,&w,800,600,
            SDL_WINDOW_MAXIMIZED | SDL_WINDOW_RESIZABLE | SDL_WINDOW_OPENGL,
            "GalaxyBead v0.test",&r) || TTF_Init())
    {
        fprintf(stderr,"Error initializing...\n");
        return EXIT_FAILURE;
    }

    fprintf(stderr,"Initialization successful!\n");
    SDL_RenderClear(r);
    SDL_RenderPresent(r);

    HWND hwnd = mySDL_Get_WinHandle(w);
    if(!hwnd)
    {
        fprintf(stderr,"Window handle NULL\n");
        return EXIT_FAILURE;
    }

    /*
    HMENU menu = CreateMenu();
    HMENU menu_file = CreateMenu();
    AppendMenu(menu_file,MF_STRING,MENU_FILE_NEW,"New");
    AppendMenu(menu_file,MF_STRING,MENU_FILE_OPEN,"Open");
    AppendMenu(menu_file,MF_SEPARATOR,(UINT_PTR)NULL,NULL);
    AppendMenu(menu_file,MF_STRING,MENU_FILE_EXIT,"Exit");

    AppendMenu(menu,MF_POPUP,(UINT_PTR)menu_file,"File");
    AppendMenu(menu,MF_STRING,(UINT_PTR)NULL,"Edit");
    SetMenu(hwnd,menu);
    */

    bool close = false;
    SDL_Event event;
    //SDL_EventState(SDL_SYSWMEVENT, SDL_ENABLE);
    while(!close)
    {
        SDL_PollEvent(&event);
        switch(event.type)
        {
            case SDL_WINDOWEVENT_CLOSE:
            case SDL_QUIT:
                close = true;
                break;
            /*
            case SDL_SYSWMEVENT:
                if(event.syswm.msg->msg.win.msg == WM_COMMAND)
                {
                    printf("test\n");
                    if(event.syswm.msg->msg.win.lParam == MENU_FILE_EXIT)
                    {
                        printf("exiting!\n");
                        close = true;
                    }
                }
                break;
            */
            default:
                break;
        }

        SDL_RenderClear(r);
        SDL_RenderPresent(r);
    }

    mySDL_Close(LEVEL_REND,r,w);
    fprintf(stderr,"Closing successful!\n");
    return 0;
}