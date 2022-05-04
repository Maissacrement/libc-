#include <curl/curl.h>
#include <string>
#include <iostream>
#include <nlohmann/json.hpp>

using json = nlohmann::json;
using namespace std;

string data;

void fetch (char* URL)
{
    CURL *curl = curl_easy_init();
    if(curl) {
        CURLcode res;
        curl_easy_setopt(curl, CURLOPT_URL, URL);
        res = curl_easy_perform(curl);
        json jtes = curl_easy_cleanup(curl);
        cout << jtes;
    }
} 

// Driver Code
int main()
{
    int apple_count {0};
    std::cout << "This program returns the integer value "
              << apple_count
              << "\n";
    fetch("https://dummyjson.com/products");

    return 0;
}