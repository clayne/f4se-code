#pragma once

namespace RE
{
	struct hkContainerHeapAllocator;

	template <class T>
	class hkArrayBase
	{
	public:
		using size_type = std::int32_t;
		using value_type = T;
		using pointer = value_type*;

	private:
		pointer _data;                // 00
		size_type _size;              // 08
		size_type _capacityAndFlags;  // 0C
	};

	template <class T, class Allocator = hkContainerHeapAllocator>
	class hkArray :
		public hkArrayBase<T>  // 00
	{
	public:
	};
}
