/******************************************************************************
	TO COMPILE:	Look at the makefile as well as the documentation

	Title:			lab8.cpp
	Author: 		Nicholas Liverett
	Date Created: 	10/31/24
	Last Updated: 	10/31/24
	Purpose: 		To demonstrate that data can be distributed on different 
					computers to be accessed and manipulated from a C++ program.

*******************************************************************************/

#include <iostream>
#include <string>
#include <curl/curl.h>
#include <nlohmann/json.hpp>
#include <sstream>

using json = nlohmann::json;
using namespace std;

//Function prototypes (do not change these)
static size_t WriteCallback(void*, size_t , size_t, ostream*);
string extractJson(const string&, const string&, const string&);

int main() 
{
	//variable definitions
    CURL* curl;
    CURLcode res;
    string readBuffer, startDelimiter, endDelimiter, jsonString;
    ostringstream oss;

	//Use CURL to retrieve data from website and store in ostringstream variable
    curl_global_init(CURL_GLOBAL_ALL);
    curl = curl_easy_init();
    if(curl) 
	{
        curl_easy_setopt(curl, CURLOPT_URL, "https://earthquake.usgs.gov/earthquakes/feed/v1.0/summary/all_month.geojson");
        curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, WriteCallback);
        curl_easy_setopt(curl, CURLOPT_WRITEDATA, &oss);
        curl_easy_setopt(curl, CURLOPT_SSL_VERIFYPEER, 0L);

        res = curl_easy_perform(curl);

        if(res != CURLE_OK) 
			cerr << "curl_easy_perform() failed: " << curl_easy_strerror(res) << endl;
        else 
            readBuffer = oss.str();

        curl_easy_cleanup(curl);
    }
    curl_global_cleanup();

	cout << endl;
	
	//now parse through the data and print
    try 
	{
        // create the json object
        json jsonObject = json::parse(readBuffer);
		
        // Access and print each object in the array using a range-based for loop (foreach loop)
        // looking at the format, we need each element in the features dictionary
        cout << "Earthquakes with magnitude greater than or equal to 4.5: " << endl;
        int numGreater = 1;
        
        for (auto& element : jsonObject["features"]) 
		{
            // looking at the way the data is formatted
            // in each features there is a properties dictionary to access 
            // the properties of a specific earthquake

            // if the earthquakes have a magnitude greater than 4.5
            
            if (element["properties"]["mag"] >= 4.5) {
                cout << "Earthquake " << numGreater << ": \n\tPlace: " << element["properties"]["place"] << "\n\tMagnitude: " << element["properties"]["mag"] << endl;
                cout << endl;
                numGreater++;
            }
            // There are a lot of earthquakes so I limit it to print the first 10
            if (numGreater > 10)
                break;
		}

        cout << "\nEarthquakes that caused a tsunami:\n\n";

        numGreater = 1;
        for (auto& element: jsonObject["features"]) {

            if (element["properties"]["tsunami"] == 1) {
                cout << "Earthquake " << numGreater << ": \n\tPlace: " << element["properties"]["place"] << "\n\tMagnitude: " << element["properties"]["mag"] << endl;
                cout << endl;
                numGreater++;
            }

            if (numGreater > 10)
                break;

        }

    } 
	catch (exception& e) 
    {
        cerr << "Error: " << e.what() << endl;
    }

    return 0;
}

// Callback function writes data to a ostream (do not modifiy this function)
static size_t WriteCallback(void* contents, size_t size, size_t nmemb, ostream* userp) 
{
    userp->write(static_cast<char*>(contents), size * nmemb);
    return size * nmemb;
}
