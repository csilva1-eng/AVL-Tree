// #include <catch2/catch_test_macros.hpp>
// #include <iostream>
// #include <vector>
// #include <algorithm>
// #include <random>
//
// #include "AVL.h"
// #include "captureInput.h"
//
// using namespace std;
// std::string generate_random_string(size_t length);
// // // you must write 5 unique, meaningful tests for credit on the testing portion of this project!
//
//
// TEST_CASE("Five Inc Commands", "[Test]") {
// 	captureInput runner;
// 	std::vector<std::string> actualOutput, expectedOutput;
//
// 	SECTION("insert bad name") {
// 		runner.setInstructions("insert \"90210song\" 11111111");
// 		actualOutput = runner.getTree().printInorder();
// 		expectedOutput = {};
// 		REQUIRE(actualOutput.size() == expectedOutput.size());
// 		REQUIRE(actualOutput == expectedOutput);
// 	}
//
// 	SECTION("insert short UFID") {
// 		runner.setInstructions("insert \"chris\" 0");
// 		actualOutput = runner.getTree().printInorder();
// 		expectedOutput = {};
// 		REQUIRE(actualOutput.size() == expectedOutput.size());
// 		REQUIRE(actualOutput == expectedOutput);
// 	}
//
// 	SECTION("insert long UFID") {
// 		runner.setInstructions("insert \"chris\" 100000000");
// 		actualOutput = runner.getTree().printInorder();
// 		expectedOutput = {};
// 		REQUIRE(actualOutput.size() == expectedOutput.size());
// 		REQUIRE(actualOutput == expectedOutput);
// 	}
//
// 	SECTION("insert incorrect UFID") {
// 		runner.setInstructions("insert \"chris\" -19203929");
// 		actualOutput = runner.getTree().printInorder();
// 		expectedOutput = {};
// 		REQUIRE(actualOutput.size() == expectedOutput.size());
// 		REQUIRE(actualOutput == expectedOutput);
// 	}
//
// 	SECTION("insert bad UFID and bad name") {
// 		runner.setInstructions("insert \"this((bad(@)name\" 1");
// 		actualOutput = runner.getTree().printInorder();
// 		expectedOutput = {};
// 		REQUIRE(actualOutput.size() == expectedOutput.size());
// 		REQUIRE(actualOutput == expectedOutput);
// 	}
// }
//
//
// TEST_CASE("insert command and 4 rotation case", "[Test]") {
//
// 	AVL tree;
// 	tree.insert("chris", 10000000);
// 	tree.insert("kathering", 20000000);
// 	tree.insert("Antony", 30000000);
// 	std::vector<string> actualOutput = tree.printInorder();
// 	std::vector<string> expectedOutput = {"chris", "kathering", "Antony"};
// 	SECTION("insert Command") {
// 		REQUIRE(actualOutput.size() == expectedOutput.size());
// 		REQUIRE(actualOutput == expectedOutput);
// 	}
//
// 	AVL LLTree;
// 	LLTree.insert("Antony",30000000);
// 	LLTree.insert("kathering", 20000000);
// 	LLTree.insert("chris", 10000000);
// 	actualOutput = LLTree.printInorder();
// 	SECTION("Left Left Rotation") {
// 		REQUIRE(actualOutput.size() == expectedOutput.size());
// 		REQUIRE(actualOutput == expectedOutput);
// 	}
//
// 	AVL RRTree;
// 	RRTree.insert("chris", 10000000);
// 	RRTree.insert("kathering",20000000);
// 	RRTree.insert("Antony", 30000000);
// 	actualOutput = RRTree.printInorder();
// 	SECTION("Right Right Rotation") {
// 		REQUIRE(actualOutput.size() == expectedOutput.size());
// 		REQUIRE(actualOutput == expectedOutput);
// 	}
//
// 	AVL LRTree;
// 	LRTree.insert("Antony", 30000000);
// 	LRTree.insert("chris", 10000000);
// 	LRTree.insert("kathering", 20000000);
// 	actualOutput = LRTree.printInorder();
// 	SECTION("Left Right Rotation") {
// 		REQUIRE(actualOutput.size() == expectedOutput.size());
// 		REQUIRE(actualOutput == expectedOutput);
// 	}
//
// 	AVL RLTree;
// 	RLTree.insert("chris", 10000000);
// 	RLTree.insert("Antony", 30000000);
// 	RLTree.insert("kathering", 20000000);
// 	actualOutput = RLTree.printInorder();
// 	SECTION("Right Left Rotation") {
// 		REQUIRE(actualOutput.size() == expectedOutput.size());
// 		REQUIRE(actualOutput == expectedOutput);
// 	}
// }
//
//
// TEST_CASE("insert 100, del 10", "[Test]") {
// 	AVL hundredTree;
// 	std::vector<std::pair<std::string, int>> expectedOutput;
// 	std::vector<std::string> actualOutput;
//
// 	for(int i = 0; i < 100; i++)
// 	{
// 		int randomInput = (rand() % 90000000) + 10000000;
// 		std::string input = generate_random_string(13);
// 		if (std::count(expectedOutput.begin(), expectedOutput.end(), std::make_pair(input, randomInput)) == 0)
// 		{
// 			expectedOutput.push_back(std::make_pair(input, randomInput));
// 			hundredTree.insert(input, randomInput);
// 		}
// 	}
// 	actualOutput = hundredTree.printInorder();
// 	std::cout << actualOutput.size() << std::endl;
//
//
// 		int count = 100;
// 		for (int i = 0; i <10; i++) {
// 			int delRand = (rand() % count);
//
// 			hundredTree.removeById(expectedOutput[delRand].second);
// 			expectedOutput.erase(expectedOutput.begin() + delRand);
// 			count--;
//
// 		}
//
// 		actualOutput = hundredTree.printInorder();
//
// 		REQUIRE(expectedOutput.size() == actualOutput.size());
// 		std::sort(expectedOutput.begin(), expectedOutput.end(), [](const auto& p1, const auto& p2) {
// 			return p1.second < p2.second;
// 		});
// 		for (int i = 0; i < 90; i++) REQUIRE(expectedOutput[i].first == actualOutput[i]);
//
// }
//
//
//
// TEST_CASE("insert UFid beginning with 0s", "[Test]") {
// 	AVL tree;
//
// 	tree.insert("Antony", 00112233);
//
// 	std::vector<std::string> actualOutput = tree.printInorder();
// 	std::vector<std::string> expectedOutput = {};
//
// 	REQUIRE(actualOutput.size() == expectedOutput.size());
// 	REQUIRE(actualOutput == expectedOutput);
// }
//
// TEST_CASE("All 3 delete case", "[Test]") {
// 	AVL tree;
// 	SECTION("no children") {
// 		tree.insert("Antony", 20000000);
// 		tree.insert("chris", 30000000);
// 		tree.insert("silva", 10000000);
// 		tree.removeById(30000000);
//
// 		std::vector<std::string> actualOutput = tree.printInorder();
// 		REQUIRE(actualOutput.size() == 2);
// 		REQUIRE(actualOutput[0] == "silva");
// 		REQUIRE(actualOutput[1] == "Antony");
// 	}
//
// 	SECTION("one child on left") {
// 		tree.insert("Antony", 50000000);
// 		tree.insert("isabel", 60000000);
// 		tree.insert("silva", 10000000);
// 		tree.insert("chris", 30000000);
//
// 		tree.removeById(30000000);
// 		std::vector<std::string> actualOutput = tree.printInorder();
// 		REQUIRE(actualOutput.size() == 3);
// 		REQUIRE(actualOutput[0] == "silva");
// 		REQUIRE(actualOutput[1] == "Antony");
// 		REQUIRE(actualOutput[2] == "isabel");
// 	}
//
// 	SECTION("one child on right") {
// 		tree.insert("Antony", 50000000);
// 		tree.insert("isabel", 60000000);
// 		tree.insert("silva", 90000000);
// 		tree.insert("chris", 30000000);
//
// 		tree.removeById(60000000);
// 		std::vector<std::string> actualOutput = tree.printInorder();
// 		REQUIRE(actualOutput.size() == 3);
// 		REQUIRE(actualOutput[0] == "chris");
// 		REQUIRE(actualOutput[1] == "Antony");
// 		REQUIRE(actualOutput[2] == "silva");
// 	}
//
// 	SECTION("two children") {
// 		tree.insert("Antony", 50000000);
// 		tree.insert("isabel", 60000000);
// 		tree.insert("kat", 51000000);
// 		tree.insert("silva", 90000000);
// 		tree.insert("chris", 30000000);
//
// 		tree.removeById(60000000);
// 		std::vector<std::string> actualOutput = tree.printInorder();
// 		REQUIRE(actualOutput.size() == 4);
// 		REQUIRE(actualOutput[0] == "chris");
// 		REQUIRE(actualOutput[1] == "Antony");
// 		REQUIRE(actualOutput[2] == "kat");
// 		REQUIRE(actualOutput[3] == "silva");
//
// 	}
//
//
// 	SECTION("delete root") {
// 		tree.insert("Antony", 20000000);
// 		tree.insert("chris", 30000000);
// 		tree.insert("silva", 10000000);
// 		tree.removeById(20000000);
//
// 		std::vector<std::string> actualOutput = tree.printInorder();
// 		REQUIRE(actualOutput.size() == 2);
// 		REQUIRE(actualOutput[0] == "silva");
// 		REQUIRE(actualOutput[1] == "chris");
// 	}
// }
//
// TEST_CASE("delete entire tree", "[Test]") {
// 	AVL tree;
// 	std::vector<std::string> actualOutput;
// 	std::vector<std::string> expectedOutput;
// 	std::vector<std::pair<std::string, int>> HelperExpectedOutput;
// 	for(int i = 0; i < 30; i++)
// 	{
// 		int randomInput = (rand() % 90000000) + 10000000;
// 		std::string input = generate_random_string(13);
// 		if (std::count(HelperExpectedOutput.begin(), HelperExpectedOutput.end(), std::make_pair(input, randomInput)) == 0)
// 		{
// 			HelperExpectedOutput.push_back(std::make_pair(input, randomInput));
// 			tree.insert(input, randomInput);
// 		}
// 	}
//
// 	for (int i = 0; i <30; i++) {
// 		tree.removeById(HelperExpectedOutput[i].second);
// 	}
//
// 	actualOutput = tree.printInorder();
//
// 	REQUIRE(actualOutput.size() == expectedOutput.size());
// 	REQUIRE(actualOutput == expectedOutput);
//
// }
//
// TEST_CASE("testing search", "[Test]") {
// 	AVL tree;
// 	tree.insert("Antony", 12345678);
// 	tree.insert("chris", 12345679);
// 	tree.insert("isabel", 12345670);
// 	tree.insert("kat", 12345672);
// 	tree.insert("kathering", 10345678);
//
// 	SECTION("search by id") {
// 		std::string name = tree.searchIDTEST(tree.getRoot(), 12345670);
// 		REQUIRE(name == "isabel");
// 	}
//
// 	SECTION("search by name") {
// 		std::vector<int> ids = tree.searchNameTEST(tree.getRoot(), "kat");
// 		REQUIRE(ids[0] == 12345672);
// 	}
//
// 	SECTION("search by name multiples") {
// 		tree.insert("chris", 12341981);
// 		tree.insert("chris", 78839200);
// 		tree.insert("chris", 87654321);
// 		std::vector<int> ids = tree.searchNameTEST(tree.getRoot(), "chris");
// 		REQUIRE(ids[0] == 12341981);
// 		REQUIRE(ids[1] == 78839200);
// 		REQUIRE(ids[2] == 12345679);
// 		REQUIRE(ids[3] == 87654321);
// 	}
//
// }
//
// TEST_CASE("test max amt commands", "[Test]") {
// 	captureInput runner; // 250 insertions, 200 removal, 30 search, 30 prints, 490 insertion
// 	std::vector<int> toRemove;
// 	std::vector<std::string> toRemoveName;
// 	for (int i = 0; i < 250; i++) {
// 		int randomInput = (rand() % 90000000) + 10000000;
// 		std::string name = generate_random_string(13);
//
// 		std::string input = "insert \"" + name + "\" " + std::to_string(randomInput);
// 		runner.setInstructions(input);
// 		toRemove.push_back(randomInput);
// 		toRemoveName.push_back(name);
// 	}
//
//
// 	for (int i = 0; i <200; i++) {
// 		int randomRemove = rand() % toRemove.size();
//
// 		std::string input = "remove " + std::to_string(toRemove[randomRemove]);
// 		toRemove.erase(toRemove.begin() + randomRemove);
// 		toRemoveName.erase(toRemoveName.begin() + randomRemove);
// 		runner.setInstructions(input);
//
// 	}
//
// 	bool swap = false;
// 	 for (int i = 0; i < 30; i++) {
// 	 	int randomSearch = rand() % toRemove.size();
// 	 	std::string input;
// 	 	if (swap) {
// 	 		input = "search \"" + std::to_string(toRemove[randomSearch]) + "\"";
// 	 	} else {
// 	 		input = "search " + toRemoveName[randomSearch];
// 	 	}
// 	 	swap = !swap;
// 	 	runner.setInstructions(input);
// 	 }
//
// 	int count = 0;
// 	for (int i = 0; i <30; i++) {
// 		int whichPrint = count % 4;
// 		std::string input;
// 		if (whichPrint == 0) {
// 			input = "printInorder";
// 		} else if (whichPrint == 1) {
// 			input = "printPreorder";
// 		} else if (whichPrint == 2) {
// 			input = "printPostorder";
// 		} else if (whichPrint == 3) {
// 			input = "printLevelCount";
// 		}
// 		count++;
// 		runner.setInstructions(input);
// 	}
//
// 	for (int i = 0; i < 490; i++) {
// 		int randomInput = (rand() % 90000000) + 10000000;
// 		std::string name = generate_random_string(13);
//
// 		std::string input = "insert \"" + name + "\" " + std::to_string(randomInput);
// 		runner.setInstructions(input);
// 	}
//
// 	runner.determineInstructions();
//
// 	int size = runner.getTree().printInorder().size();
//
// 	REQUIRE(size == 540);
// }
//
// TEST_CASE("test prints", "[Test]") {
// 	AVL tree;
// 	tree.insert("Antony", 12345678);
// 	tree.insert("c", 12345679);
// 	tree.insert("isabel", 12345670);
// 	tree.insert("kat", 12345672);
// 	tree.insert("kathering", 10345678);
// 	tree.insert("ch", 12341981);
// 	tree.insert("chr", 78839200);
// 	tree.insert("chris", 87654321);
//
// 	std::vector<std::string> inorder = tree.printInorder();
// 	std::vector<std::string> expectedInorder = {"kathering", "ch", "isabel", "kat", "Antony", "c", "chr", "chris"};
// 	std::vector<std::string> preorder = tree.printPreorder();
// 	std::vector<std::string> expectedPreorder = {"isabel", "kathering", "ch", "Antony", "kat", "chr", "c", "chris"};
// 	std::vector<std::string> postorder = tree.printPostorder();
// 	std::vector<std::string> expectedPostorder = {"ch", "kathering", "kat", "c", "chris", "chr", "Antony", "isabel"};
// 	REQUIRE(inorder.size() == 8);
// 	REQUIRE(inorder == expectedInorder);
// 	REQUIRE(preorder.size() == 8);
// 	REQUIRE(preorder == expectedPreorder);
// 	REQUIRE(postorder.size() == 8);
// 	REQUIRE(postorder == expectedPostorder);
// }
//
// TEST_CASE("inserting dupes", "[Test]") {
// 	AVL tree;
// 	tree.insert("Antony", 12345678);
// 	tree.insert("c", 12345679);
// 	tree.insert("isabel", 12345670);
// 	tree.insert("kat", 12345672);
// 	tree.insert("kathering", 10345678);
//
// 	SECTION("insert dupe id") {
// 		tree.insert("darth vader", 12345678);
// 		std::vector<std::string> actual = tree.printInorder();
// 		std::string name = tree.searchIDTEST(tree.getRoot(), 12345678);
// 		REQUIRE(actual.size() == 5);
// 		REQUIRE(name == "Antony");
// 	}
// }
//
// TEST_CASE("remove Nth order val", "[testingNth]") {
// 	AVL tree;
//
//
// 	std::vector<string> actualOutput;
// 	std::vector<std::string> preActualOutput;
// 	std::vector<std::pair<std::string, int>> expectedOutput;
//
// 	for(int i = 0; i < 30; i++)
// 	{
// 		int randomInput = (rand() % 90000000) + 10000000;
// 		std::string input = generate_random_string(13);
// 		if (std::count(expectedOutput.begin(), expectedOutput.end(), std::make_pair(input, randomInput)) == 0)
// 		{
// 			expectedOutput.push_back(std::make_pair(input, randomInput));
// 			tree.insert(input, randomInput);
// 		}
// 	}
//
// 	preActualOutput = tree.printInorder();
// 	int removeN = rand() % preActualOutput.size() + 1;
// 	tree.removeNth(removeN);
//
// 	actualOutput = tree.printInorder();
// 	std::sort(actualOutput.begin(), actualOutput.end());
// 	std::sort(preActualOutput.begin(), preActualOutput.end());
// 	REQUIRE(actualOutput.size() == preActualOutput.size() - 1);
// }
//
//
// std::string generate_random_string(size_t length) {
// 	const std::string characters = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz";
// 	std::random_device random_device;
// 	std::mt19937 generator(random_device());
// 	std::uniform_int_distribution<> distribution(0, characters.size() - 1);
//
// 	std::string random_string;
// 	for (size_t i = 0; i < length; ++i) {
// 		random_string += characters[distribution(generator)];
// 	}
//
// 	return random_string;
// }
//
//
// //last things to do... maybe write a few more test cases... change around how catcher gets the inputs cause it can just crash
// //write the big O for the functions they wanted me to make write the reflection thats it
