#pragma once


namespace uai
{
class IGameLoop
{
public:
	virtual void Startup() = 0;
	virtual bool Tick() = 0;
	virtual void Shutdown() = 0;
};
}
