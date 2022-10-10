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
	b = InitialPosition::Service;
}

DE Hand SC Elapse(State S, int * p, int * s)
{
	handle.C = ConstSPInfo::Continue;
	return handle;
}

DE void SC SetPower(int p) {
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
