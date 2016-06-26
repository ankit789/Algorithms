#include <iostream>
//#include<bool.h>

bool is64Bit()
{
    int ExtendedFeatureFlags;
    asm ( "mov $0x80000001, %%eax; " // 0x80000001 gets Extended Feature Flags
              "cpuid; "                 // Call CPUID instruction.
              "mov %%edx, %0; "         // Copy EDX into first output variable.
              :"=r"(ExtendedFeatureFlags)  // Output variable.
              :                            // No input variables.
              :"%eax","%ebx","%ecx","%edx" // Clobbered registers.
            );
    return ExtendedFeatureFlags & (1<<29);
    // If the 29th bit is on, the processor supports 64bit
    // extensions.
}

int main()
{
    std::cout << "Is 64bit?: " << (is64Bit() ? "YES" : "NO") << std::endl;
    return 0;
}
