#include "NumeralConverter.hpp"

NumeralConverter::NumeralConverter(NumSystem system, std::string value)
{
    valueSystem = system;
    inputValue = value;
}

//Check if input string contains correct digits
bool NumeralConverter::valueGood()
{
    switch(valueSystem)
    {
        case NumSystem::BIN:
            for(int i = 0; i < inputValue.length(); i++)
                if(inputValue[i] != '0' && inputValue[i] != '1')
                    return false;
            break;

        case NumSystem::OCT:
            for(int i = 0; i < inputValue.length(); i++)
                if(inputValue[i] != '0' && inputValue[i] != '1' && inputValue[i] != '2' && inputValue[i] != '3'
                && inputValue[i] != '4' && inputValue[i] != '5' && inputValue[i] != '6' && inputValue[i] != '7')
                    return false;
            break;

        case NumSystem::DEC:
            for(int i = 0; i < inputValue.length(); i++)
                if(inputValue[i] != '0' && inputValue[i] != '1' && inputValue[i] != '2' && inputValue[i] != '3'
                && inputValue[i] != '4' && inputValue[i] != '5' && inputValue[i] != '6' && inputValue[i] != '7'
                && inputValue[i] != '8' && inputValue[i] != '9')
                    return false;
            break;

        case NumSystem::HEX:
            for(int i = 0; i < inputValue.length(); i++)
                if(inputValue[i] != '0' && inputValue[i] != '1' && inputValue[i] != '2' && inputValue[i] != '3'
                && inputValue[i] != '4' && inputValue[i] != '5' && inputValue[i] != '6' && inputValue[i] != '7'
                && inputValue[i] != '8' && inputValue[i] != '9' && inputValue[i] != 'A' && inputValue[i] != 'B' 
                && inputValue[i] != 'C' && inputValue[i] != 'D' && inputValue[i] != 'E' && inputValue[i] != 'F')
                    return false;
            break;
    }

    return true;
}

std::string NumeralConverter::ConvertValue(NumSystem target)
{
    switch(valueSystem)
    {
        case NumSystem::BIN:
            if(target == NumSystem::BIN)
                return inputValue;

            if(target == NumSystem::DEC)
                return binToDec();

            break;

        case NumSystem::DEC:
            if(target == NumSystem::BIN)
                return decToBin();

            if(target == NumSystem::DEC)
                return inputValue;

        break;
    }
}

//Conversion funtions start here

//Convert BIN to DEC and vice versa
std::string NumeralConverter::binToDec()
{
    int val = 0;
    int power = inputValue.length()-1;

    for(int i = 0; i < inputValue.length(); i++)
    {
        if(inputValue[i] == '1')
            val += pow(2, power);

        power--;
    }

    return std::to_string(val);
}

std::string NumeralConverter::decToBin()
{
    std::string binValTemp, binVal;
    int decVal = std::stoi(inputValue);

    while(decVal != 0)
    {
        if(decVal % 2 == 0)
            binValTemp += "0";
        else
            binValTemp += "1";
        
        decVal /= 2;
    }

    //Revert value
    for (int i = binValTemp.length() - 1; i >= 0; i--)
        binVal += binValTemp[i];

    return binVal;
}
