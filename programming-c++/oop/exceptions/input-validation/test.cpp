#include <gtest/gtest.h>
#include <stdexcept>
#include <string>

#include "user.h"

using namespace std;

TEST(UserTest, ConstructorTest) 
{
    // Setup
    User user(7, "homer", "c3R1ZGVudA");
    
    // Verify
    EXPECT_EQ(7, user.id());
    EXPECT_EQ("homer", user.username());
    EXPECT_EQ("c3R1ZGVudA", user.password());
}

TEST(UserTest, InvalidIdTest) 
{
    // Verify
    EXPECT_THROW(User(-1, "homer", "c3R1ZGVudA"), std::invalid_argument);
}

TEST(UserTest, ValidIdBoundaryTest) 
{
    // Verify
    EXPECT_NO_THROW(User(0, "homer", "c3R1ZGVudA"));
}

TEST(UserTest, InvalidUsernameTooShortTest) 
{
    // Verify
    EXPECT_THROW(User(1, "hom", "c3R1ZGVudA"), std::invalid_argument);
}

TEST(UserTest, InvalidUsernameTooLongTest) 
{
    // Verify
    string username(41, 'x');
    EXPECT_THROW(User(1, username, "c3R1ZGVudA"), std::invalid_argument);
}

TEST(UserTest, ValidUsernameBoundaryTest) 
{
    // Verify
    EXPECT_NO_THROW(User(1, string(4, 'x'), "c3R1ZGVudA"));
    EXPECT_NO_THROW(User(1, string(40, 'x'), "c3R1ZGVudA"));
}

TEST(UserTest, InvalidPasswordTest) 
{
    // Verify
    EXPECT_THROW(User(1, "homer", "123456789"), std::invalid_argument);
}

TEST(UserTest, ValidPasswordBoundaryTest) 
{
    // Verify
    EXPECT_NO_THROW(User(1, "homer", "1234567890"));
}
