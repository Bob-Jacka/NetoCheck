#include "ListNode.cpp"
#include "dependencies/catch_amalgamated.hpp"

constexpr auto positive = "[Positive]"; ///Positive test tag
constexpr auto negative = "[Negative]"; ///Negative test tag

//Empty

TEST_CASE("Create empty List object and and check for emptiness", positive) {
    auto sut = List();
    auto res = sut.Empty();
    REQUIRE(res == true);
}

TEST_CASE("Create non-empty List object and and check for emptiness", positive) {
    auto sut = List();
    sut.PushBack(1);
    auto res = sut.Empty();
    REQUIRE(res == false);
}

TEST_CASE("Create List object with elem and pop elem", positive) {
    auto sut = List();
    sut.PushBack(1);
    sut.PopBack();
    auto res = sut.Empty();
    REQUIRE(res == true);
}

//Size

TEST_CASE("Create empty List and check for empty", positive) {
    auto sut = List();
    auto res = sut.Size();
    REQUIRE(res == 0);
}

TEST_CASE("Create non-empty List and check for empty", positive) {
    auto sut = List();
    sut.PushBack(1);
    auto res = sut.Size();
    REQUIRE(res == 1);
}

//Push (Front or Back)

TEST_CASE("Push elements in front of List", positive) {
    auto sut = List();
    SECTION("1. Add elements") {
        sut.PushFront(1);
        sut.PushFront(2);
        sut.PushFront(3);
    }SECTION("2. Check") {
        REQUIRE(sut.Size() == 3);
        REQUIRE(sut.Empty() == false);
    }
}

TEST_CASE("Push elements in back of List", "Positive") {
    auto sut = List();
    SECTION("1. Add elements") {
        sut.PushBack(1);
        sut.PushBack(2);
        sut.PushBack(3);
    }SECTION("2. Check") {
        REQUIRE(sut.Size() == 3);
        REQUIRE(sut.Empty() == false);
    }
}

TEST_CASE("Push elements in front and back of List", positive) {
    auto sut = List();
    SECTION("1. Add elements") {
        sut.PushFront(1);
        sut.PushFront(2);
        sut.PushFront(3);
        sut.PushBack(4);
        sut.PushBack(5);
        sut.PushBack(6);
    } SECTION("2. Check") {
        REQUIRE(sut.Size() == 6);
        REQUIRE(sut.Empty() == false);
    }
}

//Pop

TEST_CASE("Pop elements in front of List", positive) {
    auto sut = List();
    SECTION("1. Add elements") {
        sut.PushFront(1);
        sut.PushFront(2);
        sut.PushFront(3);
    }SECTION("2. Action and check") {
        auto f_pop = sut.PopFront();
        auto s_pop = sut.PopFront();
        auto t_pop = sut.PopFront();

        REQUIRE(f_pop == 1);
        REQUIRE(s_pop == 2);
        REQUIRE(t_pop == 3);
        REQUIRE(sut.Empty() == true);
        REQUIRE(sut.Size() == 0);
    }
}

TEST_CASE("Pop elements from empty list with front", negative) {
    auto sut = List();
    REQUIRE(sut.Size() == 0);
    REQUIRE_THROWS(sut.PopFront());
}

TEST_CASE("Pop elements from empty list with back", negative) {
    auto sut = List();
    REQUIRE(sut.Size() == 0);
    REQUIRE_THROWS(sut.PopBack());
}

TEST_CASE("Pop elements in back of List", positive) {
    auto sut = List();
    SECTION("1. Add elements") {
        sut.PushBack(1);
        sut.PushBack(2);
        sut.PushBack(3);
    }SECTION("2. Action") {
        sut.PopBack();
        sut.PopBack();
        sut.PopBack();
    }SECTION("3. Check") {
        REQUIRE(sut.Size() == 0);
        REQUIRE(sut.Empty() == true);
    }
}

//Clear

TEST_CASE("Clear elements from List object", positive) {
    auto sut = List();
    SECTION("1. Add elements") {
        sut.PushBack(1);
        sut.PushBack(2);
        sut.PushBack(3);
    }SECTION("2. Action") {
        REQUIRE_NOTHROW(sut.Clear());
    }SECTION("3. Check") {
        REQUIRE(sut.Size() == 0);
        REQUIRE(sut.Empty() == true);
    }
}

TEST_CASE("Clear elements from empty List object", negative) {
    auto sut = List();
    SECTION("1. Action") {
        REQUIRE_NOTHROW(sut.Clear());
    } SECTION("2. Check") {
        REQUIRE(sut.Size() == 0);
        REQUIRE(sut.Empty() == true);
    }
}