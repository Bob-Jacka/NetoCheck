#include "ListNode.cpp"
#include "../catch_amalgamated.hpp"


TEST_CASE("Create list with null elements") {
    const auto sut = ListNode(1);
    REQUIRE(sut.next == nullptr);
}
