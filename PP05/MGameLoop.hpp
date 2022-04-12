#pragma once
#include <chrono>
#include <thread>
#include "MConsolUtil.hpp"

using namespace std;

namespace MuSeoun_Engine
{
    class MGameLoop
    {
    private:
        bool _isGameRunning;
        MConsoleRenderer cRenderer;
        
        int tic = 0;
        double ticTime = 0;

    public:
        MGameLoop()
        {
            _isGameRunning = false;
        }
        ~MGameLoop()
        {

        }

        void Run()
        {
            _isGameRunning = true;
            Initialize();

            while (_isGameRunning)
            {
                Input();
                Update();
                Render();
            }
            Release();
        }
        void Stop()
        {
            _isGameRunning = false;
        }
    private:
        void Initialize()
        {

        }
        void Release()
        {

        }
        void Input()
        {
            /*if (GetAsyncKeyState(VK_SPACE) & 0x8000 || GetAsyncKeyState(VK_SPACE) & 0x8001)
            {

            }
            else
            {

            }*/
        }
        void Update()
        {

        }
        void Render()
        {
            if (ticTime >= 1.0f)
            {
                string fps = "FPS(seconds) : " + to_string(tic);
                cRenderer.DrawString(fps);
                ticTime = 0;
                tic = 0;
            }
            chrono::system_clock::time_point startRenderTimePoint = chrono::system_clock::now();
            
            cRenderer.Clear();                           //콘솔창 지우는거 << 생각보다 잡아먹는게 많다 이런 피셜
            cRenderer.MoveCursor(10, 10);
            //  0.03   1초  33프레임
            
            chrono::duration<double> renderDuration = chrono::system_clock::now() - startRenderTimePoint; //1틱 ex 0.03초
            tic++; //1틱

            ticTime = ticTime + renderDuration.count(); // 0.03초

                //cout << "FPS(second) : " + i;
            
                
            
              
        }
        ////cout << "Rendering speed : " << renderDuration.count() << "sec" << endl;
        //int remainingFrameTime = 100 - (int)(renderDuration.count() * 1000.0);
        //if (remainingFrameTime > 0)
        // this_thread::sleep_for(chrono::milliseconds(remainFrameTime));
    };
}
