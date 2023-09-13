#pragma once
#include <cstdint>
//This function returnes if the system's memory is little or big endian,

bool IsLittleEndian();


//bool ConvertEndians(void* p_src, uint64_t ByteCount, bool quad);
//TODO test
//bool ConvertEndians(void* p_src, uint64_t ByteCount, bool quad) {
//	// Check if ByteCount is a positive multiple of 8 for 64-bit, or 4 for 32-bit, machines
//	int ByteGroupSize = quad ? 8 : 4;
//
//	if (ByteCount <= 1 || ByteCount % ByteGroupSize != 0) {
//		return false;
//	}
//
//	// Cast the void pointer to a char pointer for byte-level manipulation
//	char* src = static_cast<char*>(p_src);
//
//	for (uint64_t i = 0; i < ByteCount; i += ByteGroupSize) {
//		// Swap the bytes within each ByteGroupSize-byte chunk
//		for (uint64_t j = 0; j < ByteGroupSize / 2; ++j) {
//			std::swap(src[i + j], src[i + (ByteGroupSize - 1) - j]);
//		}
//	}
//
//	return true;
//}
