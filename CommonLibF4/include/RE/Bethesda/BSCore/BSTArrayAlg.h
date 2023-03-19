#pragma once

#include "RE/Bethesda/BSCore/MemoryManager.h"
#include "RE/Bethesda/BSCore/BSTArray.h"

namespace RE
{

	template <std::uint32_t N>
	struct BSTAlignedHeapArrayAllocator
	{
	public:
		class Allocator
		{
		public:
			using size_type = std::uint32_t;
			using difference_type = std::ptrdiff_t;
			using propagate_on_container_move_assignment = std::true_type;

			Allocator() noexcept = default;
			Allocator(const Allocator&) = delete;

			Allocator(Allocator&& a_rhs) noexcept :
				_data{ std::exchange(a_rhs._data, nullptr) },
				_capacity{ std::exchange(a_rhs._capacity, 0) }
			{}

			~Allocator() noexcept = default;

			Allocator& operator=(const Allocator&) = delete;

			Allocator& operator=(Allocator&& a_rhs) noexcept
			{
				if (this != std::addressof(a_rhs)) {
					_data = std::exchange(a_rhs._data, nullptr);
					_capacity = std::exchange(a_rhs._capacity, 0);
				}
				return *this;
			}

			[[nodiscard]] void* allocate(uint32_t a_bytes) { return aligned_alloc(N, a_bytes); }
			void deallocate(void* a_ptr) { aligned_free(a_ptr); }

			[[nodiscard]] void* data() noexcept { return _data; }
			[[nodiscard]] const void* data() const noexcept { return _data; }
			void set_data(void* a_data) noexcept { _data = a_data; }

			[[nodiscard]] size_type capacity() const noexcept { return _capacity; }
			void set_capacity(size_type a_capacity, size_type) noexcept { _capacity = a_capacity; }

		private:
			void* _data{ nullptr };    // 00
			size_type _capacity{ 0 };  // 08
		};
	};

	extern template class BSTAlignedHeapArrayAllocator<0x10>::Allocator;

	template <class T, std::uint32_t N = alignof(T)>
	using BSTAlignedArray = BSTArray<T, typename BSTAlignedHeapArrayAllocator<N>::Allocator>;
}
