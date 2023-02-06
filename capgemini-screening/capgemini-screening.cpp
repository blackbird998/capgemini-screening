#include <iostream>
#include <vector>
#include <string.h>
#include <map>
#include <algorithm>

#include "phone.h"

struct tmpPhoneData
{
	std::string tmpBrandName = "";
	std::string tmpModelName = "";
	std::string tmpFormFactor = "";
	unsigned int tmpYearOfIssue = 0;
	float tmpScreenSize = 0.0f;
	float tmpPrice = 0.0f;
};
void interface(std::vector<Phone*> phoneDatabase);
void showByBrand(std::vector<Phone*> phoneDatabase, std::string brandName);
void showByFormFactorAndScreenSize(std::vector<Phone*> phoneDatabase, std::string formFactor, float screenSize);

void showDatabase(std::vector<Phone*> phoneDatabase) {
	int interator = 0;
	for (Phone* i : phoneDatabase) {
		std::cout << "Index: " << interator++ << "\n";
		std::cout << "Brand name: ";
		std::cout << i->getBrandName()<< "\n";
		std::cout << "Model name: ";
		std::cout << i->getModelName() << "\n";
		std::cout << "Form Factor ";
		std::cout << i->getFormFactor() << "\n";
		std::cout << "Year of issue: ";
		std::cout << i->getYearOfIssue() << "\n";
		std::cout << "Screen size (in): ";
		std::cout << i->getScreenSize() << "\n";
		std::cout << "Price: ";
		std::cout << i->getPrice() << "\n\n";
	}
}
void showByBrand(std::vector<Phone*> phoneDatabase, std::string brandName) {
	int interator = 0;
	for (Phone* i : phoneDatabase) {
		if (i->getBrandName() == brandName) {
			std::cout << "\nIndex: " << interator++ << "\n";
			std::cout << "Brand name: ";
			std::cout << i->getBrandName() << "\n";
			std::cout << "Model name: ";
			std::cout << i->getModelName() << "\n";
			std::cout << "Form Factor ";
			std::cout << i->getFormFactor() << "\n";
			std::cout << "Year of issue: ";
			std::cout << i->getYearOfIssue() << "\n";
			std::cout << "Screen size (in): ";
			std::cout << i->getScreenSize() << "\n";
			std::cout << "Price: ";
			std::cout << i->getPrice() << "\n\n";
		}	
	}
}
void showByFormFactorAndScreenSize(std::vector<Phone*> phoneDatabase, std::string formFactor, float screenSize) {
	int interator = 0;
	for (Phone* i : phoneDatabase) {
		if (i->getFormFactor() == formFactor && i->getScreenSize() == screenSize) {
			std::cout << "\nIndex: " << interator++ << "\n";
			std::cout << "Brand name: ";
			std::cout << i->getBrandName() << "\n";
			std::cout << "Model name: ";
			std::cout << i->getModelName() << "\n";
			std::cout << "Form Factor ";
			std::cout << i->getFormFactor() << "\n";
			std::cout << "Year of issue: ";
			std::cout << i->getYearOfIssue() << "\n";
			std::cout << "Screen size (in): ";
			std::cout << i->getScreenSize() << "\n";
			std::cout << "Price: ";
			std::cout << i->getPrice() << "\n\n";
		}
	}
}
void showPopularBrand(std::vector<Phone*> phoneDatabase) {
	std::map<std::string, int> countMap;
	for (auto& elem : phoneDatabase)
	{
		auto result = countMap.insert(std::pair<std::string, int>(elem->getBrandName(), 1));
		if (result.second == false)
			result.first->second++;
	}
	int max = 0;
	auto popularBrand = std::max_element(countMap.begin(), countMap.end(), [](const auto& x, const auto& y) {
		return x.second < y.second;
		});
	std::cout << "Popular brand: " << popularBrand->first << ", number of phones: " << popularBrand->second << "\n";
	

}
void showPopularScreenSize() {

}
void interface(std::vector<Phone*> phoneDatabase) {
	tmpPhoneData tmpPhoneData;
	int index;
	int switch_on;
	std::string brandName;
	std::string formFactor;
	float screenSize;

	while(true){
		std::cout << "Choose action : \n1. Add phone\n2. Delete phone\n3. See reports\n4. Exit\nOption: ";
		std::cin >> switch_on;

		switch (switch_on)
		{
		case 1:
			std::cout << "Brand name: ";
			std::cin >> tmpPhoneData.tmpBrandName;
			std::cout << "Model name: ";
			std::cin >> tmpPhoneData.tmpModelName;
			std::cout << "Form Factor ";
			std::cin >> tmpPhoneData.tmpFormFactor;
			std::cout << "Year of issue: ";
			std::cin >> tmpPhoneData.tmpYearOfIssue;
			std::cout << "Screen size (in): ";
			std::cin >> tmpPhoneData.tmpScreenSize;
			std::cout << "Price: ";
			std::cin >> tmpPhoneData.tmpPrice;

			phoneDatabase.push_back(new Phone(tmpPhoneData.tmpBrandName, tmpPhoneData.tmpModelName, tmpPhoneData.tmpFormFactor, tmpPhoneData.tmpYearOfIssue, tmpPhoneData.tmpScreenSize, tmpPhoneData.tmpPrice));
			showDatabase(phoneDatabase);

			break;
		case 2:
			showDatabase(phoneDatabase);
			std::cout << "Enter index of the phone to delete: ";
			std::cin >> index;
			phoneDatabase.erase(phoneDatabase.begin() + index);
			showDatabase(phoneDatabase);
			break;
		case 3:
			std::cout << "Choose report:\n1. Show all phones by the same brand\n2. Show all phones of a given form factor and screen size\n3. Show the name of the brand with the maximum quantity of the phones\n4. Show TOP-3 screen sizes";
			std::cin >> switch_on;
			switch (switch_on)
			{
			case 1:
				std::cout << "Enter brand name: ";
				std::cin >> brandName;
				showByBrand(phoneDatabase, brandName);
				break;
			case 2:
				std::cout << "Enter form factor: ";
				std::cin >> formFactor;
				std::cout << "Enter screen size: ";
				std::cin >> screenSize;
				showByFormFactorAndScreenSize(phoneDatabase, formFactor, screenSize);
				break;
			case 3:
				//std::cout << "Not implemented";
				showPopularBrand(phoneDatabase);
				break;
			case 4:
				std::cout << "Not implemented";
				break;
			default:
				std::cout << "Wrong option!\n";
				break;
			}

			break;
		case 4:
			std::cout << "\nProgram will close now.";
			return;

			break;

		default:
			std::cout << "Wrong option!\n";
			break;
		}
	}
}

int main()
{
	std::vector<Phone*> phoneDatabase;
	interface(phoneDatabase);

}


