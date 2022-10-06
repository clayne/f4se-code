// F4SE
#include "common/IDebugLog.h"  // IDebugLog
#include <f4se/PluginAPI.h>

#include <shlobj.h>	// CSIDL_MYCODUMENTS

// User Defined Header
#include "Global.h"

PluginHandle			g_pluginHandle = kPluginHandle_Invalid;
F4SEMessagingInterface* g_messaging = NULL;

bool logEnabled = true;
bool eventLogEnabled = true;


void OnF4SEMessage(F4SEMessagingInterface::Message* msg) {
	switch (msg->type) {
	case F4SEMessagingInterface::kMessage_GameLoaded:
		if (!Install()) {
			log("Couldn't install hooks");
		}
		break;
	case F4SEMessagingInterface::kMessage_GameDataReady:
	case F4SEMessagingInterface::kMessage_NewGame:
	case F4SEMessagingInterface::kMessage_PostLoadGame:
		break;
	}
}

/* Plugin Query */
extern "C" {
	bool F4SEPlugin_Query(const F4SEInterface* f4se, PluginInfo* info) {
		std::string logPath{ "\\My Games\\Fallout4\\F4SE\\" PLUGIN_NAME ".log" };
		gLog.OpenRelative(CSIDL_MYDOCUMENTS, logPath.c_str());
		gLog.SetPrintLevel(IDebugLog::kLevel_Error);
		gLog.SetLogLevel(IDebugLog::kLevel_DebugMessage);
		_MESSAGE("%s %s Query", prefixLog().c_str(), PLUGIN_NAME);

		info->infoVersion = PluginInfo::kInfoVersion;
		info->name = PLUGIN_NAME;
		info->version = PLUGIN_VERSION;

		if (f4se->runtimeVersion != RUNTIME_VERSION_1_10_163) {
			_MESSAGE("%s Unsupported runtime version %d", prefixLog().c_str(), f4se->runtimeVersion);
			//return false;
		}

		g_pluginHandle = f4se->GetPluginHandle();

		// Get the messaging interface
		g_messaging = (F4SEMessagingInterface*)f4se->QueryInterface(kInterface_Messaging);
		if (!g_messaging) {
			log("Couldn't get messaging interface");
			return false;
		}
		return true;
	}

	bool F4SEPlugin_Load(const F4SEInterface* f4se) {
		_MESSAGE("%s %s Loaded", prefixLog().c_str(), PLUGIN_NAME);

		if (g_messaging)	{
			log("Registered Listener");
			g_messaging->RegisterListener(g_pluginHandle, "F4SE", OnF4SEMessage);
		}
		return true;
	}
}