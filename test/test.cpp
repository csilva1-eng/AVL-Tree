#include <catch2/catch_test_macros.hpp>
#include <iostream>
#include <vector>
#include <algorithm>
#include <random>

#include "AVL.h"

using namespace std;
std::string generate_random_string(size_t length);


TEST_CASE("Five Inc Commands", "[checkin]") {
	AVL tree;

	SECTION("insert bad name") {
		REQUIRE_THROWS_AS(tree.insert("90210song", 11111111), std::invalid_argument);
	}

	SECTION("insert short UFID") {
		REQUIRE_THROWS_AS(tree.insert("chris", 0), std::invalid_argument);
	}

	SECTION("insert long UFID") {
		REQUIRE_THROWS_AS(tree.insert("chris", 100000000), std::invalid_argument);
	}

	SECTION("insert incorrect UFID") {
		REQUIRE_THROWS_AS(tree.insert("chris", -19203929), std::invalid_argument);
	}

	SECTION("insert bad UFID and bad name") {
		REQUIRE_THROWS_AS(tree.insert("this((bad(@)name", 1), std::invalid_argument);
	}
}

TEST_CASE("insert x vals", "[testing]") {
	AVL tree;
	tree.insert("chris", 10000001);
	tree.insert("kathering", 20000000);
	tree.insert("Antony", 30000000);
	tree.insert("Isabel", 20000300);
	std::vector<string> actualOutput = tree.printInorder();
	std::vector<string> expectedOutput = {"chris", "kathering", "Isabel", "Antony"};
	SECTION("insert 4") {
		REQUIRE(actualOutput.size() == expectedOutput.size());
		REQUIRE(actualOutput == expectedOutput);
	}

	tree.insert("bleh", 10000000);
	actualOutput = tree.printInorder();
	expectedOutput = {"bleh", "chris", "kathering", "Isabel", "Antony"};
	SECTION("insert 5") {
		REQUIRE(actualOutput.size() == expectedOutput.size());
		REQUIRE(actualOutput == expectedOutput);

	}
}

TEST_CASE("insert command and 4 rotation case", "[bro]") {
	AVL tree;
	tree.insert("chris", 10000000);
	tree.insert("kathering", 20000000);
	tree.insert("Antony", 30000000);
	std::vector<string> actualOutput = tree.printInorder();
	std::vector<string> expectedOutput = {"chris", "kathering", "Antony"};
	SECTION("insert Command") {
		REQUIRE(actualOutput.size() == expectedOutput.size());
		REQUIRE(actualOutput == expectedOutput);
	}

	AVL LLTree;
	LLTree.insert("Antony",30000000);
	LLTree.insert("kathering", 20000000);
	LLTree.insert("chris", 10000000);
	actualOutput = LLTree.printInorder();
	SECTION("Left Left Rotation") {
		REQUIRE(actualOutput.size() == expectedOutput.size());
		REQUIRE(actualOutput == expectedOutput);
	}

	AVL RRTree;
	RRTree.insert("chris", 10000000);
	RRTree.insert("kathering",20000000);
	RRTree.insert("Antony", 30000000);
	actualOutput = RRTree.printInorder();
	SECTION("Right Right Rotation") {
		REQUIRE(actualOutput.size() == expectedOutput.size());
		REQUIRE(actualOutput == expectedOutput);
	}

	AVL LRTree;
	LRTree.insert("Antony", 30000000);
	LRTree.insert("chris", 10000000);
	LRTree.insert("kathering", 20000000);
	actualOutput = LRTree.printInorder();
	SECTION("Left Right Rotation") {
		REQUIRE(actualOutput.size() == expectedOutput.size());
		REQUIRE(actualOutput == expectedOutput);
	}

	AVL RLTree;
	RLTree.insert("chris", 10000000);
	RLTree.insert("Antony", 30000000);
	RLTree.insert("kathering", 20000000);
	actualOutput = RLTree.printInorder();
	SECTION("Right Left Rotation") {
		REQUIRE(actualOutput.size() == expectedOutput.size());
		REQUIRE(actualOutput == expectedOutput);
	}
}

