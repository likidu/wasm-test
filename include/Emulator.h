#ifndef EMULATOR_H
#define EMULATOR_H

#include "PPU.h"
#include <smk/Window.hpp>

namespace sn
{
    const int NESVideoWidth  = ScanlineVisibleDots;
    const int NESVideoHeight = VisibleScanlines;

    class Emulator
    {
    public:
        Emulator();
        void run(std::string rom_path);

    private:
        smk::Window m_window;
    };
} // namespace sn

#endif // EMULATOR_H