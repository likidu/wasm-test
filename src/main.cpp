#include "Emulator.h"
#include <iostream>
#include <smk/Audio.hpp>
#include <sstream>
#include <string>

int main(int argc, char **argv)
{
    smk::Audio audio;

    std::locale::global(std::locale("C.UTF-8"));
    // ROM path
    std::string path;

    sn::Emulator emulator;

    for (int i = 1; i < argc; ++i)
    {
        std::string arg(argv[i]);
        if (arg == "-h" || arg == "--help")
        {
            std::cout << "SimpleNES is a simple NES emulator.\n"
                      << "It can run off .nes images.\n"
                      << "Set keybindings with keybindings.conf\n\n"
                      << "Usage: SimpleNES [options] rom-path\n\n"
                      << "Options:\n"
                      << "-h, --help             Print this help text and exit\n"
                      << "-s, --scale            Set video scale. Default: 3.\n"
                      << "                       Scale of 1 corresponds to " << sn::NESVideoWidth << "x"
                      << sn::NESVideoHeight << std::endl
                      << "-w, --width            Set the width of the emulation screen (height is\n"
                      << "                       set automatically to fit the aspect ratio)\n"
                      << "-H, --height           Set the height of the emulation screen (width is\n"
                      << "                       set automatically to fit the aspect ratio)\n"
                      << "                       This option is mutually exclusive to --width\n"
                      << std::endl;
            return 0;
        }

        if (path.empty())
        {
            std::cout << "Argument required: ROM path" << std::endl;
            path = "Super Mario Bros. 3 (USA).nes";
            path = "NEStress.NES";
            // return 1;
        }

        emulator.run(path);
        return 0;
    }
}