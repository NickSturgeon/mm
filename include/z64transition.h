#ifndef Z64_TRANSITION_H
#define Z64_TRANSITION_H

#include "ultra64.h"

#include "overlays/fbdemos/ovl_fbdemo_triforce/z_fbdemo_triforce.h"
#include "overlays/fbdemos/ovl_fbdemo_wipe1/z_fbdemo_wipe1.h"
#include "overlays/fbdemos/ovl_fbdemo_wipe3/z_fbdemo_wipe3.h"
#include "overlays/fbdemos/ovl_fbdemo_wipe4/z_fbdemo_wipe4.h"
#include "overlays/fbdemos/ovl_fbdemo_wipe5/z_fbdemo_wipe5.h"

#define TC_SET_PARAMS (1 << 7)

typedef struct {
    /* 0x00 */ void* (*init)(void* transition);
    /* 0x04 */ void  (*destroy)(void* transition);
    /* 0x08 */ void  (*update)(void* transition, s32 updateRate);
    /* 0x0C */ void  (*draw)(void* transition, Gfx** gfxP);
    /* 0x10 */ void  (*start)(void* transition);
    /* 0x14 */ void  (*setType)(void* transition, s32 type);
    /* 0x18 */ void  (*setColor)(void* transition, u32 color);
    /* 0x1C */ void  (*setEnvColor)(void* transition, u32 color);
    /* 0x20 */ s32   (*isDone)(void* transition);
} TransitionInit; // size = 0x24

typedef struct {
    union {
        struct {
    /* 0x00 */ u32 count : 8;
    /* 0x00 */ uintptr_t addr : 24;
        };
    /* 0x00 */ u32 word;
    } loadInfo;
    /* 0x04 */ void* vramStart;
    /* 0x08 */ void* vramEnd;
    /* 0x0C */ uintptr_t vromStart;
    /* 0x10 */ uintptr_t vromEnd;
    /* 0x14 */ TransitionInit* initInfo;
    /* 0x18 */ size_t size;
} TransitionOverlay;

typedef struct {
    /* 0x0 */ char unk_0[0xC];
} TransitionFade; // size = 0xC

typedef enum {
 /* 0 */ TRANSITION_CIRCLE_IN,
 /* 1 */ TRANSITION_CIRCLE_OUT,
} TransitionCircleDirection;

#define FBDEMO_CIRCLE_GET_MASK_TYPE(type) (type & 1)

typedef struct {
    /* 0x00 */ Color_RGBA8_u32 color;
    /* 0x04 */ f32 referenceRadius; // Reference for where to transition to
    /* 0x08 */ f32 stepValue; // How fast the Transition is 
    /* 0x0C */ f32 startingRadius; // Radius value where transition will begin
    /* 0x10 */ f32 targetRadius; // Final radius of transition circle
    /* 0x14 */ u8 direction; // Direction the circle is transitioning ( In / Out )
    /* 0x15 */ u8 maskType; // Positive / Negative mask type. Value of 0 will create a black circle
    /* 0x16 */ u8 isDone; // Signals when Transition is done updating
    /* 0x18 */ TexturePtr texture;
    /* 0x1C */ u8 masks;
    /* 0x1D */ u8 maskt;
    /* 0x1E */ s8 unk_1E; // Set to 4 and never used
    /* 0x1F */ s8 unk_1F; // Set to 0 and never used
} TransitionCircle; // size = 0x20

#define TRANS_TRIGGER_OFF 0 // transition is not active
#define TRANS_TRIGGER_START 20 // start transition (exiting an area)
#define TRANS_TRIGGER_END -20 // transition is ending (arriving in a new area)

typedef enum {
    /*  0 */ TRANS_MODE_OFF,
    /*  1 */ TRANS_MODE_SETUP,
    /*  2 */ TRANS_MODE_INSTANCE_INIT,
    /*  3 */ TRANS_MODE_INSTANCE_RUNNING,
    /*  4 */ TRANS_MODE_FILL_WHITE_INIT,
    /*  5 */ TRANS_MODE_FILL_IN,
    /*  6 */ TRANS_MODE_FILL_OUT,
    /*  7 */ TRANS_MODE_FILL_BROWN_INIT,
    /*  8 */ TRANS_MODE_08, // unused
    /*  9 */ TRANS_MODE_09, // unused
    /* 10 */ TRANS_MODE_INSTANT,
    /* 11 */ TRANS_MODE_INSTANCE_WAIT,
    /* 12 */ TRANS_MODE_SANDSTORM_INIT,
    /* 13 */ TRANS_MODE_SANDSTORM,
    /* 14 */ TRANS_MODE_SANDSTORM_END_INIT,
    /* 15 */ TRANS_MODE_SANDSTORM_END,
    /* 16 */ TRANS_MODE_CS_BLACK_FILL_INIT,
    /* 17 */ TRANS_MODE_CS_BLACK_FILL
} TransitionMode;

