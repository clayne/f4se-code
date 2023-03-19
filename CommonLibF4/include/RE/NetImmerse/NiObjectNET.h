#pragma once

#include "RE/Bethesda/BSSystem/BSFixedString.h"
#include "RE/NetImmerse/NiMain/NiObject.h"
#include "RE/NetImmerse/NiMain/NiSmartPointer.h"

namespace RE
{
	class NiExtraDataContainer;
	class NiTimeController;

	class __declspec(novtable) NiObjectNET :
		public NiObject  // 00
	{
	public:
		static constexpr auto RTTI{ RTTI::NiObjectNET };
		static constexpr auto VTABLE{ VTABLE::NiObjectNET };
		static constexpr auto Ni_RTTI{ Ni_RTTI::NiObjectNET };

		enum CopyType : std::int32_t
		{
			COPY_NONE = 0x0,
			COPY_EXACT = 0x1,
			COPY_UNIQUE = 0x2,
		};


		NiObjectNET();
		virtual ~NiObjectNET();  // NOLINT(modernize-use-override) 00

		F4_HEAP_REDEFINE_NEW(NiObjectNET);

		[[nodiscard]] std::string_view GetName() const { return name; }

		// members
		BSFixedString name{ "" };                 // 10
		NiPointer<NiTimeController> controllers;  // 18
		NiExtraDataContainer* extra{ nullptr };   // 20
	};
	static_assert(sizeof(NiObjectNET) == 0x28);
}
