
#include "All_Exceptions.h"
#include "Weapon_Bundle.h"
#include "gtest/gtest.h"

TEST(Weapon_Bundle_Class, pistol_Atrribute) {

    Weapon_Bundle test_bundle;
    Pistol test_pistol("Revolver", 51, 150);

    try {
        test_bundle.get_pistol();
    }
    catch (Invalid_GunType_Exception e) {
        std::cout << "exception thrown!" << std::endl;
        EXPECT_EQ(e.what(), "no such gun");
    }

    test_bundle.change_pistol(test_pistol);
    EXPECT_EQ(test_bundle.get_pistol().get_name(), "Revolver");
    EXPECT_EQ(test_bundle.get_pistol().get_damage(), 51);
    EXPECT_EQ(test_bundle.get_pistol().get_reward(), 150);

}

TEST(Weapon_Bundle_Class, heavy_gun_Atrribute) {

    Weapon_Bundle test_bundle;
    Heavy_Gun test_heavy_gun("AK", 31, 100);

    try {
        test_bundle.get_heavy_gun();
    }
    catch (Invalid_GunType_Exception e) {
        std::cout << "exception thrown!" << std::endl;
        EXPECT_EQ(e.what(), "no such gun");
    }

    test_bundle.change_heavy_gun(test_heavy_gun);
    EXPECT_EQ(test_bundle.get_heavy_gun().get_name(), "AK");
    EXPECT_EQ(test_bundle.get_heavy_gun().get_damage(), 31);
    EXPECT_EQ(test_bundle.get_heavy_gun().get_reward(), 100);

}

TEST(Weapon_Bundle_Class, knife_Atrribute) {

    Weapon_Bundle test_bundle;

    EXPECT_EQ(test_bundle.get_knife().get_name(), "Knife");
    EXPECT_EQ(test_bundle.get_knife().get_damage(), 43);
    EXPECT_EQ(test_bundle.get_knife().get_reward(), 500);

}
