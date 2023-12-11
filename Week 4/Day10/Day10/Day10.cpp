// Day10.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <vector>



/*
	╔══════════╗
	║ File I/O ║
	╚══════════╝

	3 things are required for File I/O:
	1) Open the file
	2) read/write to the file
	3) close the file



*/
int main()
{
	std::cout << "Hello PG2!\n";

	/*

		╔════════════════╗
		║ write csv data ║
		╚════════════════╝

		[  Open the file  ]
		[  Write to the file  ]
		[  Close the file  ]

		you need the path to the file
			use full path ( drive + directories + filename )
			or use relative path ( directories + filename )
			or current directory ( filename )

		Make sure to separate the data in the file with a delimiter.
		The delimiter is important because it is used
			to separate the data when reading the file back in.


		Lecture code: set a filePath variable, open an output file, write some csv data to it
	*/
	std::string fileName = "2312.csv";
	std::string path = "C:\\temp\\2312\\";
	std::string fullPath = path + fileName;

	//1. OPEN the file
	std::ofstream outFile(fullPath);

	char delimiter = '*';
	if (outFile.is_open())
	{
		//2. WRITE to the file
		outFile << "Batman!" << delimiter << 5 << delimiter;
		outFile << 13.7 << delimiter << true << delimiter << 420 << "\n";

	}
	else
		std::cout << fullPath << " could not be opened.\n";

	//3. CLOSE the file
	outFile.close();

	/*

		╔═══════════════╗
		║ read csv data ║
		╚═══════════════╝

		[  Open the file  ]
		[  read the file  ]
		[  Close the file  ]

		Lecture code: using the filePath variable, open an input file, use getline to read a line, print the line
	*/
	{
		//1. OPEN the file
		std::ifstream inputFile(fullPath);

		if (inputFile.is_open())
		{
			//2. READ the file
			std::string line;
			std::getline(inputFile, line);
			std::cout << line << "\n";

			std::stringstream lineStream(line);
			std::string data;
			std::cout << "\n PARSING the CSV\n";
			int index = 1;
			while (std::getline(lineStream, data, delimiter))
			{
				if(index == 1) //string
					std::cout << data << "\n";
				else if (index == 2)
				{
					int five = std::stoi(data);
					std::cout << five << "\n";
				}
				else if (index == 3)
				{
					double dbl = std::stod(data);
					std::cout << dbl << "\n";
				}
				else if (index == 4)
				{
					bool isTrue = std::stoi(data);
					std::cout << isTrue << "\n";
				}
				else
				{
					int four20 = std::stoi(data);
					std::cout << four20 << "\n";
				}
				
				index++;
			}
		}
		else
			std::cout << fullPath << " could not be found. STEEV!!!\n";

		//3. CLOSE the file
	}//inputFile.close(); automatically closes when the variable goes out of scope


	/*

		╔═════════════════════╗
		║ parsing csv strings ║
		╚═════════════════════╝

		use getline on a string stream instead of a file stream

		Lecture code:
			using the line read in above, use a stringstream to split the line using getline.
			store the separate items in a vector
			parse each item in the vector to an appropriate variable.


	*/





	/*

		CHALLENGE:

		Parse the multi csv string (below) to get the data.
		NOTE: the data is a collection of object data.
		There are multiple delimiters.
		Separate on the first delimiter (collectionSeparator) to get the csv data for each object.
		Then, separate the object csv data on objectSeparator to get the details of the object.

		EX: hero#hero#hero   each hero is separated by a #
			name^secret^age  the details of each hero is separated by a ^

	*/
	std::string multi = "Batman^Bruce Wayne^35#Superman^Clark Kent^25#Wonder Woman^Diana Prince^25#Aquaman^Arthur Curry^12";
	char collectionSeparator = '#';
	char objectSeparator = '^';
}