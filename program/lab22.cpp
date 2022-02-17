

#if defined(UNICODE) && !defined(_UNICODE)
    #define _UNICODE
#elif defined(_UNICODE) && !defined(UNICODE)
    #define UNICODE
#endif
#include <chrono>
#include <ctime>
#include <cmath>
#include <math.h>
#include <tchar.h>
#include <windows.h>
#include <winuser.h>
#include <iostream>
#define ID_TIMER 1
#include <cstdlib>
#include <ctime>

/*  Declare Windows procedure  */
LRESULT CALLBACK WindowProcedure (HWND, UINT, WPARAM, LPARAM);
std::chrono::time_point<std::chrono::system_clock> m_StartTime;
    std::chrono::time_point<std::chrono::system_clock> m_EndTime;
    bool                                               m_bRunning = false;
void start()
    {
        m_StartTime = std::chrono::system_clock::now();
        m_bRunning = true;
    }

    void stop()
    {
        m_EndTime = std::chrono::system_clock::now();
        m_bRunning = false;
    }

    double elapsedMilliseconds()
    {
        std::chrono::time_point<std::chrono::system_clock> endTime;

        if(m_bRunning)
        {
            endTime = std::chrono::system_clock::now();
        }
        else
        {
            endTime = m_EndTime;
        }

        return std::chrono::duration_cast<std::chrono::milliseconds>(endTime - m_StartTime).count();
    }

    double elapsedSeconds()
    {
        return elapsedMilliseconds() / 1000.0;
    }


char conv(int tic)
          {
               switch (tic)
               {
                    case 0: return '0';
                    case 1: return '1';
                    case 2: return '2';
                    case 3: return '3';
                    case 4: return '4';
                    case 5: return '5';
                    case 6: return '6';
                    case 7: return '7';
                    case 8: return '8';
                    case 9: return '9';
                    default:
                         return '0';

               }
          }
int pos=0;
int k=5;
int spend=0;
   char timespent[5];
    int fullTime = 0;
int n=0;
    bool starti = 0;
    bool textOut1 = 0;
int spend1=0;
int spend2=0;
    bool print=0;
    bool textOut2=0;
    int del=0;
    bool gg=true;
    bool gg1 =true;
    bool gg2=true;
    int kol=0;
POINT pt;

/*  Make the class name into a global variable  */
TCHAR szClassName[ ] = _T("GDI_Lab");

int WINAPI WinMain (HINSTANCE hThisInstance,
                     HINSTANCE hPrevInstance,
                     LPSTR lpszArgument,
                     int nCmdShow)
{
    HWND hwnd;               /* This is the handle for our window */
    MSG messages;            /* Here messages to the application are saved */
    WNDCLASSEX wincl;        /* Data structure for the windowclass */

    /* The Window structure */
    wincl.hInstance = hThisInstance;
    wincl.lpszClassName = szClassName;
    wincl.lpfnWndProc = WindowProcedure;      /* This function is called by windows */
    wincl.style = CS_DBLCLKS | CS_HREDRAW | CS_VREDRAW;                 /* Catch double-clicks */
    wincl.cbSize = sizeof (WNDCLASSEX);

    /* Use default icon and mouse-pointer */
    wincl.hIcon = LoadIcon (NULL, IDI_APPLICATION);
    wincl.hIconSm = LoadIcon (NULL, IDI_APPLICATION);
    wincl.hCursor = LoadCursor (NULL, IDC_ARROW);
    wincl.lpszMenuName = NULL;                 /* No menu */
    wincl.cbClsExtra = 0;                      /* No extra bytes after the window class */
    wincl.cbWndExtra = 0;                      /* structure or the window instance */
    /* Use Windows's default colour as the background of the window */
    wincl.hbrBackground = (HBRUSH) COLOR_BACKGROUND;

    /* Register the window class, and if it fails quit the program */
    if (!RegisterClassEx (&wincl))
        return 0;

    /* The class is registered, let's create the program*/
    hwnd = CreateWindowEx (
           0,                   /* Extended possibilites for variation */
           szClassName,         /* Classname */
           _T("GDI_Lab"),       /* Title Text */
           WS_OVERLAPPEDWINDOW, /* default window */
           CW_USEDEFAULT,       /* Windows decides the position */
           CW_USEDEFAULT,       /* where the window ends up on the screen */
           CW_USEDEFAULT,                 /* The programs width */
           CW_USEDEFAULT,                 /* and height in pixels */
           HWND_DESKTOP,        /* The window is a child-window to desktop */
           NULL,                /* No menu */
           hThisInstance,       /* Program Instance handler */
           NULL                 /* No Window Creation data */
           );
    while(!SetTimer(hwnd,ID_TIMER,20,NULL))
        if(IDCANCEL ==MessageBox(hwnd,"Too many clocks or timers",szClassName,MB_ICONEXCLAMATION|MB_RETRYCANCEL))
        return FALSE;

    /* Make the window visible on the screen */
    ShowWindow (hwnd, nCmdShow);
    UpdateWindow(hwnd);
    /* Run the message loop. It will run until GetMessage() returns 0 */
    while (GetMessage (&messages, NULL, 0, 0))
    {
        /* Translate virtual-key messages into character messages */
        TranslateMessage(&messages);
        /* Send message to WindowProcedure */
        DispatchMessage(&messages);
    }

    /* The program return-value is 0 - The value that PostQuitMessage() gave */
    return messages.wParam;
}


