#include "UtilityAI/BlackBoard.hpp"


namespace uai
{
auto BlackBoard::GetValue(const HashedString& name) -> std::optional<BlackBoardValue>
{
	auto value = mBoardMap.find(name);
	if (value != mBoardMap.end()) 
	{
		return value->second;
	}
	return std::nullopt;
}

auto BlackBoard::SetValue(const HashedString& name, const BlackBoardValue& value) -> void
{
	mBoardMap.insert(std::make_pair(name,value));
}

auto BlackBoard::ClearValue(const HashedString& name) -> void
{
	auto iter = mBoardMap.find(name);
	if (iter != mBoardMap.end())
	{
		mBoardMap.erase(iter);
	}
}
}
