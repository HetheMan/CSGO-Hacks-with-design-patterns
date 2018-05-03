#pragma once
#include <string>
#include <iostream> // For STL i/o
#include <ctime> // For std::chrono
#include <thread> // For std::this_thread
#include <windows.h>
#include <tchar.h>  
#include <vector>
#include <tlhelp32.h> 

using namespace std;
class MyMemoryManager
{
private: // Private members: We are going to setup some getters later on!
	HANDLE m_hProcess; // The HANDLE to the process to attach
	DWORD m_dwProcessId; // The Process Id of the process to attach
	std::vector<MODULEENTRY32> m_Modules; // std::vector containing all the modules we grab from the process
	MODULEENTRY32 engineDLL;
	DWORD dwEngineBase;
	MODULEENTRY32 clientDLL;
	DWORD dwClientBase;
	DWORD ClientDLL_Base, ClientDLL_Size;
	DWORD EngineDLL_Base, EngineDLL_Size;
public:
	// This constructor will attach to a specific process (default CS:GO)
	MyMemoryManager(const string strProcessName);
	MyMemoryManager();
	bool Attach(const string strProcessName);
	bool GrabModule(const string strProcessName);
	template <class T> bool Read(DWORD dwAddress, T& Value)
	{
		if (ReadProcessMemory(m_hProcess, (LPCVOID)dwAddress, (LPVOID)&Value, sizeof(T), NULL) == 0)
		{
			int lastError = GetLastError();
			cout << "Error: " << lastError << endl;
			return false;
		}
		else {
			return true;
		}
	}
	// Write a Value in memory
	// Returns true on success, false on failure
	template <class T> bool Write(DWORD dwAddress, const T& Value)
	{
		if (WriteProcessMemory(m_hProcess, (LPVOID)dwAddress, (LPCVOID)&Value, sizeof(T), NULL) == 0)
		{
			int lastError = GetLastError();
			cout << "Error: " << lastError << endl;
			return false;
		}
		else {
			return true;
		}
	}
	//Sets and gets
	HANDLE GetHandle();
	DWORD GetProcId();
	std::vector<MODULEENTRY32> GetModules();
	MODULEENTRY32 GetModule(const string modulo);
	void setClientDLL(MODULEENTRY32 modulo);
	MODULEENTRY32 getClientDLL();
	void setEngineDLL(MODULEENTRY32 modulo);
	MODULEENTRY32 getEngineDLL();
	void setClientBase(DWORD clienteBase);
	DWORD getClientBase();
	void setEngineBase(DWORD engineBase);
	DWORD getEngineBase();

};


