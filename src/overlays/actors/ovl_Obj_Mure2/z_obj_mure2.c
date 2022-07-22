/*
 * File: z_obj_mure2.c
 * Overlay: ovl_Obj_Mure2
 * Description: Circle of rocks spawner
 */

#include "z_obj_mure2.h"

#define FLAGS 0x00000000

#define THIS ((ObjMure2*)thisx)

void ObjMure2_Init(Actor* thisx, PlayState* play);
void ObjMure2_Update(Actor* thisx, PlayState* play);

void func_809613C4(ObjMure2* this, PlayState* play);
void func_809613FC(ObjMure2* this, PlayState* play);
void func_80961490(ObjMure2* this, PlayState* play);

void func_809613B0(ObjMure2*);

#if 0
const ActorInit Obj_Mure2_InitVars = {
    ACTOR_OBJ_MURE2,
    ACTORCAT_PROP,
    FLAGS,
    GAMEPLAY_KEEP,
    sizeof(ObjMure2),
    (ActorFunc)ObjMure2_Init,
    (ActorFunc)Actor_Noop,
    (ActorFunc)ObjMure2_Update,
    (ActorFunc)NULL,
};

// static InitChainEntry sInitChain[] = {
static InitChainEntry D_809615F4[] = {
    ICHAIN_F32(uncullZoneForward, 100, ICHAIN_CONTINUE),
    ICHAIN_F32(uncullZoneScale, 2100, ICHAIN_CONTINUE),
    ICHAIN_F32(uncullZoneDownward, 100, ICHAIN_STOP),
};

#endif

extern InitChainEntry D_809615F4[];

#pragma GLOBAL_ASM("asm/non_matchings/overlays/ovl_Obj_Mure2/func_80960CF0.s")

#pragma GLOBAL_ASM("asm/non_matchings/overlays/ovl_Obj_Mure2/func_80960E0C.s")

#pragma GLOBAL_ASM("asm/non_matchings/overlays/ovl_Obj_Mure2/func_80960F0C.s")

#pragma GLOBAL_ASM("asm/non_matchings/overlays/ovl_Obj_Mure2/func_80961018.s")

#pragma GLOBAL_ASM("asm/non_matchings/overlays/ovl_Obj_Mure2/func_8096104C.s")

#pragma GLOBAL_ASM("asm/non_matchings/overlays/ovl_Obj_Mure2/func_809611BC.s")

#pragma GLOBAL_ASM("asm/non_matchings/overlays/ovl_Obj_Mure2/func_809612BC.s")

void ObjMure2_Init(Actor* thisx, PlayState* play) {
    ObjMure2* this = THIS;

    Actor_ProcessInitChain(&this->actor, D_809615F4);
    if (play->csCtx.state != 0) {
        this->actor.uncullZoneForward += 1200.0f;
    }

    func_809613B0(this);
}

void func_809613B0(ObjMure2 *arg0) {
    arg0->actionFunc = func_809613C4;
}

#pragma GLOBAL_ASM("asm/non_matchings/overlays/ovl_Obj_Mure2/func_809613C4.s")

#pragma GLOBAL_ASM("asm/non_matchings/overlays/ovl_Obj_Mure2/func_809613E8.s")

#pragma GLOBAL_ASM("asm/non_matchings/overlays/ovl_Obj_Mure2/func_809613FC.s")

#pragma GLOBAL_ASM("asm/non_matchings/overlays/ovl_Obj_Mure2/func_8096147C.s")

#pragma GLOBAL_ASM("asm/non_matchings/overlays/ovl_Obj_Mure2/func_80961490.s")

#pragma GLOBAL_ASM("asm/non_matchings/overlays/ovl_Obj_Mure2/ObjMure2_Update.s")
