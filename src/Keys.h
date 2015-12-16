#pragma once

enum Key
{
  KB_NONE = 0,

  /* Printable keys */
  KB_SPACE,
  KB_APOSTROPHE,
  KB_COMMA,
  KB_MINUS,
  KB_PERIOD,
  KB_SLASH,
  KB_0,
  KB_1,
  KB_2,
  KB_3,
  KB_4,
  KB_5,
  KB_6,
  KB_7,
  KB_8,
  KB_9,
  KB_SEMICOLON,
  KB_EQUAL,
  KB_A,
  KB_B,
  KB_C,
  KB_D,
  KB_E,
  KB_F,
  KB_G,
  KB_H,
  KB_I,
  KB_J,
  KB_K,
  KB_L,
  KB_M,
  KB_N,
  KB_O,
  KB_P,
  KB_Q,
  KB_R,
  KB_S,
  KB_T,
  KB_U,
  KB_V,
  KB_W,
  KB_X,
  KB_Y,
  KB_Z,
  KB_LEFT_BRACKET,
  KB_BACKSLASH,
  KB_RIGHT_BRACKET,
  KB_GRAVE_ACCENT,
  KB_WORLD_1,
  KB_WORLD_2,

  /* Function keys */
  KB_ESCAPE,
  KB_ENTER,
  KB_TAB,
  KB_BACKSPACE,
  KB_INSERT,
  KB_DELETE,
  KB_RIGHT,
  KB_LEFT,
  KB_DOWN,
  KB_UP,
  KB_PAGE_UP,
  KB_PAGE_DOWN,
  KB_HOME,
  KB_END,
  KB_CAPS_LOCK,
  KB_SCROLL_LOCK,
  KB_NUM_LOCK,
  KB_PRINT_SCREEN,
  KB_PAUSE,
  KB_F1,
  KB_F2,
  KB_F3,
  KB_F4,
  KB_F5,
  KB_F6,
  KB_F7,
  KB_F8,
  KB_F9,
  KB_F10,
  KB_F11,
  KB_F12,
  KB_F13,
  KB_F14,
  KB_F15,
  KB_F16,
  KB_F17,
  KB_F18,
  KB_F19,
  KB_F20,
  KB_F21,
  KB_F22,
  KB_F23,
  KB_F24,
  KB_F25,
  KB_KP_0,
  KB_KP_1,
  KB_KP_2,
  KB_KP_3,
  KB_KP_4,
  KB_KP_5,
  KB_KP_6,
  KB_KP_7,
  KB_KP_8,
  KB_KP_9,
  KB_KP_DECIMAL,
  KB_KP_DIVIDE,
  KB_KP_MULTIPLY,
  KB_KP_SUBTRACT,
  KB_KP_ADD,
  KB_KP_ENTER,
  KB_KP_EQUAL,
  KB_LEFT_SHIFT,
  KB_LEFT_CONTROL,
  KB_LEFT_ALT,
  KB_LEFT_SUPER,
  KB_RIGHT_SHIFT,
  KB_RIGHT_CONTROL,
  KB_RIGHT_ALT,
  KB_RIGHT_SUPER,
  KB_MENU,

  MOUSE_LEFT,
  MOUSE_RIGHT,
  MOUSE_MIDDLE,
  MOUSE_SCROLL_UP,
  MOUSE_SCROLL_DOWN,

  KEY_COUNT
};

inline Key operator++(Key & key)
{
  key = static_cast <Key>(key + 1);

  if (key > KEY_COUNT)
    key = KB_NONE;

  return key;
}

inline Key operator++(Key & key, int)
{
  Key k = key;
  key = static_cast <Key>(key + 1);

  if (key > KEY_COUNT)
    key = KB_NONE;

  return k;
}

class Keys
{
private:
  static const char * const names[KEY_COUNT];

  Keys();
  ~Keys();

public:
  static const char * getName(Key key) { return names[key]; }
};

