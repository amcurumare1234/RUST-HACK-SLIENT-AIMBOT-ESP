#include "misc.h"
#include "offsets.h"

// I shared a Tutorial rust cheat source for you
// This resource is just an instructional resource if you have knowledge you can really benefit from this resource
// Contact: ReFo#7149

int main() {
	auto process = get_process_id("RustClient.exe");
	if (process) {
		 auto process_base_addr = get_base_address("RustClient.exe");
		 auto assembly_base_addr = get_base_address("GameAssembly.dll"); // We have nothing to do with UnityPlayer.dll because it will only have adminmode feature
			DWORD64 localplayer1 = memory::read<DWORD64>(assembly_base_addr + basenetworkable);
			DWORD64 localplayer2 = memory::read<DWORD64>(localplayer1 + 0xB8);
			DWORD64 localplayer3 = memory::read<DWORD64>(localplayer2 + 0x0);
			DWORD64 localplayer4 = memory::read<DWORD64>(localplayer3 + 0x10);
			DWORD64 localplayer5 = memory::read<DWORD64>(localplayer4 + 0x28);
			DWORD64 localplayer6 = memory::read<DWORD64>(localplayer5 + 0x18);
			DWORD64 localplayer7 = memory::read<DWORD64>(localplayer6 + 0x20);
		        while (true) {
			int flag = memory::read<int>(localplayer7 + playerflags);
			memory::write<int>(playerflags, (flag |= admin));
		}
	}
}
