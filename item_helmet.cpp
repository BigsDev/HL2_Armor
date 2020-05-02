//========= Copyright Valve Corporation, All rights reserved. ============//
//
// --Create By: Bigs--
//
// $NoKeywords: $
//=============================================================================//

#include "cbase.h"
#include "hl2_player.h"
#include "basecombatweapon.h"
#include "gamerules.h"
#include "items.h"
#include "engine/IEngineSound.h"

// memdbgon must be the last include file in a .cpp file!!!
#include "tier0/memdbgon.h"

class CItemHelmet : public CItem
{
public:
	DECLARE_CLASS(CItemHelmet, CItem);

	void Spawn(void)
	{
		Precache();
		SetModel("models/items/car_battery01.mdl");
		BaseClass::Spawn();
	}
	void Precache(void)
	{
		PrecacheModel("models/items/car_battery01.mdl");

		PrecacheScriptSound("ItemBattery.Touch");

	}
	bool MyTouch(CBasePlayer *pPlayer)
	{
		CHL2_Player *pHL2Player = dynamic_cast<CHL2_Player *>(pPlayer);
			return (pHL2Player && pHL2Player->ApplyHelmet());
	}
};

LINK_ENTITY_TO_CLASS(item_helmet, CItemHelmet);
PRECACHE_REGISTER(item_helmet);

