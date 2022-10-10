#include "ats.h"
#include <string.h>

BOOL APIENTRY DllMain(
	HMODULE hModule,
	DWORD  ul_reason_for_call,
	LPVOID lpReserved
)
{
	switch (ul_reason_for_call)
	{
	case DLL_PROCESS_ATTACH:
	case DLL_THREAD_ATTACH:
	case DLL_THREAD_DETACH:
	case DLL_PROCESS_DETACH:
		break;
	}
	return TRUE;
}

DE void SC Load() {
}

DE void SC Dispose() {
}

DE int SC GetPluginVersion() {
	return PI_VERSION;
}

DE void SC SetVehicleSpec(Spec s)
{
}

DE void SC Initialize(int b) {
}

bool IsConstSpeedModeEnabling = false;
bool IsConstSpeedModeDisabling = false;
bool IsConstSpeedModeEnabled = false;
bool IsHoldingSpeedModeEnabled = false;

const int PANEL_HOLD_BRAKE_MODE_AIR_ENABLED = 207;
const int PANEL_HOLD_BRAKE_MODE_EC_ENABLED = 36;

DE Hand SC Elapse(State S, int * p, int * s)
{
	if (S.V < 15 || handle.P != 3)
	{
		IsConstSpeedModeDisabling = IsConstSpeedModeEnabled;
		IsConstSpeedModeEnabling = false;
		IsConstSpeedModeEnabled = false;
	}

	if (S.V < 15 || handle.P != -1)
	{
		IsHoldingSpeedModeEnabled = false;
	}

	if (IsConstSpeedModeEnabling)
	{
		handle.C = ConstSPInfo::Enable;
		IsConstSpeedModeEnabled = true;
		IsConstSpeedModeEnabling = false;
	}
	else if (IsConstSpeedModeDisabling)
	{
		handle.C = ConstSPInfo::Disable;
		IsConstSpeedModeDisabling = false;
	}
	else
	{
		handle.C = ConstSPInfo::Continue;
	}

	Hand _hand = handle;

	if (IsHoldingSpeedModeEnabled) {
		_hand.B = 1;
		p[PANEL_HOLD_BRAKE_MODE_EC_ENABLED] = 1;
	}
	else
	{
		p[PANEL_HOLD_BRAKE_MODE_EC_ENABLED] = 0;
	}

	if (S.V < 15 && handle.P < 0 && S.I == 0)
	{
		_hand.B = -handle.P + 1;
		p[PANEL_HOLD_BRAKE_MODE_AIR_ENABLED] = 1;
	}
	else
	{
		p[PANEL_HOLD_BRAKE_MODE_AIR_ENABLED] = 0;
	}

	if (handle.B > 0)
		_hand.B = handle.B = 1;

	return _hand;
}

DE void SC SetPower(int p) {
	if (handle.P >= 4 && p == 3)
	{
		IsConstSpeedModeDisabling = false;
		IsConstSpeedModeEnabling = true;
		IsConstSpeedModeEnabled = false;
	}

	if (handle.P == -2 && p == -1)
		IsHoldingSpeedModeEnabled = true;

	handle.P = p;
}

DE void SC SetBrake(int b) {
	handle.B = b;
}

DE void SC SetReverser(int r) {
	handle.R = r;
}

DE void SC DoorOpen() {
}

DE void SC DoorClose() {
}


DE void SC KeyDown(int k) {
}

DE void SC KeyUp(int k) {
}

DE void SC HornBlow(int k) {

}

DE void SC SetSignal(int a) {
}

DE void SC SetBeaconData(Beacon b) {
}
