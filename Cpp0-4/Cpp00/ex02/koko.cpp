#include <iostream>
#include <ctime> // Required for time_t, time(), tm, localtime(), and strftime()
#include <cstdio> // Required for snprintf or similar functions for string formatting

// int main() {
//     time_t currentTime = time(NULL);
//     tm* localTime = localtime(&currentTime); // Convert to local time structure

//     char buffer[80]; // Buffer to store the formatted time string
//     strftime(buffer, sizeof(buffer), "%Y%m%d_%H%M%S", localTime); // Format the time

//     std::cout << "Formatted timestamp: " << buffer << std::endl;

//     return 0;
// }

// #include <iostream>
// #include <ctime> // Required for time() and ctime()

// int main() {
//     time_t currentTime = time(NULL); // Get current time, store in currentTime
//     std::cout << "Current Unix timestamp: " << currentTime << std::endl;

//     // Convert timestamp to a human-readable string
//     char* timeString = ctime(&currentTime); 
//     std::cout << "Current date and time: " << timeString << std::endl;

//     return 0;
// }

