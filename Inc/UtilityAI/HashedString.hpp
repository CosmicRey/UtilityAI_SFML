#pragma once

#include <algorithm>
#include <string>
#include <string_view>

class HashedString
{
	size_t mHashValue;
	std::string mName;

public:
	HashedString() = default;
	HashedString(const HashedString&) = default;
	HashedString(HashedString&&) = default;
	HashedString& operator=(const HashedString&) = default;
	HashedString& operator=(HashedString&&) = default;
	HashedString(const std::string_view& HashedString);

	void Set(const std::string_view& HashedString);
	size_t GetHashValue() const { return mHashValue; }
	std::string_view GetString() const { return mName; }

	bool operator==(const HashedString& other) const { return mHashValue == other.mHashValue; }

	bool operator<(const HashedString& other) const { return mHashValue < other.mHashValue; }

	bool operator>(const HashedString& other) const { return mHashValue > other.mHashValue; }
private:
	void _SetString(const std::string& str);
	const std::string& _GetString() { return mName; };
};

namespace std
{
template <>
struct hash<HashedString>
{
	size_t operator()(const HashedString& x) const
	{
		return x.GetHashValue();
	}
};
}