#define TRANS_TYPE_WIPE4 (1 << 5)
#define TRANS_TYPE_WIPE3 (1 << 6)
#define TRANS_TYPE_SET_PARAMS (1 << 7)

typedef enum {
    /*  0 */ TRANS_TYPE_WIPE,
    /*  1 */ TRANS_TYPE_TRIFORCE,
    /*  2 */ TRANS_TYPE_FADE_BLACK,
    /*  3 */ TRANS_TYPE_FADE_WHITE,
    /*  4 */ TRANS_TYPE_FADE_BLACK_FAST,
    /*  5 */ TRANS_TYPE_FADE_WHITE_FAST,
    /*  6 */ TRANS_TYPE_FADE_BLACK_SLOW,
    /*  7 */ TRANS_TYPE_FADE_WHITE_SLOW,
    /*  8 */ TRANS_TYPE_WIPE_FAST,
    /*  9 */ TRANS_TYPE_FILL_WHITE_FAST, // Not actually fast due to bug in Play_UpdateTransition
    /* 10 */ TRANS_TYPE_FILL_WHITE,
    /* 11 */ TRANS_TYPE_INSTANT,
    /* 12 */ TRANS_TYPE_FILL_BROWN,
    /* 13 */ TRANS_TYPE_FADE_WHITE_CS_DELAYED,
    /* 14 */ TRANS_TYPE_SANDSTORM_PERSIST,
    /* 15 */ TRANS_TYPE_SANDSTORM_END,
    /* 16 */ TRANS_TYPE_CS_BLACK_FILL,
    /* 17 */ TRANS_TYPE_FADE_WHITE_INSTANT,
    /* 18 */ TRANS_TYPE_FADE_GREEN,
    /* 19 */ TRANS_TYPE_FADE_BLUE,
    /* 20 */ TRANS_TYPE_FADE_DYNAMIC, // Chooses Black or White based on time of day
    /* 21 */ TRANS_TYPE_CIRCLE,
    /* 22 */ TRANS_TYPE_WIPE5,
    // transition types 23 - 31 are unused
    // transition types 32 - 39 are Wipe4 TODO needs macro
    // transition types 40 - 63 are unused
    // transition types 64 - 127 are Wipe3 TODO needs macro
    /* 64 */ TRANS_TYPE_64 = 64,
    /* 70 */ TRANS_TYPE_70 = 70,
    /* 72 */ TRANS_TYPE_72 = 72,
    /* 73 */ TRANS_TYPE_73,
    /* 80 */ TRANS_TYPE_80 = 80,
    /* 86 */ TRANS_TYPE_86 = 86
} TransitionType;

typedef enum {
    /* 0 */ FBDEMO_FADE,
    /* 1 */ FBDEMO_TRIFORCE,
    /* 2 */ FBDEMO_WIPE1,
    /* 3 */ FBDEMO_WIPE3,
    /* 4 */ FBDEMO_WIPE4,
    /* 5 */ FBDEMO_CIRCLE,
    /* 6 */ FBDEMO_WIPE5
} FbDemoType;

#define TRANS_NEXT_TYPE_DEFAULT 0xFF

typedef struct {
    /* 0x000 */ s16 transitionType;
    /* 0x002 */ s8 fbdemoType;
    /* 0x003 */ char unk_003[0x5];
    /* 0x008 */ union {
        TransitionFade fade;
        TransitionCircle circle;
        TransitionTriforce triforce;
        TransitionWipe1 wipe1;
        TransitionWipe3 wipe3;
        TransitionWipe4 wipe4;
        TransitionWipe5 wipe5;
    } instanceData;
    /* 0x220 */ char unk_220[0x10];
    /* 0x230 */ void* (*init)(void* transition);
    /* 0x234 */ void  (*destroy)(void* transition);
    /* 0x238 */ void  (*update)(void* transition, s32 updateRate);
    /* 0x23C */ void  (*draw)(void* transition, Gfx** gfxP);
    /* 0x240 */ void  (*start)(void* transition);
    /* 0x244 */ void  (*setType)(void* transition, s32 type);
    /* 0x248 */ void  (*setColor)(void* transition, u32 color);
    /* 0x24C */ void  (*setEnvColor)(void* transition, u32 color);
    /* 0x250 */ s32   (*isDone)(void* transition);
    /* 0x254 */ char unk_254[0x4];
} TransitionContext; // size = 0x258

#endif