/*  This function is called by the Windows function DispatchMessage()  */


LRESULT CALLBACK WindowProcedure (HWND hwnd, UINT message, WPARAM wParam, LPARAM lParam)
{

    switch (message)                  /* handle the messages */
    {
        HDC hdc;
        PAINTSTRUCT ps;
        RECT rect;
        HBRUSH hBrush;
        HPEN hPen;
        hBrush=CreateSolidBrush(RGB(0,0,255));
        case WM_CREATE:

            break;
        case WM_TIMER:
                InvalidateRect(hwnd,NULL,TRUE);
                if((elapsedMilliseconds() >= 2000)&& gg){
                    print=1;
                    start();
                    gg=false;
                }
                return 0;
        case WM_KEYDOWN:
            switch (wParam)
            {
                case VK_SPACE:
                    start();
                    pt.x=1000;
                    pt.y=700;
                    ScreenToClient(hwnd, &pt);
                    SetCursorPos(pt.x,pt.y);

                    break;

                default:
                    break;
            }
            break;
        case WM_KEYUP:
            switch(wParam)
            {
                case VK_F2:

                    break;
                case VK_F1:
                    start();
                    stop();
                    print=false;
                    textOut1=false;
                    textOut2=false;
                    print=false;
                    gg=true;
                    gg1=true;
                    break;

                default:
                    break;

            }
            break;
        case WM_PAINT:
            {

            hdc=BeginPaint(hwnd,&ps);
            GetClientRect(hwnd,&rect);
            SetTextColor(hdc,RGB(0,0,255));
            SetBkMode(hdc,TRANSPARENT);
            hBrush=CreateSolidBrush(RGB(190,190,190));
            SelectObject(hdc,hBrush);


            hBrush=CreateSolidBrush(RGB(255,0,0));
                    SelectObject(hdc,hBrush);
            if(print){
                    Ellipse(hdc,100,70,150,120);



                    if (textOut1)
                    {
                        timespent[0]=conv((spend1/10000)%10);
                        timespent[1]=conv((spend1/1000)%10);
                        timespent[2]=conv((spend1/100)%10);
                        timespent[3]=conv((spend1/10)%10);
                        timespent[4]=conv(spend1%10);
                        TextOut(hdc,500,100,timespent,10);
                    }
                    if (textOut2)
                    {
                        timespent[0]=conv((spend2/10000)%10);
                        timespent[1]=conv((spend2/1000)%10);
                        timespent[2]=conv((spend2/100)%10);
                        timespent[3]=conv((spend2/10)%10);
                        timespent[4]=conv(spend2%10);
                        TextOut(hdc,500,300,timespent,10);
                    }

            }
                EndPaint(hwnd, &ps);
                DeleteObject(hBrush);
                DeleteObject(hPen);
                ReleaseDC(hwnd,hdc);
            }
            break;

        case WM_DESTROY:

        PostQuitMessage (0);       /* send a WM_QUIT to the message queue */
            break;
        default:                      /* for messages that we don't deal with */
            return DefWindowProc (hwnd, message, wParam, lParam);
    }

    return 0;
}








