#ifndef COREPURITY_UTL_FILE_UTL_H
#define COREPURITY_UTL_FILE_UTL_H

#include <string>

namespace corepurity_core {

    class FileUtl 
    {
    public:
        static std::string read_file(const char* filepath)
        {
            FILE* file = fopen(filepath, "rt");  // New FILE object 'file'
            fseek(file, 0, SEEK_END);            // Go to the end of the file
            unsigned long length = ftell(file);  // Determine file length in bytes
            char* data = new char[length + 1];   // Create a new character array 'data'
            memset(data, 0, length + 1);         // Clear the data array
            fseek(file, 0, SEEK_SET);            // Go to the beginning of the file
            fread(data, 1, length, file);        // Read the file into data
            fclose(file);                        // Close the file
                                                 //
            std::string result(data);            // Create a new string 'result' from data
            delete[] data;                       // Delete the data array
            return result;                       // Return result
        }

    };

}

#endif//COREPURITY_UTL_FILE_UTL_H
