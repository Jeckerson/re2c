#ifndef _range_suffix_h
#define _range_suffix_h

#include <stddef.h> // NULL

#include "c99_stdint.h"
#include "free_list.h"

namespace re2c {

class RegExp; // forward

class RangeSuffix
{
	static free_list<RangeSuffix *> freeList;

public:
	uint32_t l;
	uint32_t h;
	RangeSuffix * next;
	RangeSuffix * child;

	RangeSuffix (uint32_t lo, uint32_t hi)
		: l     (lo)
		, h     (hi)
		, next  (NULL)
		, child (NULL)
	{
		freeList.insert(this);
	}
};

RegExp * emit(RangeSuffix * p, RegExp * re);

} // namespace re2c

#endif // _range_suffix_h
