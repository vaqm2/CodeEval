#include <iostream>
#include <fstream>
#include <string>

int main(int argc, char **argv)
{
    std::string fileName = argv[1];
    std::fstream filePtr(fileName);
    std::string line;

    while(std::getline(filePtr, line))
    {
        int num_categories = 0;
        //Check Number of Categories by counting spaces upto first Delimiter
        for(int i = 0; i <= line.length(); i++)
        {
            if(line[i] == ' ')
            {
                num_categories++;
            }
            else if(line[i] == '|')
            {
                break;
            }
        }
        //Declare Array of Max_Scores which will be comapred and Updated on each new row
        int max_scores[num_categories];            
        size_t space_position = 0;
        int category_number   = 0;
        bool first_pass       = 1;
        while(space_position != std::string::npos)
        {
            space_position         = line.find(' ');
            std::string sub_string = line.substr(0, space_position);
            line                   = line.substr(space_position + 1, line.length() - space_position);
            if(sub_string == "|")
            {
                first_pass = 0;
                category_number = 0;
            }
            else
            {
                int current_score = std::stoi(sub_string);
                if(first_pass == 1)
                {
                    max_scores[category_number] = current_score;
                }
                else
                {
                    if(current_score > max_scores[category_number])
                    {
                        max_scores[category_number] = current_score;
                    }                    
                }
                category_number++;
            }
        }
        for(int i = 0; i < num_categories; i++)
        {
            if(i > 0)
            {
                std::cout << ' ';
            }
            std::cout << max_scores[i];
        }
        std::cout << std::endl;
    }    
    filePtr.close();    
    return 0;
}
