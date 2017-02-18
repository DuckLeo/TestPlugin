// test_plugin - ������ ��� ������

#include "../SDK/plugin.h"
#include <string>

#define SP_PLUGIN_VERSION	"0.0.1"

typedef void (*logprintf_t)(char* format, ...);

logprintf_t logprintf;

void **ppPluginData;

extern void *pAMXFunctions;

PLUGIN_EXPORT bool PLUGIN_CALL Load(void **ppData)
{
	pAMXFunctions = ppData[PLUGIN_DATA_AMX_EXPORTS];
	logprintf = (logprintf_t)ppData[PLUGIN_DATA_LOGPRINTF];
	logprintf(" ");
	logprintf("������ test_plugin v"SP_PLUGIN_VERSION" ��������");
	logprintf(" ");
	return 1;
}

PLUGIN_EXPORT void PLUGIN_CALL Unload()
{
	logprintf("������ test_plugin v"SP_PLUGIN_VERSION" ��������");	
}

// native TP_ToLowerString(string[]);
static cell AMX_NATIVE_CALL TP_ToLowerString(AMX *amx, cell *params)
{
	char *string;
	int len = 0;
	amx_StrParam(amx, params[1], string);
	if (string != NULL)
	{
		len = strlen(string);
		for (int i = 0; i < len; i++)
		{
			switch (string[i])
			{
				case 'A': string[i] = 'a'; break;
				case 'B': string[i] = 'b'; break;
				case 'C': string[i] = 'c'; break;
				case 'D': string[i] = 'd'; break;
				case 'E': string[i] = 'e'; break;
				case 'F': string[i] = 'f'; break;
				case 'G': string[i] = 'g'; break;
				case 'H': string[i] = 'h'; break;
				case 'I': string[i] = 'i'; break;
				case 'J': string[i] = 'j'; break;
				case 'K': string[i] = 'k'; break;
				case 'L': string[i] = 'l'; break;
				case 'M': string[i] = 'm'; break;
				case 'N': string[i] = 'n'; break;
				case 'O': string[i] = 'o'; break;
				case 'P': string[i] = 'p'; break;
				case 'Q': string[i] = 'q'; break;
				case 'R': string[i] = 'r'; break;
				case 'S': string[i] = 's'; break;
				case 'T': string[i] = 't'; break;
				case 'U': string[i] = 'u'; break;
				case 'V': string[i] = 'v'; break;
				case 'W': string[i] = 'w'; break;
				case 'X': string[i] = 'x'; break;
				case 'Y': string[i] = 'y'; break;
				case 'Z': string[i] = 'z'; break;
				case '�': string[i] = '�'; break;
				case '�': string[i] = '�'; break;
				case '�': string[i] = '�'; break;
				case '�': string[i] = '�'; break;
				case '�': string[i] = '�'; break;
				case '�': string[i] = '�'; break;
				case '�': string[i] = '�'; break;
				case '�': string[i] = '�'; break;
				case '�': string[i] = '�'; break;
				case '�': string[i] = '�'; break;
				case '�': string[i] = '�'; break;
				case '�': string[i] = '�'; break;
				case '�': string[i] = '�'; break;
				case '�': string[i] = '�'; break;
				case '�': string[i] = '�'; break;
				case '�': string[i] = '�'; break;
				case '�': string[i] = '�'; break;
				case '�': string[i] = '�'; break;
				case '�': string[i] = '�'; break;
				case '�': string[i] = '�'; break;
				case '�': string[i] = '�'; break;
				case '�': string[i] = '�'; break;
				case '�': string[i] = '�'; break;
				case '�': string[i] = '�'; break;
				case '�': string[i] = '�'; break;
				case '�': string[i] = '�'; break;
				case '�': string[i] = '�'; break;
				case '�': string[i] = '�'; break;
				case '�': string[i] = '�'; break;
				case '�': string[i] = '�'; break;
				case '�': string[i] = '�'; break;
				case '�': string[i] = '�'; break;
				case '�': string[i] = '�'; break;
			}
		}
		string[len] = '\0';
	}
	else
	{
		string = "";
	}
	cell *addr = NULL;
	amx_GetAddr(amx, params[1], &addr);
	amx_SetString(addr, string, 0, 0, len+1);
	return 1;
}

// native bool:TP_IsFindIpString(string[]);
static cell AMX_NATIVE_CALL TP_IsFindIpString(AMX *amx, cell *params)
{
	char *string;
	amx_StrParam(amx, params[1], string);
	if (string != NULL)
	{
		int
			digits = 0,
			digit_groups = 0,
			len = strlen(string)
		;
		for (int pos = 0; pos < len; pos++)
		{
			switch (string[pos])
			{
				case 0: break;
				case '0': digits++; break;
				case '1': digits++; break;
				case '2': digits++; break;
				case '3': digits++; break;
				case '4': digits++; break;
				case '5': digits++; break;
				case '6': digits++; break;
				case '7': digits++; break;
				case '8': digits++; break;
				case '9': digits++; break;
				default:
				{
					if (digits >= 2)
					{
						digit_groups++;
						digits = 0;
					}
				}
			}
		}
		if (digits >= 2) digit_groups++;
		if (digit_groups >= 3) return 1;
	}
	return 0;
}

// native bool:TP_IsNumberString(string[]);
static cell AMX_NATIVE_CALL TP_IsNumberString(AMX *amx, cell *params)
{
	char *string;
	amx_StrParam(amx, params[1], string);
	if (string != NULL)
	{
		int i = 0;
		if (string[0] == '-')
		{
			i = 1;
		}
		for (int len = strlen(string); i < len; i++)
		{
			if ((string[i] < '0') || (string[i] > '9'))
			{
				return 0;
			}
		}
	}
	else
	{
		return 0;
	}
	return 1;
}

AMX_NATIVE_INFO NATIVES_LIST[] =
{
	{"TP_ToLowerString", TP_ToLowerString},
	{"TP_IsFindIpString", TP_IsFindIpString},
	{"TP_IsNumberString", TP_IsNumberString},
	{0, 0}
};

PLUGIN_EXPORT unsigned int PLUGIN_CALL Supports()
{
	return SUPPORTS_VERSION | SUPPORTS_AMX_NATIVES;
}

PLUGIN_EXPORT int PLUGIN_CALL AmxLoad(AMX *amx)
{
	return amx_Register(amx, NATIVES_LIST, -1);
}

PLUGIN_EXPORT int PLUGIN_CALL AmxUnload(AMX *amx)
{
	return AMX_ERR_NONE;
}