TEST_CASE("insert 100", "[testing2]") {
	AVL hundredTree;
	std::vector<std::pair<std::string, int>> expectedOutput;
	std::vector<std::string> actualOutput;

	for(int i = 0; i < 100; i++)
	{
		int randomInput = (rand() % 99999999) + 10000000;
		std::string input = generate_random_string(13);
		if (std::count(expectedOutput.begin(), expectedOutput.end(), std::make_pair(input, randomInput)) == 0)
		{
			expectedOutput.push_back(std::make_pair(input, randomInput));
			hundredTree.insert(input, randomInput);
		}
	}

	actualOutput = hundredTree.printInorder();

	SECTION("insert 100") {
		REQUIRE(expectedOutput.size() == actualOutput.size());
		std::sort(expectedOutput.begin(), expectedOutput.end(), [](const auto& p1, const auto& p2) {
			return p1.second < p2.second;
		});
		for (int i = 0; i < 100; i++) REQUIRE(expectedOutput[i].first == actualOutput[i]);
	}
}

TEST_CASE("Remove x amount", "[testingR]") {
	AVL tree;
	tree.insert("chris", 10000000);
	tree.insert("kathering", 20000000);
	tree.insert("Antony", 30000000);
	tree.insert("bleh", 23490391);
	tree.insert("satw", 99332211);
	tree.insert("apweo", 29999900);
	tree.removeById(29999900);

	std::vector<string> actualOutput = tree.printInorder();
	std::vector<string> expectedOutput = {"kathering", "Antony"};
	REQUIRE(actualOutput.size() == expectedOutput.size());
	REQUIRE(actualOutput == expectedOutput);
}

TEST_CASE("insert 100, del 10", "[testingR10]") {
	AVL hundredTree;
	std::vector<std::pair<std::string, int>> expectedOutput;
	std::vector<std::string> actualOutput;

	for(int i = 0; i < 100; i++)
	{
		int randomInput = (rand() % 99999999) + 10000000;
		std::string input = generate_random_string(13);
		if (std::count(expectedOutput.begin(), expectedOutput.end(), std::make_pair(input, randomInput)) == 0)
		{
			expectedOutput.push_back(std::make_pair(input, randomInput));
			hundredTree.insert(input, randomInput);
		}
	}
	actualOutput = hundredTree.printInorder();
	std::cout << actualOutput.size() << std::endl;


		int count = 100;
		for (int i = 0; i <10; i++) {
			int delRand = (rand() % count);

			hundredTree.removeById(expectedOutput[delRand].second);
			expectedOutput.erase(expectedOutput.begin() + delRand);
			count--;

		}

		actualOutput = hundredTree.printInorder();

		REQUIRE(expectedOutput.size() == actualOutput.size());
		std::sort(expectedOutput.begin(), expectedOutput.end(), [](const auto& p1, const auto& p2) {
			return p1.second < p2.second;
		});
		for (int i = 0; i < 90; i++) REQUIRE(expectedOutput[i].first == actualOutput[i]);

}

TEST_CASE("remove Nth order val", "[testingNth]") {
	AVL tree;
	tree.insert("kathering", 20000000);
	tree.insert("Antony", 30000000);
	tree.insert("bleh", 23490391);
	tree.insert("satw", 99332211);
	tree.insert("apweo", 29999900);


	std::vector<string> actualOutput = tree.printInorder();
	std::vector<string> expectedOutput = {"kathering", "bleh", "apweo", "Antony", "satw"};

	tree.removeNth(3);

	actualOutput = tree.printInorder();
	expectedOutput = {"kathering", "bleh", "Antony", "satw"};
	REQUIRE(actualOutput.size() == expectedOutput.size());
	REQUIRE(actualOutput == expectedOutput);
}
// // you must write 5 unique, meaningful tests for credit on the testing portion of this project!


std::string generate_random_string(size_t length) {
	const std::string characters = "0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz";
	std::random_device random_device;
	std::mt19937 generator(random_device());
	std::uniform_int_distribution<> distribution(0, characters.size() - 1);

	std::string random_string;
	for (size_t i = 0; i < length; ++i) {
		random_string += characters[distribution(generator)];
	}

	return random_string;
}