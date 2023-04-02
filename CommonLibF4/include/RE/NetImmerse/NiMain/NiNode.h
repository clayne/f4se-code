#pragma once

#include "RE/Bethesda/Atomic.h"
#include "RE/NetImmerse/NiMain/NiAVObject.h"
#include "RE/NetImmerse/NiMain/NiSmartPointer.h"
#include "RE/NetImmerse/NiMain/NiTArray.h"

namespace RE
{
	class __declspec(novtable) NiNode :
		public NiAVObject  // 000
	{
	public:
		static constexpr auto RTTI{ RTTI::NiNode };
		static constexpr auto VTABLE{ VTABLE::NiNode };
		static constexpr auto Ni_RTTI{ Ni_RTTI::NiNode };

		// NOLINTNEXTLINE(modernize-use-equals-default)
		NiNode() :
			NiNode(0)
		{}

		explicit NiNode(std::uint32_t a_numChildren) :
			children(a_numChildren)
		{
			stl::emplace_vtable(this);
			REL::Relocation<std::uintptr_t> childrenVTable{ REL::ID(390064) };
			reinterpret_cast<std::uintptr_t&>(children) = childrenVTable.address();
		}

		// add
		virtual void AttachChild(NiAVObject* a_child, bool a_firstAvail);                                 // 3A
		virtual void InsertChildAt(std::uint32_t a_idx, NiAVObject* a_child);                             // 3B
		virtual void DetachChild(NiAVObject* a_child);                                                    // 3D
		virtual void DetachChild(NiAVObject* a_child, NiPointer<NiAVObject>& a_avObject);                 // 3C
		virtual void DetachChildAt(std::uint32_t a_idx);                                                  // 3F
		virtual void DetachChildAt(std::uint32_t a_idx, NiPointer<NiAVObject>& a_avObject);               // 3E
		virtual void SetAt(std::uint32_t a_idx, NiAVObject* a_child);                                     // 41
		virtual void SetAt(std::uint32_t a_idx, NiAVObject* a_child, NiPointer<NiAVObject>& a_avObject);  // 40
		virtual void UpdateUpwardPass(NiUpdateData& a_data);                                              // 42

		static NiObject* CreateObject()
		{
			using func_t = decltype(&NiNode::CreateObject);
			REL::Relocation<func_t> func{ REL::ID(695914), 0x6 };
			return func();
		}

		static NiNode* Create()
		{
			return (NiNode*)CreateObject();
		}

		// members
		NiTObjectArray<NiPointer<NiAVObject>> children;  // 120
		BSTAtomicValue<std::uint32_t> dirtyState;        // 138
		float meshLODFadeAmount{ 0.0F };                 // 13C

		F4_HEAP_REDEFINE_ALIGNED_NEW(NiNode);
	};
	static_assert(sizeof(NiNode) == 0x140);
}
