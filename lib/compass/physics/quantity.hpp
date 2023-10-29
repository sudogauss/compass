// Copyright (C) sudogauss - All Rights Reserved
// Unauthorized copying of this file, via any medium is strictly prohibited
// Proprietary
// Written by sudogauss
// ⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⣀⠀⠀⠀⠀⠀⠀⣀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀
// ⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⢹⣄⠀⠀⠀⠀⣠⡟⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀
// ⠀⠀⠀⠀⠀⣤⡀⠀⢀⣤⣶⣿⣿⣿⣿⣿⣿⣿⣿⣶⣤⡀⣀⣤⣶⡟⠀⠀⠀⠀
// ⠀⠀⠀⠀⠀⠈⣻⣾⣿⣿⣿⡿⠟⠛⠛⠛⠛⠻⢿⣿⣿⣿⡿⣻⡟⠀⠀⠀⠀⠀
// ⠀⠀⠀⠀⠀⣴⣿⣿⣿⠟⠁⠀⠀⠀⠀⢀⣠⣴⣿⣿⡿⠋⣼⣿⣦⠀⠀⠀⠀⠀
// ⠀⢠⣄⣀⣼⣿⣿⡿⠁⠀⠀⠀⣀⣤⣾⣿⣿⣿⡿⠋⢀⣼⢿⣿⣿⣧⣀⣠⡄⠀
// ⠀⠀⠀⠙⣿⣿⣿⠁⠀⠀⠀⣼⠛⢿⣿⣿⡿⠋⠀⢀⡾⠃⠈⣿⣿⣿⠋⠀⠀⠀
// ⠀⠀⠀⠀⣿⣿⣿⠀⠀⢀⣾⠃⠀⠀⢙⡋⠀⠀⢠⡿⠁⠀⠀⣿⣿⣿⠀⠀⠀⠀
// ⠀⠀⠀⣠⣿⣿⣿⡀⢀⡾⠁⠀⢀⣴⣿⣿⣦⣠⡟⠁⠀⠀⢀⣿⣿⣿⣄⠀⠀⠀
// ⠀⠘⠋⠉⢻⣿⣿⣷⡿⠁⢀⣴⣿⣿⣿⡿⠟⠋⠀⠀⠀⢀⣾⣿⣿⡟⠉⠙⠃⠀
// ⠀⠀⠀⠀⠀⢻⣿⡟⢀⣴⣿⣿⠿⠋⠁⠀⠀⠀⠀⢀⣴⣿⣿⣿⡟⠀⠀⠀⠀⠀
// ⠀⠀⠀⠀⠀⣼⢟⣴⣿⣿⣿⣷⣦⣤⣤⣤⣤⣴⣶⣿⣿⣿⡿⣯⡀⠀⠀⠀⠀⠀
// ⠀⠀⠀⠀⣼⠿⠛⠉⠉⠛⠿⣿⣿⣿⣿⣿⣿⣿⣿⠿⠛⠉⠀⠈⠛⠀⠀⠀⠀⠀
// ⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⣸⠋⠀⠉⠉⠀⠙⣧⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀
//

#pragma once

#include "units.hpp"

#include <type_traits>

namespace compass::physics {

template<typename T, typename Unit> struct physical_unit {

    T scalar;
    using unit_type = Unit;

    physical_unit() {
        static_assert(std::is_arithmetic<T>::value && std::is_base_of<units::unit, Unit>::value);

    }

    physical_unit(T _scalar) {
        static_assert(std::is_arithmetic<T>::value && std::is_base_of<units::unit, Unit>::value);
        value = _scalar;
    }
};

template<typename Phy, typename Unit> void convert(Phy& _physical_unit)
{
  static_assert(false);
}

template<typename T, typename UnitFrom, typename UnitTo> void convert(const physical_unit<T, UnitFrom>& _from_physical_unit, physical_unit<T, UnitTo>& _to_physical_unit)
{

  if(std::is_same<UnitFrom, UnitTo>::value)
    return;

  if(std::is_base_of<units::length::__length_unit, UnitFrom>::value && std::is_base_of<units::length::__length_unit, UnitTo>::value)
  {
    auto new_scalar_ = static_cast<T>(_from_physical_unit * UnitFrom::mult / UnitTo::mult);
    _to_physical_unit.scalar = new_scalar_;
  }
  else if(std::is_base_of<units::length::__angular_unit, UnitFrom>::value && std::is_base_of<units::length::__angular_unit, UnitTo>::value)
  {
    auto new_scalar_ = static_cast<T>(_from_physical_unit * UnitFrom::mult / UnitTo::mult);
    _to_physical_unit.scalar = new_scalar_;
  }
  else {
    static_assert(false);
  }
}

} // namespace compass::physics