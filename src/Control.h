#pragma once
#include "Keys.h"
#include "Binding.h"
#include "GameLogic.h"
#include "InterfaceLogic.h"

class Control
{
public:
  Control();
  ~Control();

  void keyDown(Key key);
  void keyUp(Key key);
  void mouseMove(float x, float y);
  void mouseDown(Key key);
  void mouseUp(Key key);
  void mouseScroll(float dx, float dy);
  void update();

private:
  struct KeyState
  {
    bool isPressed;
    bool wasChanged;
    int pressCount;
    int repeatCount;
  };

  struct KeyInternalState
  {
    uint64_t keyNextRepeatCounter; 
    int pressCount;
    bool wasChanged;
  };

  const uint64_t freq;
  const uint64_t repeatDelay;
  const uint64_t repeatInterval;
  uint64_t currentCounter;
  KeyInternalState internalKeyStates[KEY_COUNT];
  float mouseX;
  float mouseY;
  bool mouseMoved;

  void updateGameControl();
  void updateMenuControl(MenuLogic & menu, const char * layoutName);
  void updateSettingsControl();
  void updateLeaderboardControl();
  void updateInternalState();
  KeyState getKeyState(Key key) const;
};
