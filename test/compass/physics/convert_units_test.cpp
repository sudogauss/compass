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

#include <gtest/gtest.h>

#include <type_traits>

#include <compass/physics/units.hpp>
#include <compass/physics/quantity.hpp>

TEST(CompassPhysics, SuccessfulLengthConvertUnitsTest)
{
    compass::physics::physical_unit<double, compass::physics::units::length::meter> distance(20.65);
    compass::physics::physical_unit<double, compass::physics::units::length::kilometer> kdistance;

    compass::physics::convert<>(distance, kdistance);

    bool distance_units = std::is_same<typename decltype(distance)::physical_unit, compass::physics::units::length::meter>::value;
    bool kdistance_units = std::is_same<typename decltype(kdistance)::physical_unit, compass::physics::units::length::meter>::value;

    ASSERT_TRUE(distance_units);
    ASSERT_TRUE(kdistance_units);    
    ASSERT_FLOAT_EQ(kdistance.scalar, 0.02065);
}

int main(int argc, char** argv)
{
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
