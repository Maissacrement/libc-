#include <curl/curl.h>
#include <string>
#include <nlohmann/json.hpp>
#include <iostream>

using json = nlohmann::json;
using namespace std;

string data;

void fetch (std::string URL)
{
    char* char_arr;
    char_arr = &URL[0];
    try
    {
        /* code */
        CURL *curl = curl_easy_init();
        if(curl) {
            CURLcode res;
            curl_easy_setopt(curl, CURLOPT_URL, char_arr);
            res = curl_easy_perform(curl);
            curl_easy_cleanup(curl);
        }
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
}