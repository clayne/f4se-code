#pragma once
#include "RE/Bethesda/BSResource/BSResourceID.h"
#include "RE/Bethesda/BSShader/BSShaderData.h"
#include "RE/Bethesda/BSTextureSet.h"
#include "RE/Bethesda/FormComponents.h"
#include "RE/Bethesda/BSCore/MemoryManager.h"
#include "RE/Bethesda/TESBoundObjects.h"

namespace RE
{
	class DecalData;

	class __declspec(novtable) BGSTextureSet :
		public TESBoundObject,  // 000
		public BSTextureSet     // 068
	{
	public:
		static constexpr auto RTTI{ RTTI::BGSTextureSet };
		static constexpr auto VTABLE{ VTABLE::BGSTextureSet };
		static constexpr auto FORM_ID{ ENUM_FORM_ID::kTXST };

		F4_HEAP_REDEFINE_NEW(BGSTextureSet);

		// members
		BSFixedString materialName;        // 078
		TESTexture textures[8];            // 080
		DecalData* decalData;              // 100
		std::uint16_t flags;               // 108
		BSResource::ID textureFileIDs[8];  // 10C
		BSShaderData materialData;         // 170
	};
	static_assert(sizeof(BGSTextureSet) == 0x350);
}
