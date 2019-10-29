#include <gtest/gtest.h>
#include "printip.h"

TEST(TestPrintIP, printip_char) {
    std::stringstream output;
    print_ip(char(-1), output);
    ASSERT_TRUE(output.str() == "255\n");
}

TEST(TestPrintIP, printip_short) {
    std::stringstream output;
    print_ip(short(0), output);
    ASSERT_TRUE(output.str() == "0.0\n");
}

TEST(TestPrintIP, printip_int) {
    std::stringstream output;
    print_ip(int(2130706433), output);
    ASSERT_TRUE(output.str() == "127.0.0.1\n");
}

TEST(TestPrintIP, printip_long) {
    std::stringstream output;
    print_ip(long(8875824491850138409), output);
    ASSERT_TRUE(output.str() == "123.45.67.89.101.112.131.41\n");
}

TEST(TestPrintIP, printip_string) {
    std::stringstream output;
    print_ip(std::string("192.168.1.1"), output);
    ASSERT_TRUE(output.str() == "192.168.1.1\n");
}

TEST(TestPrintIP, printip_vector) {
    std::stringstream output;
    print_ip(std::vector<int>{1, 2, 3, 4}, output);
    ASSERT_TRUE(output.str() == "1.2.3.4\n");
}

TEST(TestPrintIP, printip_list) {
    std::stringstream output;
    print_ip(std::list<char>{5, 6, 7, 8}, output);
    ASSERT_TRUE(output.str() == "5.6.7.8\n");
}

TEST(TestPrintIP, printip_tuple) {
    std::stringstream output;
    print_ip(std::make_tuple(long(9), long(10), long(11), long(12)), output);
    ASSERT_TRUE(output.str() == "9.10.11.12\n");
}

int main(int argc, char *argv[])
{
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
