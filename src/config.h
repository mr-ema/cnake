#ifndef CNAKE_CONFIG_H
#define CNAKE_CONFIG_H

#include "types.h"

// Configurations
#define SCREEN_WIDTH (u32)1280
#define SCREEN_HEIGHT (u32)620
#define OFFSET_X (f32)500
#define OFFSET_Y (f32)300
#define TARGET_FPS 60
#define TILE_SIZE (u8)10
#define TILE_SCALE_DELTA (u8)2 /* Scale grid objects size */
#define FRAME_UPDATE_INTERVAL (u8)5

// Default controls
#define DEFAULT_KEY_MOVE_UP     KEY_K
#define DEFAULT_KEY_MOVE_DOWN   KEY_J
#define DEFAULT_KEY_MOVE_LEFT   KEY_H
#define DEFAULT_KEY_MOVE_RIGHT  KEY_L
#define DEFAULT_KEY_PAUSE_GAME  KEY_ESCAPE
#define DEFAULT_KEY_GOBACK      KEY_ESCAPE

// Colors
#define SCREEN_BACKGROUND       (Color){ 0, 0, 0, 255 }
#define GRID_COLOR              (Color){ 50, 50, 50, 255 }
#define GRID_BORDER_COLOR       (Color){ 0, 150, 0, 255 }
#define HEAD_COLOR              (Color){ 0, 150, 0, 255 }
#define BODY_COLOR              (Color){ 0, 100, 0, 255 }
#define FRUIT_COLOR             (Color){ 150, 0, 0, 255 }

#endif
