#include "c-echo.h"
#include "header/rectangle.hpp" 

#include "gtest/gtest.h"

TEST(EchoTest, HelloWorld) {
	char* test_val[3]; test_val[0] = "./c-echo"; test_val[1] = "hello"; test_val[2] = "world";
	EXPECT_EQ("hello world", echo(3,test_val));
}

TEST(EchoTest, EmptyString) {
    char* test_val[1]; test_val[0] = "./c-echo";
    EXPECT_EQ("", echo(1,test_val));
}

TEST(RectangleTest, TestPos){	
	Rectangle r1;
	r1.set_width(3);
	r1.set_height(4);
	EXPECT_EQ(12, r1.area());
}

TEST(RectangleTest, TestZero) {
        Rectangle r1;
        r1.set_width(0);
        r1.set_height(0);
        EXPECT_EQ(0, r1.area());

}

TEST(RectangleTest, TestNeg) {
        Rectangle r1;
        r1.set_width(3);
        r1.set_height(-4);
        EXPECT_EQ(-12, r1.area());

}

int main(int argc, char **argv){
	::testing::InitGoogleTest(&argc, argv);
	return RUN_ALL_TESTS();
}


