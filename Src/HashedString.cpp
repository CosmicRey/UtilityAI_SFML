#include "UtilityAI/HashedString.hpp"

namespace
{
std::hash<std::string> sHasher;
}

HashedString::HashedString(const std::string_view& name)
	: mName{ name }
	, mHashValue{ 0 }
{
	mHashValue = sHasher(name.data());
}

void HashedString::Set(const std::string_view& name)
{
	mName = name;
	mHashValue = sHasher(name.data());
}

void HashedString::_SetString(const std::string& str)
{
	Set(str);
}