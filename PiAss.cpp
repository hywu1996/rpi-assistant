//
//  PiAss.cpp
//  
//
//  Created by Anthony Wong on 2018-11-07.
//
//

#include "PiAss.hpp"

using namespace std;
using json = nlohmann::json;

int main(){
    cout << "Starting piAss\n" << endl;
    string jsonString = json_serializer("FLAC",16,"EN",2,false,false,"hello world!");
    cout << jsonString << endl;
    json j = json::parse(jsonString);
    cout << "example deserialization: get encoding value in inner config JSON" << endl;
    cout << j["config"]["encoding"] << endl;

}


