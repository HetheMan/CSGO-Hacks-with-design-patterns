#ifndef offsets_H
#define offsets_H
#include <windows.h>
#include <cstddef>
namespace netvars {
	extern DWORD m_ArmorValue;
	extern DWORD m_Collision;
	extern DWORD m_CollisionGroup;
	extern DWORD m_Local;
	extern DWORD m_MoveType;
	extern DWORD m_OriginalOwnerXuidHigh;
	extern DWORD m_OriginalOwnerXuidLow;
	extern DWORD m_aimPunchAngle;
	extern DWORD m_aimPunchAngleVel;
	extern DWORD m_bGunGameImmunity;
	extern DWORD m_bHasDefuser;
	extern DWORD m_bHasHelmet;
	extern DWORD m_bInReload;
	extern DWORD m_bIsDefusing;
	extern DWORD m_bIsScoped;
	extern DWORD m_bSpotted;
	extern DWORD m_bSpottedByMask;
	extern DWORD m_clrRender;
	extern DWORD m_dwBoneMatrix;
	extern DWORD m_fAccuracyPenalty;
	extern DWORD m_fFlags;
	extern DWORD m_flFallbackWear;
	extern DWORD m_flFlashDuration;
	extern DWORD m_flFlashMaxAlpha;
	extern DWORD m_flNextPrimaryAttack;
	extern DWORD m_hActiveWeapon;
	extern DWORD m_hMyWeapons;
	extern DWORD m_hObserverTarget;
	extern DWORD m_hOwner;
	extern DWORD m_hOwnerEntity;
	extern DWORD m_iAccountID;
	extern DWORD m_iClip1;
	extern DWORD m_iCompetitiveRanking;
	extern DWORD m_iCompetitiveWins;
	extern DWORD m_iCrosshairId;
	extern DWORD m_iEntityQuality;
	extern DWORD m_iFOVStart;
	extern DWORD m_iGlowIndex;
	extern DWORD m_iHealth;
	extern DWORD m_iItemDefinitionIndex;
	extern DWORD m_iItemIDHigh;
	extern DWORD m_iObserverMode;
	extern DWORD m_iShotsFired;
	extern DWORD m_iState;
	extern DWORD m_iTeamNum;
	extern DWORD m_lifeState;
	extern DWORD m_nFallbackPaintKit;
	extern DWORD m_nFallbackSeed;
	extern DWORD m_nFallbackStatTrak;
	extern DWORD m_nForceBone;
	extern DWORD m_nTickBase;
	extern DWORD m_rgflCoordinateFrame;
	extern DWORD m_szCustomName;
	extern DWORD m_szLastPlaceName;
	extern DWORD m_thirdPersonViewAngles;
	extern DWORD m_vecOrigin;
	extern DWORD m_vecVelocity;
	extern DWORD m_vecViewOffset;
	extern DWORD m_viewPunchAngle;
} // namespace netvars
namespace signatures {
	extern DWORD dwClientState;
	extern DWORD dwClientState_GetLocalPlayer;
	extern DWORD dwClientState_IsHLTV;
	extern DWORD dwClientState_Map;
	extern DWORD dwClientState_MapDirectory;
	extern DWORD dwClientState_MaxPlayer;
	extern DWORD dwClientState_PlayerInfo;
	extern DWORD dwClientState_State;
	extern DWORD dwClientState_ViewAngles;
	extern DWORD dwEntityList;
	extern DWORD dwForceAttack;
	extern DWORD dwForceAttack2;
	extern DWORD dwForceBackward;
	extern DWORD dwForceForward;
	extern DWORD dwForceJump;
	extern DWORD dwForceLeft;
	extern DWORD dwForceRight;
	extern DWORD dwGameDir;
	extern DWORD dwGameRulesProxy;
	extern DWORD dwGetAllClasses;
	extern DWORD dwGlobalVars;
	extern DWORD dwGlowObjectManager;
	extern DWORD dwInput;
	extern DWORD dwInterfaceLinkList;
	extern DWORD dwLocalPlayer;
	extern DWORD dwMouseEnable;
	extern DWORD dwMouseEnablePtr;
	extern DWORD dwPlayerResource;
	extern DWORD dwRadarBase;
	extern DWORD dwSensitivity;
	extern DWORD dwSensitivityPtr;
	extern DWORD dwSetClanTag;
	extern DWORD dwViewMatrix;
	extern DWORD dwWeaponTable;
	extern DWORD dwWeaponTableIndex;
	extern DWORD dwYawPtr;
	extern DWORD dwZoomSensitivityRatioPtr;
	extern DWORD dwbSendPackets;
	extern DWORD dwppDirect3DDevice9;
	extern DWORD m_pStudioHdr;
} // namespace signatures

#endif