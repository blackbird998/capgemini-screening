#include "phone.h"


//Phone::Phone() {};
Phone::Phone(std::string _brandName = "", std::string _modelName = "", std::string _formFactor = "", unsigned int _yearOfIssue = 0, float _screenSize = 0.0f, float _price = 0.0f) {
	brandName = _brandName;
	modelName = _modelName;
	formFactor = _formFactor;
	yearOfIssue = _yearOfIssue;
	screenSize = _screenSize;
	price = _price;
}


