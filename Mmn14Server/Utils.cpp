#include "Utils.h"

int CheckedEndianes = 2;
//This function returnes if the system's mem is little or big endian,
//This is the optimized version
bool IsLittleEndian() {
	if (CheckedEndianes == 2)
	{
		uint16_t value = 0x01; // A 16-bit integer with the value 1
		uint8_t* byteArray = reinterpret_cast<uint8_t*>(&value);
		CheckedEndianes = (byteArray[0] == 0x01);
	}
	return (CheckedEndianes);
}

