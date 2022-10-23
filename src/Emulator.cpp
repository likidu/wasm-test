#include "Emulator.h"
#include <iostream>
#include <smk/Color.hpp>
#include <smk/Window.hpp>
#include <string>

namespace sn
{
  Emulator::Emulator()
  {
    m_window = smk::Window(NESVideoWidth, NESVideoHeight, "SimpleNES");
  }

  void Emulator::run(std::string rom_path)
  {
    std::cout << "ROM path" << rom_path << std::endl;

    m_window.ExecuteMainLoop([&] {
      m_window.PoolEvents();
      m_window.Clear(smk::Color::Black);
#ifndef __EMSCRIPTEN__
      m_window.LimitFrameRate(60.f);
#endif
      m_window.Display();
    });
  }
} // namespace sn
