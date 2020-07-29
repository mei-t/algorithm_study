#include <iostream>
#include <unordered_map>
#include "tinyxml2.h"
using namespace std;

class XmlParse{
public:
    string encodeXml(string& s){
        int index = 0;
        string res = "";
        while(index < s.size()){
            res += (index == 0 ? "" : " ");
            switch(s[index]){
                case '<':
                    index++;
                    if(s[index] == '/'){
                        res += "0";
                        detectWord(s, &index, '>');
                    } else {
                        res += xmlMap[detectWord(s, &index, ' ')];
                    }
                    break;
                case '"':
                    index += 1;
                    res += detectWord(s, &index, '"');
                    break;
                case ' ':
                    index++;
                    res += xmlMap[detectWord(s, &index, '=')];
                    break;
                case '>':
                    res += "0";
                    break;
                case '/':
                    res += "0";
                    detectWord(s, &index, '>');
                    break;
                default:
                    res += (s[index-1] == ' ' ? xmlMap[detectWord(s, &index, '=')] : detectWord(s, &index, '<'));
            }
            index++;
        }
        return res;
    }

private:
    unordered_map<string, string> xmlMap = {
        {"family", "1"},
        {"person", "2"},
        {"firstName", "3"},
        {"lastName", "4"},
        {"state", "5"}
    };

    string detectWord(string& s, int* index, char del){
        int start = *index;
        while(s[*index] != del)
            (*index)++;
        return s.substr(start, *index - start);
    }
};

class XmlParse2{
public:
    string encodeXml(const char* filename){
        tinyxml2::XMLDocument doc;
        doc.LoadFile(filename);
        tinyxml2::XMLElement* elem = doc.RootElement();
        string s = "";
        encodeXml(elem, s);
        return s;
    }
private:
    unordered_map<string, string> tagMap = {
        {"family", "1"},
        {"person", "2"}
    };

    unordered_map<string, string> attribMap = {
        {"firstName", "3"},
        {"lastName", "4"},
        {"state", "5"}
    };

    void encodeXml(tinyxml2::XMLElement* elem, string& s){
        s += tagMap[elem->Name()] + " ";
        const tinyxml2::XMLAttribute* attrib = elem->FirstAttribute();
        while(attrib){
            s += attribMap[attrib->Name()] + " ";
            s += (string)(attrib->Value()) + " ";
            attrib = attrib->Next();
        }

        s += "0 ";
        if(elem->ToText())
            s += elem->GetText();
        elem = elem->FirstChildElement();
        while(elem){
            encodeXml(elem, s);
            elem = elem->NextSiblingElement();
        }
        s += "0 ";
    }
};

int main(void){
    // string s = "<family lastName=\"McDowell\" state=\"CA\"><person firstName=\"Gayle\">Some Message</person></family>";
    // XmlParse xp;
    // cout << xp.encodeXml(s) << endl;
    XmlParse2 xp2;
    string s = xp2.encodeXml("sample.xml");
    cout << s << endl;
    return 0;
}