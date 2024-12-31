#include <iostream>
#include <string>
#include <curl/curl.h>
#include <json/json.h>  // JSONCPP für JSON-Verarbeitung

// Funktion, um die Antwort von der API zu speichern
size_t WriteCallback(void* contents, size_t size, size_t nmemb, void* userp) {
    ((std::string*)userp)->append((char*)contents, size * nmemb);
    return size * nmemb;
}

// Funktion, um das Wetter abzurufen
void getWeather(const std::string& city, const std::string& apiKey) {
    CURL* curl;
    CURLcode res;

    std::string readBuffer;
    std::string url = "http://api.openweathermap.org/data/2.5/weather?q=" + city + "&appid=" + apiKey + "&units=metric";

    curl_global_init(CURL_GLOBAL_DEFAULT);
    curl = curl_easy_init();

    if (curl) {
        curl_easy_setopt(curl, CURLOPT_URL, url.c_str());
        curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, WriteCallback);
        curl_easy_setopt(curl, CURLOPT_WRITEDATA, &readBuffer);

        res = curl_easy_perform(curl);

        if (res == CURLE_OK) {
            Json::Value jsonData;
            Json::CharReaderBuilder reader;
            std::string errs;
            std::istringstream s(readBuffer);

            if (Json::parseFromStream(reader, s, &jsonData, &errs)) {
                // Wetterdaten extrahieren
                std::string cityName = jsonData["name"].asString();
                float temperature = jsonData["main"]["temp"].asFloat();
                std::string description = jsonData["weather"][0]["description"].asString();

                std::cout << "Wetter für " << cityName << ":\n";
                std::cout << "Temperatur: " << temperature << "°C\n";
                std::cout << "Beschreibung: " << description << "\n";
            } else {
                std::cerr << "Fehler beim Verarbeiten der JSON-Antwort: " << errs << std::endl;
            }
        } else {
            std::cerr << "Fehler bei der Anfrage: " << curl_easy_strerror(res) << std::endl;
        }

        curl_easy_cleanup(curl);
    }

    curl_global_cleanup();
}

int main() {
    std::string city;
    std::string apiKey = "DEIN_API_SCHLÜSSEL"; // Deinen API-Schlüssel hier einfügen

    std::cout << "Gib eine Stadt ein: ";
    std::cin >> city;

    getWeather(city, apiKey);

    return 0;
}
