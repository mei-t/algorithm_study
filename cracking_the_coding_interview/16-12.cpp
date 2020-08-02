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
        string s;
        try{
            s = encodeXml(elem) + "0";
        }
        catch(char* e){
            cout << e << endl;
        }
        return s;
    }

private:
    unordered_map<string, string> encodeTag = {
        {"family", "1"},
        {"person", "2"}
    };

    unordered_map<string, string> encodeAttrib = {
        {"firstName", "3"},
        {"lastName", "4"},
        {"state", "5"}
    };

    string encodeXml(tinyxml2::XMLElement* elem){
        if(!elem)
            return "";
            
        string s;
        if(encodeTag.count(elem->Name())){
            s = encodeTag[elem->Name()] + " ";
        } else {
            throw "Tag doesn't find.";
        }
        const tinyxml2::XMLAttribute* attrib = elem->FirstAttribute();
        while(attrib){
            if(encodeAttrib.count(attrib->Name()))
                s += encodeAttrib[attrib->Name()] + " ";
            else
                throw "Attrib doesn't find.";
            s += (string)(attrib->Value()) + " ";
            attrib = attrib->Next();
        }

        s += "0 ";

        tinyxml2::XMLNode* node = elem->FirstChild();
        while(node){
            if(node->ToText()){
                s += elem->GetText();
                s += " 0 ";
            }
            s += encodeXml(node->ToElement());
            node = node->NextSibling();
        }
        return s;
    }
};

int main(void){
    string s1 = "<family lastName=\"McDowell\" state=\"CA\"><person firstName=\"Gayle\">Some Message</person></family>";
    XmlParse xp;
    cout << xp.encodeXml(s1) << endl;
    XmlParse2 xp2;
    string s2 = xp2.encodeXml("sample.xml");
    cout << s2 << endl;
    return 0;
}