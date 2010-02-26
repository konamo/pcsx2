/* SPU2-X, A plugin for Emulating the Sound Processing Unit of the Playstation 2
 * Developed and maintained by the Pcsx2 Development Team.
 * 
 * Original portions from SPU2ghz are (c) 2008 by David Quintana [gigaherz]
 *
 * SPU2-X is free software: you can redistribute it and/or modify it under the terms
 * of the GNU Lesser General Public License as published by the Free Software Found-
 * ation, either version 3 of the License, or (at your option) any later version.
 *
 * SPU2-X is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY;
 * without even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR
 * PURPOSE.  See the GNU Lesser General Public License for more details.
 *
 * You should have received a copy of the GNU Lesser General Public License
 * along with SPU2-X.  If not, see <http://www.gnu.org/licenses/>.
 */
 
#include "Global.h"
#include "Dialogs.h"
 
bool DebugEnabled=false;
bool _MsgToConsole=false;
bool _MsgKeyOnOff=false;
bool _MsgVoiceOff=false;
bool _MsgDMA=false;
bool _MsgAutoDMA=false;
bool _MsgOverruns=false;
bool _MsgCache=false;

bool _AccessLog=false;
bool _DMALog=false;
bool _WaveLog=false;

bool _CoresDump=false;
bool _MemDump=false;
bool _RegDump=false;

wchar_t AccessLogFileName[255];
wchar_t WaveLogFileName[255];

wchar_t DMA4LogFileName[255];
wchar_t DMA7LogFileName[255];

wchar_t CoresDumpFileName[255];
wchar_t MemDumpFileName[255];
wchar_t RegDumpFileName[255];

/*namespace DebugConfig {

static const wchar_t* Section = L"DEBUG";

void ReadSettings()
{
	DebugEnabled = CfgReadBool(Section, L"Global_Enable",0);
	_MsgToConsole= CfgReadBool(Section, L"Show_Messages",0);
	_MsgKeyOnOff = CfgReadBool(Section, L"Show_Messages_Key_On_Off",0);
	_MsgVoiceOff = CfgReadBool(Section, L"Show_Messages_Voice_Off",0);
	_MsgDMA      = CfgReadBool(Section, L"Show_Messages_DMA_Transfer",0);
	_MsgAutoDMA  = CfgReadBool(Section, L"Show_Messages_AutoDMA",0);
	_MsgOverruns = CfgReadBool(Section, L"Show_Messages_Overruns",0);
	_MsgCache    = CfgReadBool(Section, L"Show_Messages_CacheStats",0);

	_AccessLog   = CfgReadBool(Section, L"Log_Register_Access",0);
	_DMALog      = CfgReadBool(Section, L"Log_DMA_Transfers",0);
	_WaveLog     = CfgReadBool(Section, L"Log_WAVE_Output",0);

	_CoresDump   = CfgReadBool(Section, L"Dump_Info",0);
	_MemDump     = CfgReadBool(Section, L"Dump_Memory",0);
	_RegDump     = CfgReadBool(Section, L"Dump_Regs",0);

	CfgReadStr(Section,L"Access_Log_Filename",AccessLogFileName,255,L"logs/SPU2Log.txt");
	CfgReadStr(Section,L"WaveLog_Filename",   WaveLogFileName,  255,L"logs/SPU2log.wav");
	CfgReadStr(Section,L"DMA4Log_Filename",   DMA4LogFileName,  255,L"logs/SPU2dma4.dat");
	CfgReadStr(Section,L"DMA7Log_Filename",   DMA7LogFileName,  255,L"logs/SPU2dma7.dat");

	CfgReadStr(Section,L"Info_Dump_Filename",CoresDumpFileName,255,L"logs/SPU2Cores.txt");
	CfgReadStr(Section,L"Mem_Dump_Filename", MemDumpFileName,  255,L"logs/SPU2mem.dat");
	CfgReadStr(Section,L"Reg_Dump_Filename", RegDumpFileName,  255,L"logs/SPU2regs.dat");
}


void WriteSettings()
{
	CfgWriteBool(Section,L"Global_Enable",DebugEnabled);

	CfgWriteBool(Section,L"Show_Messages",             _MsgToConsole);
	CfgWriteBool(Section,L"Show_Messages_Key_On_Off",  _MsgKeyOnOff);
	CfgWriteBool(Section,L"Show_Messages_Voice_Off",   _MsgVoiceOff);
	CfgWriteBool(Section,L"Show_Messages_DMA_Transfer",_MsgDMA);
	CfgWriteBool(Section,L"Show_Messages_AutoDMA",     _MsgAutoDMA);
	CfgWriteBool(Section,L"Show_Messages_Overruns",    _MsgOverruns);
	CfgWriteBool(Section,L"Show_Messages_CacheStats",  _MsgCache);

	CfgWriteBool(Section,L"Log_Register_Access",_AccessLog);
	CfgWriteBool(Section,L"Log_DMA_Transfers",  _DMALog);
	CfgWriteBool(Section,L"Log_WAVE_Output",    _WaveLog);

	CfgWriteBool(Section,L"Dump_Info",  _CoresDump);
	CfgWriteBool(Section,L"Dump_Memory",_MemDump);
	CfgWriteBool(Section,L"Dump_Regs",  _RegDump);

	CfgWriteStr(Section,L"Access_Log_Filename",AccessLogFileName);
	CfgWriteStr(Section,L"WaveLog_Filename",   WaveLogFileName);
	CfgWriteStr(Section,L"DMA4Log_Filename",   DMA4LogFileName);
	CfgWriteStr(Section,L"DMA7Log_Filename",   DMA7LogFileName);

	CfgWriteStr(Section,L"Info_Dump_Filename",CoresDumpFileName);
	CfgWriteStr(Section,L"Mem_Dump_Filename", MemDumpFileName);
	CfgWriteStr(Section,L"Reg_Dump_Filename", RegDumpFileName);
}*/