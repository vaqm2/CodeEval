#include <iostream>
#include <fstream>
#include <map>
#include <string>

std::string SubForTeens(std::string str)
{
    if(str.find("TenOne") != std::string::npos)
    {
        str.replace(str.find("TenOne"), 6, "Eleven");
    }
    if(str.find("TenTwo") != std::string::npos)
    {
        str.replace(str.find("TenTwo"), 6, "Twelve");
    }
    if(str.find("TenThree") != std::string::npos)
    {
        str.replace(str.find("TenThree"), 8, "Thirteen");
    }
    if(str.find("TenFour") != std::string::npos)
    {
        str.replace(str.find("TenFour"), 7, "Fourteen");
    }
    if(str.find("TenFive") != std::string::npos)
    {
        str.replace(str.find("TenFive"), 7, "Fifteen");
    }
    if(str.find("TenSix") != std::string::npos)
    {
        str.replace(str.find("TenSix"), 6, "Sixteen");
    }
    if(str.find("TenSeven") != std::string::npos)
    {
        str.replace(str.find("TenSeven"), 8, "Seventeen");
    }
    if(str.find("TenEight") != std::string::npos)
    {
        str.replace(str.find("TenEight"), 8, "Eighteen");
    }
    if(str.find("TenNine") != std::string::npos)
    {
        str.replace(str.find("TenNine"), 7, "Nineteen");
    }    
    return str;
}

int main(int argc, char **argv)
{
    std::string fileName = argv[1];
    std::fstream filePtr(fileName);
    std::string line;
    std::map <int, std::string> dollarLookUp;

    dollarLookUp.insert(std::make_pair(1, "One"));
    dollarLookUp.insert(std::make_pair(2, "Two"));
    dollarLookUp.insert(std::make_pair(3, "Three"));
    dollarLookUp.insert(std::make_pair(4, "Four"));
    dollarLookUp.insert(std::make_pair(5, "Five"));
    dollarLookUp.insert(std::make_pair(6, "Six"));
    dollarLookUp.insert(std::make_pair(7, "Seven"));
    dollarLookUp.insert(std::make_pair(8, "Eight"));
    dollarLookUp.insert(std::make_pair(9, "Nine"));
    dollarLookUp.insert(std::make_pair(10, "Ten"));
    dollarLookUp.insert(std::make_pair(20, "Twenty"));
    dollarLookUp.insert(std::make_pair(30, "Thirty"));
    dollarLookUp.insert(std::make_pair(40, "Forty"));
    dollarLookUp.insert(std::make_pair(50, "Fifty"));
    dollarLookUp.insert(std::make_pair(60, "Sixty"));
    dollarLookUp.insert(std::make_pair(70, "Seventy"));
    dollarLookUp.insert(std::make_pair(80, "Eighty"));
    dollarLookUp.insert(std::make_pair(90, "Ninety"));

    while(std::getline(filePtr, line))
    {
        int dollarAmount = std::stoi(line);
        std::string dollarText = "Dollars";
        int i = 0;
        while(dollarAmount > 0)
        {
            int quotient  = dollarAmount / 10;
            int remainder = dollarAmount % 10;
            dollarAmount = quotient;
            if(i == 0 && remainder > 0)
            {
                dollarText = dollarLookUp.find(remainder)->second + dollarText;
            }
            else if(i == 1 && remainder > 0)
            {
                dollarText = dollarLookUp.find(remainder*10)->second + dollarText;
            }
            else if(i == 2 && remainder > 0)
            {
                dollarText = dollarLookUp.find(remainder)->second + "Hundred" + dollarText;
            }
            else if(i == 3 && remainder > 0)
            {
                dollarText = dollarLookUp.find(remainder)->second + "Thousand" + dollarText;
            }
            else if(i == 4 && remainder > 0)
            {
                if(dollarText.find("Thousand") != std::string::npos)
                {
                    dollarText = dollarLookUp.find(remainder*10)->second + dollarText;
                }
                else
                {
                    dollarText = dollarLookUp.find(remainder*10)->second + "Thousand" + dollarText;
                }
            }
            else if(i == 5 && remainder > 0)
            {
                if(dollarText.find("Thousand") != std::string::npos)
                {
                    dollarText = dollarLookUp.find(remainder)->second + "Hundred" + dollarText;
                }
                else
                {
                    dollarText = dollarLookUp.find(remainder)->second + "Hundred" + "Thousand" + dollarText;
                }
            }
            else if(i == 6 && remainder > 0)
            {
                dollarText = dollarLookUp.find(remainder)->second + "Million" + dollarText;
            }
            else if(i == 7 && remainder > 0)
            {
                if(dollarText.find("Million") != std::string::npos)
                {
                    dollarText = dollarLookUp.find(remainder*10)->second + dollarText;
                }
                else
                {
                    dollarText = dollarLookUp.find(remainder*10)->second + "Million" + dollarText;
                }
            }
            else if(i == 8 && remainder > 0)
            {
                if(dollarText.find("Million") != std::string::npos)
                {
                    dollarText = dollarLookUp.find(remainder)->second + "Hundred" + dollarText;
                }
                else
                {
                    dollarText = dollarLookUp.find(remainder)->second + "Hundred" + "Million" + dollarText;
                }
            }
            i++;
        }
        dollarText = SubForTeens(dollarText);
        std::cout << dollarText << std::endl;
    }
    filePtr.close();
    return 0;
}
