#pragma once

class FrameClock
{
  private:
    static float lastFrame;
    static float deltaTime;

  public:
    static void updateDeltaTime();
    static float getDeltaTime();
};
