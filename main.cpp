#include <string>
#include <iostream>
#include <iterator>
#include <fstream>
#include <sstream>

#include <JSON.h>
#include <functions.h>

using namespace std;

// Print out function
void print_out(const wchar_t* output)
{
    wcout << output;
    wcout.flush();
}

int main(int argc, char **argv)
{

    std::fstream stream;
    stream.open("test1.json");

    if(!stream.is_open())
    {
        std::cout << "Can not open file" << std::endl;
        return -1;
    }

    std::stringstream buff;
    buff << stream.rdbuf();


    JSONObject root;

    JSONValue *value = JSON::Parse(buff.str().c_str());
    if(value == NULL)
        std::cout << "Can not parse JSON file" << std::endl;
    else
    {
        root = value->AsObject();

        if (root.find(L"topics") != root.end() && root[L"topics"]->IsArray())
        {
            JSONArray arr = root[L"topics"]->AsArray();
            JSONObject topic;
            JSONValue *temp;

            for(size_t i = 0; i < arr.size(); i++)
            {
                temp = JSON::Parse(arr[i]->Stringify().c_str());
                topic = temp->AsObject();
                if(topic.find(L"name") != root.end() && topic[L"name"]->IsString())
                    std::wcout << topic[L"name"]->Stringify() << std::endl;
            }
        }

        if(root.find(L"boolean") != root.end() && root[L"boolean"]->IsBool())
        {


        }
    }

    return 0;
}




