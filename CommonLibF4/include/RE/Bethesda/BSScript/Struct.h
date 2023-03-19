#pragma once

#include "RE/Bethesda/BSContainer.h"
#include "RE/Bethesda/BSSystem/BSFixedString.h"
#include "RE/Bethesda/BSLock.h"
#include "RE/Bethesda/BSScript/StructTypeInfo.h"
#include "RE/Bethesda/BSScript/Variable.h"
#include "RE/Bethesda/BSCore/BSTArray.h"
#include "RE/Bethesda/BSCore/BSTEvent.h"
#include "RE/Bethesda/BSCore/BSTHashMap.h"
#include "RE/Bethesda/BSCore/BSTObjectArena.h"
#include "RE/Bethesda/BSSystem/BSTSmartPointer.h"
#include "RE/Bethesda/BSCore/BSTTuple.h"
#include "RE/Bethesda/BSCore/MemoryManager.h"

namespace RE
{
	namespace BSScript
	{
		class StructTypeInfo;
		class Variable;

		class Struct :
			public BSIntrusiveRefCounted  // 00
		{
		public:
			~Struct();

			// members
			BSSpinLock structLock;                 // 04
			BSTSmartPointer<StructTypeInfo> type;  // 10
			bool constructed{ true };              // 18
			bool valid{ false };                   // 19
			Variable variables[0];                 // 20
		};
		static_assert(sizeof(Struct) == 0x20);
	}
}
