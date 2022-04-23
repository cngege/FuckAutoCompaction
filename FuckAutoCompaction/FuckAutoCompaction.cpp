#include "pch.h"
#include <EventAPI.h>
#include <LoggerAPI.h>
#include <MC/Level.hpp>
#include <MC/BlockInstance.hpp>
#include <MC/Block.hpp>
#include <MC/BlockSource.hpp>
#include <MC/Actor.hpp>
#include <MC/Player.hpp>
#include <MC/ItemStack.hpp>
#include <LLAPI.h>
#include <MC/BedrockLog.hpp>

Logger FuckAutoCompactionLogger("FuckAutoCompaction");

void PluginInit()
{
	FuckAutoCompactionLogger.info("插件加载");
}

//enum BedrockLog::LogCategory, class std::bitset<3>, enum BedrockLog::LogRule, enum LogAreaID, unsigned int, char const *, int, char const *, ...
/*
THook(void, "?log@BedrockLog@@YAXW4LogCategory@1@V?$bitset@$02@std@@W4LogRule@1@W4LogAreaID@@IPEBDH4ZZ",enum BedrockLog::LogCategory* thi, std::bitset<3> a, BedrockLog::LogRule b, LogAreaID c, unsigned int d, char const* e, int f, char const* __ptr64 g, ...) {
	std::cout << "output:" << std::endl;
	//original(thi, a, b, c, d, e, f, g);
}
*/


//?log@BedrockLog@@YAXW4LogCategory@1@V?$bitset@$02@std@@W4LogRule@1@W4LogAreaID@@IPEBDH4ZZ
//?log_va@BedrockLog@@YAXW4LogCategory@1@V?$bitset@$02@std@@W4LogRule@1@W4LogAreaID@@IPEBDH4PEAD@Z

THook(void, "?log_va@BedrockLog@@YAXW4LogCategory@1@V?$bitset@$02@std@@W4LogRule@1@W4LogAreaID@@IPEBDH4PEAD@Z", enum BedrockLog::LogCategory thi, class std::bitset<3> a, enum BedrockLog::LogRule b, enum LogAreaID c, unsigned int d, char const* e, int f, char const* g, char * va) {
	std::string log(e);
	if (log.find("DBStorage::_scheduleNextAutoCompaction") != -1 )
	{
		return;
	}
	original(thi, a, b, c, d, e, f, g, va);
}
