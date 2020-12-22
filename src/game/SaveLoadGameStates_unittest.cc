#include "gtest/gtest.h"

#include "SaveLoadGameStates.h"
#include <string_theory/string>

TEST(SaveLoadGameTest, getSetGameStates)
{
	SavedGameStates states;

	states.Set("test_BOOL", true);
	states.Set("test_INT", 123);
	states.Set("test_FLOAT", 4.56f);
	states.Set("test_STRING", ST::string("abc"));
	states.Set("test_STRING_LIT", "def");

	EXPECT_EQ(states.Get<bool>("test_BOOL"), true);
	EXPECT_EQ(states.Get<int32_t>("test_INT"), 123);
	ASSERT_DOUBLE_EQ(states.Get<float>("test_FLOAT"), 4.56f);
	EXPECT_STREQ(states.Get<ST::string>("test_STRING").c_str(), "abc");
	EXPECT_STREQ(states.Get<ST::string>("test_STRING_LIT").c_str(), "def");
}

TEST(SaveLoadGameTest, edgeCases)
{
	SavedGameStates states;
	states.Set("K", true);

	ASSERT_THROW(states.Get<bool>(""), std::out_of_range);
	ASSERT_THROW(states.Get<int32_t>(ST::string("k")), std::out_of_range);
	ASSERT_THROW(states.Get<int32_t>("K"), std::bad_variant_access);
	ASSERT_THROW(states.Get<float>("K"), std::bad_variant_access);
}

TEST(SaveLoadGameTest, serializeJSON)
{
	SavedGameStates s;
	s.Set("B", true);
	s.Set("I", 987);
	s.Set("F", 6.5f);
	s.Set("S", ST::string("abc"));

	std::stringstream ss;
	s.Serialize(ss);
	EXPECT_EQ(ss.str(), "{\"B\":true,\"F\":6.5,\"I\":987,\"S\":\"abc\"}");
}

TEST(SaveLoadGameTest, deserializeEmpty)
{
	std::string json = "{}";
	std::stringstream ss(json);

	SavedGameStates s;
	s.Deserialize(ss);
	EXPECT_EQ(s.GetAll().size(), 0);
}

TEST(SaveLoadGameTest, deserializeJSON)
{
	std::string json = R"({"B":true,"F":3.4,"I":567,"S":"xyz"})";
	std::stringstream ss(json);

	SavedGameStates s;
	s.Deserialize(ss);

	EXPECT_EQ(s.Get<bool>("B"), true);
	EXPECT_EQ(s.Get<float>("F"), 3.4f);
	EXPECT_EQ(s.Get<int32_t>("I"), 567);
	EXPECT_EQ(s.Get<ST::string>("S"), "xyz");
	EXPECT_EQ(s.GetAll().size(), 4);
}