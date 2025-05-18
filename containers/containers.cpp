// containers.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>;
#include <array>;
#include <vector>;
#include <list>;
#include <map>;




void testArray()
{
    //create the array
    std::array<std::string, 7> weekdays = { "Monday", "Tuesday", "Wednesday", "Thursday", "Friday", "Saturday", "Sunday" };
    //yes, i know it is 7.... still wanted to use the function
    std::cout << weekdays.max_size() << std::endl;
    //foreach to get each value
    for (std::string day : weekdays)
    {
        std::cout << day << std::endl;
    }
}

void testVector()
{
    //create the vector
    std::vector<int> intVector = { 1,4,6,8,9 };
    //1,4,6,8,9,12
    intVector.push_back(12);
    //1,4,6,8,9,12,3
    intVector.push_back(3);
    //1,4,6,8,9,12
    intVector.pop_back();
    for (int val : intVector)
    {
        std::cout << val << std::endl;
    }
}

void testList()
{
    //make the list
    std::list<std::string> fruits = { "apple", "banana", "dragon fruit" };
    //orange, apple, banana, dragon fruit
    fruits.push_front("orange");
    //orange, apple, banana, dragon fruit, kiwi
    fruits.push_back("kiwi");
    //orange, apple, dragon fruit, kiwi
    fruits.remove("banana");
    for (std::string fruit : fruits)
    {
        std::cout << fruit << std::endl;
    }
}

void testMap()
{
    //make the map
    std::map<std::string, int> groceryProducts = { {"carrots", 22},{"potatoes", 30},{"white bread", 15} };
    groceryProducts.insert({"tomatoes", 17});
    groceryProducts.insert({ "chips", 7});
    groceryProducts.insert({ "gummy bears" , 20});

    groceryProducts["carrots"] = 21;

    //using auto because i dont want to remember what type this is, or how to use the standard for loop on it
    //also the map auto sorts itself based on sorting the keys of each item
    for (auto pair : groceryProducts)
    {
        std::cout << pair.first << " : " << pair.second << std::endl;
    }
}

int main()
{
    testArray();
    testVector();
    testList();
    testMap();
}