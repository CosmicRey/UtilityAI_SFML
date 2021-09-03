#pragma once

#include "HashedString.hpp"

#include <variant>
#include <optional>
#include <unordered_map>

namespace uai
{
#define RegisterBlackboardVariable(Name) static HashedString Name(#Name);


using BlackBoardValue = std::variant<int, float>;

class BlackBoard
{
	std::unordered_map<HashedString, BlackBoardValue> mBoardMap;
public:
	auto GetValue(const HashedString& name) -> std::optional<BlackBoardValue>;
	auto SetValue(const HashedString& name, const BlackBoardValue& value) -> void;
	auto ClearValue(const HashedString& name) -> void;
};
}