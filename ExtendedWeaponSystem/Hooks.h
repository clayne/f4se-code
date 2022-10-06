#pragma once

BSTEventDispatcher<void*>* GetGlobalEventDispatcher(BSTGlobalEvent* globalEvents, const char* dispatcherName);


struct CustomThirdPersonState {
public:
	UInt32	unk00[0x0EC >> 2];
	float	currentZoomOffset;
};

struct WeaponData {
	TESForm* item;					// 00
	TBO_InstanceData* instanceData;	// 08
};

class BSAnimationGraphEvent {
public:
	TESObjectREFR*	refr;
	BSFixedString	name;
	BSFixedString	args;
};

struct TESEquipEvent {
	TESObjectREFR*					owner;			// 00
	UInt32							FormID;			// 08
	char							padding[9];
	bool							isEquipping;
	char							padding2[111];

	BGSInventoryItem::Stack*		invItem;
	char							padding3[15];
	TESObject*						item;
	TESObjectWEAP::InstanceData*	instanceData;
};
STATIC_ASSERT(offsetof(TESEquipEvent, instanceData) == 0xa8);
STATIC_ASSERT(offsetof(TESEquipEvent, invItem) == 0x88);

DECLARE_EVENT_DISPATCHER(TESEquipEvent, 0x00442870);

class TESEquipEventSink : public BSTEventSink<TESEquipEvent> {
protected:
	virtual ~TESEquipEventSink() {};
	virtual EventResult ReceiveEvent(TESEquipEvent* evn, void* dispatcher) override;
};

struct PlayerAmmoCountEvent {
	UInt32							ammoCount;			// 00
	UInt32							totalAmmoCount;		// 04
	UInt64							unk08;				// 08
	TESObjectWEAP*					weapon;				// 10
	TESObjectWEAP::InstanceData*	weaponInstance;		//
														//...
};
STATIC_ASSERT(offsetof(PlayerAmmoCountEvent, weapon) == 0x10);

class PlayerAmmoCountEventSink : public BSTEventSink<PlayerAmmoCountEvent> {
public:
	virtual ~PlayerAmmoCountEventSink() {};
	virtual EventResult ReceiveEvent(PlayerAmmoCountEvent* evn, void* dispatcher) override;
};

struct PlayerWeaponReloadEvent {

};

class PlayerWeaponReloadEventSink : public BSTEventSink<PlayerWeaponReloadEvent> {
public:
	virtual ~PlayerWeaponReloadEventSink() {};
	virtual EventResult ReceiveEvent(PlayerWeaponReloadEvent* evn, void* dispatcher) override;
};

struct PlayerSetWeaponStateEvent {

};

class PlayerSetWeaponStateEventSink : public BSTEventSink<PlayerSetWeaponStateEvent> {
public:
	virtual ~PlayerSetWeaponStateEventSink() { };
	virtual EventResult ReceiveEvent(PlayerSetWeaponStateEvent* evn, void* dispatcher) override;
};

class TESLoadGameHandler : public BSTEventSink<TESLoadGameEvent> {
public:
	virtual ~TESLoadGameHandler() { };
	virtual EventResult ReceiveEvent(TESLoadGameEvent* evn, void* dispatcher) override;
};

struct BGSOnPlayerUseWorkBenchEvent {

};
DECLARE_EVENT_DISPATCHER(BGSOnPlayerUseWorkBenchEvent, 0x00441970);

class BGSOnPlayerUseWorkBenchEventSink : public BSTEventSink<BGSOnPlayerUseWorkBenchEvent> {
public:
	virtual ~BGSOnPlayerUseWorkBenchEventSink() { };
	virtual EventResult ReceiveEvent(BGSOnPlayerUseWorkBenchEvent* evn, void* dispatcher) override;
};

typedef void(*_TogglePOV)(void* arg1, ButtonEvent* event);
typedef void(*_MovementHandler)(void*, ButtonEvent*);
typedef void(*_SprintHandler)(void*, ButtonEvent*);
typedef void(*_ReadyWeaponHandler)(void*, ButtonEvent*);
typedef std::uint32_t(*_PlayerUseAmmoEvent_ReceiveEvent)(Actor* actor, const WeaponData& a_weapon, std::uint32_t a_equipIndex, std::uint32_t a_shotCount);
typedef EventResult(*_PlayerAnimGraphEvent_ReceiveEvent)(void*, BSAnimationGraphEvent*, void*);
typedef EventResult(*_MenuOpenCloseEvent_ReceiveEvent)(void*, MenuOpenCloseEvent*, void*);

bool Install();
bool RegisterAfterLoadEvents();