#include "MyMemoryManager.h"
// Default constructor: won't attach to any process
MyMemoryManager::MyMemoryManager()
{
	// Init members
	m_hProcess = INVALID_HANDLE_VALUE;
	m_dwProcessId = 0;
	// Just for safety, I clear out the modules vector
	m_Modules.clear();
}
// This constructor will attach to a specific process (default CS:GO)
MyMemoryManager::MyMemoryManager(const string strProcessName)
{
	// Init members
	m_hProcess = INVALID_HANDLE_VALUE;
	cout << strProcessName;
	m_dwProcessId = 0;
	// Just for safety, I clear out the modules vector
	m_Modules.clear();
	// Attach and throw if the function failed so we can manage the fail
	if (!Attach(strProcessName)) {
		cout << "nope";
		throw;
	}
}
// Attach to a process based on strProcessName
// Returns true on success, false on failure
bool MyMemoryManager::Attach(const std::string strProcessName)
{

	HANDLE hSnapshot = CreateToolhelp32Snapshot(TH32CS_SNAPPROCESS, NULL);
	if (hSnapshot == INVALID_HANDLE_VALUE) {
		cout << "Snapshot en attach no valido";
		return false;
	}

	PROCESSENTRY32 ProcEntry;
	// Remember to set the dwSize member of ProcEntry to sizeof(PROCESSENTRY32)
	ProcEntry.dwSize = sizeof(PROCESSENTRY32);

	// Call Process32First
	if (Process32First(hSnapshot, &ProcEntry))
	{
		if (!strcmp(ProcEntry.szExeFile, strProcessName.c_str()))
		{
			CloseHandle(hSnapshot);
			// Open an handle and set the m_hProcess member using OpenProcess
			// (Notice the usage of PROCESS_ALL_ACCESS flag in order to grant read/write privileges)
			m_hProcess = OpenProcess(PROCESS_ALL_ACCESS, FALSE, ProcEntry.th32ProcessID);
			// Store the process id into m_dwProcessId
			m_dwProcessId = ProcEntry.th32ProcessID;
			// Return true meaning success
			return true;
		}
	}
	else
	{
		// If the Process32First call failed, it means that there is no
		// process running in the first place, we can return directly.
		CloseHandle(hSnapshot);
		return false;
	}

	// If we are here it means that the Process32First call returned TRUE, but the first process
	// wasn't the process that we were searching for. Now we can loop through the processes
	// using Process32Next
	while (Process32Next(hSnapshot, &ProcEntry))
	{
		// We do the same check we did for Process32First
		if (!strcmp(ProcEntry.szExeFile, strProcessName.c_str()))
		{
			// If we are here it means that the process has been found, we can
			// open an handle to it and set the m_hProcess member using OpenProcess
			// (Notice the usage of PROCESS_ALL_ACCESS flag in order to grant read/write privileges)
			m_hProcess = OpenProcess(PROCESS_ALL_ACCESS, FALSE, ProcEntry.th32ProcessID);
			// Store the process id into m_dwProcessId
			m_dwProcessId = ProcEntry.th32ProcessID;
			// Return true meaning success
			return true;
		}
	}
	// Continue loop while the Process32Next call returns TRUE meaning that there are still processes to check

	// If we are here it means that the process has not been found or that there are no processes to scan for anymore.
	// We can close the snapshot handle and return false.
	CloseHandle(hSnapshot);
	return false;
}
// Grabs a module and adds it to m_Modules if found based on strModuleName
// Returns true on success, false on failure
bool MyMemoryManager::GrabModule(const std::string strModuleName)
{
	// First of all we create a snapshot handle specific for modules
	// (notice the usage of TH32CS_SNAPMODULE) so we are able to call Module32First/Next
	// Remeber to close it when you don't use it anymore!
	HANDLE hSnapshot = CreateToolhelp32Snapshot(TH32CS_SNAPMODULE, m_dwProcessId);
	// Check if the snapshot created is valid
	if (hSnapshot == INVALID_HANDLE_VALUE) {
		cout << " Snapshot de modulo no funciona";
		return false;
	}

	// Create the helper struct that will contain all the infos about the current module
	// while we loop through all the loaded modules
	MODULEENTRY32 ModEntry;
	// Remember to set the dwSize member of ModEntry to sizeof(MODULEENTRY32)
	ModEntry.dwSize = sizeof(MODULEENTRY32);

	// Call Module32First
	if (Module32First(hSnapshot, &ModEntry))
	{
		// Notice that you have to enable Multi-Byte character set in order
		// to avoid converting everything.
		// strcmp is not the only way to compare 2 strings ofc, work with your imagination
		if (!strcmp(ModEntry.szModule, strModuleName.c_str()))
		{
			// If we are here it means that the module has been found, we can add the module to the vector
			// But first of all we have to close the snapshot handle!
			CloseHandle(hSnapshot);
			// Add ModEntry to the m_Modules vector
			m_Modules.push_back(ModEntry); // You can add a check here to see if the module is already there ;)
										   // Return true meaning success
			return true;
		}
	}
	else
	{
		CloseHandle(hSnapshot);
		return false;
	}
	while (Module32Next(hSnapshot, &ModEntry))
	{
		// We do the same check we did for Module32First
		if (!strcmp(ModEntry.szModule, strModuleName.c_str()))
		{
			// If we are here it means that the module has been found, we can add the module to the vector
			// But first of all we have to close the snapshot handle!
			CloseHandle(hSnapshot);
			// Add ModEntry to the m_Modules vector
			m_Modules.push_back(ModEntry); // You can add a check here to see if the module is already there ;)
										   // Return true meaning success
			return true;
		}
	}
	// Continue loop while the Module32Next call returns TRUE meaning that there are still modules to check

	// If we are here it means that the module has not been found or that there are no modules to scan for anymore.
	// We can close the snapshot handle and return false.
	CloseHandle(hSnapshot);
	return false;
}
//RPM/WPM wrappers

// Read a value from memory and put it in Value
// Returns true on success, false on failure

// Getters
HANDLE MyMemoryManager::GetHandle() { return m_hProcess; }
DWORD MyMemoryManager::GetProcId() { return m_dwProcessId; }
vector<MODULEENTRY32> MyMemoryManager::GetModules() { return m_Modules; }
MODULEENTRY32 MyMemoryManager::GetModule(const string modulo) {
	for (auto m : this->GetModules()) // Loop through the modules grabbed
	{
		if (!strcmp(m.szModule, modulo.c_str()))
		{
			return m;
		}
	}
}
void MyMemoryManager::setClientDLL(MODULEENTRY32 modulo) {
	this->clientDLL = modulo;
	dwClientBase = reinterpret_cast<DWORD>(modulo.modBaseAddr);
}
MODULEENTRY32 MyMemoryManager::getClientDLL() { return this->clientDLL; }
void MyMemoryManager::setEngineDLL(MODULEENTRY32 modulo) {
	this->engineDLL = modulo;
	dwEngineBase = reinterpret_cast<DWORD>(modulo.modBaseAddr);
}
MODULEENTRY32 MyMemoryManager::getEngineDLL() { return this->engineDLL; }
void MyMemoryManager::setClientBase(DWORD clienteBase) {
	this->dwClientBase = clienteBase;
}
DWORD MyMemoryManager::getClientBase() {
	return this->dwClientBase;
}
void MyMemoryManager::setEngineBase(DWORD engineBase) {
	this->dwEngineBase = engineBase;
}
DWORD MyMemoryManager::getEngineBase() { return this->dwEngineBase; }