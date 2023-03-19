#pragma once
#include "RE/Bethesda/BSPortalGraph.h"
#include "RE/NetImmerse/NiMain/NiCullingProcess.h"
#include "RE/NetImmerse/NiMain/NiSmartPointer.h"
#include "RE/Bethesda/BSCore/BSTHashMap.h"

namespace RE
{
	class BSCompoundFrustum;
	class BSMultiBound;
	class BSOcclusionPlane;
	class NiAccumulator;
	class NiAVObject;
	class NiBound;
	class NiVisibleArray;

	class BSCullingProcess : public NiCullingProcess
	{
	public:
		static constexpr auto RTTI{ RTTI::BSCullingProcess };
		static constexpr auto VTABLE{ VTABLE::BSCullingProcess };

		enum BSCPCullingType
		{
			BSCP_CULL_NORMAL = 0x0,
			BSCP_CULL_ALLPASS = 0x1,
			BSCP_CULL_ALLFAIL = 0x2,
			BSCP_CULL_IGNOREMULTIBOUNDS = 0x3,
			BSCP_CULL_FORCEMULTIBOUNDSNOUPDATE = 0x4,
		};

		BSCullingProcess() = delete;
		BSCullingProcess(NiVisibleArray* a_array) :
			NiCullingProcess(0)
		{
			ctor(a_array);
		};

		//add
		virtual void AppendNonAccum([[maybe_unused]] NiAVObject& a_object) { return; }
		virtual bool TestBaseVisibility_BSMultiBound([[maybe_unused]] BSMultiBound& a_bound) { return false; }
		virtual bool TestBaseVisibility_BSOcclusionPlane([[maybe_unused]] BSOcclusionPlane& a_plane) { return false; }
		virtual bool TestBaseVisibility_NiBound([[maybe_unused]] NiBound& a_bound) { return false; }

		void SetAccumulator(NiAccumulator* accumulator) {
			using func_t = decltype(&BSCullingProcess::SetAccumulator);
			REL::Relocation<func_t> func{ REL::ID(236955) };
			return func(this, accumulator);
		}

		//members
		BSTHashMap<NiAVObject *,bool> kRoomSharedMap;
		BSPortalGraphEntry* pPortalGraphEntry;
		BSCPCullingType kCullMode;
		BSCPCullingType eTypeStackA[10];
		std::uint32_t iCTStackIndex;
		BSCompoundFrustum* pCompoundFrustum;
		NiPointer<NiAccumulator> spAccumulator;
		bool bRecurseToGeometry;

	private:
		BSCullingProcess* ctor(NiVisibleArray* a_array)
		{
			using func_t = decltype(&BSCullingProcess::ctor);
			REL::Relocation<func_t> func{ REL::ID(423200) };
			return func(this, a_array);
		};
	};
	static_assert(sizeof(BSCullingProcess) == 0x1A0);
}
