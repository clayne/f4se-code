#pragma once

#include "RE/Bethesda/BSTHashMap.h"
#include "RE/NetImmerse/NiMain/NiSmartPointer.h"
#include "RE/NetImmerse/NiMain/NiTArray.h"
#include "RE/NetImmerse/NiMain/NiTimeController.h"

namespace RE
{
	class BSAnimNote;
	class BSAnimNoteListener;
	class NiAVObjectPalette;
	class NiControllerSequence;
	class NiTextKeyExtraData;
	class NiStringPalette;

	class NiControllerManager :
		public NiTimeController  // 00
	{
	public:
		static constexpr auto RTTI{ RTTI::NiControllerManager };
		static constexpr auto VTABLE{ VTABLE::NiControllerManager };
		static constexpr auto Ni_RTTI{ Ni_RTTI::NiControllerManager };

		[[nodiscard]] static NiControllerManager* GetNiControllerManager(const NiObjectNET* a_object)
		{
			using func_t = decltype(&NiControllerManager::GetNiControllerManager);
			REL::Relocation<func_t> func{ REL::ID(1013515) };
			return func(a_object);
		}

		[[nodiscard]] NiControllerSequence* GetSequenceByName(const BSFixedString& a_name)
		{
			using func_t = decltype(&NiControllerManager::GetSequenceByName);
			REL::Relocation<func_t> func{ REL::ID(846648) };
			return func(this, a_name);
		}

		[[nodiscard]] NiControllerSequence* GetSequenceAt(std::uint16_t a_index)
		{
			if (a_index >= 0 && a_index < sequenceArray.size()) {
				return sequenceArray[a_index].get();
			}

			return nullptr;
		}

		[[nodiscard]] std::uint16_t GetSequenceCount() const noexcept
		{
			return sequenceArray.size();
		}

		// members
		NiTObjectArray<NiPointer<NiControllerSequence>> sequenceArray;  // 48
		std::byte activeSequences[0x70 - 0x60];                         // 60 - TODO
		BSTHashMap<BSFixedString, NiControllerSequence*> stringMap;     // 70
		BSAnimNoteListener* listener;                                   // A0
		bool cumulative;                                                // A8
		std::byte tempBlendSeqs[0xC0 - 0xB0];                           // B0 - TODO
		NiPointer<NiAVObjectPalette> objectPalette;                     // C0
	};
	static_assert(sizeof(NiControllerManager) == 0xC8);
}
