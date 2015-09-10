#include <iostream>
#include <fstream>
#include <string>

int index(int rowNum, int colNum, int nCols)        
{
    return (rowNum * nCols + colNum);
}
int main(int argc, char **argv)
{
    std::string fileName = argv[1];
    std::fstream filePtr(fileName);
    std::string line;

    while(std::getline(filePtr, line))
    {
        size_t delimiter_position = line.find(',');
        int nrows                 = std::stoi(line.substr(0, delimiter_position));
        line                      = line.substr(delimiter_position + 1, line.length() - delimiter_position);
        delimiter_position        = line.find(';');
        int ncols                 = std::stoi(line.substr(0, delimiter_position));
        line                      = line.substr(delimiter_position + 1,line.length() - delimiter_position);
        //        std::cout << nrows << '\t' << ncols << '\t' << line << std::endl;
        for(int i = 0; i < line.length(); i++)
        {
            if(line[i] == '*')
            {
                std::cout << line[i];
            }
            else
            {                
               int rowNum             = i / ncols;
               int colNum             = i % ncols;
               int num_Adjacent_Mines = 0;
               //Checking Adjacent Locations for Mines
               if(rowNum - 1 >= 0) // 1
               {
                   if(line[index(rowNum - 1, colNum, ncols)] == '*')
                   {
                       num_Adjacent_Mines++;
                   }
               }
               if(rowNum - 1 >= 0 && colNum - 1 >= 0) //2
               {
                   if(line[index(rowNum - 1, colNum - 1, ncols)] == '*')
                   {
                       num_Adjacent_Mines++;
                   }
               }
               if(rowNum - 1 >= 0 && colNum + 1 < ncols) //3
               {
                   if(line[index(rowNum - 1, colNum + 1, ncols)] == '*')
                   {
                       num_Adjacent_Mines++;
                   }
               }
               if(rowNum + 1 < nrows) //4
               {
                   if(line[index(rowNum + 1, colNum, ncols)] == '*')
                   {
                       num_Adjacent_Mines++;
                   }
               }
               if(rowNum + 1 < nrows && colNum - 1 >= 0) //5
               {
                   if(line[index(rowNum + 1, colNum - 1, ncols)] == '*')
                   {
                       num_Adjacent_Mines++;
                   }
               }
               if(rowNum + 1 < nrows && colNum + 1 < ncols) //6
               {
                   if(line[index(rowNum + 1, colNum + 1, ncols)] == '*')
                   {
                       num_Adjacent_Mines++;
                   }
               }
               if(colNum + 1 < ncols) //7
               {
                   if(line[index(rowNum, colNum + 1, ncols)] == '*')
                   {
                       num_Adjacent_Mines++;
                   }
               }
               if(colNum - 1 >= 0) //8
               {
                   if(line[index(rowNum, colNum - 1, ncols)] == '*')
                   {
                       num_Adjacent_Mines++;
                   }
               }               
               std::cout << num_Adjacent_Mines;     
            }            
        }
        std::cout << std::endl;
    }
    filePtr.close();
    return 0;
}
