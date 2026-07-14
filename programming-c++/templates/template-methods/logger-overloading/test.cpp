#include <string>

#include <gtest/gtest.h>

#include "logger.h"

TEST(LoggerTest, LogLevels)
{
    Logger logger("[main]");

    logger.fatal("power lost");
    logger.error("sensor failure");
    logger.warning("temperature high");
    logger.info("system started");
    logger.debug("loop iteration");

    ASSERT_EQ(5, logger.size());
    EXPECT_EQ("[main] FATAL: power lost", logger.lines()[0]);
    EXPECT_EQ("[main] ERROR: sensor failure", logger.lines()[1]);
    EXPECT_EQ("[main] WARNING: temperature high", logger.lines()[2]);
    EXPECT_EQ("[main] INFO: system started", logger.lines()[3]);
    EXPECT_EQ("[main] DEBUG: loop iteration", logger.lines()[4]);
}

TEST(LoggerTest, DifferentParameterTypes)
{
    Logger logger("[sensor]");

    // The compiler picks the matching overload for each argument type
    logger.info("calibration done");            // const char* -> std::string
    logger.info(std::string("value read"));     // std::string
    logger.debug(42);                           // int
    logger.warning(36.6);                       // double
    logger.error('X');                          // char

    ASSERT_EQ(5, logger.size());
    EXPECT_EQ("[sensor] INFO: calibration done", logger.lines()[0]);
    EXPECT_EQ("[sensor] INFO: value read", logger.lines()[1]);
    EXPECT_EQ("[sensor] DEBUG: 42", logger.lines()[2]);
    EXPECT_EQ("[sensor] WARNING: 36.6", logger.lines()[3]);
    EXPECT_EQ("[sensor] ERROR: X", logger.lines()[4]);
}

TEST(LoggerTest, EmptyLogger)
{
    Logger logger("[main]");

    EXPECT_EQ(0, logger.size());
    EXPECT_TRUE(logger.lines().empty());
}
