/*
https://thispointer.com/c11-multithreading-part-9-stdasync-tutorial-example/

Need of std::async()
Suppose we have to fetch some data (string) from DB and some from files in file-system. 
Then I need to merge both the strings and print.
*/

#include <iostream>
#include <string>
#include <chrono>
#include <thread>
using namespace std::chrono;

std::string fetchDataFromDB(std::string recvdData) {
    // Make sure that function takes 5 seconds to complete
    std::this_thread::sleep_for(seconds(5));
    //Do stuff like creating DB Connection and fetching Data
    return "DB_" + recvdData;
}
std::string fetchDataFromFile(std::string recvdData) {
    // Make sure that function takes 5 seconds to complete
    std::this_thread::sleep_for(seconds(5));
    //Do stuff like fetching Data File
    return "File_" + recvdData;
}
int main() {
    // Get Start Time
    system_clock::time_point start = system_clock::now();
    //Fetch Data from DB
    std::string dbData = fetchDataFromDB("Data");
    //Fetch Data from File
    std::string fileData = fetchDataFromFile("Data");
    // Get End Time
    auto end = system_clock::now();
    auto diff = duration_cast < std::chrono::seconds > (end - start).count();
    std::cout << "Total Time Taken = " << diff << " Seconds" << std::endl;
    //Combine The Data
    std::string data = dbData + " :: " + fileData;
    //Printing the combined Data
    std::cout << "Data = " << data << std::endl;
    return 0;
}

